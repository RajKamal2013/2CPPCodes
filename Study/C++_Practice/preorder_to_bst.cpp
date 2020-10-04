#include<iostream>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;

class vector1 
{
   int n;
   public:
      int *arr;
      vector1(int n);
      int size();
      void get(int n,int *arr);
      friend  istream & operator >>(istream &din,vector1 &v);
};


vector1 :: vector1 (int N)
  {
     this->n=N;
     arr=new int[N];
  };

int vector1 :: size()
  {
      return n;
  }
 
void vector1 :: get (int n,int *arr)
  {
    for(int i=0;i<n;i++)
     {
       this->arr[i]=arr[i];
     }
  }

istream & operator >>(istream  & din,vector1 &v)
{
   int n=v.size();
   for(int i=0;i<n;i++)
      din >> v.arr[i];
   return din;
} 

struct node 
 {
   int data;
   node *left;
   node *right;
 };

void inorder(node *root)
 {
    node *ptr=root;
    if(ptr!=NULL) 
    {
      inorder(ptr->left);
      printf("%d ",ptr->data);
      inorder(ptr->right);
    }
 }

void preorder(node *root)
 {
    node *ptr=root;
    if(ptr!=NULL)
    {
      printf("%d ",ptr->data);
      preorder(ptr->left);
      preorder(ptr->right);
    }
 }

void postorder(node *root)
  {
    node *ptr=root;
    if(ptr!=NULL)
     {
          postorder(ptr->left);
          postorder(ptr->right);
          printf("%d ",ptr->data);
     }
   }

int main()
 {
   node *root=NULL;
   stack<node *>s;
   int N;
   printf("Enter the number of nodes \n");
   scanf("%d",&N);
   vector1 v(N);
   cin >> v;
   int data;
   data=v.arr[0];
   node *ptr;
   node *new_node=new node;
   new_node->data=data;
   new_node->left=NULL;
   new_node->right=NULL;
   root=new_node;
   s.push(root);
   for(int i=1;i<N;i++)
    {
        node *temp=new node;
        data=v.arr[i];
        temp->data=data;
        temp->right=NULL;
        temp->left=NULL;
        ptr=s.top();
        if(ptr->data > data)
          {
             ptr->left=temp;
             s.push(temp);
          }
        if(ptr -> data < data)
          {
             node *var;
             s.pop(); 
             while((!s.empty())&&(ptr->data < data))
               {
                  var=ptr;
                  ptr=s.top();
                  s.pop();
               }
            if(s.empty()==true && ptr->data < data)
             {
               ptr->right=temp;
               s.push(temp);
             }
            else
             {
               s.push(ptr); 
               var->right=temp;
               s.push(temp);
             }
          }
          if(ptr->data==data)
          ;
     }
   printf("PREORDER :\n");
   preorder(root);
   cout<<endl;
   printf("INORDER :\n");
   inorder(root);
   cout<<endl;
   printf("POSTORDER :\n");
   postorder(root);
   cout<<endl;
   return 0;
 }

 
       

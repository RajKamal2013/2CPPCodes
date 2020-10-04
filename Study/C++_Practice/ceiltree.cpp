#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node
 {
   int data;
   node *left;
   node *right;
 };

class vector1
 {
   int n;
    public:
      int *arr;
       vector1(int n);
      int  size();
      void get(int n,int *arr);
      friend istream & operator >>(istream & din,vector1 &v);
 };

vector1 :: vector1(int n)
  {
    this->n=n;
    arr=new int[n];
  }

int  vector1 :: size()
 {
    return this->n;
 }
 

void vector1 :: get (int n,int *arr)
{
     for(int i=0;i<n;i++)
        this->arr[i]=arr[i];
}
 
istream & operator >>(istream & din,vector1 &v)
 {
    int n=v.size();
    for(int i=0;i<n;i++)
       din >> v.arr[i];
    return din;
 }

int smallest(node *root)
 {
    if(root==NULL)
       return -1;
    else
       {
          node *ptr=root;
          if(ptr->left==NULL)
              return ptr->data;
          else
             return smallest(ptr->left);
        }
 }

int largest(node *root)
 {
    if(root==NULL)
      return -1;
    else
      {
         node *ptr=root;
         if(ptr->right==NULL)
            return ptr->data;
         else
            return largest(ptr->right);
      }
 }

void inorder(node *root)
  {
       node *ptr=root;
       if(root!=NULL)
        {
         inorder(ptr->left);
         printf("%d ",ptr->data);
         inorder(ptr->right);
        }
  }
           
int ceil(node *root,int data)
 {
   if(root==NULL)
      return -1;
   else
    {
      if(root->data==data)
           return data;
      else
         {
            if(root->data < data)
                   {
                     if(root->right!=NULL)
                          return ceil(root->right,data);
                      else
                          return root->data;
                   }
            
                   
            if(root->data > data)
               {     
                   node *temp,*ptr;
                   temp=root;
                   ptr=root;
                   int tempdata1,tempdata2;
                   while(ptr!=NULL && ptr->data > data)
                       {
                         temp=ptr;
                         ptr=ptr->left;
                       }
                   if(ptr!=NULL)
                      {
                        tempdata1=largest(ptr);
                        tempdata2=smallest(ptr->right);
                        if(tempdata1>=data && tempdata1 < tempdata2) 
                           return tempdata1;
                        else if(tempdata2 >=data && tempdata2< tempdata1)
                           return tempdata2;
                        else
                           return temp->data;
                      }
                    if(ptr==NULL)
                          return temp->data;
                }
      }
 }

}
void insert(node ** root,int data)
 {
    node *new_node=new  node;
    new_node->data=data;
    new_node->right=NULL;
    new_node->left=NULL;
    if(*root==NULL)
       *root=new_node;
    else
      {
         node *ptr=*root;
         if(ptr->data >data)
              insert(&ptr->left,data);
          else
              insert(&ptr->right,data);
     }
 }

int main()
 {
    int N;
    printf("enter the number of nodes \n");
    scanf("%d",&N);
    vector1 v(N);
    node *root=NULL;
    cout<<"Enter the nodes \n";
    cin >> v;
    for(int i=0;i<N;i++)
     {
          int data=v.arr[i];
          insert(&root,data);
     }
    cout<<endl;
    inorder(root);
    cout<<endl;
    for(int i=0;i<100;i++)
        cout<<i<<"\t"<<ceil(root,i)<<endl;
    return 0;
 }
  
          

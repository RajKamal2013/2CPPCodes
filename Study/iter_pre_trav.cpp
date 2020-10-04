#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;

class Vector
 {
   int n;
  
   public: 
     int *arr;
     Vector(int n);
     int size();
     int *get();
     void display();
     friend istream & operator >>(istream &din,Vector v);
     friend ostream & operator <<(ostream &din,Vector v);
 };

Vector :: Vector(int n)
 {
    this->n=n;
    arr=new int[n];
 }

void Vector ::display()
 {
   for(int i=0;i<n;i++)
      cout<<arr[i]<<"\t";
   cout<<endl;
 }

int* Vector :: get()
 {
    return this->arr;
 }

int Vector :: size()
  {
    return this->n;
  }
   
istream & operator >> (istream &din,Vector v)
 {
   int n=v.size();
   for(int i=0;i<n;i++)
     din>>v.arr[i];
   return din;
 }

ostream & operator <<(ostream &dout,Vector v)
 {
   int n=v.size();
   for(int i=0;i<n;i++)
    dout<<v.arr[i];
   return dout;
 }

struct node 
{
   int data;
   node *left;
   node *right;
};

void insert(node **root,int data)
 {
//    printf("Inserting \n");
    node *new_node=new node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    if(*root==NULL)
         *root=new_node;
    else
    {
      node *ptr = *root;
      if(ptr->data > data)
           insert(&(ptr->left),data);
      else
           insert(&(ptr->right),data);
    }
 }

void preorder(node *root)
{
  // printf("print preorder\n");
   node *ptr=root;
   if(ptr!=NULL)
    {
 //       cout<<"<--"<<ptr->data<<"-->\t";
     printf("<<--%d-->>",ptr->data);   
     preorder(ptr->left);
     preorder(ptr->right);
    }
}


void print_preorder(node *root)
 {
    printf("printing preorder\n");
    if(root!=NULL)
    {
       stack<node *> s1;
       node *ptr=root;
       node *temp;
       s1.push(ptr);
       while(!s1.empty())
       {
            temp=s1.top();
            s1.pop();
            if(temp!=NULL)
            {
                printf("<--%d-->",temp->data);
                if(temp->right!=NULL)
                      s1.push(temp->right);
                if(temp->left!=NULL)
                      s1.push(temp->left);
            }
       }
    }
}



int main()
{
  int n;
  node *root=NULL;
  cout<<"Enter the size of the array\n";
  cin>>n;
  Vector v(n);
  int *arr;
  arr=new int [n];
  cin>>v;
//  cout<<v;
  v.display();
  for(int i=0;i<n;i++)
   {
     cout<<v.arr[i]<<"\t";
     insert(&root,v.arr[i]);
   }
  printf("\n");
  preorder(root);
  printf("\n");
  print_preorder(root);
  return 0;
}   

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
      int*  put();
      void  get(int *arr,int n);
      friend istream & operator >>(istream &din,vector1 v);
 };


vector1 :: vector1(int n)
  {
     this->n=n;
     arr=new int [n];
  }

int *vector1 :: put()
 {
    return arr;
 }

void vector1 :: get(int *arr, int n)
 {
   for(int i=0;i<n;i++)
         this->arr[i]=arr[i];
 }

istream & operator >>(istream &din ,vector1 v)
 {
   int n=v.n;
   for(int i=0;i<n;i++)
     din>>v.arr[i];
   return din;
 }
  
      

struct node
{
  int data;
  node *left;
  node *right;
};

void insert (node **root,int data)
 {
    node *new_node=new node;
    new_node->data=data;
    new_node->right= NULL;
    new_node->left=NULL;
    if(*root==NULL)
       *root=new_node;
    else
     {
        node *ptr=*root;
        if(ptr->data > data)
             insert(&ptr->left,data);
        else
             insert(&ptr->right,data);
     }
 }
  

void print_preorder(node *root)
 {
    stack< node *>s;
    s.push(root);
    node *ptr;
    while(!s.empty())
     {
         ptr=s.top();
         s.pop();
         printf("%d ",ptr->data);
         if(ptr->right!=NULL)
             s.push(ptr->right);
         if(ptr->left!=NULL)
             s.push(ptr->left);
     }
   cout<<endl;
 }


int main()
 {
    node *root=NULL;
    int nodes;
    
    cout<<"Enter the number of nodes\n";
    cin>>nodes;
    vector1 v(nodes);
    cout<<"enter the vertices\n";
    cin>> v;
    int data;
    for(int i=0;i<nodes;i++)
     {
       data=v.arr[i];
       insert (&root,data);
     }
     print_preorder(root);
     return 0;
 }

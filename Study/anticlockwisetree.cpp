#include<iostream>
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
     friend istream & operator >>(istream &din,vector1 v);
};

vector1 :: vector1(int n)
 {
   this->n=n;
   arr=new int[n];
 }

int vector1 :: size()
 {
   return n;
 }

istream & operator >>(istream &din,vector1 v)
{
   int n=v.size();
   for(int i=0;i<n;i++)
   {
      din>>v.arr[i];
   }
   return din;
}
  

struct node 
{
  int data;
  node *right;
  node *left;
};

void printleaves(node *root)
{
   if(root!=NULL)
    {
        if((root->left==NULL)&&(root->right==NULL))
            printf("%d ",root->data);
        if(root->left)
           printleaves(root->left);
        if(root->right)
           printleaves(root->right);
    }
}
     

void printleftboundary(node *root)
 {
    if(root)
     {
         if(root->left )
             printf("%d ",root->data);
         else if(root->right)
             printf("%d ",root->data);
         if(root->left)
            printleftboundary(root->left);
         else if(root->right)
            printleftboundary(root->right);
     }
}

void printrightboundary(node *root)
{
   if(root)
   {
      if(root->right)
            printrightboundary(root->right);
      else
            printrightboundary(root->left);
      if(root->right)
         printf("%d ",root->data);
      else if(root->left)
         printf("%d ",root->data);
   }
}


void insert(node ** root,int data)
 {
    node *new_node=new node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    if(*root==NULL)
       {
          *root=new_node;
       }
    else 
      {
         node *ptr=*root;
         if(ptr->data>data)
              insert(&ptr->left,data);
         else
              insert(&ptr->right,data);
      }
}


int main()
{
   int n,data;
   cout<<"Enter the number of the nodes: ";
   cin>>n;
   vector1 v(n);
   cin>>v;
   node *root=NULL;
   for(int i=0;i<n;i++)
     {
       data=v.arr[i];
       insert(&root,data);
     }
//   printf("left boundary : ");
   printleftboundary(root);
  // printf("\n");
  // printf("Leaves : ");
   printleaves(root);
  // printf("\n Right Boundary : ");
   printrightboundary(root);
   cout<<endl;
   return 0;
}

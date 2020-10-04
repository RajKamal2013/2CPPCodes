#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;

struct node
{
   int data;
   node *left;
   node *right;
};


void insert(node  **root,int data)
 {
    node *new_node=new node;
    new_node->data=data;
    new_node->right=NULL;
    new_node->left=NULL;
    if(*root==NULL)
       {
         *root=new_node;
         return;
       }
    else
      {
         node *ptr=*root;
         if(ptr->data>data)
             insert(&(ptr->left),data);
         else
             insert(&(ptr->right),data);
      }
 }


void preorder(node *root)
 {
    if(root!=NULL)
     {
         printf("--%d--",root->data);
         preorder(root->left);
         preorder(root->right);
     }
}


void iter_preorder(node *root)
  {
     stack <node *> s;
     s.push(root);
     node *ptr;
     printf("<--");
     if(root==NULL)
        return;
     while(s.empty()==false)
      {
        ptr = s.top();
        s.pop();
        printf("%d-->",ptr->data);
        if(ptr->right)
          s.push(ptr->right);
        if(ptr->left)
            s.push(ptr->left);
      }  
     printf("-->");
  }

int main()
{
   node *root=NULL;
   int data;
   cout<<"enter the 10 node:\n";
   for(int i=0;i<5;i++)
    {
       scanf("%d",&data);
       insert(&root,data);
    }
 //   preorder(root);
    printf("\n");
    iter_preorder(root);
    printf("\n");
   return 0;
 }
  

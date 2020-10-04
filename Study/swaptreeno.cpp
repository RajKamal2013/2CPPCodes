#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node 
{
  int data;
  node *left;
  node *right;
};

node *ptr,*var;
int count=0;

void inordercheck(node *cur)
{
  node *prev=cur;
  if(cur!=NULL)
  {
      inordercheck(cur->left);
      if(cur->data < prev->data)
       {
           if(count==0)
               ptr=prev;
           else
               var=cur;
       }
     inordercheck(cur->right);
 }
}

void inorder(node *cur)
 {
   if(cur!=NULL)
    {
          inorder(cur->left);
          cout<<cur->data<<" ";
          inorder(cur->right);
    }
 }
    

void insert(node **root,int data)
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
          if(ptr->data > data)
             insert(&(ptr->left),data);
          else
             insert(&(ptr->right),data);
     }
  }


node *parent(node *child,node *root)
{
   printf("parent function \n");
   node *var=root;
   node *ptr=NULL;
   if(child==root)
       return NULL;
   else
     {
       ptr=var;
       while(var!=NULL)
         {
             if(var->data>child->data)
              {
                    ptr=var;
                    var=var->left;
              }
             else if(var->data < child->data)
             {
                   ptr=var;
                   var=var->right;
             }
             else 
             {
                 break;
             }
        }
        printf("parent of %d is %d \n",child->data,ptr->data);
        return ptr;
    }
}

node *search(node *root,int data)
 {
    if(root!=NULL)
     {
       if(root->data==data)
          return  root;
       else if(root->data > data)
           return search(root->left,data);
       else if(root->data < data) 
          return search(root->right,data);
    }
    else
      return NULL;
 }
              

                       

void swap(node **src,node **dest,node **root)
{
   node *ptr=*root;
   node *tempnode;
   int tempdata;
   node *p1,*p2;
   p1=parent(*src,ptr);
   printf("parent -%d\n",p1->data);
   p2=parent(*dest,ptr);
   printf("parent of the src and dest  %d - %d\n",p1->data,p2->data);
   tempnode=(*src)->left;
   (*src)->left=(*dest)->left;
   (*dest)->left=tempnode;
   tempnode=(*src)->right;
   (*src)->right=(*dest)->right;
   (*src)->left=tempnode;
   if(p1->left==(*src))
      p1->left=(*dest);
   else
      p1->right=(*dest);
  if(p2->left==(*dest))
      p2->left=(*src);
  else
      p2->right=(*src);
 }


int main()
 {
    int n,data;
    node *root=NULL;
    cout<<"Enter the number of nodes \n";
    cin>>n;
    for(int i=0;i<n;i++)
     {
          cin>>data;
          insert(&root,data);
     }
    inorder(root);
    cout<<endl;
    int src,dest;
    node *srcnode,*destnode;
    cout<<"Enter the nodes to swap\n";
    cin>>src>>dest;
    srcnode=search(root,src);
    printf("%d -data \n",srcnode->data);
    destnode=search(root,dest);
    swap(&srcnode,&destnode,&root);
    inorder(root);
    cout<<endl;
    return 0;
}
   

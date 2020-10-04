#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

class vector1
 {
    int n;
    public:
     vector1(int n);
     int *arr;
     int  size();
     int *put();
     friend istream & operator >>(istream & din,vector1 &v1);
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
  

int * vector1 :: put()
  {
    return arr;
  }

istream & operator >>(istream & din ,vector1 &v)
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
   node *left;
   node *right;
};


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

int search (int* arr,int N,int key)
 {
     int index=0;
     for(int i=0;i<N;i++)
        {
          if(arr[i]==key)
            {
              index=i;
               break;
            }
        }
        return index;
  }
      
bool issafe(int startp,int endp,int startq,int endq)
  {
     if((startp<=endp)&&(startq<=endq))
         return true;
     else
         return false;
  }
void createbinarytree(node **root,int *pre,int *post,int n,int startp,int endp,int startq,int endq)
 {
       // printf("here %d %d %d %d  \n",startp,endp,startq,endq);
        node *ptr=*root;
        node *new_node=new node;
        if(pre[startp]==post[endq])
            new_node->data=pre[startp];
        new_node->left=NULL;
        new_node->right=NULL;
        if(*root==NULL)
             *root=new_node;
        int indexp,indexq;
        if(endq-1 >=0 && startp+1 <=n-1)
          {
             indexp=search(pre,n,post[endq-1]);
             indexq=search(post,n,pre[startp+1]);
             if(issafe(startp+1,indexp-1,startq,indexq))
                 createbinarytree(&(*root)->left,pre,post,n,startp+1,indexp-1,startq,indexq);
             if(issafe(indexp,endp,indexq+1,endq-1))
                 {
               //  cout<<"right child\n";
                 createbinarytree(&(*root)->right,pre,post,n,indexp,endp,indexq+1,endq-1);
                 }
          }
   }  



int main()
{
   node *root=NULL;
   int N;
   scanf("%d",&N);
   vector1 v1(N),v2(N);
   cin>>v1;
   cin>>v2;
   int *pre,*post;
   pre=new int[N];
   post=new int[N];
   pre=v1.put();
   post=v2.put();
   int startp(0),endp(N-1);
   int startq(0),endq(N-1);
   
   createbinarytree(&root,pre,post,N,startp,endp,startq,endq);
   printf("PREORDER :\n");
   preorder(root);
   printf("\n");
   printf("POSTORDER :\n");
   postorder(root);
   printf("\n");
   printf("INORDER :\n");
   inorder(root);
   printf("\n");
   return 0;
 }

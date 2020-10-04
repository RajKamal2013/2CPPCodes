#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 100

struct node
{
   int priority;
   int data;
   struct node *left;
   struct node *right;
};

class heap
{
   node *head;
   int count;
   public:
   heap();
   void enqueue(int key,int data);
   void insert(int key,int data);
   int dequeue();
   int remove();
   void display();
   void display_priority(int data);
   int size();
   int Isfull();
   int IsEmpty();
}

heap :: heap()
{
   count=-1;
   head=NULL;
}


void heap:: insert(int key,int data)
{
   node *newnode=new node;
   newnode->key=key;
   newnode->data=data;
   newnode->left=NULL;
   newnode->right=NULL;
   if(head==NULL)
    {
       newnode->left=NULL;
       newnode->right=NULL;
       head=newnode;
    }
   else
    {
       node *ptr=head;
       if(ptr->left==NULL)
         {
            ptr->left=newnode;
                        
    {
   

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
   int data;
   node *next;
};


void addfront(node **head,int data)
  {
    node *new_node=new node;
    new_node->data=data;
    new_node->next=NULL;
    if(*head==NULL)
       *head=new_node;
    else
     {
       new_node->next=*head;
       *head=new_node;
     }
  }


void  append(node *head,int data)
  {
     node *new_node=new node;
     new_node->data=data;
     new_node->next=NULL;
     if(head==NULL)
       head=new_node;
     else
       {
         node *ptr=head;
         while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
         ptr->next=new_node;
       }
       
  }



void  display(node *head)
  {
     node *temp=head;
     while(temp)
      {
          cout<<temp->data<<"-->";
          temp=temp->next;
      }
      cout<<endl;
   }

node *search(node *head,int data)
  {
    node *ptr=NULL;
    node *temp=NULL;
    ptr=head;
    int found=0;
    while((ptr!=NULL )&& (found!=1))
      {
           if(ptr->data==data)
              {
                 temp=ptr;
                 found=1;
                 break;
              }
            ptr=ptr->next;
       }
   return temp;
 }

class list
{
  node *head;
  public:
    list();
    void addbeg(int data);
    void display();
    void append(int data);
    node*  search(int data);
 };

list :: list()
{
  head=NULL;
}

void list :: addbeg(int data)
 {
    node *new_node=new node;
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)
       head=new_node;
    else
     {
       new_node->next=head;
       head=new_node;
     }
}

void list :: append(int data)
  {
     node *new_node=new node;
     new_node->data=data;
     new_node->next=NULL;
     if(head==NULL)
       head=new_node;
     else
       {
         node *ptr=head;
         while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
     ptr->next=new_node;
  }
}

void list :: display()
  {
     node *temp=head;
     while(temp)
      {
          cout<<temp->data<<"-->";
          temp=temp->next;
      }
      cout<<endl;
  }


node * list ::search(int data) 
  {
    node *ptr=NULL;
    node *temp=NULL;
    ptr=head;
    int found=0;
    while((ptr!=NULL )&& (found!=1))
      {
           if(ptr->data==data)
              {
                 temp=ptr;
                 found=1;
                 break;
              }
            ptr=ptr->next;
       }
   return temp;
 }

void menu()
  {
    cout<<"1.addfornt\t";
    cout<<"2.append\t";
    cout<<"3.display\t";
    cout<<"4.search\t";
    cout<<"5.exit\n";
  }  

int main()
{
   list l;
   node *head=NULL;
   int choice;
   void (list :: *fptr)(int)=&list :: addbeg;
   node *temp;
   int data;
   do
    {
       menu();
       cout<<"enter the choice :";
       cin>>choice;
       switch(choice)
       {
         case 1:
         {
           cout<<"enter the data ";
           cin>>data;
           //l.addbeg(data);
           (l.*fptr)(data);
           addfront(&head,data);
           break;
         }            
       
        case 2:
         {
           cout<<"enter the data ";
           cin>>data;
           l.append(data);
           append(head,data);
           break;
         }
        case 3:
         {
           cout<<"DISPLAY\n";
           l.display();
           cout<<endl<<endl;
           display(head);
           break;
         }
        case 4:
          {
            
           cout<<"enter the data ";
           cin>>data;
           temp=l.search(data);
           temp=search(head,data);
           cout<<"data "<<temp->data<<endl; 
           break;
          }
         case 5:
          {
             break;
          }
     }
}while(choice!=5);
return 0;
}

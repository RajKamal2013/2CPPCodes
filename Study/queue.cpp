#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 100 

class queue
{
  struct node 
  {
    int data;
    struct node *next;
  };
  node *head;
  int rear,front;
 public:
  queue();
  void insert(int data);
  void enqueue(int data);
  int remove();
  int dequeue();
  void display();
  int size();
  int IsEmpty();
  int IsFull();
  ~queue();
};

queue :: queue()
{
   rear=-1;
   front=-1;
   head=NULL;
}

void queue :: enqueue(int data)
{
   if(((front==0)&&(rear==MAX-1))&&(rear+1==front))
    {
        cout<<"QUEUE IS FULL\n";
    }
   else
    {
      insert(data);
      rear=rear++ % MAX;
      if(front!=-1)
         front=0;
    }
}

//NOTE:: front means the place where next addition is done where as rear means the place from where next data is to be  removed.so 
//if front==rear means queue is empty that is to next these place to be emptied is the ,is the place which is next addtion is done... 


int queue :: dequeue() 
{
     int data;
     if(rear==-1)//(rear==front) will also work
      {
         cout<<"QUEUE IS EMPTY\n";
         return -1;
      }
     else
      {
          data=remove();
          front=front++ % MAX;
          if(front==rear)
              {
                 front=-1;
                 rear=-1;
              }
           return data;
       } 
}

void queue :: insert(int data)
 {
    node *newnode=new node ;
    newnode->data=data;
    if(head==NULL)
     {
         newnode->next=NULL;
         head=newnode;
     }
    else
     {
        node *ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
     }
  }

int queue :: remove()
{
   int data;
   if(head==NULL)
     {
          cout<<"QUEUE IS EMPTY\n";
          return -1;
     }
   else
    {
       data=head->data;
       node *ptr;
       ptr=head;
       head=head->next;
       delete(ptr);
       return data;
    }
}

void queue :: display()
{
   node *ptr=head;
   if(head==NULL)
    {
        cout<<"QUEUE IS EMPTY \n";
    }
   else
    {
       while(ptr!=NULL)
          {
                 cout<<"<--"<<ptr->data<<"-->"<<endl;
                 ptr=ptr->next;
          }
    }
}



int queue :: IsEmpty()
{
   if(rear==-1)
      return 1;
   else
      return 0;
}

int queue ::IsFull()
{
    if(((front==0)&&(rear==MAX-1))&&(rear+1==front))
         return 1;
    else
          return 0;
}

int queue :: size()
{
  int count;
  if(rear>=front)
      count=rear-front+1;
  else
     count=(rear+1)+(MAX-front);
  return count;
}




queue::~queue()
{
   node *ptr=head;
   while(head->next!=NULL)
      {
         ptr=head;
         head=head->next;
         delete(ptr);
      }
   delete(head);
}


int main()
{ 
     int data;
     queue  q1;
     cout<<"Enter data to enter in queue \n";
     cin>>data;
     q1.enqueue(data);
     while(!cin.eof())
      {
          cin>>data;
          q1.enqueue(data);
      }     

     q1.enqueue(12);
     q1.enqueue(13);
     q1.display();
     data=q1.dequeue();
     cout<<"Data="<<data<<"\n";
     q1.display();
      return 0;
}

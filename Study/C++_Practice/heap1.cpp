#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;


#define MAX 100

class heap
{
   struct node 
   {
      int data;
      int priority;
      int order;
   }arr[MAX];
   int count;
  public:
   heap();
   void enqueue(int data,int priority,int order);
   void maxheapify(int pos);
   void buildmaxheap();
   int dequeue();
   int size();
   void display();
  // int IsFull();
  // int IsEmpty();
  // int show_priority(int data);
 };

heap :: heap()
{
   count=0;
}

void heap :: enqueue(int priority,int data,int order)
{
   if(count>=MAX-1)
     {
       cout<<"queue is full\n";
     }
   else
     {
        arr[count].data=data;
        arr[count].priority=priority;
        arr[count].order=order;
        count++;
     }
}


void heap :: buildmaxheap()
{
   for(int pos=(count-1)/2;pos>=0;pos--)
      maxheapify(pos);
}

void heap :: maxheapify(int pos)
{
    int left,right,largest;
    node temp;
    left =2*pos+1;
    right=2*pos+2;
    if((left<=MAX-1)&&(arr[left].priority > arr[pos].priority))
      largest=left;
    else
      largest=pos;
    if((right<=MAX-1)&&(arr[right].priority>arr[largest].priority))
      largest=right;
    if(largest!=pos)
    {
        temp.data=arr[pos].data;
        temp.priority=arr[pos].priority;
        temp.order=arr[pos].order;
        arr[pos].data=arr[largest].data;
        arr[pos].priority=arr[largest].priority;
        arr[pos].order=arr[largest].order;
        arr[largest].data=temp.data;
        arr[largest].order=temp.order;
        arr[largest].priority=temp.priority;
        maxheapify(largest);
   }
}

void heap :: display()
{
   for(int i=0;i<count-1;i++)
   {
      cout<<"<--"<<arr[i].priority<<"--"<<arr[i].data<<"-->";
   }
   cout<<"\n";
}

int heap ::dequeue()
{
   if(count==0)
    {
     cout<<"Queue is empty"<<"\n";
     return -1;
    }
   else
   {
    int max;
    count--;
   
    max=arr[0].data;
    arr[0].data=arr[count].data;
    arr[0].priority=arr[count].priority;
    arr[0].order=arr[count].order;
    maxheapify(0);
    return max;
   }
}
   
int heap :: size()
{
  if(count==0)
   return count;
  else
    return count-1;
}


int main()
{
    heap h1;
    int data,priority,order;

       order=1;
       cin>>priority>>data;
       h1.enqueue(priority,data,order);
    while(!cin.eof())
    {
        cin>>priority>>data;
        order++;
        h1.enqueue(priority,data,order);
    }
    h1.display();
    h1.buildmaxheap();
    h1.display();
    data=h1.dequeue();
    cout<<data<<"\n";
    return 0;
 }

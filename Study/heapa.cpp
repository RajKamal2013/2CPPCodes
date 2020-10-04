#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 100

class heap
{
   int arr[MAX];
   int count;
   
   public:
   heap();
   void enqueue(int data);
   int dequeue();
   void makeheap();
   void maxheapify(int pos);
   void display();
 //  int size();
 //  int IsFull();
  // int IsEmpty();
};


heap :: heap()
{
   count=0;
}

void heap :: enqueue(int data)
{
  if(count>=MAX-1)
     cout<<"QUEUE is full\n";
  else
     arr[count++]=data;
}

void heap :: makeheap()
{
   for(int i=(count-1)/2;i>=0;i--)
    {
       cout<<"heapifying \n";
       maxheapify(i);
    }
}


void heap :: maxheapify(int pos)
{
   int left,right,largest;
   left=2*pos +1;
   right=2*pos+2;
   if((left<=count-1)&&(arr[left]>arr[pos]))
      largest=left;
   else
      largest =pos;
   if((right<=count-1)&&(arr[right]>arr[largest]))
      largest=right;
   if(largest!=pos)
     {
        cout<<"changing"<<arr[pos]<<arr[largest]<<"\n";
        int temp=arr[pos];
        arr[pos]=arr[largest];
        arr[largest]=temp;
        cout<<"changed"<<arr[pos]<<arr[largest]<<"\n";
        maxheapify(largest);
     }
   
 }
  

int heap :: dequeue()
{
   int max;
   count--;
   max=arr[0];
   arr[0]=arr[count];
   maxheapify(0);
   return max;
}

void heap :: display()
{
   for(int i=0;i<=count-1;i++)
      cout<<"<--"<<arr[i]<<"-->";
   cout<<"\n";
}

int main()
{
   heap h1;
   h1.enqueue(12);
   h1.enqueue(20);
   h1.enqueue(1);
   h1.enqueue(2);
   h1.enqueue(30);
   h1.enqueue(35);
   h1.enqueue(40);
   h1.display();
   h1.makeheap();
   h1.display();
   return 0;
}

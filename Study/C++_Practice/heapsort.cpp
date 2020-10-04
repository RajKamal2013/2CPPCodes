#include<iostream>
#include<cstdlib>
using namespace std;

int heapsize;

void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}


void max_heapify(int *a,int pos)
 {
    int left,right,max;
    left=2*pos+1; 
    right=2*pos+2;
    if((left<heapsize)&&(a[left]>=a[pos]))
        max=left;
    else
        max=pos;
    if((right<heapsize)&&(a[right]>=a[max]))
         max=right;
    if(max!=pos)
      {
       swap((a+max),(a+pos));
       max_heapify(a,max);
      }
 }


void build_max_heap(int *a,int len)
 {
     heapsize=len;
     int i=len/2;
     for(i=len/2;i>=0;i--)
       {
           max_heapify(a,i);
       }
 }

void heapsort(int *a,int len)
 {
    build_max_heap(a,len);
    int temp=a[0];
    for(int i=len-1;i>=1;i--)
      {
          swap(a+i,a+0);
          heapsize--;
          max_heapify(a,0);
      }
}


int main()
{
   int len;
   cout<<"Enter the length of the array:\t";
   cin>>len;
   int a[len];
   cout<<"Enter the digits\n";
   for(int i=0;i<len;i++)
    cin>>a[i];
   cout<<"the Digits are :\n";
   for(int i=0;i<len;i++)
    cout<<a[i]<<"\t";
   cout<<endl;
   heapsort(a,len);
   for(int i=0;i<len;i++)
    cout<<a[i]<<"\t";
   cout<<endl;
  return 0;
}

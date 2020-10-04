#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}


int partition(int *arr,int start,int end)
{
  
  int pivot=arr[end];
  int j=start-1;
  
  for(int i=start;i<end;i++)
  {
    if(arr[i]<pivot)
      {
         j++;
         swap(arr[i],arr[j]);
      }
  }
  
  j++;
  swap(arr[j],arr[end]);
  return j;
   
}


void quicksort(int *arr,int start,int end)
 {
      int pivot=partition(arr,start,end);
      quicksort(arr,start,pivot-1);
      quicksort(arr,pivot+1,end);
 }


int main()
{ 
   int len;
   int *arr;
   cin>>len;
   arr=new int[len];
   for(int i=0;i<len;i++)
       cin>>arr[i];
   quicksort(arr,0,len-1);
   for(int i=0;i<len;i++)
   {
     cout<<arr[i]<<"\n";
   }
   cout<<endl;
   return 0;
}




















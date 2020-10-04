#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}

int partition(int a[],int start,int end)
{
       int index=start-1;
       int pivot=a[end];
       for(int i=start;i<=end-1;i++)
        {
          if(a[i]<pivot)
           {
              index++;
              swap(a+index,a+i);
           }
        }
       index++;
       swap(a+index,a+end);
    return index;
}

void qsort(int *a,int start,int end)
  {
    if(start<end)
     {
         int pivot=partition(a,start,end);
         qsort(a,start,pivot-1);
         qsort(a,pivot+1,end);
     }
  }

int main()
{
   int *a;
   int len;
   cout<<"Enter the lenght \t";
   cin>>len;
   a=new int[len];
   cout<<"Enter the digits"<<endl;
   for(int i=0;i<len;i++)
     cin>>a[i];
   cout<<endl;
   for(int i=0;i<len;i++)
     cout<<a[i]<<"\t";
   cout<<endl;
   len--;
   qsort(a,0,len);
   cout<<"Sorted sequence \n";
   for(int i=0;i<=len;i++)
     cout<<a[i]<<"\t";
   cout<<endl;
   return 0;
}
   
     

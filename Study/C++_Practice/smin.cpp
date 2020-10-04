#include<iostream>
#include<cstdlib>
using namespace std;

int smin(int *a,int start,int end,int minimum)
{
   if(start<end)
    {
        int mid=(start+end)/2;
        int min1,min2;
        min1=smin(a,start,mid,minimum);
        min2=smin(a,mid+1,end,minimum);
        if(min1>min2)
          return min2;
        else
          return min1;
    }
   else
    {
      if(a[start]==minimum)
         return 99999;
      else
         return a[start];
    }
 }


int main()
{
   int len;
   cout<<"Enter the length \n";
   cin>>len;
   int a[len];
   cout<<"Enter the numbers\n";
   for(int i=0;i<len;i++)
       cin>>a[i];
   int minimum=99999;
   for(int i=0;i<len;i++)
     {
         if(a[i]<minimum)
               minimum=a[i];
     }
    int minimum2;
    minimum2=smin(a,0,len-1,minimum);
    cout<<"MINIMUM"<<minimum<<"SECOND MINIMUM "<<minimum2<<endl;
    return 0;
}

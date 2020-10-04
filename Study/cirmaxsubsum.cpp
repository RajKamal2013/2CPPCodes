#include<iostream>
#include<cstdlib>
using namespace std;

int max_subarraysum(int a[],int n)
   {
       int max_so_far =0,max_to_here=0;
       for(int i=0;i<n;i++) 
         {
            max_to_here=max_to_here+a[i];
            if(max_to_here<0)
              max_to_here=0;
            if(max_to_here>=max_so_far)
               max_so_far=max_to_here;
         }
       return max_so_far;
   }
int cirmax_subarraysum(int *a,int n)
   {
      int max1=max_subarraysum(a,n);
      int arraysum=0;
      for(int i =0;i<n;i++)
        {
            arraysum=arraysum+a[i];
            a[i]=-a[i];
        }
     arraysum=arraysum+max_subarraysum(a,n);
     int max=(max1>arraysum)?max1:arraysum;
     return max;
   }

int main()
{
   int a1[]={8,-8,9,-9,10,-11,12};
   int n=sizeof(a1)/sizeof(a1[1]);
   int sum=cirmax_subarraysum(a1,n);
   cout<<"maximum sum is :"<<sum<<endl;
   int a2[]={10,-3,-4,7,6,5,-4,-1};
   n=sizeof(a2)/sizeof(a2[1]);
   sum=cirmax_subarraysum(a2,n);
   cout<<"maximum sum is :"<<sum<<endl;
   int a3[]={-1,40,-14,7,6,5,-4,-1};
   n=sizeof(a3)/sizeof(a3[1]);
   sum=cirmax_subarraysum(a3,n);
   cout<<"maximum sum is :"<<sum<<endl;
   return 0;
}

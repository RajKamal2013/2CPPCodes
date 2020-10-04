/*microsoft-interview-questions 23 Answers

Just got out of my interview realizing how ridiculously stupid I answered this question. The question was there is an array of positive and negative integers. Write an algorithm to find the subsequence with largest sum of integers in this array. Also, I can not return the entire array, even if it makes the largest sum. If the largest sum is less than -1, throw an exception.
*/

#include<iostream>
using namespace std;

int *findmax(int *arr,int n)
{
   int initial[n],sum[n],tempsum(0),tempinitial(0);
   for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<endl;
      sum[i]=0;
      initial[i]=i;
    }
    for(int i=0;i<n;i++)
    {
      sum[i]=tempsum+arr[i];
      if(sum[i]<0)
          tempsum=0;
      else if(sum[i]==0)
      {
         if(i==0)
            tempsum=0;
         else
             if(tempsum>0)
                 initial[i]=initial[i-1];
     }
     else
     {
         if(i==0)
            tempsum=sum[i];
         else
            if(tempsum>0)
              {
               initial[i]=initial[i-1];
               tempsum=sum[i];
              }
             else
              {
                if(sum[i-1]<0)
                 {
                   initial[i]=i;
                   tempsum=sum[i];
                 }
                else
                 {
                   initial[i]=initial[i-1];
                   tempsum=sum[i];
                }
              }
       }
   }
  int *ret_arr=new int[3];
  for(int i=0;i<2;i++)
  {
   ret_arr[i]=0;
  }
   int max(0);
  for(int i=0;i<n;i++)
  {
        if(max<sum[i])
            {
                ret_arr[0]=sum[i];
                ret_arr[1]=initial[i];
                ret_arr[2]=i;
                max=sum[i];
           }
 }
 cout<<"sum :-"<<max<<"**"<<endl;
return ret_arr;
}

int main()
{
   int arr[10];
   for(int i=0;i<10;i++)
     cin>>arr[i];
   int *a;
   a=findmax(arr,10);
   cout<<"SUM:-"<<a[0]<<endl;
   for(int i=a[1];i<=a[2];i++)
      cout<<arr[i]<<"\t";
   cout<<"\n";
   return 0;
}
  

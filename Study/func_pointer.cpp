#include<iostream>
using namespace std;

int max(int *,int);
int min(int *,int );
void select(int *,int ,int (*p)(int *,int )); 

int max(int *arr,int len)
{
  int temp=arr[0];
  for(int i=1;i<len;i++)
     if(temp<arr[i])
         temp=arr[i];
  return temp;
}
int min(int *arr,int len)
{
  int temp=arr[0];
  for(int i=1;i<len;i++)
     if(temp>arr[i])
         temp=arr[i];
  return temp;
}

void select(int *arr,int len,int (*p)(int *arr1,int len1))
 {
    int ans;
    ans=p(arr,len);
    cout<<"the answer is "<<ans<<endl;
 }

int main()
{
   int *arr=new int[20],len=0,(*ptr)(int *,int),max1,min1;
   cout<<"Enter the digits (enter ctrl +d to stop)\n";
   do
    {
       cin>>arr[len++];
    }while(!cin.eof());
   len--;
   for(int i=0;i<len;i++)
     cout<<arr[i]<<"\t";
   cout<<"\n";
   ptr=max;
   max1=ptr(arr,len);
   ptr=min;
   min1=ptr(arr,len);
   cout<<"maximum="<<max1<<"\t"<<"minumum="<<min1<<"\n";
   cout<<"MINIMUM\n";
   select(arr,len,ptr);
   cout<<"MAXIMUM\n";
   select(arr,len,max);
   return 0;
}

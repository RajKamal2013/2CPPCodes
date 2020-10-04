#include<iostream>
#include<cstdlib>
using namespace std;

int count=0;
void count_inversion(int *arr,int start,int mid,int end)
{
   int n1=mid-start+1;
   int n2=end-mid;
   int L[n1],R[n2];
   for(int i=0;i<n1;i++)
     L[i]=arr[start+i];
   for(int i=0;i<n2;i++)
     R[i]=arr[mid+1+i];
   int l(0),r(0);
   int k=0;
   while((l<n1)&&(r<n2))
   {  
     if(L[l]<=R[r])
       {
         arr[start+k]=L[l++];
         k++;
       }
     else
        {
         arr[start+k]=R[r++];
         k++;
         count=count+(n1-l);
        }
   }
   while (l<n1)
   {
      arr[start+k]=L[l++];
      k++;
     
    //  count=n2+count;
   }
   while(r<n2)
   {
      arr[start+k]=R[r++];
      k++;
   }
 }

void inversion(int *a,int start,int end)
  {
    if(start<end)
     {
        int mid=(start+end)/2;
        inversion(a,start,mid);
        inversion(a,mid+1,end);
        count_inversion(a,start,mid,end);
     }
  }

 
int  main()
{
   int len;
   cout<<"Enter the lenght of the array \t";
   cin>>len;
   int arr[len];
   cout<<"Enter the digits one by one \n";
   for(int i=0;i<len;i++)
     cin>>arr[i];
   for(int i=0;i<len;i++)
      cout<<arr[i]<<"\t";
   cout<<endl;
   inversion(arr,0,len-1);
   for(int i=0;i<len;i++)
      cout<<arr[i]<<"\t";
   cout<<endl;
   cout<<"The number of the inversions are :"<<::count<<endl;
   return 0;
}

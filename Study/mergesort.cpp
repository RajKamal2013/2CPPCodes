#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int *arr,int start,int mid,int end)
{
   
         if(start<end)
         {
         int n1=mid-start+1;
         int n2=end-mid;
         int L[n1],R[n2];
         for(int i=0;i<n1;i++)
             L[i]=arr[start+i];
         for(int i=0;i<n2;i++)
             R[i]=arr[mid+1+i];
         int l,r,k;
          l=0;
          r=0;
          k=0;
         while((l<n1)&&(r<n2))
           {
                if(L[l]<=R[r])
                {
                   arr[start+k]=L[l];
                   k++;
                   l++;
                }
                else
                {
                  arr[start+k]=R[r];
                  k++;
                  r++;
                }
           }
           while(l<n1)
             {
                  arr[start+k]=L[l];
                  k++;
                  l++;
             }
          while(r<n2)
             {
                 arr[start+k]=R[r];
                 k++;
                 r++;
             }
  
}
}
              
void mergesort(int *a,int start,int end)
  {
    if(start<end)
     {
        int mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
     }
  }

int main()
{
  int len;
  cout<<"Enter the lenght \t";
  cin>>len;
  int a[len];
  len--;
  cout<<"enter the digits\n";
  for(int i=0;i<=len;i++)
     cin>>a[i];
  cout<<"Enteries are :\n";
  for(int i=0;i<=len;i++)
     cout<<a[i]<<"\t";
  cout<<endl;
  mergesort(a,0,len);
  cout<<"Sorted order \n";
  for(int i=0;i<=len;i++)
     cout<<a[i]<<"\t";
  cout<<endl;
 return 0;
}

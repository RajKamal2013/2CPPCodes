#include<iostream>
using namespace std;

int *&b3_sort(int *&arr,int len)
  {
   int temp;
   for(int i=0;i<len;i++)
   {
     for(int j=i;j<len;j++)
      {
           if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
      }
    }
   return arr;
   }
void b2_sort(int *&arr,int len)
  {
   int temp;
   for(int i=0;i<len;i++)
   {
     for(int j=i;j<len;j++)
      {
           if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
      }
    }
  }


void *b1_sort(int *arr,int len)
 {
   int temp;
   for(int i=0;i<len;i++)
   {
     for(int j=i;j<len;j++)
      {
           if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
      }
    }
}

int *b_sort(int *arr,int len)
 {
   int temp;
   for(int i=0;i<len;i++)
   {
     for(int j=i;j<len;j++)
      {
           if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
      }
   }
   return arr;
 }

int main()
{
  int *arr=new int[20];
  int  *arr1=new int[20];
  int len=0;
  int *middleman=arr;
  int *&andy=middleman;
  int *middleman1=arr1;
  int *&andy1=middleman1;
  cout<<"Enter digits to sort (ctrl + d to stop)\n";
  do
  {
    cin>>arr[len++];
  }while(!cin.eof());
  
  len--;  
  cout<<"Before sorting:\n";
  for(int i=0;i<len;i++)
    cout<<andy[i]<<"\t";
  cout<<"\n";
  //  arr1=b_sort(arr,len);
     //  b1_sort(arr,len);
  //     b3_sort(andy,len)=andy1;
        andy1=b3_sort(andy,len);
   //    b2_sort(andy,len);
  cout<<"After sorting :\n";
  for(int i=0;i<len;i++)
    cout<<arr1[i]<<"\t";
  cout<<"\n";
 }

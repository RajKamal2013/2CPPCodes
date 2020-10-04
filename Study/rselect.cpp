#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void swap(int *a,int *b)
  {
    int temp=*a;
    *a=*b;
    *b=temp;
  }

 int partition(int *a,int start,int end)
   {
     int p=start-1;
     for(int i=0;i<=end-1;i++)
      {
        if(a[i]<=a[end])
           {
              p++;
              swap(a+i,a+p);
           }
      }
     p++;
    swap(a+p,a+end);
    return p;
 }

int random_partition(int *a,int start,int end)
  {
     int random;
     int range=end-start+1;
     random=rand()%range+start;
//     cout<<"**Random number **"<<random<<endl;
     swap(a+random,a+end);
     return partition(a,start,end);
  }

int random_select(int *a,int start,int end,int i)
 {
     if(start==end)
       return a[start];
     else
      {
        int pivot,k;
        pivot=random_partition(a,start,end); 
        k=pivot-start+1;
        if(k==i)
          return a[pivot];
        else if(i<k)
            return random_select(a,start,pivot-1,i);
        else 
            return random_select(a,pivot+1,end,i);
     }
}

int main()
{
   int len;
   cout<<"Enter the lenght \t";
   cin>>len;
   int a[len];
   cout<<"Enter the digits \n";
   for(int i=0;i<len;i++)
     cin>>a[i];
   cout<<"Digits are \n";
   for(int i=0;i<len;i++)
     cout<<a[i]<<"\t";
   cout<<endl;
   int rank,data;
   cout<<"Enter the rank \t";
   cin>>rank;
   data=random_select(a,0,len-1,rank);
   cout<<"Required data is "<<data<<"\n";
   return 0;
}

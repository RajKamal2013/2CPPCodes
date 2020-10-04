#include<iostream>
using namespace std;

int issafe(int a,int b,int c)
{
  // cout<<a<<"\t"<<b<<"\t"<<c<<endl;
  if(a<(b+c))
   {
//    cout<<"yes\n";
    return 1;
   }
  else
    return 0;
}

void swap(int *a,int *b)
 {
   // cout<<"swaping "<<*a<<*b<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;
 }

int partition(int arr[],int start,int end)
{
  int pivot=arr[end];
  int index=start-1;
  for(int i=start;i<=end;i++)
   {
     if(arr[i] < pivot)
       {
          index++;
          swap(arr[i],arr[index]);
       }
   }
   index++;
   swap(arr[end],arr[index]);
   return index;
 }

void qsort(int a[],int start,int end)
 {
   if(start<end)
    {
       int pivot=partition(a,start,end);
//       cout<<pivot<<endl;
       qsort(a,start,pivot-1);
       qsort(a,pivot+1,end);
    }
 }

int counttriangle(int *arr,int n)
 {
   // cout<<"counting \n";
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++)
     cout<<arr[i]<<"\t";
    cout<<endl;
    int i,j,k;
    i=0;
    j=i+1;
    k=n-1;
    int count=0;
    while(i<=k)
    {
       while(j<=k)
        {
		int res=issafe(arr[i],arr[j],arr[k]);
                if(res==1)
                     count=count+(k-j-1);
                j++;
        }
      i++;
      j=i+1;
   }
 return count;
}
   
class Vector
{
   int n;
   public:
     int *arr;
     Vector(int n);
     int size();
     friend istream & operator >>(istream &din,Vector &v);
     friend ostream & operator <<(ostream &dout, Vector &v);
     int * get();
};


Vector :: Vector(int n)
 {
    this->n=n;
    arr=new int[n];
 }

int Vector :: size()
 {
    return n;
 }

int *Vector :: get()
 {
     return arr;
 }

istream & operator >>(istream &din,Vector &v)
 {
  // cout<<"Inserting \n";
   int n=v.size();
   for(int i=0;i<n;i++)
    {
        din>>v.arr[i];
    }
   cout<<endl;
   return din;
}

ostream & operator <<(ostream &dout,Vector &v)
 {
    int n=v.size();
    for(int i=0;i<n;i++)
      dout<<v.arr[i];
    return dout;
 }


int main()
{
  int n;
  int *arr;
  int count;
  cin>>n;
  Vector v(n);
  arr=new int [n];
  cin >> v;
//  cout << v;
  for(int i=0;i<n;i++)
   {
    arr[i]=v.arr[i];
   // cout<<arr[i]<<"\t";
   }
   cout<<endl;
//   for(int i=0;i<n;i++)
  //   cout<<arr[i]<<"\t";
  cout<<endl;
//  qsort(arr,0,n-1);
//  for(int i=0;i<n;i++)
  //   cout<<arr[i]<<"\t";
 //  cout<<endl;
  count=counttriangle(arr,n);
   cout<<count<<endl;
  return 0;
}
  

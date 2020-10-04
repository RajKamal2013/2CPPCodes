#include<iostream>
#include<list>
#include<cstdlib>
#include<cstdio>
using namespace std;

float max(float arr[],int n)
  {
    float max=-9999;
     for(int i=0;i<n;i++)
      {
         if(arr[i]>max)
            max=arr[i];
      }
    return max;
 }

int main()
{
   list <int> *a,*b,*adj;
   float *arr,*p;
   float temp;
   int n,t,src,dest;
    
   cout<<"enter the number of vertices\n";
   cin>>n;
   cout<<"enter the time stamp\n";
   cin>>t;

   a=new list <int> [n];
   b=new list<int>[n];
   adj=new list<int>[n];
   arr=new float[n];
   p=new float[n];
   
   cout<<"enter the source and destination (enter ctrl +d to end)\n";
   while(cin>>src>>dest)
     {
         adj[src].push_back(dest);
         adj[dest].push_back(src);
     }
   for(int i=0;i<n;i++)
    {
        b[i].assign(adj[i].begin(),adj[i].end());
        arr[i]=0;
    }
   
 //  list<int> :: iterator itr;
   /*for(int i=0;i<n;i++)
    {
      cout<<i;
      for(itr=adj[i].begin();itr!=adj[i].end();itr++)
           cout<<"-->"<<*itr;
      cout<<endl;
    }*/
  //   cout<<"time == "<<t<<endl;
   list <int> ::iterator it;
   for(int time=0;time<t;time++)
     {
         for(int i=0;i<n;i++)
           {
               for(it=adj[i].begin();it!=adj[i].end();it++)
                  {
                      arr[*it]=arr[*it]+1/adj[i].size();
                  }
               temp=max(arr,n);
               p[i]=temp;
               for(int j=0;j<n;j++)
                 {
                   if(arr[i]==temp)
                       a[i].push_back(i);
                 }
            for(int i=0;i<n;i++)
               {
                 cout<<arr[i]<<"\t";
                 arr[i]=0;
               }
             cout<<endl;
          }
    }

  for(int i=0;i<n;i++)
    arr[i]=0;
  
  for(int i=0;i<n;i++)
   {
     for(it=a[i].begin();it!=a[i].end();it++)
       {
           arr[*it]=arr[*it]+p[i];
       }
   }
  temp=max(arr,n);
  for(int i=0;i<n;i++)
         cout<<i<<"\t"<<arr[i]<<endl;
  cout<<endl;
 return 0;
}

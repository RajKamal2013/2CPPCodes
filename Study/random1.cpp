#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
   int min,max,range;
   int count,temp;
   cout<<"enter the maximum number \t";
   cin>>max;
   cout<<"enter the minimum number \t";
   cin>>min;
   cout<<"Enter the count \t";
   cin>>count;
   range=max-min+1;
   for(int i=0;i<count;i++)
    {
       temp=rand()%range + min;
       cout<<temp<<"\t";
    }
    cout<<endl;
    return 0;
}

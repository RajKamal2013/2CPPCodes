#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
  int min=0;
  int max=30; 
  int r;
  int range=max-min+1;
  for(int i=0;i<max;i++)
     {
       r=rand()%range;
       cout<<r<<" ";
     }

  cout<<endl;
  int a=3;
  int c=2;
  int m=29;
  int temp=3;
  cout<<"another random generator\n";
  
  for(int i=0;i<m;i++)
     {
        cout<<temp<<endl;
        temp=(a*temp+c)%m;
     }   
  return 0;
}

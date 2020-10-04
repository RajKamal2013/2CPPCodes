#include<iostream>
using namespace std;
#define CHAR_BIT 8
int findmax(int a,int b)
{
  int c= a - ((a-b) & ((a-b)>>(sizeof(int )*CHAR_BIT -1)));
  return c;
}

int findmin(int a,int b)
{
  int c= b + ((a-b) & ((a-b)>>(sizeof(int )*CHAR_BIT -1)));
  return c;
}

int maximum(int a,int b,int c)
{
  int d=findmax(a,(findmax(b,c)));
  return d;
}

int minimum(int a,int b,int c)
{
  int d=findmin(a,(findmin(b,c)));
  return d;
}


int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int max,min;
   max=maximum(a,b,c);
   min=minimum(a,b,c);
   cout<<max<<" "<<min<<endl;
   return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int add(int x,int y)
{
  while(y!=0)
  {
   int carry= x & y;
   x=x^y;
   y=carry<<1;
  }
 return x;
}

int main()
{
  int a,b;
  cout<<"enter the digit to add \n";
  cin>>a>>b;
  cout<<"The sum of the two number is "<<add(a,b)<<endl;
  return 0;
}

  

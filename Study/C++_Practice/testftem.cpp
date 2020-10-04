#include<iostream>
using namespace std;

template <class T>
void swap1(T &a,T &b)
{
  T temp;
  temp=a;
  a=b;
  b=temp;
}

int main()
{
   int a=34,b=35;
   float x=34.34,y=12.12;
   cout<<"Before swapping\n";
   cout<<"a=="<<a<<"\t"<<"b=="<<b<<"\t"<<"x=="<<x<<"\t"<<"y=="<<y<<"\n";   
   swap1(a,b);
   swap1(x,y);
   cout<<"After swaping\n";
   cout<<"a=="<<a<<"\t"<<"b=="<<b<<"\t"<<"x=="<<x<<"\t"<<"y=="<<y<<"\n";   
   return 0;
} 

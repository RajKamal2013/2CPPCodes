#include<iostream>
using namespace std;

int & max(int &a,int &b)
 {
    if(a>b)
      return a;
    else 
      return b;
 }

int *max1(int *x,int *y)
 {
   if(*x>*y)
      return x;
   else
      return y;
 }

int main()
{
   int a=4,b=5,c;
   int *w=new int(21);
   int x=10,y=12,*z;
   c=max(a,b);
   max(a,b)=-1;
   z=max(&x,&y);
   cout<<"x=="<<x<<"\t"<<"y=="<<y<<"\t"<<"z=="<<*z<<"\n";
   cout<<"a=="<<a<<"\t"<<"b=="<<b<<"\t"<<"c=="<<c<<"\n";
   return 0;
}  
   

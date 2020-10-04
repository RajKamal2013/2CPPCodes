#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
   int src(2),dest(3),i(0);
   char a[10],b[10];
    a[i++]=src;
    a[i++]='-';
    a[i]=dest;
   cout<<a<<"\n";
   sprintf(b,"%d-%d",src,dest);
   cout<<b<<"\n";
   return 0;
}

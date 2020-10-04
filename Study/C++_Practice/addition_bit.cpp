#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
   int a;
   int b;
   printf("Enter the numbers to add :\n");
   scanf("%d %d",&a,&b);
   int sum=a^b;
   int carry=a && b;
   carry=carry<<1;
   sum=sum+carry;
   printf("SUM :%d\n",sum);
   return 0;
 }

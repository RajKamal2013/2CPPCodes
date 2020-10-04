#include<iostream>
using namespace std;

int main()
{
int a,b,x,y;
cin>>a;
x=a;
b=(a+1)>>1;
cout<<a<<endl;
y=x;
y=y|(y >>1);

y=y|(y >>2);
y=y|(y >>4);
y=y|(y >>8);
y=y|(y >>16);
cout<<y<<endl;
return 0;
}

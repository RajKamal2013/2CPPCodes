#include<iostream>
using namespace std;

int set1(int num)
{
   return ((num)&(num-1));
}

int set2(int x)
{
    int m=1;
    int d=x&m;
   // cout<<d<<endl;
  
    while(d==0)
       {
//        cout<<m<<endl;
        m=m<<1;
  //      cout<<"*"<<m<<endl;
        d=x&m;
       }
  //  cout<<m<<"\t"<<endl;
    int temp=x ^ m;
    return temp;
}
    


int main()
{
   int num;
   cin>>num;
   cout<<set1(num)<<"\t"<<set2(num)<<endl;
   return 0;
}
  

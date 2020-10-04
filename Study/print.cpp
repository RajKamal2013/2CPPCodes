#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class A
{
  public :
    static int a;
    A()
     {
        cout<<a++<<endl;
     }
};

int A ::a=1;

int main()
 {
   int N=100;
   A obj[100];
   return 0;
  }


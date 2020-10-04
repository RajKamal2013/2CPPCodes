#include<iostream>
using namespace std;

int main()
{
  int a=5;
  int b=a++ + ++a;
  cout<<"the value is "<<b<<"\n";
  return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
  int x,y;
  cin>>x>>y;
  int z= x ^ ((x ^ y) &(-1));
  int u= y ^ ((x ^ y) &(-1));
  cout<<z<<" "<< u<<endl;
  return 0;
}

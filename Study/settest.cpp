#include<iostream>
#include<set>
#include<list>
using namespace std;

void display(set<int>&T)
{
  set<int>::iterator itr;
  T.insert(50);
  for(itr=T.begin();itr!=T.end();itr++)
    cout<<*itr<<"\t";
  cout<<"\n";
}

int main()
{
  set<int>S;
  S.insert(1);
  S.insert(2);
  S.insert(3);
  display(S);
  return 0;
}

#include<iostream>
#include<deque>
using namespace std;

int main()
{
   deque<int>first(3,10);
   deque<int>::iterator it;
   for(it=first.begin();it!=first.end();it++)
      cout<<*it<<endl;
   return 0;
}

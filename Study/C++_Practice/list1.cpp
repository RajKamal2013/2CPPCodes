#include<iostream>
#include<list>
using namespace std;

int main()
{
   list < int > first;
   list < int > second(4,100);
   list < int > third(second.begin(),second.end());
   list < int > fourth(third);
   
   int arr[]={15,2,22,56,99};
   list < int > fifth(arr,arr+sizeof(arr)/sizeof(int));
   cout<<"contents of fifth are :\n";
   for(list<int>::iterator it=fifth.begin();it!=fifth.end();it++)
      cout<<*it <<" ";
   cout<<endl;

   first.assign(7,100);
   second.assign(first.begin(),first.end());
   first.assign(arr,arr+5);
   cout<<"size of first :"<<int(first.size())<<endl;
   cout<<"size of second :"<<int(second.size())<<endl;

   return 0;
}

#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;

int main()
{
   bitset<1000000>mybits;
   cout<<"enter mybits\n";
   cin>>mybits;
   if (mybits.any())
         cout << "mybits has " << (int)mybits.count() << " bits set.\n";
   else 
         cout << "mybits has no bits set.\n";   
   return 0;
}

#include<iostream>
using namespace std;

int main()
{
   char c;
   cin.get(c);
   while(c !='\n')
    {
       cout<<c;
       //cin>>c;          //it will not accept space and newline and and program won't exit.
       cin.get(c);
    }
   cout<<"\n";
   return 0;
  }

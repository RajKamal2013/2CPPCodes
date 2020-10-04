#include<iostream>
#include<bitset>
using namespace std;

int main()
{
   bitset<16> mybits;
   cout<<"Enter any binary number"<<endl;
   cin>>mybits;
   if(mybits.any())
    {
       cout<<"mybits has"<<(int) mybits.count()<<endl;
    }
    else
    cout<<"mybits has no bit set\n";
    return 0;
}


#include<iostream>
using namespace std;

int reverse(int num)
{
 // int NO_OF_BIT=sizeof(num)*8;
  int NO_OF_BIT=8;
  int temp,reverse(0);
  for(int i=0;i<NO_OF_BIT;i++)
    {
          temp=num&(1<<i);
          if(temp)
            {
               reverse |=(1<<((NO_OF_BIT -1)-i));
            }
     }
   return reverse;
}
 

int main()
{ 
  int num;
  cin>>num;
  cout<<reverse(num);
  return 0;
}

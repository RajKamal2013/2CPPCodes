#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  int i=1;
  int num=0x0123456;
  //char *start=(char *) malloc(sizeof(num));
  char *start=(char *)&num;
  char *c=(char *)&i;
  for(int j=0;j<sizeof(num);j++)
    {
     cout<<start[j];
    }
     
  cout<<endl;
  if(*c)
    cout<<"Little Endian \n";
  else
    cout<<"Big Endean \n";
  return 0;
}

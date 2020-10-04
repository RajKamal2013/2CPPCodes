#include<iostream>
#include<cstdio>
using namespace std;

int findsetbit(int number)
{
   int count=0;
   while(number>=0)
   {
        if(number%2==1)
          break;
        count++;
        number/=2;
   }
   return count;
}
 
int findunsetbit(int number)
{
   int count=0;
   while(number >=0)
   {         
      if(number %2==0)
          break;
      count++;
      number/=2;
   }
   return count;
}

void setbit(int *number,int index)
{
   *number=(*number)|(1<<index);
}

void unsetbit(int *number,int index)
{  
   *number=(*number) & ~(1<< index);
}

int findunsetbit2(int number,int i)
{
   int count =0;
   while(number!=0)
   {
      if((number%2==0)&&(count>i))
        break;
      count++;
      number/=2;
   }
   return count;
}

void swap(int *number,int unset_index,int set_index)
{
    setbit(number,unset_index);
    unsetbit(number,set_index);
}
int main()
{
  int number,tempnumber;
  cin>>number;
 // tempnumber=number;
  int set_index=findsetbit(number);
  /*cout<<set_index<<endl;*/
//  int unset_index=findunsetbit(number);
 // for(int i=0;i<=set_index;i++)
   // unsetbit(&tempnumber,i);
 // int next_setindex=findsetbit(&tempnumber);
  int next_unsetindex = findunsetbit2(number,set_index);
  swap(&number,next_unsetindex,set_index);
  cout<<number<<endl;
 
  
  /*cout<<"Next set "<<next_index<<endl;*/
  return 0;
}    

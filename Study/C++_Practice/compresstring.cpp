#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

char *compress(char *str)
{
   char *str1=new char[strlen(str)];
   int k(0),count(0);
   char temp;
   if(str)
    {
     while(*str)
      {
         //cout<<*str<<"---"<<endl;
         temp=*str;
         str++;
         count++;
         str1[k++]=temp;
       //  cout<<str1[k-1]<<"--"<<endl;
         while(*str == temp)
         {
             count++;
             str++;
         }
        sprintf(&temp,"%d",count);
        str1[k++]=temp;
       // cout<<str1[k-1]<<"--"<<endl;
        count=0;
      }
    }
   str1[k]='\0';
//   cout<<str<<"**"<<endl;
   return str1;
}


int main()
{
   char *str=new char[100];
   cout<<"Enter the string:-";
   cin>>str;
   cout<<"STRING :-";
   cout<<str<<endl;
   str=compress(str);
   cout<<"STRING :-";
   cout<<str<<endl;
   return 0;
}
        

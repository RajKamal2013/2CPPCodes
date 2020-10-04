#include<iostream>
#include<cstring>
using namespace std;

void swap(char *str,int i,int j)
{
   char temp=str[i];
   str[i]=str[j];
   str[j]=temp;
}

int main()
{
   char str[100];
   cout<<"Enter the string \n";
   cin.getline(str,100);
   cout<<"STRING :-";
   cout<<str;
   cout<<endl;
   int mid = strlen(str)/2;
   int k(0);
   int key;
   while((mid-k)>0)
   {
    
     swap(str,mid-k,mid+k);
     k++;
   }
   cout<<"STRING :-";
   cout<<str;
   cout<<endl;
   return 0;
}
   

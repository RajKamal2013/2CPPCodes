#include<iostream>
#include<cstring>
using namespace std;

void max_heapify(char *,int);
void create_heap(char *str)
{
   int n=strlen(str);
   for(int i=n/2;i>=0;i--)
     max_heapify(str,i);
}

void max_heapify(char *str,int k)
{ 
   int max;
   int n=strlen(str);
   int right=2*k+1;
   int left=2*k+2;
   char temp=str[k];
   if((left<=n)&&(str[left]>str[k]))
      max=left;
   else
      max=k;

   if((right<=n)&&(str[right]>str[max]))
      max=right;
   if(max!=k)
   {
      str[k]=str[max];
      str[max]=temp;
   }
}

int main()
{
   char str[100];
   cout<<"enter the string\n";
   cin>>str;
   cout<<str;
   create_heap(str);
   cout<<"now the string \n";
   cout<<str;
   
   return 0;
}
    

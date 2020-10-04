#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int check(char *T,char * P,int m)
{
  int ret=1;
  for(int i=0;i<m;i++)
   {
      if(T[i]!=P[i])
           {
              ret=0;
              break;
           }
   }
   return ret;
}


char *binary( int num,int *len)      //i would have use int* instead of char * but it than consumes double memory.
{
   char *str=new char[100];
   int  i=0;
   if(num==0)
         str[i]='0';
   else
    {
         while(num >=1 )
         {
            if(num % 2 == 0)
                  str[i++]='0';
            else
                  str[i++]='1';
            num=num/2;
        }
    }
    int high=i-1;
    int low=0;
    while(high>low)
     {
         char temp=str[low];
         str[low]=str[high];
         str[high]=temp;
         high--;
         low++;
     }
     *len=i;
     str[i]='\0';
   //  printf("string :%s \n",str);
     cout<<endl;
     return str;
 
}

           
int multiply(int a,int k ,int q)
 {
    int len=0;
    char *b=new char[100];
    b=binary(k,&len);
    int c=0;
    int d=1;
    for(int i=len-1;i>=0;i--)
     { 
        c=2*c;
        d=(d*d)%q;
        if(b[i]=='1')
         {
             c=c+1;
             d=(d*a)%q;
         }
     }
     return d;
 }
       
void rabinkarp(char *T,char *P,int d,int q)
{
     int ret=0;
     int n=strlen(T);
     int m=strlen(P);
     int h=multiply(d,m-1,q);
     int p=0;
     int to=0;
     
    cout<<"h="<<h<<endl; 
    for(int i=0;i<m;i++)
      {
           cout<<"P[i]"<<(int)P[i]<<"T[i]"<<(int)T[i]<<endl;
           p=(d*p+(int)P[i])%q;
           to=(d*to+(int)T[i])%q;
      }
     cout<<"p"<<p<<"--"<<"to"<<to<<endl;

     for(int s=0;s<n-m;s++)
     {
           if(to==p)
           {
             if(check(T+s,P,m))
                 {
                   printf("SHIFT =%d\n",s);
                   ret=1;
                 }
           }
           if(s<n-m)
              {
              cout<<"to"<<to<<endl;
              to=(d*(to-((int)T[s])*h)+((int)T[s+m]))%q;
              if(to<0)
                  to=to+q;
              }
     }
    if(ret==0)
       	 cout<<"NOT A SUBSTRING\n";
 }




int main()
{
   char P[100],T[500];
   cout<<"enter the Text :";
   gets(T);
   cout<<"enter the Pattern :";
   gets(P);
   rabinkarp(T,P,10,13);
   return 0;
}        

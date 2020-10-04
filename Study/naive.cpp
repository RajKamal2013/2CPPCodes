#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int  check(char *T ,char *P,int m)
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

int main()
  {
     char T[200],P[50];
     cout<<"Enter the string \n";
     gets(T);

     cout<<"Enter the pattern \n";
     gets(P);
     
     int m=strlen(P);
     int n=strlen(T);
     int shift=-9999;     
     
     for(int i=0;i<m;i++)
       printf("%c--%d\t",T[i],T[i]);
    
     cout<<endl;

     for(int i=0;i<m;i++)
	cout<<P[i]<<"--"<<int(P[i])<<"\t";

     cout<<endl;
     for(int s=0;s<n-m;s++)
      {
         if(check(T+s,P,m))
         {
           shift=s;
           printf("Match found at shift :%d\n",s);
         }
     }
    
    if(shift==-9999)
      cout<<"Pattern does not exist \n";
    
    return 0;
 } 
         
     

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int *pattern_matcher(char *P)
 {
    int m=strlen(P);
    int k=0,q;
    int *pi=new int[m];
    pi[0]=0;
    for(q=1;q<m;q++)
      {
          while((k>0)&&(P[k+1]!=P[q]))
              {
                  k=pi[k];
              }
          if(P[k+1]==P[q])
              k=k+1;
          cout<<"k"<<k<<endl;
            pi[q]=k;
     }
   for(int i=0;i<m;i++)
      cout<<pi[i]<<"\t";
   cout<<endl;
   return pi;
 }


void kmp(char *T,char *P)
 {
    int ret=0;
    int n=strlen(T);
    int m=strlen(P);
    int k=0;
    int *pi=new int[m];
    pi=pattern_matcher(P);
    for(int s=0;s<n;s++)
     {
        while((k>0)&&(P[k+1]!=T[s]))
           {
               k=pi[k];
           }
        if(T[s]==P[k])
           {
              k=k+1;
           }
        if(k==m)
          {
             ret=1;
             printf("shift occurs with %d shift \n",s-m);
             k=pi[k];
          }
    }
   if(ret==0)
      cout<<"Pattern not present \n";
}
              

int main()
{
   char P[100],T[200];
   printf("Enter the text string \n");
   gets(T);
   printf("Enter the pattern string \n");
   gets(P);
   int *pi=new int[strlen(P)];
   pi=pattern_matcher(P);
//   kmp(T,P);
   return 0;
}
         

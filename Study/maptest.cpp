#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
   int src=2;
   int dest=3;
   char a[10],b[10],c[10];
   sprintf(a,"%d-%d",src,dest);
   map<char *,int>m;
   m.insert(pair<char*,int>(a,1));
   bzero(a,10);
   src=4;
   dest=5;
   sprintf(a,"%d-%d",src,dest);
   m.insert(pair<char*,int>(a,1));
   src=2;
   dest=9;
   bzero(a,10);
   sprintf(a,"%d-%d",src,dest);
   m.insert(pair<char*,int>(a,1));
   map<char * ,int>::iterator it;
   for(it=m.begin();it!=m.end();it++)
     cout<<(*it).first<<"\t--\t"<<(*it).second<<"\n";
  char d[10];
  strcpy(d,a); 
  cout<<m.find(a)->second<<"\n";
   return 0;
}

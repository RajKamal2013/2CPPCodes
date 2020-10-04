#include<iostream>
#include<cstring>
using namespace std;

class string1
{
   char *p;
   int len;
   public:
      string1()
       {
          p=0;
          len=0;
       }
      string1( const char *str);
      string1( string1 &s);
      ~string1() { delete p;}
      void display();
};

string1 :: string1( const char *str)
 {
     len=strlen(str);
     this->p=new char[len+1];
     strcpy(this->p,str);
 }

string1 :: string1(string1 &s)
 {
    len=s.len;
    p=new char[len+1];
    strcpy(p,s.p);
 }

void string1 :: display()
 {
    cout<<"STRING :"<<p<<endl;
 }


int main()
{
   string1 s1;
   //string1 s2 = "RAJKAMAL";
   s1="RAVIKAUSHAL";
   s1.display();
   //s2.display();
   return 0;
}


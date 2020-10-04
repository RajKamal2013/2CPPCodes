#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;



class test
{
   int p;
   char *str;
   public:
    test ()
     {
        str=0;
        p=0;
     }
    test(const char *str)
     {
          p=strlen(str);
          this->str=new char[p+1];
          strcpy(this->str,str);
     }
   void display()
    {
        cout<<str<<endl;
    }
};

int main()
{
   test t1="23";
   test t2;
   t2="34";
   t1.display();
   t2.display();
   return 0;
}
   

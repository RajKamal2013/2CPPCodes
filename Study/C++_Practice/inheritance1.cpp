#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class A
{
   int a;
   public:
     void get_a(int a)
       {
          this->a=a;
       }
     void display()
       {
          cout<<a<<endl;
       }
};


class B
 {
    int b;
    public:
     void get_b(int b)
       {
          this->b=b;
       }
     void display()
       {
          cout<<b<<endl;
       }
};


class C :public A,public B
{
   int c;
   public:
     void get_c(int c)
       {
          this->c=c;
       }
     void display()       
       {
          A::display();
          B::display();
          cout<<c<<endl;
       }
};


int main()
 {
   C c;
   c.get_a(12);
   c.get_b(13);
   c.get_c(14);
   c.display();
   c.A::display();
   c.B::display();
   return 0;
}

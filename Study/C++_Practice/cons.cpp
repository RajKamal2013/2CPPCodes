#include<iostream>
using namespace std;

class test
{
   int data;
   public:
    test();
    void view_data(); 
};

test :: test()
{
   data=21;
}

void test :: view_data()
{
   cout<<"data"<<data<<endl;
}

class complexa
{
   int data;
  
   public:
     complexa(){}
     complexa(int p)
      {
          data=p;
      }
     friend void show(complexa &);
 };

void show(complexa &c)
  {
     cout<<"data"<<c.data<<endl;
  }

int main()
{
   test a;
   test b;
   a.view_data();
   b.view_data();
   complexa c;
   show(c);
   return 0;
}

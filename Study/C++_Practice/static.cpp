#include<iostream>
#include<cstdlib>
using namespace std;

class item
 {
   static int count;
   int number;
   
   public:
     void getdata(int a)
       {
           number =a;
           count++;
       }
     void getcount(void)
       {
          cout<<"number of objects"<<count<<endl;
       }
};


int item:: count;

int main()
  {
      item a,b,c;
      a.getcount();
      b.getcount();
      c.getcount();
      a.getdata(10);
      a.getcount();
      b.getdata(21);
      b.getcount();
      c.getdata(40);
      c.getcount();
      return 0;
  }



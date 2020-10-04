#include<iostream>
using namespace std;

class item
{
   private:
       int data;
       float cost;
   public:
       item(float =0){};
       item(int a,float b);
       void get_data();
       void show_data();
};

item ::item(int a ,float b)
  {
     data=a;
     cost=b;
  }
//item :: item(int a ,float b) :data(a),float(b) {}

void item :: show_data()
 {
    cout<<"data =="<<data<<endl;
    cout<<"cost =="<<cost<<endl;
 }

void item :: get_data()
 {
    int a;
    float b;
    cout<<"Enter the data and cost "<<endl;
    cin>>a>>b;
    data=a;
    cost=b;
 }


int main()
{
   item ex1;
   item ex2(12,12.34);
   ex1.show_data();
   ex2.show_data();
   ex1.get_data();
   ex1.show_data();
   return 0;
}
   

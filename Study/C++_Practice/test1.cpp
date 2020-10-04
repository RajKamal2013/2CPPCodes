#include<iostream>
using namespace std;

class person
{
     char name[20];
     int age;
  public:
     void getdata(void);
     void displaydata(void);
};

void person :: getdata(void)
{
    cout<<"Enter name and age\n";
    cin>>name >> age;
}

void person :: displaydata(void )
{
   cout<<"Displaying the data \n";
   cout<<"the name : " <<name <<" The age is :  " << age << endl;
}

int main()
{
   person p;
   p.getdata();
   p.displaydata();
   return 0;
}

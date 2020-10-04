#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class student
{
  protected:
   int roll_number;
  public:
    void get_number(int number)
      {
         roll_number=number;
      }
    void put_number()
      {
          cout<<"Roll number "<<roll_number<<endl;
      }
    void display()
      {
         cout<<"roll_number "<<roll_number<<endl;
      }
    
};

class test : virtual public student
 {
    protected :
      float part1,part2;
    public:
       void get_marks(float a,float b)
        {
            part1=a;
            part2=b;
        }
      void put_marks()
        {
           cout<<"part1 "<<part1<<endl;
           cout<<"part2 "<<part2<<endl;
        }
      /*void display()
        {
           cout<<"part1 "<<part1<<endl;
           cout<<"part2 "<<part2<<endl;
        }*/
       int display()
        {
           cout<<"part1 "<<part1<<endl;
           cout<<"part2 "<<part2<<endl;
           return 1;
        }
};

class sports : virtual public student
  {
      protected :
        float score;
      public :
        void get_score(float a)
         {
           score=a;
         }
        void put_score()
         {
           cout<<"score :"<<score<<endl;
         }
        void display()
         { 
           cout<<"score :"<<score<<endl;
         }
 };

class result : public sports,public test
 {
     protected:
        float total;
     public:
        void get_total()
         {
            total=part1+part2+score;
         }
        void put_total()
         {
           put_number();
           put_marks();
           put_score();
           cout<<"total "<<total<<endl;
         }
    /*    void display()
         { 
           put_number();
           put_marks();
           put_score();
           cout<<"total "<<score<<endl;
         }*/
 };
 

int main()
{
   result r1;
   r1.get_number(234);
   r1.get_marks(12.5,34.1);
   r1.get_score(3.4);
   r1.put_total();
   r1.display();
   return 0;
} 

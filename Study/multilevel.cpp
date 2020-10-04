/*
	This code will give example of multi level inheritance.
*/

#include <iostream>
using namespace std;

class student {
	protected:
		int roll_number;
	public:
		void get_number(int a);
		void put_number();
};

class test : public student {
	protected:
		float sub1;
		float sub2;
	public:
		void get_marks(float, float );
		void put_marks();
};

class result : public test {
	private:
		float total;
	public:
		void display();
};

void student :: get_number(int a){
	roll_number = a;
}
	

void student :: put_number(){
	cout << "Roll Number is " << roll_number << endl;
}

void test :: get_marks (float a, float b){
	sub1 = a;
	sub2 = b;
}

void test :: put_marks (){
	cout << "Sub 1 Marks = " << sub1 << endl;
	cout << "Sub 2 Marks = " << sub2 << endl;
}

void result :: display() {
	total = sub1 + sub2;
	put_number();
	put_marks();
	cout << "Total = " << total << endl;
}

int main(){
	result student1;
	student1.get_number(9012321);
	student1.get_marks(75, 25);
	student1.display();
	return 0;
}
	

/*
	this code will is an example of single inheritance.
*/
#include <iostream>
using namespace std;

class A {
	private:
		int a;
	public:
		int b;
		void get_ab();
		int get_a();
		void show_a();
		void show_ab();
};

class B: public A {
	private:
		int c;
	public:
		void mul();
		void display();
};

void A :: get_ab() {
	a = 5; 
	b = 10;
}

int A :: get_a(){
	return a;
}

void A :: show_a(){
	cout << "a = " << a << "\n";
}

void A :: show_ab(){
	cout << "a = " << a << ", b = " << b << endl;
}

void B :: mul(){
	c = get_a() * b;
}

void B :: display(){
	cout << "a = " << get_a() << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main(){
	B b;
	b.get_ab();
	b.mul();
	b.show_ab();
	b.display();
	return 0;
}
	
	

/*
	this is to show ambiguity in multiple inheritance.
*/

#include <iostream>
using namespace std;

class A {
	public:
		void display();
};

class B {
	public:
		void display();
};

class C :public A, public B {
	public:
		void display();
};

void A :: display(){
	cout << "A" << endl;
}

void B :: display() {
	cout << "B" << endl;
}

void C :: display() {
	cout << "C" << endl;
}

int main(){
	C c;
	c.display();
	c.A::display();
	c.B::display();
	c.C::display();
	return 0;
}

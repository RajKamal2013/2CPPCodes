#include <iostream> 
using namespace std;

class A {
	private:
		int a;
	public:
		int b;
		void get_ab();
		int get_a();
		void show_a(void);
};

class B : private A {
	private:
		int c;
	public:
		void mul();
		void display();
};

void A :: get_ab(){
	cout << "Enter the values for a and b" << endl;
	cin >> a >> b;
}

int A :: get_a(){
	return a;
}

void A :: show_a(){
	cout << "a = " << a << endl;
}

void B :: mul(){
	get_ab();
	c = b * get_a();
}

void B :: display(){
	show_a();
	cout << "b = " << b << "\n";
	cout << "c = " << c << "\n";
}

int main(){
	B b;
	b.mul();
	b.display();
	return 0;
}
	

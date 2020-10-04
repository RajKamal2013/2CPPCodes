#include <iostream>
#include <cstring>
using namespace std;

class person {
	private:
		char name[20];
		float age;
	public:
		person (char *s, float a){
			strcpy (name, s);
			age = a;
		}
		person & greater (person &x) {
			if (x.age >= age)
				return x;
			else
				return *this;
		}
		void display() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
		}
};

int main() {
	person p1("john", 34),
		p2("ahmed", 35),
		p3("rhj", 34);
	person P = p1.greater(p2);
	cout << "elder person is : \n";
	P.display();
	return 0;
}


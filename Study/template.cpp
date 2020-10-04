#include <iostream>
#include <cstring>
using namespace std;

template <class T1, class T2>
class test {
	private:
		T1 a;
		T2 b;
	public:
		test (T1 a, T2 b);
		void show();
};

template <class T1, class T2>
test <T1, T2> :: test (T1 a, T2 b) {
	this->a = a;
	this->b = b;
}

template <class T1, class T2>
void test <T1, T2> :: show() {
	cout << a << "," << b <<endl;
}

int main() {
	test <int, int> t1(23, 12);
	test <int, float> t2(12, 34.1);
	t1.show();
	t2.show();
	return 0;
}
	 

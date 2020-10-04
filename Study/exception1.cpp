#include <iostream>
using namespace std;

int main () {
	int a, b;
	int x;
	cout << "Enter the number ." << endl;
	cin >> a >> b;
	
	x = a - b;
	
	try {
		if (x != 0 )
			cout << "(a/x)" << a/x;
		else	
			throw (x);
	}
	
	catch (int i) {
		cout << "Exception Caught : x = " << x << endl;
	}
	cout << endl;
	return 0;
}

#include <iostream>
using namespace std;

void divide (int a, int b , int c) {
	int x = a - b;
	if (x == 0) 
		throw (x);
	else
		cout << "Result : " << c/x << endl;
	
}

int main () {
	try {
		cout << "We are inside try block " << endl;
		divide (12, 10, 30);	
		divide (12, 12, 30);
	}
	catch (int i){
		cout << "Exception  Caught : a - b " << i << endl;
	}
	return 0;
} 
	 

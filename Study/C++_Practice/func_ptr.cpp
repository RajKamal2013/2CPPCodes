#include <iostream>
using namespace std;

typedef void (*FunPtr)(int, int);
//void (*ptr) (int, int);

void Add (int i, int j){
	cout << i << " + " << j << " = " << i + j << endl;
}

void Sub (int i, int j){
	cout << i << " - " << j << " =  " << i - j << endl;
}

int main () {
	FunPtr ptr;
	ptr = &Add;
	ptr (23, 22);
	ptr = &Sub;
	ptr (23, 22);
	return 0;
}

#include <iostream>
using namespace std;

int main () {
	char c;
	c = cin.get();
	while (c != '\n') {
		cout << c;
		c = cin.get();
	}
	cout << endl;
	return 0;
}
	

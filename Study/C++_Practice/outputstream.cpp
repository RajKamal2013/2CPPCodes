#include <iostream>
using namespace std;

ostream & symbol(ostream & output) {
	return output << "\t Rs";
}

int main() {
	cout << symbol <<": $5"<<endl;
}

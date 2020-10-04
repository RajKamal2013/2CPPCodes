#include <iostream>
using namespace std;

int main() {
	char line[1000];
	cout << "Enter the line " << endl;
	cin.getline(line, 1000);
	cout << line;
	return 0;
}

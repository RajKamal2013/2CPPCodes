#include <iostream>
#include <set>
using namespace std;

int main() {
	set <int> s1;
	set <int> s2;
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(100);
	s1.insert(0);
	int myarray[] = {1, 2, 9, 40, 21, 19, 120, 100};
	s1.insert(myarray, myarray+8);
	set<int> :: iterator it;
	for (it = s1.begin(); it != s1.end(); it++){
		cout << *it << endl;
	}
	s1.erase(40);

	cout<< "new set " << endl;	
	for (it = s1.begin(); it != s1.end(); it++){
		cout << *it << endl;
	}
	s1.erase(40);
	return 0;
}

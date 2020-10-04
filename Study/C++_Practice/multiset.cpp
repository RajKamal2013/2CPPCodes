#include <iostream>
#include <set>
using namespace std;

int main() {
	multiset<int>s1;
	int myarray [] = {1, 34, 22, 1, 90, 100, 120, 130};
	s1.insert (200);
	s1.insert (12);
	s1.insert (-12);
	s1.insert (100);
	s1.insert (myarray, myarray + 8);
	
	multiset <int> :: iterator it;

	for (it = s1.begin(); it != s1.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}

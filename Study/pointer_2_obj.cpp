#include <iostream>
using namespace std;

class BC {
	public:
		int b;
		void show() {
			cout << "Base Class" << endl;
			cout << "b = " << b << endl;
		}
};

class DC : public BC {
	public:
		int d;
		void show() {
			cout << "Derrived Class " << endl;
			cout << "b = " << b << endl;
			cout << "d = " << d << endl;
		}
};

int main() {
	BC *bptr;
	BC base;
	DC *dptr;
	DC derrived;
	
	cout << "base class pointer points to base class" << endl;
	bptr = &base;
	bptr->b = 100;
	bptr->show();

	cout << "base class pointer points to derrived class" << endl;
	bptr = &derrived;
	bptr->b = 200;
	/*	
		wont work as base class pointer can't access derrived 
		class members that are not in base class 
		bptr->d = 200;
	*/
	bptr->show();

	cout << "Deerived class pointer points to derrived class" << endl;
	dptr = &derrived;
	dptr->d = 300;
	dptr->show();

/*	
	We can't point derrived class pointer to base class 
	cout << "Derrived class pointer points to base class " << endl;
	dptr = &base;
	dptr->b = 100;
	dptr->show();
*/

	cout << "Using base class to access derrived class members." << endl;
	cout << "using ((DC*)bptr)\n";
	((DC*)bptr) -> d = 400;
	((DC*)bptr) -> show();
	
	return 0;
}


	

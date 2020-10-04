#include <iostream>
using namespace std;

class vector {
	private:
		int x;
		int y;
		int z;
	
	public:
		vector(int , int, int );
		vector() {
			x=y=z=0;
		}
		void display();
		/* Either of friend fucntion and class fucntion for operator
			overloading will work, as they have same notation 
			while calling inside main.
		*/
		//vector operator-();
		friend void operator-(vector &);
};
	

vector :: vector (int n1, int n2, int n3){
	x = n1;
	y = n2;
	z = n3;
}

/*
vector vector :: operator-(){
	x = -x;
	y = -y;
	z = -z;
}
*/
void vector :: display(){
	cout << "(" << x << "," << y << "," << z <<")" << endl;
}

void operator - (vector &s){
	s.x = -s.x;
	s.y = -s.y;
	s.z = -s.z;
}

int main() {
	vector v1;
	vector v2(1,45,40);
	v1.display();
	v2.display();
	-v1;
	-v2;
	v1.display();
	v2.display();
	operator - (v1);
	operator - (v2);
	v1.display();
	v2.display();
	return 0;
}

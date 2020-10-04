#include <iostream>
using namespace std;


class Complex {
	private:
		float x;
		float y;
	public:
		Complex() { }
		Complex(float, float );
		void display();
		/*
			these two have same notation so only one 
			of them can be defined and used. 
			Other whole part needs to be commented
		*/
		//Complex operator + (Complex );
		friend Complex operator + (Complex, Complex);
}; 	

Complex :: Complex (float real, float imag){
	x = real;
	y = imag;
}

void Complex :: display(){
	cout << x << "+" << "j" << y << endl;
}
/*
Complex Complex :: operator + (Complex C1) {
	Complex C2;
	C2.x = x + C1.x;
	C2.y = y + C1.y;
	return C2;
}
*/

Complex operator + (Complex C1, Complex C2){
	Complex C;
	C.x = C1.x + C2.x;
	C.y = C1.y + C2.y;
	return C;
}


int main(){
	Complex C1, C2, C3;
	C1 = Complex(1, 2);
	C2 = Complex(3, 4);
	C3 = C1 + C2;
	
	C1.display();	
	C2.display();
	C3.display();
	
	return 0;
}


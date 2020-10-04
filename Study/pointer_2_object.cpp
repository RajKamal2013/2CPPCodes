#include <iostream>
using namespace std;

class item {
	private:
		int code;
		float price;
	public:
		void getdata (int a, float b) {
			code = a;
			price = b;
		}
		void show() {
			cout << "Code: " << code << endl;
			cout << "Price: " << price << endl;
		}
};


const int size = 2;

int main(){
	item *p = new item [size];
	item *d = p;
	int x;
	float y;
	
	for (int i = 0; i < size; i++) {
		cout << "Input code and price for item: " << i+1 << ". ";
		cin >> x >> y;
		p->getdata(x, y);
		p++;
	}
	
	for (int i=0; i < size; i++) {
		cout << "Items:" << i+1 << "\n";
		d->show();
	}
	return 0;
}


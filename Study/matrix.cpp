#include <iostream>
using namespace std;

class matrix {
	private:
		int **p;
		int d1, d2;
	
	public:
		matrix(int d1, int d2);
		void get_element(int i, int j, int value) {
			p[i][j] = value;
		}
		int & put_element(int i, int j){
			return p[i][j];
		}
		~matrix();
	};

matrix :: matrix (int r, int q){
	d1 = r;
	d2 = q;
	p = new int *[d1];
	for(int i=0; i < d1; i++){
		p[i] = new int[d2];
	}
}

matrix :: ~matrix() {
	for (int i=0; i<d2; i++)
		delete p[i];
	delete p;
}

int main(){
	int m, n, val;
	cout << "Enter the dimenions :";
	cin >> m >> n;
	matrix A(m, n);
	cout << "Enter the values in the matrix." << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++){
			cin >> val;
			A.get_element (i, j, val);
		}

	cout << "ALL entries are done\n";
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			cout << A.put_element(i, j) << " ";
		cout << endl;
	}

	cout<<"Done"<<endl;
	return 0;
}
	
	 		

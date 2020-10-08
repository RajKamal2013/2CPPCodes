#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Permutation
{
	public:
		T *arr;
		int count;
		Permutation(int i, T *arr);
		void permutation();
		~Permutation();
	private:
		void generate_permutation(T *arr, int start, int size, bool *ret);
		void swap(T* arr, int i, int j);
		void print_permutation();
		bool validate_permutation();
};

template <typename T>
Permutation <T> :: Permutation(int range, T *arr)
{
	this->count = range;
	this->arr = new T[this->count];
	for (int i = 0; i < this->count; i++) {
		this->arr[i] = arr[i];
	}
	cout << "Input " << endl;
	print_permutation();
	cout << "Output " << endl;
}

template <typename T>
void Permutation <T> :: swap (T *arr, int i, int j)
{
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <typename T>
bool Permutation <T> :: validate_permutation()
{
	bool ret = true;
	if (this->count < 2) {
		print_permutation();
		return ret;
	}
	int a, b, c;

	for (int i = 0; i < count ; i++) {
		a = i;
		b = i + 1;
		c = i + 2;

		if ((a < count) && (b < count) && (c < count)) {
			if ( arr[a] + arr[c] == 2 * arr[b]) {
				ret = false;
				break;
			}
		}
	}

	if (ret == true) {
		print_permutation();
		return true;
	} else {
		return ret;
	}
}

template <typename T>
void Permutation <T> :: print_permutation()
{
	for (int i = 0; i < count; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

template <typename T>
void Permutation<T> :: permutation()
{
	//generate_permutation(arr, 1, count - 1);
	//cout << "Permutation " << endl;
	bool ret = false;
	generate_permutation(arr, 0, count - 1, &ret);
}

template <typename T>
void Permutation <T>:: generate_permutation(T *arr, int start, int end, bool *ret)
{
	if (start > end ) {
		//print_permutation();
		*ret = validate_permutation();
		return;
	}

	if (*ret) {
		return ;
	}
	for (int i = start; i <= end; i++) {
		swap(arr, start, i);
		generate_permutation(arr, start + 1, end, ret);
		swap(arr, i , start);
	}
}

template <typename T>
Permutation <T> :: ~Permutation()
{
	delete(this->arr);
}

int main()
{
	int range;
	int *arr;
	cout << "Enter the Range " << endl;
	cin >> range;
	arr = new int[range];
	for (int i = 0; i < range; i++) {
		arr[i] = i;
	}
	Permutation<int> per(range, arr);
	per.permutation();
	return 0;
}


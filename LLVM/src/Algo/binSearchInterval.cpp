#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/*
 * Given a sorted vector and a pivot, this API finds out the interval
 * where the pivot lies.
 * Like we have array of 5, 12, 20, 45 and pivot is 10, then pivot lies in
 * between 0th and 1st index. So the answer is 0. (x,y] is the way to go
 */
int binarySearchInterval(vector<int> vec, int pivot)
{
	int mid =0;
	int low = 0;
	int high = vec.size() - 1;

	if (vec.size() == 0) {
		return -1;
	}
	if (vec.size() == 1) {
		return low;
	}

	while (high > low) {
		mid = (high + low) /2;
		if (vec[mid] < pivot) {
			low = mid + 1 ;
		} else {
			high = mid;
		}
	}
	return low;
}

int main()
{
	vector<int> vec =  {12, 20, 25, 27, 50, 75, 120, 200, 500};
	int pos = 0;
	int pivot = 100;
	int idx = 0;


	for (int data :vec) {
		cout << "idx: " << pos << " " << data << endl; 
		pos++;
	}

	cout << endl;
	idx = binarySearchInterval(vec, pivot);
	cout << "pos of " << pivot << " is " << idx << endl;

	for (int test = 0; test < 30; test++) {
		pivot = rand() % 70;
		idx = binarySearchInterval(vec, pivot);
		cout << "pos of " << pivot << " is " << idx << endl;
	}
	return 0;
}

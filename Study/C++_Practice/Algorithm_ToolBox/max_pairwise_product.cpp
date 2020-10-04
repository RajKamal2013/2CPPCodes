#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

long long maximum_pairwise_product(const vector<int>& numbers) {
	int maxIndex1 = -1, maxIndex2 = -1, n;
	n = numbers.size();
	for (int i = 0; i < n; i++) {
		if ((maxIndex1 == -1 ) || (numbers[i] > numbers[maxIndex1]))
			maxIndex1=i;
	}

	for (int i = 0; i < n; i++) {
		if ((i !=  maxIndex1) && ((maxIndex2 == -1) || (numbers[i] > numbers[maxIndex2])))
			maxIndex2=i;
	}

	return ((long long )(numbers[maxIndex1])) * numbers[maxIndex2];
}


int main() {
	int n;
	long long result;
	vector<int> numbers;

	cin>>n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	result =  maximum_pairwise_product(numbers);

	cout << result;

	return (0);

}

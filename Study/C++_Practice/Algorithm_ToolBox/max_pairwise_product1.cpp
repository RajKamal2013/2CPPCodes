//
// Created by Raj Kamal on 9/19/16.
//

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


long long maximum_pairwise_product(const vector<int> & numbers) {
    long long result =0;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (numbers[i] * numbers[j] > result )
                result = numbers[i] * numbers[j];
    return (result);
}

long long fast_maximum_pairwise_product(const vector<int>& numbers) {
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

    cout << "MaxIndex1 : " << maxIndex1 <<" MaxIndex2 : " << maxIndex2<<endl;
    return ((long long )(numbers[maxIndex1])) * numbers[maxIndex2];
}


int main() {
    int n, result1, result2, i;
    vector<int> numbers;

    /* stress Testing */
    while (true) { 
    	n = rand() % 20 + 2;
	    for (i = 0; i < n; i++) {
            numbers.push_back(rand() % 1000 + 1);
        }
        for (i = 0; i < n; i++) {
            cout << numbers[i] <<", ";
        }
        cout << endl;
        result1 =  maximum_pairwise_product(numbers);
        result2 = fast_maximum_pairwise_product(numbers);

        if (result1 != result2) {
            cout << "Error :" << result1 << "  " << result2<<endl;
        } else
            cout << "OK "<<endl;

    }

    cout << "Input Time :" << endl;

    cin>>n;
    for (i = 0; i < n; i++)
        cin >> numbers[i];

    result1 =  maximum_pairwise_product(numbers);
    result2 = fast_maximum_pairwise_product(numbers);

    if (result1 != result2) {
        cout << "Error :" << result1 << "  " << result2<<endl;
    } else
        cout << "OK "<<endl;

    return (0);

}

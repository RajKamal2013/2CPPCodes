//
// Created by kamr on 10/29/2021.
//

#ifndef GNU_SUBARRAYSUM_H
#define GNU_SUBARRAYSUM_H



int find_max_sum(vector<int> A, int n) {
    if (n < 1) {
        return 0;
    }

    int curr_sum = A[0];
    int global_sum = A[0];
    int start, end;

    for (int i = 1; i < n; i++) {
        if (curr_sum < 0) {
            curr_sum = A[i];
            start = i;
        } else {
            curr_sum = curr_sum + A[i];
        }

        if (global_sum > curr_sum) {
            global_sum = curr_sum;
            end = i;
        }
    }

    return global_sum;
}
int max(int i, int j) {
    if (i > j ) {
        return i;
    } else {
        return j;
    }
}

/* non subsequence sum */
int find_max_sum2(vector<int> array) {
    bool test = false;
    if (array.size() == 0) {
        return 0;
    }

    if (array.size() == 1) {
        return array[0];
    }

    vector<int> result(array.size(), 0);
    if (test) {
        for (auto &i:result) {
            cout << i << " ";
        }
        cout << endl;

        for (auto &i:array) {
            cout << i << " ";
        }
        cout << endl;
    }

    result[0] = array[0];
    for (int i = 1; i < array.size(); i++) {
        result[i] = max(result[i - 1], array[i]);
        if ((i - 2) >= 0) {
            result[i] = max(result[i], result[i - 2] + array[i]);
        }
    }
    return result[array.size() - 1];
}

void test_subarraysum(){
    vector<int> arr = {1,6 ,10, 14,-5,-1, 2,-1,3};
    int res = find_max_sum2(arr);
    cout << res << endl;

    arr = {1, -1, 6, -4, 2, 2};
    res = find_max_sum2(arr);
    cout << res << endl;
}
#endif //GNU_SUBARRAYSUM_H

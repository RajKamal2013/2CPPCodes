//
// Created by kamr on 10/29/2021.
//

#ifndef GNU_SUBARRAYSUM_H
#define GNU_SUBARRAYSUM_H



int find_max_sum(int[] arr, int n) {
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



#endif //GNU_SUBARRAYSUM_H

//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_NTHFIBONACCI_H
#define GNU_NTHFIBONACCI_H

int getNthFibHelper(int n) {
    if (n == 0) {
        return 0;
    } else if ( n == 1) {
        return 1;
    } else {
        return (getNthFibHelper(n - 1) + getNthFibHelper(n-2));
    }
}
int getNthFib(int n) {
    if (n == 0) {
        return 0;
    }
    return getNthFibHelper(n - 1);
}

#endif //GNU_NTHFIBONACCI_H

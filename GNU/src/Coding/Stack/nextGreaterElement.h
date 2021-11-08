//
// Created by kamr on 11/5/2021.
//

#ifndef GNU_NEXTGREATERELEMENT_H
#define GNU_NEXTGREATERELEMENT_H

/*
 * Write a function to find next greater element.
   Given a array and output an array consisting of element where each element is replaced with
   next greater element.

    Input - > 2, 5, -3, -4, 6, 7, 2
    Output -> 5, 6, 6, 6, 7, -1, 5

    Input -> 6, 4, 5, 7, 2, 1, 3
    Output > 7  5  7 -1 , 3, 3, 6




   7  2  1
    keep a stack to account for the current lowest number. Stack will have indices.
    As we interatet the array, we compare the data with stack top.
    if stack top is greater, then we place the data in stack
    if stack top is smaller, we replace the indices corresponding to array with element till the value at indices is smaller than data.
    At the end, we find what everleft in array and iterate over the array to find next greater.
 *
 *
 */
vector<int>
nextGreaterElement(vector<int> array) {

    // stack containing indices of the element whose next greater is to find
    stack<int> S = {};
    vector<int> output(array.size(), -1);
    int curr, max, sTop;

    if (array.size() == 0) {
        return {};
    }

    if (array.size() == 1) {
        return output;
    }

    // we place only  indices in the stack, as its next greater is to find
    S.push(0);
    max = array[0];


    for (int i = 1; i < array.size(); i++) {
        sTop = S.top();

        if (max < array[i]) {
            max = array[i];
        }

        // if top is greater then curr, then simply push to stack

        if (array[sTop] > array[i]) {
            S.push(i);
        } else if (array[sTop] < array[i]) {  // Top is smaller than curr, then we need to pop till we find top of stack is greater and then push.

            while ((!S.empty()) && (array[sTop]  < array[i])) {
                S.pop();
                output[sTop] = array[i];
                if (!S.empty()) {
                    sTop = S.top();
                }
            }

            S.push(i);
        } else { // equal case.
            S.push(i);
        }

    }

    while (!S.empty()) {
        sTop = S.top();

        // if the element is largest, no greater exist, (replace with - 1)
        if (array[sTop] == max) {
            output[sTop] = -1;
        } else { //we need to find greater than it in array

            curr = max;
            for (auto &data:array) {
                if (data > array[sTop]) {
                    curr = data;
                    break;
                }
            }
            output[sTop] = curr;
        }
        S.pop();
    }

    return output;
}

void
test_nextGreaterElement() {
    vector<int> array = {2, 5, -3, -4, 6, 7, 2};
    vector<int> output = {};

    cout << "-----------------------------------------------" << endl;
    output = nextGreaterElement(array);
    cout << "Input:" << endl;
    for (auto &data:array) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output :" << endl;
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << endl;

    cout << "-----------------------------------------------" << endl;
    array = {6, 4, 5, 7, 2, 1, 3};
    output = nextGreaterElement(array);
    cout << "Input:" << endl;
    for (auto &data:array) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output :" << endl;
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << endl;


 }

#endif //GNU_NEXTGREATERELEMENT_H

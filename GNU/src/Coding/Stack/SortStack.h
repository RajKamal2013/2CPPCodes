//
// Created by kamr on 11/5/2021.
//

#ifndef GNU_SORTSTACK_H
#define GNU_SORTSTACK_H

/*
 * Sort Stack ->

Write a function that sort the stack in place.
Use vector for stack (c++) -> pop_back() and push_back()
and use recursion.
-----
Stack -> <Input >   -5, 2, -2, 4, 3, 1
Stack -> <Output>  -5, -2, 1, 2, 3, 4
-----

1
Time -> O(n^2) and O(n)
Operation to be used -> pop_back and push_back
Algorithm -> Recursion to be used.

-> Input Stack -> I
-> keep one output stack(O).
-> while (I is not empty) {
        data = I.top();
        I.pop();
        function(O, data);
    }
function(O, data) {
 // Aim is to keep larger at top.
 -> if (O.empty()) {
     O.push(data);
     return;
    }
-> if (O.top() < data ) { // data is more then the top ->
        O.push(data) -> push the data top to O.
        return;
    }
-> if (O->top >= data) { ///inplace
        temp = O.top();
        O.pop();
        function(O, top) //call the function with O, data ;
        O.push(temp);
    }
}
 */

void
sortStackHelper(vector<int> &output, int data) {
    if (output.empty()) {  // output stack is empty (either we encounter first input or data is lowest till now )
        output.push_back(data);
        return;
    }
    if (output.back() < data) {  // data is more then the top of output stack,we found next greatest.
        output.push_back(data);
        return;
    }

    if (output.back() >= data) {   // our data is smaller and we need to place it to appropriate place in stack . (inplace )
        int temp = output.back();
        output.pop_back();
        sortStackHelper(output, data);
        output.push_back(temp);
        return;
    }
}

vector<int>
sortStack(vector<int> &stack) {
    if (stack.size() == 0) {
        return {};
    }

    if (stack.size() == 1) {
        return stack;
    }

    vector<int> output = {};
    vector<int> aux = {};
    int data;
    while (!stack.empty()) {
        data = stack.back();
        cout << "S : " << data << endl;
        stack.pop_back();
        aux.push_back(data);
        sortStackHelper(output, data);
    }

    /* copy back to original stack */
    while (!aux.empty()) {
        data = aux.back();
        stack.push_back(data);
        aux.pop_back();
    }

    return output;
}

void test_sortStack() {
    vector<int> stack = {-5, 2, -2, 4, 3, 1};
    vector<int> sortedStack = {};

    cout << "---------------------------------------" << endl;
    sortedStack  = sortStack(stack);
    cout << "Input:" << endl;
    while (!stack.empty()) {
        cout << stack.back() << " ";
        stack.pop_back();
    }
    cout << endl;

    cout << "output <sorted stack>" << endl;
    while (!sortedStack.empty()) {
        cout << sortedStack.back() << " ";
        sortedStack.pop_back();
    }
    cout << endl;
}

#endif //GNU_SORTSTACK_H

//
// Created by kamr on 10/30/2021.
//

#ifndef GNU_VALIDATEBST_H
#define GNU_VALIDATEBST_H

#include <bits/stdc++.h>
bool validateBST_int(BST *tree, int max, int min) {
    bool test = false;
    bool lt, rt, ret;
    ret = true;

    if (tree == nullptr) {
        return true;
    }

    if ((tree->value < min) || (tree->value >= max)) {
        if (test) {
            cout << __LINE__ << endl;
        }
        return false;
    }

    if ((tree->left) && (tree->left->value > tree->value)) {
        if (test) {
            cout << __LINE__ << endl;
        }
        return false;
    }

    if ((tree->right) && (tree->right->value < tree->value)) {
        if (test) {
            cout << __LINE__ << endl;
        }
        return false;
    }


    lt = validateBST_int(tree->left, tree->value, min);
    rt = validateBST_int(tree->right, max, tree->value);

    if (test) {
        cout << "Left :" << lt << "Right :" << rt << endl;
    }

    ret = lt && rt;
    return ret;
}

bool validateBst(BST *tree) {
    int maxL, minR;
    maxL = INT_MIN;
    minR = INT_MAX;
    if (tree == nullptr) {
        return true;
    } else {
        return validateBST_int(tree, INT_MAX, INT_MIN);
    }
}

void
test_validateBST()
{
    vector<int> input;
    BST *tree = new BST(10);
    bool isBST;
    BST *curr;

    curr = tree;
    input = {5, 15, 2, 5, 13, 22, 1, 14};
    for (auto &data:input) {
        curr->insert(data);
    }
    isBST = validateBst(curr);
    cout << "Input:" << endl;
    tree->inorder();
    cout<<"output" << endl;
    if (isBST) {
        cout << "IsbST" << " TRUE" << endl;
    } else {
        cout << "IsbST" << " FALSE" << endl;
    }
}
#endif //GNU_VALIDATEBST_H

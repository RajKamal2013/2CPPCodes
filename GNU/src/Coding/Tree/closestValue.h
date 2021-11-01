//
// Created by kamr on 10/29/2021.
//

#ifndef GNU_CLOSESTVALUE_H
#define GNU_CLOSESTVALUE_H

#include "BST.h"



int findClosestValueInBst_int(BST *tree, int target, int closest) {
    if (abs(target - closest) > abs(target - tree->value)) {
        closest = tree->value;
    }
    if ((tree->left != nullptr) && (target < tree->value)) {
        return findClosestValueInBst_int(tree->left, target, closest);
    } else if ((tree->right != nullptr) && (target > tree->value)) {
        return findClosestValueInBst_int(tree->right, target, closest);
    } else {
        return closest;
    }
}

int findClosestValueInBst(BST *tree, int target) {
    if (tree != nullptr) {
        return findClosestValueInBst_int(tree, target, tree->value);
    } else {
        return -1;
    }
}



int min(int a, int b) {
    int ret = (a > b) ? b : a;
    return ret;
}
int BuggyfindClosestValueInBst(BST *tree, int target, int closer = -1, int minDiff = -1) {

    bool ret = true;
    if (tree == nullptr) {
        return closer;
    }

    int currCloser, diff;
    if (tree->value == target) {
        return tree->value;
    } else if (tree->value > target) {
        if (tree->left != nullptr) {
            if (tree->left->value < target) {
                if ((tree->value - target) < (target - tree->left->value)) {
                    /* now check for larger value than tree->left and lesser than target */
                    diff = tree->value - target;
                    currCloser = tree->value;
                } else {
                    diff = target- tree->left->value;
                    currCloser = tree->left->value;
                }
                if (minDiff == -1) {
                    minDiff = diff;
                    closer = currCloser;
                } else if (minDiff > diff) {
                    minDiff = diff;
                    closer = currCloser;
                } else {

                }
                if (tree->left->right != nullptr) {
                    return BuggyfindClosestValueInBst(tree->left->right, target, closer, minDiff);
                }
            } else {
                return BuggyfindClosestValueInBst(tree->left, target, minDiff, closer);
            }
        } else {
            closer = tree->value;
            return tree->value;
        }
    } else if (tree->value < target) {
        if (tree->right != nullptr) {
            if (tree->right->value > target) {
                if ((target - tree->value) < (tree->right->value - target)) {
                    /* now check for larger value than tree->left and lesser than target */
                    diff = target - tree->value;
                    currCloser = tree->value;
                } else {
                    diff = tree->right->value - target;
                    currCloser = tree->right->value;
                }
                if (minDiff == -1) {
                    minDiff = diff;
                    closer = currCloser;
                } else if (minDiff > diff) {
                    minDiff = diff;
                    closer = currCloser;
                } else {

                }
                if (tree->right->left != nullptr) {
                    return BuggyfindClosestValueInBst(tree->right->left, target, closer, minDiff);
                }
            } else {
                return BuggyfindClosestValueInBst(tree->right, target, minDiff, closer);
            }
        } else {
            closer = tree->value;
            return tree->value;
        }
    }
    return closer;
}

void
test_findCloesestValueInBst() {
    vector<int> input;
    BST *tree = new BST(10);
    int target, closestValueToTarget;
    BST *curr;

    curr = tree;
    input = {5, 15, 2, 5, 13, 22, 1, 14};
    for (auto &data:input) {
        curr->insert(data);
    }
    target = 12;
    closestValueToTarget = findClosestValueInBst(tree, target);
    cout << "Input" << endl;
    cout << "Inorder: " << endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;


    target = 22;
    closestValueToTarget = findClosestValueInBst(tree, target);
    cout << "Input" << endl;
    cout << "Inorder: " << endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;


    BST *root = new BST(10);
    curr = root;
    input = {5, 3, 8, 12, 11, 15, 13, 14};
    for (auto &data:input) {
        curr->insert(data);
    }
    target = 20;
    closestValueToTarget = findClosestValueInBst(curr, target);
    cout << "Input" << endl;
    cout << "Inorder: " <<  endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;

}
#endif //GNU_CLOSESTVALUE_H

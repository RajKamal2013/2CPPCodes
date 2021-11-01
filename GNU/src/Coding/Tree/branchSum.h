//
// Created by kamr on 10/31/2021.
//

#ifndef GNU_BRANCHSUM_H
#define GNU_BRANCHSUM_H

/* Iterative branch sum */
/*
 * while (!S.empty()) {
    curr = S.top();
    if (lefi is not nullptr) && ((curr->left != prev) || (curr->right != prev)) {
        sum = sum + curr->left->value;
    } else if (curr-> left == prev ) {  // we have visited in last iteration. now we should push the right
        if (curr->right) {
            sum = sum + curr->right->value;
            push the curr->right to stack
        }
    } else if (curr->right == prev) {  // we have visited the right, now we should pop the node.
        S.pop();
        sum = sum - curr->value;
    }  else if (curr->left == nullptr) {
        S.pop();
        push the "sum" to the res array
        sum = sum  - curr.value;
    } else {

    }
    prev = curr;
}
 */

void
branchSum_int(BST *root, int sum, vector<int> &res) {
    bool test = true;
    if (root == nullptr) {
        return;
    }
    if ((root->left == nullptr) && (root->right == nullptr)) {
        sum = sum + root->value;
        res.push_back(sum);
    }
    sum = sum + root->value;
    branchSum_int(root->left, sum, res);
    branchSum_int(root->right, sum, res);
}

vector<int> branchSums(BST *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int> res;
    int sum = 0;
    branchSum_int(root, sum, res);
    return res;
}

void test_branchSums() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14};
    for (auto &data:list) {
        root->insert(data);
    }

    vector<int> res;
    res = branchSums(root);
    for (auto &data:res) {
        cout << data << " " ;
    }
    cout << endl;
}

#endif //GNU_BRANCHSUM_H

//
// Created by kamr on 11/1/2021.
//

#ifndef GNU_KTHLARGESTVALUE_H
#define GNU_KTHLARGESTVALUE_H


void
inOrderTraverseKthLargest(BST *tree, vector<int> &res) {
    if (tree == nullptr) {
        return;
    }
    inOrderTraverseKthLargest(tree->left, res);
    res.push_back(tree->value);
    inOrderTraverseKthLargest(tree->right, res);
}

int
findKthLargestValueInBst(BST *tree, int k) {
    vector<int> traverse;
    inOrderTraverseKthLargest(tree, traverse);
    return  traverse[traverse.size()-k];
}




int
findKthValueInBstHelper(BST *tree, int k, int count, stack<BST*> &S) {
    bool test = false;
    int include = 0;

    /* leaf */
    if (tree == nullptr) {
        return 0;
    }
    /* We have already reached k */
    if (count >= k) {
        if (test) {
            cout << __LINE__ << " -> " << "We already Found K before Node: " << tree->value << endl;
        }
        return count;
    }

    /* Compute left count */
    int lCount;
    /*travel left */
    if (tree->left != nullptr) { // non nullcase.
        lCount = findKthValueInBstHelper(tree->left, k, count, S);
    } else {
        lCount = count;
    }

    /* Left node has reached k */
    if (lCount >= k ) {
        if (test) {
            cout << "Prev: " << count << " Left :" << lCount << " Node :" << tree->value << endl;
            cout << __LINE__ << " -> " << "We already Found K before Node" << tree->value << endl;
        }
        return lCount;
    }


    if (!S.empty())  {
        if (tree->value != S.top()->value) {
            lCount = lCount + 1;
            S.push(tree);
        }
    }else {
        S.push(tree);
        lCount = lCount + 1;
    }


    if (test) {
        cout << "Prev: " << count << " Node + Left :" << lCount << " Node :" << tree->value << endl;
    }

    if (lCount >= k ) {
            /* Left node including node has reached k */
            if (test) {
                cout << "Prev: " << count << " Left :" << lCount << " Node :" << tree->value << endl;
                cout << __LINE__ << " -> " << "We Found K " << endl;
            }
        return lCount;
    }

    if (tree->right != nullptr) {
        /* Travel right */
        int rCount = findKthValueInBstHelper(tree->right, k, lCount, S);

        if (test) {
            cout << "Node + Left + Right : " << rCount << " Node :" << tree->value << endl;
        }

        /* With Right node we found */
        if (rCount >= k) {
            if (test) {
                if (rCount == k) {
                    cout << __LINE__ << " -> " << "We found Kth: " << S.top()->value << endl;
                }
            }
        }
        return rCount;
    } else {
        return lCount;
    }
}
int
findKthValueInBst(BST *tree, int k) {
    if (tree == nullptr) {
        return 0;
    }

    stack <BST*> S={};
    bool test = false;
    int ret = findKthValueInBstHelper(tree, k, 0, S);
    if (test) {
        cout << __LINE__ << " -> " << "Ret : " << ret << " Kth largest Value: " << S.top()->value << endl;
    }
    return S.top()->value;
}



void
test_KLargestvalueInBST() {
    BST *curr = nullptr;
    bool ret;
    vector<int> list;
    vector<int> traverse;
    int k;
    int nodevalue;

    cout << "-------------------------------------------------------------------" << endl;
    BST *root = new BST(10);
    curr = root;
    list = {5, 12, 3, 8, 7, 9, 14};
    for (auto &data:list) {
        curr->insert(data);
    }
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    traverse.clear();
    inOrderTraverse(curr, traverse);
    for (auto &data:traverse) {
        cout << data << " ";
    }
    cout<< endl;
    k = 4;
    nodevalue = findKthLargestValueInBst(curr, k);
    cout << "Output" << endl;
    cout << "Kth <" << k << "> " << "largest Value in BST is " << nodevalue << endl;

    k = 1;
    nodevalue = findKthLargestValueInBst(curr, k);
    cout << "Output" << endl;
    cout << "Kth <" << k << "> " << "largest Value in BST is " << nodevalue << endl;


    cout << "-------------------------------------------------------------------" << endl;
    BST *root1 = new BST(15);
    curr = root1;
    list = {5, 20, 2, 5, 17, 22, 1, 3};
    for (auto &data:list) {
        curr->insert(data);
    }
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    traverse.clear();
    inOrderTraverse(curr, traverse);
    for (auto &data:traverse) {
        cout << data << " ";
    }
    cout<< endl;
    inOrderTraverse(curr, traverse);
    cout << "Output" << endl;
    k = 3;
    nodevalue = findKthLargestValueInBst(curr, k);
    cout << "Output" << endl;
    cout << "Kth <" << k << "> " << "largest Value in BST is " << nodevalue << endl;

}

/*
 *               15
               /   \
              /     \
             5      20
            / \     / \
           2   5   17  22
          / \
         1  3

    Input ->
        {15, 5, 20, 2, 5, 17, 22, 1, 3 }
        k = 3
    Ouput -> 3

10, 5, 12, 3, 8, 7, 9, 14
                   10
                  /  \
                 /    \
                5     12
               / \      \
              3   8      14
                 / \
                7   9
    InPut = {10, 5, 12, 3, 8, 7, 9, 14}
    k = 4
 */
#endif //GNU_KTHLARGESTVALUE_H

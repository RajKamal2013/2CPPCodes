//
// Created by kamr on 11/1/2021.
//

#ifndef GNU_CHECKHEIGHTBALANCED_H
#define GNU_CHECKHEIGHTBALANCED_H

int
heightBalancedBinaryTree_helper(BST *tree, bool &isBalanced) {

    bool test = true;
    /* in previous recursion stack, we found unbalanced node */
    if (isBalanced == true) {
        if (test) {
            cout << __LINE__ << " -> " << "Balanced :" << isBalanced << endl;
        }
        return -1;
    }

    /* we reached leaf */
    if (tree == nullptr) {
        return 0;
    }

    int lt, rt, ht;
    /* left height */
    lt = heightBalancedBinaryTree_helper(tree->left, isBalanced);
    /* right height */
    rt = heightBalancedBinaryTree_helper(tree->right, isBalanced);

    /* we already found unbalanced node */
    if ((lt == -1) || (rt == -1)) {
        if (test) {
            cout << "Node -> " << tree->value << " lt-> " << lt << " rt->" <<rt << endl;
        }
        return -1;
    } else {
        cout << "Node -> " << tree->value << " lt-> " << lt << " rt->" <<rt << endl;
    }
    /* verify critrea */
    if (abs(lt-rt) > 1) {
        isBalanced = false;
        if (test) {
            cout << __LINE__ << " -> " << "UnBalanced Node:" << tree->value << endl;
        }
        return -1;
    } else {
        ht = (lt > rt) ? (lt + 1) : (rt + 1);
        if (test) {
            cout << "Node -> " << tree->value << " Height->" << ht << endl;
        }
        return ht;
    }
}


bool
heightBalancedBinaryTree(BST *tree) {
    bool isBalanced = true;
    bool test = true;
    int ret = heightBalancedBinaryTree_helper(tree, isBalanced);
    if (ret == -1) {
        if (test) {
            cout << "IsBalanced : " << isBalanced << " ret: " << ret << endl;
        }
        isBalanced = false;
    } else {
        if (test) {
            cout << "IsBalanced : " << isBalanced << " ret: " << ret << endl;
        }
        isBalanced = true;
    }
    return isBalanced;
}

void
test_heightBalancedBinaryTree() {
    BST *curr = nullptr;
    bool ret;
    vector<int> list;
    vector<int> traverse;

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
    ret = heightBalancedBinaryTree(curr);
    cout << "Output" << endl;
    if (ret) {
        cout << "Tree is Height Balanced" << endl;
    } else {
        cout << "Tree is not Height Balanced" << endl;
    }

    cout << "-------------------------------------------------------------------" << endl;
    BST *root1 = new BST(4);
    curr = root1;
    list = {5, 6, 7, 8, 1};
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
    ret = heightBalancedBinaryTree(curr);
    cout << "Output" << endl;
    if (ret) {
        cout << "Tree is Height Balanced" << endl;
    } else {
        cout << "Tree is not Height Balanced" << endl;
    }
}
#endif //GNU_CHECKHEIGHTBALANCED_H

/*
 * 10, 5, 12, 3, 8, 7, 9, 14
                   10
                  /  \
                 /    \
                5     12
               / \      \
              3   8      14
                 / \
                7   9
-> yes

4, 5, 6, 7, 1
         4
        / \
       1   5
            \
             6
              \
               7
-> no
 */
//
// Created by kamr on 10/31/2021.
//

#ifndef GNU_MIRROR_H
#define GNU_MIRROR_H

void
mirror (BST *root) {
    if (root != nullptr) {
        BST *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

void
invertBinaryTree(BST *tree) {
    if (tree == nullptr) {
        return;
    }
    mirror(tree);
}

void test_mirror()
{
    BST *curr = nullptr;
    vector<int> list;
    vector<int> res;

    BST *root = new BST(10);
    curr = root;
    list = {5, 3, 8, 12, 11, 15, 13, 17};
    for (auto &data:list) {
        curr->insert(data);
    }
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    inOrderTraverse(root, res);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    invertBinaryTree(curr);
    cout << "Output" << endl;
    cout << "Inorder Mirror"  << endl;
    inOrderTraverse(root, res);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
}

/* Results
         Input                          Output
         10                             10
        /  \                           /  \
       /    \                         /    \
       5     12                       12     5
      / \   /  \                     /  \   / \
     3   8  11 15                   15  11 8   3
               / \                  / \
             13  17                17 13

 Inorder <Input> -> 3, 5, 8, 10, 11, 12, 13, 15, 17
 Inorder <Output>-> 17, 15, 13, 12, 11, 10, 8, 5, 3
 */

#endif //GNU_MIRROR_H

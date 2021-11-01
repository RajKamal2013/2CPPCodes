//
// Created by kamr on 10/31/2021.
//

#ifndef GNU_DIAMETER_H
#define GNU_DIAMETER_H

int
Height(BST *node, int& Diameter) {
    if (node == nullptr) {
        return 0;
    }
    bool test = true;
    int diameter = 0;
    int ltHeight = Height(node->left, Diameter);
    int rtHeight = Height(node->right, Diameter);

    /*
    if (test) {
        cout << __LINE__ << "-> " << "Diameter: " << Diameter << endl;
    }
     */
    diameter = ltHeight + rtHeight + 1;

    if (diameter > Diameter) {
        if (test) {
            cout << __LINE__ << " ->" << " Node: " << node->value << " Prev: " << Diameter << " Cur: " << diameter << endl;
        }
        Diameter = diameter;
    }
    int ret = (ltHeight > rtHeight) ? (ltHeight + 1) : (rtHeight + 1);
    if (test) {
        cout << __LINE__ << " ->" << " Node: " << node->value << " Height: " << ret << endl;
    }
    return  ret;
}


int binaryTreeDiameter(BST *root) {
    if (root == nullptr) {
        return -1;
    }
    int Diameter = 0;
    int height = Height(root, Diameter);
    bool test = true;

    if (test) {
        cout << __LINE__ << " -> " << "Diameter :" << Diameter << endl;
        cout << __LINE__ << " -> " <<"Height :" << height << endl;
     }
    return (Diameter - 1);
}

void
test_diameter() {
    BST *curr = nullptr;
    int ret;
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
    ret = binaryTreeDiameter(curr);
    cout << "Output" << endl;
    cout << "Diameter: " << ret << endl;
}
/*
 *          Input
         10
        /  \
       /    \
      5     12
     / \   /  \
    3   8  11 15
               / \
             13  17

 Diameter ->  5

 */

#endif //GNU_DIAMETER_H

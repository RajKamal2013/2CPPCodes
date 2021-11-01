//
// Created by kamr on 10/31/2021.
//

#ifndef GNU_SUCCESSOR_H
#define GNU_SUCCESSOR_H

BST *
findSuccessor(BST *tree, BST *node) {
    stack<BST*> S;
    BST *curr, *prev, *last;
    S.push(tree);
    prev = last = nullptr;
    bool test = true;
    vector<int> arr = {};

    while(!S.empty()) {
        curr = S.top();

        /*
          * left is not null, we have not visited yet, prev, prev->left == curr or last.
          * prev->right == curr ,means last we visted the node and now left or right child.
          * curr->left != prev means, we are not self looping as we have successfully visited left
        */
        if ((curr->left != nullptr) && ((prev == nullptr) || (prev->left == curr) || (prev->right == curr)) && (curr->left != prev)) {
            S.push(curr->left);
        } else if (curr->left == nullptr) {
            S.pop();
            arr.push_back(curr->value);
            /* push the right we have visted the node is visted */
            if (curr->right != nullptr) {
                S.push(curr->right);
            }
            /* we found node */
            if (last == node) {
                if (test) {
                    cout << __LINE__ << "-> " << " We found node" << endl;
                    for (auto &data:arr) {
                        cout << data << " ";
                    }
                    cout << endl;
                }
                break;
            } else {
                last = curr;
            }

        } else if (curr->left == prev) {
            S.pop();
            arr.push_back(curr->value);
            /* push the right we have visted the node is visted */
            if (curr->right != nullptr) {
                S.push(curr->right);
            }
            /* we found node */
            if (last == node) {
                if (test) {
                    cout << __LINE__ << "-> " << " We found node" << endl;
                    for (auto &data:arr) {
                        cout << data << " ";
                    }
                    cout << endl;
                }
                break;
            } else {
                last = curr;
            }
        } else {
            /*
            S.pop();
            arr.push_back(curr->value);
            if (curr->right != nullptr) {
                S.push(curr->right);
            }
            if (last == node) {
                if (test) {
                    cout << __LINE__ << "-> " << " We found node" << endl;
                    for (auto &data:arr) {
                        cout << data << " ";
                    }
                    cout << endl;
                }
                break;
            } else {
                last = curr;
            }
            prev = curr;
             */
        }
        prev = curr;
    }
    /* we found self */
    if (curr == last) {
        if (test) {
            cout << __LINE__ << "-> " << " We could not found node" << endl;
            for (auto &data:arr) {
                cout << data << " ";
            }
            cout << endl;
        }
        return nullptr;
    } else {
        if (test) {
            cout << __LINE__ << "-> " << " We found node" << endl;
            for (auto &data:arr) {
                cout << data << " ";
            }
            cout << endl;
        }
        return curr;
    }
}

void
test_Successor() {
    BST *curr = nullptr;
    int ret;
    BST *node, *succ;
    vector<int> list;
    vector<int> res;


    BST *root = new BST(10);
    curr = root;
    list = {5, 12, 3, 8, 9, 6, 11, 15, 13, 17, 18, 2, 1};
    for (auto &data:list) {
        curr->insert(data);
    }
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    inOrderTraverse(root, res);
    node = curr->find(5);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    cout << "Successor for Node :" << node->value << " is to find ?" << endl;
    succ = findSuccessor(root, node);
    cout << "Output :" << endl;
    cout << "Successor of Node : " << node->value << " is :" << succ->value << endl;



    BST *root1 = new BST(1);
    curr = root1;
    res.clear();
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    inOrderTraverse(curr, res);
    node = curr->find(1);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    cout << "Successor for Node :" << node->value << " is to find ?" << endl;
    succ = findSuccessor(curr, node);
    cout << "Output :" << endl;
    if (succ != nullptr) {
        cout << "Successor of Node : " << node->value << " is :" << succ->value << endl;
    } else {
        cout << "Successor of Node : " << node->value << " Does not exist" << endl;
    }

    BST *root2 = new BST(2);
    root2->insert(3);
    curr = root2;
    res.clear();
    cout << "Input" << endl;
    cout << "Inorder" << endl;
    inOrderTraverse(curr, res);
    node = curr->find(2);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    cout << "Successor for Node :" << node->value << " is to find ?" << endl;
    succ = findSuccessor(curr, node);
    cout << "Output :" << endl;
    if (succ != nullptr) {
        cout << "Successor of Node : " << node->value << " is :" << succ->value << endl;
    } else {
        cout << "Successor of Node : " << node->value << " Does not exist" << endl;
    }
}


/*
 * Input
         10
        /  \
       /    \
      5     12
     / \   /  \
    3   8  11 15
               / \
             13  17

 successor of 8 ->  10


                  10
                  /  \
                 /    \
                5     12
               / \   /  \
              3   8  11 15
             /      \     / \
            2       9   13  17
           /        /         \
          1        6          18

 successor of 5 is 6
 */


#endif //GNU_SUCCESSOR_H

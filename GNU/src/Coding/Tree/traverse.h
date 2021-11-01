//
// Created by kamr on 10/30/2021.
//

#ifndef GNU_TRAVERSE_H
#define GNU_TRAVERSE_H


#include <stack>
#include <queue>

void
postOrderTraverse(BST *tree, vector<int> &array) {
    if (tree != nullptr) {
        postOrderTraverse(tree->left, array);
        postOrderTraverse(tree->right, array);
        array.push_back(tree->value);
    }
}

void
iterative_postOrderTraverse(BST *tree, vector<int> &array) {
    BST *prev, *curr;
    stack<BST*> S;
    prev = nullptr;
    bool test = true;


    S.push(tree);
    if (test) {
        cout << "Push :" << tree->value << endl;
    }
    while (!S.empty()) {
        if (test) {
            cout << __LINE__ << "- > " <<  "Size :" << S.size() << endl;
        }
        curr = S.top();
        if (test) {
            cout << __LINE__ << "- > " << "Top -> " << curr->value << endl;
            for (auto &data:array) {
                cout << data << " ";
            }
            cout << endl;
            if (prev)
                cout << __LINE__ << "- > " << "prev "  << prev->value << endl;
        }
        if ((curr->left != nullptr) &&
            //((prev == nullptr) || (prev->right == curr)) &&
            ((curr->left != prev) || (curr->right != prev))) {
            S.push(curr->left);
            if (test) {
                cout <<  __LINE__ << "- > " << "Push :" << curr->left->value << endl;
            }
            prev = curr;
        } else if (curr->left == nullptr) {
            S.pop();
            if (test) {
                cout << __LINE__ << "- > " << "Pop: " << curr->value << endl;
            }
            array.push_back(curr->value);
            prev = curr;
        } else if (curr->left == prev) {  // last time we popped left, now put right
            if (curr->right) {
                S.push(curr->right);
                if (test) {
                    cout << __LINE__ << "- > " << "Push :" << curr->right->value << endl;
                }
            }
            prev = curr;
        } else if(curr->right == prev) {
            S.pop();
            if (test) {
                cout << __LINE__ << "- > "<< "Pop: " << curr->value << endl;
            }
            array.push_back(curr->value);
            prev = curr;
        } else {
            if (curr->right) {
                S.push(curr->right);
                if (test) {
                    cout << __LINE__ << "- > " << "Push: " << curr->right->value << endl;
                }
            }
            prev = curr;
        }
    }
}

void
inOrderTraverse(BST *tree, vector<int> &array) {
    if (tree != nullptr) {
        inOrderTraverse(tree->left, array);
        array.push_back(tree->value);
        inOrderTraverse(tree->right, array);
    }
}

void
iterative_inOrderTraverse(BST *tree, vector<int> &array) {
    BST *prev, *curr;
    stack<BST*> S;
    prev = nullptr;
    bool test = false;


    S.push(tree);
    if (test) {
        cout << "Push :" << tree->value << endl;
    }
    // we will iterate till stack is not empty, till all the elements are not placed in stack
    while(!S.empty()) {
        if (test) {
            cout << "Size :" << S.size() << endl;
        }
        // get the top
        curr = S.top();

        // we have not visited left child
        if ((curr->left != nullptr) && ((prev == nullptr) || (prev->left == curr) || (prev->right == curr)) && (curr->left != prev)) {
            S.push(curr->left);
            if (test) {
                cout << "Push :" << curr->left->value << endl;
            }
            prev = curr;
        } else if (curr->left == nullptr) {  // we have encounter node with no left child,
            // visit right child
            S.pop();
            if (test) {
                cout << "Pop: " << curr->value << endl;
            }
            array.push_back(curr->value);
            if (curr->right) {
                S.push(curr->right);
                if (test) {
                    cout << "Push  :" << curr->right->value << endl;
                }
            }
            prev = curr;
        } else if (curr->left == prev) { // we have encounter last parent of last element popped
            S.pop();
            if (test) {
                cout << "Pop: " << curr->value << endl;
            }
            array.push_back(curr->value);
            if (curr->right) {
                S.push(curr->right);
                if (test) {
                    cout << "Push  :" << curr->right->value << endl;
                }
            }
            prev  = curr;
        } else {
            S.pop();
            if (test) {
                cout << "Pop: " << curr->value << endl;
            }
            array.push_back(curr->value);
            if (curr->right) {
                S.push(curr->right);
                if (test) {
                    cout << "Push  :" << curr->right->value << endl;
                }
            }
            prev  = curr;
        }
    }
}

void
preOrderTraverse(BST *tree, vector<int> &array) {
    if (tree != nullptr) {
        array.push_back(tree->value);
        preOrderTraverse(tree->left, array);
        preOrderTraverse(tree->right, array);
    }
}


void
test_traverse() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14};
    vector<int> res;

    for (auto &data:list) {
        root->insert(data);
    }
    cout << "Inorder" << endl;
    inOrderTraverse(root, res);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    iterative_inOrderTraverse(root, res);
    cout << "Iterative Inorder " << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    cout << "PostOrder" << endl;
    postOrderTraverse(root, res);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    /*
    iterative_postOrderTraverse(root, res);cout << "Iterative PostOrder " << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
     */

    cout << "PreOrder" << endl;
    preOrderTraverse(root, res);
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

}
#endif //GNU_TRAVERSE_H

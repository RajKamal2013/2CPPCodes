//
// Created by kamr on 10/29/2021.
//

#ifndef GNU_BST_H
#define GNU_BST_H

class BST {
private:
    BST &findMin() {
        if (left == nullptr) {
            return *this;
        } else {
            return left->findMin();
        }
    }

public:
    int value;
    BST *left;
    BST *right;

    BST(int val, BST* lt= nullptr, BST *rt= nullptr) {
        value = val;
        left = lt;
        right = rt;
    }

    BST &insert(int val) {
        if (this->value > val) {
            if (left != nullptr) {
                left->insert(val);
            } else {
                left = new BST(val);
            }
        } else {
            if (right != nullptr) {
                right->insert(val);
            } else {
                right = new BST(val);
            }
        }
        return *this;
    }

    bool contains(int val) {
        if (this->value == val) {
            return true;
        } else if (this->value > val) {
            if (left != nullptr) {
                return left->contains(val);
            } else {
                return false;
            }
        } else {
            if (right != nullptr) {
                return right->contains(val);
            } else {
                return false;
            }
        }
    }

    BST* find(int val) {
        if (this->value == val) {
            return this;
        } else if (this->value > val) {
            if (left != nullptr) {
                return left->find(val);
            } else {
                return nullptr;
            }
        } else {
            if (right != nullptr) {
                return right->find(val);
            } else {
                return nullptr;
            }
        }
    }

    int minimum() {
        return findMin().value;
    }

    BST &remove(int val, BST *parent = nullptr) {
        if ((this->value > val) && (left != nullptr)){
            left->remove(val, this);
        } else if ((this->value < val) && (right != nullptr)) {
            right->remove(val, this);
        } else if (this->value == value) {
            if ((left != nullptr) && (right != nullptr)) {
                this->value = right->findMin().value;
                right->remove(this->value, this);
            } else if (parent == nullptr) {  // normal case
                if (left != nullptr) {
                    this->value = this->left->value;
                    this->right = this->left->right;
                    this->left = this->left->left;
                } else if (right != nullptr) {
                    this->value = this->right->value;
                    this->right = this->right->right;
                    this->left = this->right->left;
                } else {
                    // only one node.
                }
            } else if (parent->left == this) {
                    parent->left = (left != nullptr)?left:right;
            } else if (parent->right == this) {
                    parent->right = (right != nullptr)?right:left;
            }
        } else {
            /* do nothing */
        }
        return *this;
    }

    void PrintInorder(BST *node, ostream &out) {
        if (node != nullptr) {
            PrintInorder(node->left, out);
            out << node->value << " " ;
            PrintInorder(node->right, out);
        }
    }

    void inorder(ostream &out = cout) {
            PrintInorder(this, out);
            out << endl;
    }
};

void
test_BST() {
    BST *btree = new BST(5);
    cout << "Inorder" << endl;
    btree->inorder();
    BST &temp = btree->remove(5);
    if (&temp != nullptr) {
        cout << "Removed data:" << temp.value << endl;
    }
    if (btree == nullptr) {
        cout << "btree is null";
    } else {
        cout << "Btree is not null: Inorder:" << endl;
        btree->inorder();
    }


    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14};
    for (auto &data:list) {
        root->insert(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
    cout << "Min: " << root->right->minimum() << endl;
    root->remove(12);
    cout << "Inorder" << endl;
    root->inorder();
    cout<< "Removing elements of BST" << endl;
    for (auto &data:list) {
        root->remove(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
}



#endif //GNU_BST_H

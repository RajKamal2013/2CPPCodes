//
// Created by kamr on 10/27/2021.
//

#ifndef GNU_BST_H
#define GNU_BST_H


/* need to fix the 139 return */


template<typename Comparable>
class BinarySearchTree
{
private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(Comparable &x, BinaryNode *lt, BinaryNode *rt) : element{x}, left{lt}, right{rt} {}
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };
    BinaryNode *root;

    void insert(Comparable &x, BinaryNode * &t) {
        if (t == nullptr) {

            t = new BinaryNode{x, nullptr, nullptr};
            cout << "inserted " << x << endl;
        } else if (t->element > x) {
            return insert(x, t->left);
        } else if (t->element < x) {
            return insert(x, t->right);
        } else {
            ;
        }
    }

    void insert(Comparable &&x, BinaryNode * &t) {
        if (t == nullptr) {
            cout << "inserted <&&L>" << x << endl;
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        } else if (t->element > x ) {
            return insert(std::move(x), t->left);
        } else if (t->element < x) {
            return insert(std::move(x), t->right);
        } else {
            ;
        }
    }

    BinaryNode *findMin(BinaryNode *t) {
        if (t == nullptr) {
            return nullptr;
        } else if (t->left == nullptr) {
            return t;
        } else {
            return findMin(t->left);
        }
    }

    BinaryNode *findMax(BinaryNode *t) {
        if (t != nullptr) {
            while (t->right != nullptr) {
                t = t->right;
            }
        }
        return t;
    }

    bool contains(Comparable &x, BinaryNode *t)  {
        if (t == nullptr) {
            return false;
        } else if (t->element > x) {
            return contains(x, t->left);
        } else if (t->element < x) {
            return contains(x, t->right);
        } else {
            return true;
        }
    }

    void makeEmpty(BinaryNode * &t) {
        if ( t!= nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    void printTree(BinaryNode *t, ostream &out)  {
        if (t != nullptr) {
            printTree(t->left, out);
            out << t->element << " ";
            printTree(t->right, out);
        }
    }

    BinaryNode* clone(BinaryNode *t)  {
        if (t == nullptr) {
            return nullptr;
        } else {
            return  new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }
    }

    void remove(Comparable &x, BinaryNode *&t) {
        if (t == nullptr) {
            return;
        }

        if (t->element > x) {
            remove(x, t->left);
        } else if (t->element < x) {
            remove (x, t->right);
        } else {
            if ((t->right != nullptr) && (t->left != nullptr)) {
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            } else {
                BinaryNode *oldNode = t;
                t = (t->left != nullptr) ? t->left :t->right;
                delete oldNode;
            }
        }
    }

public:
    BinarySearchTree() : root{nullptr} {}
    BinarySearchTree(BinarySearchTree &rhs) : root{nullptr} {
        root = clone(rhs.root);
    }
    BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root} {
        rhs.root = nullptr;
    }

    ~BinarySearchTree() {
        makeEmpty();
    }

    BinarySearchTree & operator=(BinarySearchTree &rhs) {
        BinarySearchTree copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    BinarySearchTree & operator=(BinarySearchTree &&rhs) {
        std::swap(root, rhs.root);
        return  *this;
    }

    Comparable &findMax()  {
        return findMax(root)->element;
    }

    Comparable &findMin() {
        return  findMin(root)->element;
    }

    bool contains (Comparable &x) {
        return contains(x, root);
    }

    bool isEmpty() {
        return (root == nullptr);
    }

    void makeEmpty() {
        makeEmpty();
    }

    void printTree(ostream &out = cout) {
        if (isEmpty()) {
            out << "BST is empty";
        } else {
            printTree(root, out);
        }
    }

    void insert(Comparable & x) {
        insert(x, root);
    }

    void insert(Comparable &&x) {
        insert(std::move(x), root);
    }

    void remove(Comparable & x) {
        remove(x, root);
    }
};


void test_BST()
{
    BinarySearchTree<int> t;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = 0; i < 25; i++)
        t.insert( i );

    cout << "Insert Complete" << endl;
    t.printTree();
    t.insert(30);
    t.insert(27);
    t.printTree();
    cout << endl;
    i = 20;
    t.remove(i);
    t.printTree();
    cout << "Done" << endl;
   // t.printTree();

    //for( i = 1; i < NUMS; i+= 2 )
      //  t.remove( i );

}


#endif //GNU_BST_H

#include<iostream>
#include <vector>
#include <iterator>
#include <queue>
#include "treeNode.h"
using namespace std;

template <class T>
class BTree {
  public:
    BTree() {
      root = NULL;
    };

    ~BTree() {
      m_destroy();
    };

    virtual void insert(T value) {
      m_insert(root, value);
    };

    virtual Node<T>* search(T value) {
      return m_search(root, value);
    };

    virtual Node<T>* remove(T value) {
      return m_remove(root, value);
    };

/*
    virtual bool operator== (BTree<T> &other) {
      return m_equal(root, other.first());
    }; 

    void bool operator= (BTree<T> &other) {
      m_assign(root, other.first());
    };
*/

    virtual bool operator< (BTree<T> &other) {
      return (root->getData() < other.getRoot()->getData());
    };

    virtual void inorder_traversal() {
      inorder(root);
    };

    virtual void preorder_traversal() {
      preorder(root);
    };

    virtual void postorder_traversal() {
      postorder(root);
    };

    virtual void levelorder_traversal() {
      levelorder(root);
    };

    virtual int size() {
      return m_size(root);
    };

    Node<T>* minimum (Node<T> *head) {
      Node<T> *temp = head;
      Node<T> *ptr = head;
      if (root == NULL) {
        cout << "Error: minimum(): Root is NULL " << endl;
        return NULL;
      } 
      while (temp != NULL) {
        ptr = temp;
        temp = temp->getLeft();
      }
      return  ptr;
    };

    Node<T>* maximum(Node<T> *head) {
      Node<T> *temp = head;
      Node<T> *ptr = head;
      if (root == NULL) {
        cout << "Error: maximum(): Root is NULL " << endl;
        return NULL;
      } 
      while (temp != NULL) {
        ptr = temp;
        temp = temp->getRight();
      }
      return ptr;
    };

    Node<T>*& getRoot() {
      return root;
    };

  protected:
    Node<T> *root;

    void m_destroy(Node<T>*& node) {
      if (node != NULL) {
        m_destroy(node->getLeft());
        m_destroy(node->getRight());
        delete node;
      }
    };

    void  m_insert(Node<T> *&node, T data) {
      if (node == NULL) {
        node = new Node<T>(data);
      } else if (node->getData() > data) {
        m_insert(node->getLeft(), data);
      } else {
        m_insert(node->getRight(), data);
      }
    };

  
    Node<T>* m_remove(Node<T> *&node, T value) {
      Node<T> *temp = m_search(root, value);
      Node<T> *ptr;
  
      if (temp == NULL) {
        cout << "Error : m_remove(): Data to be Deleted Not Found" << endl;
        return NULL;
      }

      if (node == NULL) {
        cout << "Error : m_remove(): Root is NULL " << endl;
        return NULL;
      };
      
      if (node->getData() > value) {
        node->setLeft(m_remove(node->getLeft(), value));
      } else if (node->getData() < value) {
        node->setRight(m_remove(node->getRight(), value));
      } else {
        if (node->getLeft() == NULL) {
          ptr = node->getRight();
          delete (node);
          return ptr;
         } else if (node->getRight() == NULL) {
           ptr = node->getLeft();
           delete(node);
           return ptr;
         } else {
           ptr = minimum(node->getRight());
           node->setData(ptr->getData());
           node->setRight(m_remove(node->getRight(), ptr->getData()));
         }
      }
      return node;
    };

    Node<T>* m_search(Node<T> *node, T value) {
      if (node == NULL) {
        return NULL;
      }
      if (node->getData() == value) {
        return node;;
      } else if (node->getData() < value) {
        return m_search(node->getRight(), value);
      } else {
        return m_search(node->getLeft(), value);
      }
    };

    void inorder(Node<T> *node) {
      if (node != NULL) {
        inorder(node->getLeft());
        cout<< node->getData() << " ";
        inorder(node->getRight());
      }
    };

    void preorder(Node<T> *node) {
      if (node != NULL) {
        cout<< node->getData() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
      }
    };

    void postorder(Node<T> *node) {
      if (node != NULL) {
        postorder(node->getLeft());
        postorder(node->getRight());
        cout<< node->getData() << " ";
      }
    };

    void levelorder(Node<T> *node) {
      Node<T> *temp;
      queue< Node<T>* > Q;
      vector<T> V;

      if (node == NULL) 
        return;

      Q.push(node);
      Q.push(NULL);

      while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (temp != NULL) {
          V.push_back(temp->getData());

          if (temp->getLeft() != NULL) {
           Q.push(temp->getLeft());
          }
          if(temp->getRight() != NULL) {
            Q.push(temp->getRight());
          }
        } else {
          if (!Q.empty()) {
            Q.push(NULL);
          }
        }
      }

      typename vector<T>::iterator itr;

      for (itr = V.begin(); itr != V.end(); itr++) {
          cout << *itr << " ";
      }

      cout << endl;
    };
      /*
    int height(Node<T> *&node) {
    };

    int depth(Node<T> *&node) {
    };
    */

    int m_size(Node<T> *node) {
      if (node == NULL) {
        return 0;
      }
      int leftsize, rightsize;
      leftsize = (node->getLeft() == NULL) ? 0 : m_size(node->getLeft());
      rightsize = (node->getRight() == NULL) ? 0 : m_size(node->getRight());
      return (1 + (leftsize + rightsize)); 
    };

};


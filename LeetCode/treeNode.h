#include <iostream>
using namespace std;

/*
 * Class for basic Tree Node
 */
template<class T>
class Node {
public:

  Node() {
    left = right = NULL;
  };

  Node(T value) :data(value), left(NULL), right(NULL) {
  };

  void operator= (const Node<T> &other) {
    data = other.data;
  };

  bool operator< (T &other) {
    return (data < other);
  };

  T getData() {
    return this->data;
  };

  Node<T>*& getLeft() {
    return this->left;
  };

  Node<T>*& getRight() {
    return this->right;
  };

  void setData(T data) {
    this->data = data;
  };

  void setLeft(Node<T> *left) {
    this->left = left;
  };

  void setRight(Node<T> *right) {
    this->right = right;
  };

  ~Node() {
  };

private: 
  T data;
  Node *left, *right;
};

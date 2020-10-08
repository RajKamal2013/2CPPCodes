#include "LeetCode/binary_tree.h"

int main() {
  int arr[] = {45, 30, 60, 20, 40, 10, 5, 15, 50, 48, 55, 80, 100, 90, 120};
  int data;
  BTree<int> *BST = new BTree<int>();
  Node<int> *node;
  int arr_size = sizeof(arr) / sizeof(int);
  cout<< "Size of array :" << arr_size << endl;

  /************************Insertion Test **********************/
  for (int i = 0; i < arr_size; i++) {
    BST->insert(arr[i]);
  }

  /************************Traversal Test************************/
  cout<<"Preorder :" << endl;
  BST->preorder_traversal();
  cout<<endl<<"Postorder :" << endl;
  BST->postorder_traversal();
  cout<<endl<<"Inorder :" << endl;
  BST->inorder_traversal();
  cout << endl;
  cout << "Level Order Traversal " << endl; 
  BST->levelorder_traversal();
  cout << "Size of binary Tree :" << BST->size() <<endl;

  /*************************Min Max Test ***********************/
  node = BST->maximum(BST->getRoot());
  cout <<"maximum : " << node->getData() << endl;
  node = BST->minimum(BST->getRoot());
  cout <<"minimum : " << node->getData() << endl;
  cout << endl;


  /************************Deletion Test ***********************/
  data = 45;
  node = BST->remove(data);
  cout << "Node removed : " << data << " ROOT now : " << node->getData() << endl;
  data = 20;
  node = BST->remove(data);
  cout << "Node removed : " << data << " ROOT now : " << node->getData() << endl;
  data = 80;
  node = BST->remove(data);
  cout << "Node removed : " << data << " ROOT now : " << node->getData() << endl;
  data = 90;
  node = BST->remove(data);
  cout << "Node removed : " << data << " ROOT now : " << node->getData() << endl;
  cout<<"Preorder :" << endl;
  BST->preorder_traversal();
  cout<<endl<<"Postorder :" << endl;
  BST->postorder_traversal();
  cout<<endl<<"Inorder :" << endl;
  BST->inorder_traversal();
  cout << endl;
  cout << "Level Order Traversal " << endl; 
  BST->levelorder_traversal();
  node = BST->maximum(BST->getRoot());
  cout <<"maximum : " << node->getData() << endl;
  node = BST->minimum(BST->getRoot());
  cout <<"minimum : " << node->getData() << endl;
  cout << "Size of binary Tree :" << BST->size() <<endl;
  cout << endl;

  /*************************** Search Test *****************************/
  data = 60;
  node = BST->search(data);
  if (node != NULL) {
    cout << "Data is present: " << node->getData() << endl;
  }else {
    cout << "Data is not present : " << data << endl;
  }
  data = 90;
  node = BST->search(data);
  if (node != NULL) {
    cout << "Data is present: " << node->getData() << endl;
  }else {
    cout << "Data is not present : " << data << endl;
  }

  /******************************Level Order Testing  ********************/
  cout << "Level Order Traversal " << endl; 
  BST->levelorder_traversal();

  return 0;

}

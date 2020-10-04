#include<iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

void insert(node **root,int data);
{
  node *new_node=new node;
  new_node->data=data;
  new_node->right=

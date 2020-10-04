/*
 * to test the new() 
 */
#include <iostream>
using namespace std;

struct edge {
	int src;
	int dest;
	int weight;
};

int main() {
	edge *node1 = NULL;
	node1 = new edge();

	node1->src = 1;
	node1->dest = 2;
	node1->weight = 3;

	cout << "(" << node1->src <<"," << node1->dest << ","<< node1->weight << ")"<< endl;	
	return 0;
}

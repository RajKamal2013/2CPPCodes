/*
 * Sample Code for Topological Sorting (DAG)
 * Author :- Raj Kamal<rajkamal2013@gmail.com>
 */

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define	WHITE	0
#define GREY	1
#define BLACK	2
#define NIL	-1

/*
 * DEBUG	for checking entry points
 * DEBUG1	for DFS
 * DEBUG2	for Topological Sort
 */

class Graph {
	public:
		int V;
		list<int> *AdjList;
		int time;
		vector<int> color;
		vector<int> discover;
		vector<int> finish;
		stack<int> Stack;
		void DFS_VISIT(int src);
	public:
		Graph(int V);
		void display_graph();
		void add_edge(int src, int dest);
		void Topological_Sort(int vertex);
};

Graph :: Graph(int V) {
#ifdef DEBUG
	printf("Inside Graph() with %d.\n", V);
#endif
	this->V	= V;
	AdjList	= new list<int> [V]; 
	color.resize(V);
	discover.resize(V);
	finish.resize(V);
#ifdef DEBUG
	printf("Leaving Graph().\n");
#endif
}

void Graph :: add_edge(int src, int dest) {
#ifdef DEBUG
	printf("Inside add_edge() with (src, dest):(%d, %d)\n", &src, &dest);
#endif
	AdjList[src].push_back(dest);
#ifdef DEBUG
	printf("Leaving add_edge().\n");
#endif
}

void Graph :: display_graph() {
#ifdef DEBUG
	printf("Inside display_graph().\n");
#endif
	list<int> :: iterator itr;
	for (int i = 0; i < V; i++) {
		cout << i << "-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << *itr << "-->";
		}
		cout << "NULL" << endl;
	}
#ifdef DEBUG
	printf("Leaving display_graph().\n");
#endif
}

void Graph :: Topological_Sort(int src) {
#ifdef DEBUG
	printf("Inside Topological Sort().\n");
#endif
	int i;
	for (i = 0; i < V; i++) {
		color[i]	= WHITE;
		discover[i]	= NIL;
		finish[i]	= NIL;
	}
	time	= 0;
	i = src;
	do {
		if(color[i] == WHITE) {
			DFS_VISIT(i);
		}
		i = (i + 1)%V;
	}while(i != src);
	cout << "Topological Ordering : "<<endl;
	while(!Stack.empty()) {
		cout << Stack.top() << "("<<finish[Stack.top()]<<","<<discover[Stack.top()]<<")"<<endl;
		Stack.pop();
	}
#ifdef DEBUG
	printf("Leaving Topological Sort().\n");
#endif
}

void Graph :: DFS_VISIT(int src) {
#ifdef DEBUG
	printf("Inside DFS_VISIT().\n");
#endif
	list<int> :: iterator itr;
	time		= time + 1;
	discover[src]	= time;
	color[src]	= GREY;
	
	for (itr = AdjList[src].begin(); itr != AdjList[src].end(); itr++) {
		if (color[*itr] == WHITE) {
			DFS_VISIT(*itr);
		}
	}
	
	time		= time + 1;
	finish[src]	= time;
	Stack.push(src);
#ifdef DEBUG
	printf("Leaving DFS_VISIT() with %d.\n", src);
#endif
}

int main() {
#ifdef DEBUG
	printf("Inside main().\n");
#endif
	int V, src, dest;
	Graph *G;
	cout << "Enter the number of vertices .\n";
	cin >> V;
	G = new Graph(V);
	
	cout << "Enter EOF to quit().\n";
	cout << "Enter the src and destination of the edge :"<<endl;
	while(scanf("%d %d", &src, &dest)!=EOF) {
		G->add_edge(src, dest);
	}
	G->display_graph();
	G->Topological_Sort(0);
#ifdef DEBUG
	printf("Leaving main().\n");
#endif
	return 0;
}				

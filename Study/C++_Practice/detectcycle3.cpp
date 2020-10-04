/*
 * Code to detect cycle in Undirected Graph using DFS
 * Author:Raj Kamal<rajkamal2013@gmail.com>
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <vector>
using namespace std;

#define	WHITE	0
#define	GREY	1
#define BLACK	2

class Graph {
	private:
		int V;
		list<int> *AdjList;
		vector<int> color;
		int DFS_VISIT(int src, int parent);
	public:
		Graph(int vertex);
		void add_edge(int src, int dest);
		void display_graph();
		void cycle();
};

Graph :: Graph(int V) {
	this->V = V;
	AdjList = new list<int>[V];
	color.resize(V);
}

void Graph :: add_edge(int src, int dest) {
	AdjList[src].push_back(dest);
	AdjList[dest].push_back(src);
}

void Graph :: display_graph() {
	list<int> :: iterator itr;
	for (int i = 0; i < V; i++) {
		cout << i <<"-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << *itr <<"<-->";
		}
		cout <<"NULL"<<endl;
	}
}

int Graph :: DFS_VISIT(int src, int parent) {
	cout << "DFS VISIT with ("<<src<<","<<parent<<endl;
	int ret = 0;
	list<int> :: iterator itr;
	color[src] = GREY;
	for(itr = AdjList[src].begin(); itr != AdjList[src].end(); itr++) {
		if (color[*itr] == WHITE) {
			ret = DFS_VISIT(*itr, src);
		}
		else {
			if(*itr != parent) {
				ret = 1;
				cout << "Cycle found between :" <<"("<<src<<","<<*itr<<")"<<endl;
				break;
			}
		}
	}
	return ret;
}

void Graph :: cycle() {
	int ret = 0;
	for (int i = 0; i < V; i++) {
		color[i] = WHITE;
	}
	for (int i = 0; i < V; i++) {
		if (color[i] == WHITE) {
			ret = DFS_VISIT(i, -1);
		}
		if (ret == 1){ 
			cout << "Cycle found between :" <<endl;
			break;
		}
	}
}
			
int main() {
	int V, src, dest;
	Graph *G;
	cout << "Enter the Number of vertices .\n";
	cin >>V;
	G = new Graph(V);
	cout << "Enter the src and destination of edge.\n";
	cout << "Enter EOF to exit.\n";
	while (scanf("%d %d", &src, &dest) != EOF) {
		G->add_edge(src, dest);
	}
	G->display_graph();
	G->cycle();
	return 0;
}

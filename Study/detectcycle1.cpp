/*
 * Sample Code to Detect Cycle in Directed Graph using DFS
 * Raj Kamal <rajkamal2013@gmail.com>
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
using namespace std;

#define	WHITE	0
#define	GREY	1
#define BLACK	2

struct Graph {
	private:
		int vertex;
		list<int> *AdjList;
		vector<int> color;
		int DFS_VISIT(int v);
	public:
		Graph(int vertex);
		void add_edge(int src, int dest);
		void display_graph();
		void cycle();
};

Graph :: Graph(int vertex) {
	this->vertex = vertex;
	AdjList = new list<int>[vertex];
	color.resize(vertex);
}

void Graph :: add_edge(int src, int dest) {
	AdjList[src].push_back(dest);
}

void Graph :: display_graph() {
	list<int> :: iterator itr;
	for (int i = 0;i < vertex; i++) {
		cout<<i<<"-->";
		for(itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout<<*itr<<"<-->"<<endl;
		}
		cout << endl;
	}
}

void Graph :: cycle() {
	int ret;
	for (int i = 0; i < vertex; i++) {
		color[i] = WHITE;
	}
	for (int i = 0; i < vertex; i++) {
			ret = DFS_VISIT(i);
			if (ret == 1) {
				cout << "CYCLE FOUND" <<endl;
				break;
			}
	}
}	

int Graph :: DFS_VISIT(int src) {
	list<int> :: iterator itr;
	int ret = 0;
	color[src] = GREY;
	for (itr = AdjList[src].begin(); itr != AdjList[src].end(); itr++) {
		if (color[*itr] == GREY) {
			ret = 1;
			break;
		}
		if (color[*itr] == WHITE) {
			ret = DFS_VISIT(*itr);
		}
	}
	color[src] = BLACK;
	return ret;
}	


int main() {
	Graph *G;
	int vertex, src, dest;
	cout << "Enter the number of vertex.\n";
	cin >> vertex;
	G = new Graph(vertex);
	cout << "Press EOF to stop input.\n";
	cout << "Enter src and dest of the edge.\n";
	while(scanf("%d %d", &src, &dest) != EOF) {
		G->add_edge(src, dest);
	}
	G->display_graph();
	G->cycle();
	return 0;
}


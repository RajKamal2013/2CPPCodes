/*
 * Sample Code to detect Bipartite Graph 
 * Author :- Raj Kamal<rajkamal2013@gmail.com>
 */
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Graph {
	int V;
	list<int> *AdjList;
	vector<int> color;
	queue<int> Q;
	public:
		Graph(int V);
		void add_edge(int src, int dest);
		void display_graph();
		int IsBipartite(int src);
};

Graph :: Graph(int V) {
	this->V = V;
	AdjList = new list<int> [V];
	color.resize(V);
};

void Graph :: add_edge(int src, int dest) {
	AdjList[src].push_back(dest);
}

void Graph :: display_graph() {
	list<int> :: iterator itr;
	for (int i = 0; i < V; i++) {
		cout << i << "-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end() ; itr++) {
			cout << *itr <<"<-->";
		}
		cout << "NULL" << endl;
	}
}

int Graph :: IsBipartite(int src) {
	list <int> :: iterator itr;
	int top;
	for (int i = 0; i < V; i++) {
		color[i] = -1;
	}
	color[src] = 1; 
	Q.push(src);
	while(!Q.empty()) {
		top = Q.front();
		for (itr = AdjList[top].begin(); itr != AdjList[top].end(); itr++) {
			if(color[*itr] == -1) {
				color[*itr] = 1 - color[top];
				Q.push(*itr);
			}
			else {
				if(color[*itr] == color[top]) {
					cout << "Not Bipartite "<<endl;
					return -1;
				}
			}
		}
		 Q.pop();
	}
	return 0;
}

int main() {
	int V, src, dest, result;
	Graph *G;
	cout << "Enter the Number of vertices .\n";
	cin >> V;
	G	= new Graph(V);
	cout << "Enter EOF to Quit.\n";
	cout << "Enter the src and destination of the edge.\n";
	while (scanf("%d %d", &src, &dest)!= EOF) {
		G->add_edge(src, dest);
	}
	G->display_graph();
	result	= G->IsBipartite(0);
	if (result == 0) {
		printf ("Bipartite Graph.\n");
	}
	else {
		cout <<" Not Bipartite Graph.\n";
	}
	return 0;
}

	

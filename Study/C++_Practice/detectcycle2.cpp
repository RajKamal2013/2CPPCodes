/*
 * Detect cycle in undirected graph using union find algorithm.
 * Raj Kamal<rajkamal2013@gmail.com>
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

struct Edge{
	int src;
	int dest;
};

class Graph {
	private:
		int V;
		int E;
		Edge *edge;
		list<int> *AdjList;
		vector<int> color;
		void create_edge();
		void display_edge();
		/* union and find algorithm APIs */
		vector<int> parent;
		vector<int> rank;
		int Find(int x);
		void Union(int x, int y);
		void MakeSet(int x); 
	public:
		Graph(int vertex);
		void add_edge(int src, int dest);
		void display_graph();
		void cycle();
};

Graph :: Graph(int V) {
#ifdef DEBUG
	printf("Inside Graph().\n");
#endif
	this->V = V;
	this->E = 0;
	AdjList = new list<int> [V];
	color.resize(V);
#ifdef DEBUG
	printf("Leaving Graph().\n");
#endif
}

void Graph :: add_edge(int src, int dest) {
#ifdef DEBUG
	printf("Inside add_edge().\n");
#endif
	AdjList[src].push_back(dest);
	E++;
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
		cout << i <<"-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << *itr << "<-->" ;
		}
		cout << "NULL"<<endl;
	}
#ifdef DEBUG
	printf("Leaving display_graph().\n");
#endif
}

void Graph :: create_edge() {
#ifdef DEBUG
	printf("Inside create_edge().\n");
#endif
	int j = 0;
	edge = new Edge[V];
	list<int> :: iterator itr;
	for (int i = 0; i < V; i++) {
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			edge[j].src = i;
			edge[j].dest = *itr;
			j++;
		}
	}
#ifdef DEBUG
	printf("Leaving create_edge().\n");
#endif
}

void Graph :: display_edge() {
#ifdef DEBUG
	printf("Inside display_edge().\n");
#endif
	cout << "V = " <<V << "E = "<< E <<endl; 
	for (int i = 0; i < E; i++){
		cout<<i+1<<"."<<"("<<edge[i].src<<","<<edge[i].dest<<")"<<endl;
	}
#ifdef DEBUG
	printf("Leaving display_edge().\n");
#endif
}

void Graph :: MakeSet(int x) {
#ifdef DEBUG
	printf("Inside MakeSet().\n");
#endif
	parent[x] = -1;
	rank[x] = 0;
#ifdef DEBUG
	printf("Leaving MakeSet().\n");
#endif
}

int Graph :: Find(int x) {
#ifdef DEBUG
	printf("Inside Find.\n");
#endif
	if (parent[x] == -1) {
		return x;
	}
	else {
		return Find(parent[x]);
	}
#ifdef DEBUG
	printf("Leaving Find().\n");
#endif
}

void Graph :: Union(int x, int y) {
#ifdef DEBUG
	printf("Inside Union().\n");
#endif
	int xRoot, yRoot;
	xRoot = Find(x);
	yRoot = Find(y);
	if(xRoot == yRoot) {
		return;
	}
	else {
		if (rank[xRoot] > rank[yRoot]) {
			parent[yRoot] = xRoot;
			rank[xRoot]   = rank[xRoot] + 1; 
		}
		else if (rank[xRoot] < rank[yRoot]) {
			parent[xRoot]	= yRoot;
			rank[yRoot]	= rank[yRoot] + 1;
		}
		else {
			parent[xRoot]	= yRoot;
			rank[xRoot]	= rank[xRoot] + 1;
		}
	}
#ifdef DEBUG
	printf("Leaving Union().\n");
#endif
}

void Graph :: cycle() {
#ifdef DEBUG
	printf("Inside cycle().\n");
#endif
	int xRoot, yRoot;
	rank.resize(V);
	parent.resize(V);
	for (int i = 0; i < V; i++) {
		MakeSet(i);
	}
	create_edge();
	display_edge();
	for (int i = 0; i < E; i++) {
		xRoot = Find(edge[i].src);
		yRoot = Find(edge[i].dest);
		if (xRoot == yRoot) {
			cout << "Cycle Found in Graph Between ("<<edge[i].src<<","<<edge[i].dest<<")"<<endl;
			break;
		}
		else 
			Union(edge[i].src, edge[i].dest);
	}
#ifdef DEBUG
	printf("Leaving cycle().\n");
#endif
}	

int main() {
#ifdef DEBUG 
	printf("Inside main().\n");
#endif
	Graph *G;
	int vertex, src, dest;
	cout<< "Enter the number of vertices.\n";
	cin>>vertex;
	G = new Graph(vertex);
	cout<<"Enter the src and destination of the edges.\n";
	cout<<"Press EOF to exit.\n";
	while(scanf("%d %d",&src, &dest) != EOF) {
		G->add_edge(src, dest);
	}
	G->display_graph();
	G->cycle();
#ifdef DEBUG 
	printf("Leaving main().\n");
#endif
}

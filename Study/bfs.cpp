/*
 * BFS implementation in C++
 * Raj Kamal <rajkamal2013@gmail.com>
 */
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define NIL -1

class Graph {
	private:
		int vertex;
		list<int> *AdjList;
		vector<int> color;
		vector<int> d;
		vector<int> pi;
		queue<int> q;
	public:
		Graph(int V);
		void add_edge(int src, int dest);
		void display_graph();
		void BFS(int src);
		void print_path(int src, int dest);
};

Graph :: Graph(int V) {
#ifdef DEBUG
	printf("Inside the Graph().\n");
#endif
	this->vertex = V;
	AdjList = new list<int>[vertex];
	d.resize(vertex);
	pi.resize(vertex);
	color.resize(vertex);
#ifdef DEBUG
	printf("Leaving the Graph().\n");
#endif
}

void Graph :: add_edge(int src, int dest) {
#ifdef DEBUG
	printf("Inside add_edge().\n");
#endif
	AdjList[src].push_back(dest);
#ifdef DEBUG
	printf("Leaving add_edge().\n");
#endif
}

void Graph :: display_graph() {
#ifdef DEBUG
	printf("Inside the display_graph().\n");
#endif
	list<int>::iterator itr;
	for (int i = 0 ;i < vertex; i++) {
		cout<<i<<"-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout <<*itr<<"<-->";
		}
		cout<<endl;
	}
#ifdef DEBUG
	printf("Leaving the display_graph().\n");
#endif
}

void Graph :: BFS(int src) {
#ifdef DEBUF
	printf("Inside BFS().\n");
#endif
	int v;
	for (int i =0; i < vertex; i++){
		color[i]	= WHITE;
		d[i]	= 0;
		pi[i]	= NIL;
	} 
	list<int>::iterator itr;
	color[src]	= GREY;
	d[src]		= 0;
	pi[src]		= NIL;
	q.push(src);
	cout<<"BFS Visit from source : "<< src<<endl;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(itr = AdjList[v].begin(); itr != AdjList[v].end(); itr++) {
			if(color[*itr] == WHITE) {
				color[*itr] = GREY;
				d[*itr] = d[v] + 1;
				pi[*itr] = v;
				q.push(*itr);
			}
		}	
		color[v] = BLACK;
		cout<<v <<"----";
	}
	cout <<endl;
#ifdef DEBUG
	printf("Leaving BFS().\n");
#endif	
}

void Graph :: print_path(int src, int dest) {
	if (dest == src) 
		cout << dest ;
	else if (pi[dest] == NIL)
		cout << "No path from "<<src<<"to"<< dest<<endl;
	else
		print_path(src, pi[dest]);
}
				
int main() {
#ifdef DEBUG
	printf("Inside main().\n");
#endif
	int vertex, src, dest;
	Graph *G;
	cin >> vertex;
	G = new Graph(vertex);
	G->add_edge(0,1);
	G->add_edge(1,2);
	G->add_edge(2,3);
	G->add_edge(3,0);
	G->add_edge(1,3);
	G->add_edge(2,0);
	G->display_graph();
	G->BFS(1);
	G->print_path(0,2);
#ifdef DEBUG
	printf("Leaving main().\n");
#endif
	return 0;
}

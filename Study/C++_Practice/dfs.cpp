#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

#define	NIL	-1
#define	WHITE	0
#define	GREY	1 
#define	BLACK	2

void display_begin(char *str) {
	cout << "--------------------------"<<str<<"------------------------"<<endl;
}
void display_end() {
	cout <<"------------------------------------------------------------"<<endl;
}
struct Graph {
	private:
		int vertex;
		list<int> *AdjList;
		vector<int> color;
		vector<int> discover;
		vector<int> finish;
		vector<int> pi;
		void DFS_VISIT(int v);
		int time;
	public:
		Graph(int vertex);
		void add_edge(int src, int dest);
		void display_graph();
		void DFS();
		void print_path(int src, int dest);
};

Graph :: Graph(int vertex) {
#ifdef DEBUG
	printf ("Inside Graph().\n");
#endif
	this->vertex = vertex;
	AdjList = new list<int>[vertex];
	color.resize(vertex);
	discover.resize(vertex);
	finish.resize(vertex);
	pi.resize(vertex);
#ifdef DEBUG
	printf ("Leaving Graph().\n");
#endif

}

void Graph :: add_edge(int src, int dest) {
#ifdef DEBUG
	printf ("Inside add_edge().\n");
#endif
	AdjList[src].push_back(dest);
#ifdef DEBUG
	printf ("Leaving add_edge().\n");
#endif
}

void Graph :: display_graph() {
#ifdef DEBUG
	printf("Inside display_edge().\n");
#endif
	display_begin("GRAPH");
	list<int>::iterator itr;
	for (int i = 0; i < vertex; i++) {
		cout << i <<"--->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << *itr <<"<-->";
		}
		cout << endl;
	}
	display_end();
#ifdef DEBUG
	printf("Leaving display_edge().\n");
#endif
}

void Graph :: DFS() {
#ifdef DEBUG
	printf("Inside DFS().\n");
#endif
	display_begin("DFS");
	for (int i = 0; i < vertex; i++) {
		color[i]	= WHITE;
		discover[i]	= NIL;
		finish[i]	= NIL;
		pi[i]		= NIL;
	}
	time = 0;
	for (int i = 0; i < vertex; i++) {
		if (color[i] == WHITE) {
			DFS_VISIT(i);
		}
	}
	display_end();
#ifdef DEBUG
	printf("Leaving DFS().\n");
#endif
}

void Graph :: DFS_VISIT(int src) {
#ifdef DEBUG
	printf ("Inside DFS_VISIT().\n");
#endif
	list<int> :: iterator itr;
	time = time + 1;
	color[src] = GREY;
	discover[src] = time;
	cout << "Vertex : "<< src << "Discover Time : " << time << endl;
	for (itr = AdjList[src].begin(); itr != AdjList[src].end(); itr++) {
		if (color[*itr] == WHITE) {
			pi[*itr] = src;
			DFS_VISIT(*itr);
		}
	}
	color[src] = BLACK;
	time = time + 1;
	finish[src] = time;
	cout << "Vertex : " << src << " : Finish Time : " << time << endl;
#ifdef DEBUG
	printf("Leaving DFS_VISIT)().\n");
#endif
}
	
void Graph :: print_path(int src, int dest) {
#ifdef DEBUG
	printf("Inside print_path().\n");
#endif
	if (dest == src) {
		cout << src << "-->";
	}
	else if(pi[dest] == NIL) {
		cout << "NO path from " << src << dest << endl;
	}
	else {
		print_path(src, pi[dest]);
	}
	if (dest != src) {
		cout << dest <<"-->";
	}
#ifdef DEBUG
	printf("Leaving print_path().\n");
#endif
}
   	
int main() {
#ifdef DEBUG
	printf ("Inside main().\n");
#endif
	int vertex, choice, src, dest;
	Graph *G;
	display_begin("Input");
	cout << "Enter the number of vertices in the Graph.\n";
	cin >> vertex;
	G = new Graph(vertex);
	cout << "Press ctrl + D to quit" << endl;
	cout << "Enter src and dest of the edge" << endl;
	while (scanf("%d %d", &src, &dest) != EOF) {
		G->add_edge(src, dest);
	}
	display_end();
	G->display_graph();
	G->DFS();
	display_begin("Input");
	cout << "Press ctrl + D to quit" <<endl;
	cout << "Enter src and dest to get the path printed.\n";
	while (scanf("%d %d", &src, &dest) != EOF) {
		display_begin("PRINT PATH");
		G->print_path(src, dest);
		cout << endl;
		display_end();
	}
	display_end();
	return 0;
#ifdef DEBUG
	printf("Leaving main().\n");
#endif	
}
	

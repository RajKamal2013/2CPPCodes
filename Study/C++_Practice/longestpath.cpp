/* 
 * Sample Code to find the longest path in DAG
 * AUTHOR :- Raj Kamal<rajkamal2013@gmail.com>
 */
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

struct AdjNode {
	int dest;
	int weight;
};
/* 
 * DEBUG	Check Entry Points 
 * DEBUG1	Check DFS 
 * DEBUG2	Check Topological Sort
 * DEBUG3	Check Longest Path
 */

#define NINF	INT_MIN
#define NIL	-1
#define	WHITE	0
#define GRAY	1
#define BLACK	2
class Graph {
	private:
		int V;
		list<AdjNode> *AdjList;
		vector<int> color;
		vector<int> discover;
		vector<int> finish; 
		vector<int> pi;
		vector<int> dist;
		stack<int> Stack;
		int time;
		int longest_dist;
		int path_src;
		int path_dest;
		void DFS_VISIT(int src);
		void Find_Longest(int src);
	public:
		Graph(int V);
		void add_edge(int src, int dest, int weight);
		void display_graph();
		void topological_sort(int src);
		void Longest_Path();
};

Graph :: Graph(int V) {
#ifdef DEBUG
	printf("Inside Graph() with %d.\n", V);
#endif
	this->V	= V;
	AdjList = new list<AdjNode>[V];
	color.resize(V);
	discover.resize(V);
	finish.resize(V);
	pi.resize(V);
	dist.resize(V);
#ifdef DEBUG
	printf("Leaving Graph().\n");
#endif
}

void Graph :: add_edge(int src, int dest, int weight) {
#ifdef DEBUG
	printf("Inside add_edge() with (src, dest, weight):(%d , %d  %d).\n", src, dest, weight);
#endif
	AdjNode node;
	node.weight = weight;
	node.dest = dest;
	AdjList[src].push_back(node);
#ifdef DEBUG
	printf("Leaving add_edge().\n");
#endif
}

void Graph :: display_graph() {
#ifdef DEBUG
	printf("Inside display_edge().\n");
#endif
	list<AdjNode> :: iterator itr;
	for (int i = 0; i < V; i++) {
		cout << i << "-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << itr->dest <<"<-->";
		}
		cout << "NULL" << endl;
	}
#ifdef DEBUG
	printf("Leaving display_edge().\n");
#endif
}

void Graph :: DFS_VISIT(int src) {
#ifdef DEBUG
	printf("Inside DFS_VISIT() with %d\n", src);
#endif
	color[src] = GRAY;
	time = time + 1;
	discover[src] = time;
	list<AdjNode> :: iterator itr;	
#ifdef DEBUG1
	cout << "Vertex :"<<src<<" Start Time :"<<time<<endl;
#endif
	for (itr = AdjList[src].begin(); itr != AdjList[src].end(); itr++) {
		if (color[itr->dest] == WHITE) {
			color[itr->dest]	= GRAY;
			pi[itr->dest]		= src;
			DFS_VISIT(itr->dest);
		}
	}
	color[src]	= BLACK;
	time		= time + 1;
	finish[src]	= time;	
	Stack.push(src);
#ifdef DEBUG1
	cout << "Vertex :"<<src<<" Finish Time :"<<time<<endl;
#endif
	color[src] = GRAY;
#ifdef DEBUG
	printf("Leaving DFS_VISIT() .\n");
#endif
}

void Graph :: topological_sort(int src) {
#ifdef DEBUG
	printf("Inside topological_sort() with src %d.\n", src);
#endif
	int i = src;
	list<AdjNode> :: iterator itr;
	do {
		color[i]	= WHITE;
		pi[i]		= NIL;
		discover[i]	= 0;
		finish[i]	= 0;
		dist[i]		= NINF;
		i		= (i + 1)%V;
	}while(i != src);
	i = src;
	time = 0;
	do {
		if(color[i] == WHITE) {
			DFS_VISIT(i);
		}
	}while(i != src);

		
	dist[src] = 0;
	while(!Stack.empty()){
		i = Stack.top();
#ifdef DEBUG2
		cout << "Top of the Stack "<< i <<endl;
		cout << "Distance Before for" << i << "-->" << dist[i]<<endl;
#endif
		if (dist[i] != NINF){
			for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
				if(dist[itr->dest] < dist[i] + itr->weight) {
					dist[itr->dest] = dist[i] + itr->weight;
				}
			}
		}
		Stack.pop();
#ifdef DEBUG2
		cout << "Distance After for" << i << "-->" << dist[i] << endl;
#endif
	}		
	Find_Longest(src);	
#ifdef DEBUG2		
	i = src;
	do {
		if (dist[i] == NINF) {
			cout << "Vertex : "<< i << "Distance : " << "NINF" <<endl;
		}
		else {
			cout << "Vertex : "<< i << "Distance : " << dist[i]<<endl;
		}
		i = (i + 1)%V;
	}while(i != src);
#endif
#ifdef DEBUG
	printf("Leaving topological_sort().\n");
#endif
}

void Graph :: Find_Longest(int src) {
#ifdef DEBUG
	printf ("Inside Find_Longest() with src %d.\n", src);
#endif
	int max		= 0;
	int source	= src;
	int destination	= 0; 
	for (int i = 0; i < V; i++) {
		if (max < dist[i]) {
			max		= dist[i];
			destination 	= i;
		}
	}
#ifdef DEBUG3
	printf("Current Max Distance is %d and path (%d, %d)\n", longest_dist, path_src, path_dest);
	printf("MAX DISTANCE is %d and path (%d, %d)\n", max, source, destination);
#endif
	if (max > longest_dist) {
		longest_dist 	= max;
		path_src	= source;
		path_dest	= destination;
	}
#ifdef DEBUG3
	printf("Updated Max Distance is %d and path (%d, %d)\n", longest_dist, path_src, path_dest);
#endif
#ifdef DEBUG
	printf("Leaving Find_Longest().\n");
#endif
}

void Graph :: Longest_Path() {
#ifdef DEBUG
	printf("Inside Longest_Path)().\n");
#endif
	longest_dist	= 0;
	path_src	= -1;
	path_dest	= -1;
	for (int i = 0; i < V; i++) 
		topological_sort(i);
	cout << "Longest Path Distance :"<< longest_dist <<endl; 
	cout << "Longest Path is " <<"(" << path_src << ", "<< path_dest <<")" <<endl;
#ifdef DEBUG
	printf("Leaving Longest_Path().\n");
#endif
}
	
int main() {
#ifdef DEBUG
	printf("Inside main().\n");
#endif
	int V, src, dest, weight;
	Graph *G;
	cout << "Enter the Count of Vertex "<<endl;
	cin >> V;
	G = new Graph(V);
	cout << "Enter EOF to stop " << endl;
	cout << "Enter the source and destination Vertex of edge and weight"<< endl;
	while(scanf("%d %d %d", &src, &dest, &weight) != EOF) {
		G->add_edge(src, dest, weight);
	}
	G->display_graph();
	//G->topological_sort(1);
	G->Longest_Path();
	return 0;
#ifdef DEBUG
	printf("Leaving main().\n");
#endif
}


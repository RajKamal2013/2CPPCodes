/*
 * Sample Code for PRIMs Algorithm.
 * Author :- Raj Kamal<rajkamal2013@gmail.com>
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

/*
 DEBUG0 -> Checking Entry and Exit points 
 DEBUG1 -> Checking specifics in Graph
 DEBUG2 -> Checking HEAP functions
 DEBUG3 -> Checking MST functions
*/

#define	NIL	-1
#define	INFINITY	99999 

class edge {
	int src;
	int dest;
	int weight;
	public :
		edge (int src, int dest, int weight) {
			this->src	= src;
			this->dest	= dest;
			this->weight	= weight;
		} 
		int get_src() {
			return src;
		}
		int get_dest() {
			return dest;
		}
		int get_weight() {
			return weight;
		}
};

struct vertices {
	int vertex;
	int key;
};

class Graph {
	int V;
	list<edge *> *AdjList;
	vector<int> pi;
	vector<int> key;
	/* set A -> MST and B -> vertices which are yet to be included */
	vector<int> A;
	vector<int> B;   
	/* heap */
	int heap_size;
	int length;
	//vector<vertices> heap;
	void BUILD_MIN_HEAP(); 
	void MIN_HEAPIFY(int i);
	int EXTRACT_MIN();
	void swap(int i, int j);
	public :
		Graph(int vertex);
		void add_edge(int src, int dest, int weight);
		void display_graph();
		void display_heap();
		/* MST */
		void PRIM_MST(int src);
};


Graph :: Graph(int V) {
#ifdef DEBUG0
	printf ("Inside Graph().\n");
#endif
	this->V = V;
	AdjList = new list<edge *>[V];
	pi.resize(V);
	heap.resize(V);
	key.resize(V);
	A.resize(V);
	B.resize(V);
	length = V;
	heap_size = V;
#ifdef DEBUG0
	printf ("Leaving Graph().\n");
#endif
}

void Graph :: add_edge(int src, int dest, int weight) {
#ifdef DEBUG0
	printf ("Inside add_edge().\n");
#endif
	edge *node1, *node2;
	node1 = new edge(src, dest, weight);
	node2 = new edge(dest, src, weight);
	AdjList[src].push_back(node1);
	AdjList[dest].push_back(node2);
#ifdef DEBUG0
	printf ("Leaving add_edge().\n");
#endif
}

void Graph :: display_graph() {
#ifdef DEBUG0
	printf ("Inside display_graph().\n");
#endif
	list<edge *> :: iterator itr;
	for (int i = 0; i < V; i++) {
		cout << i << "-->";
		for (itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++) {
			cout << (*itr)->get_dest() << "-->";
		}
		cout << endl;
	}
#ifdef DEBUG0
	printf ("Leaving display_graph().\n");
#endif
}
void Graph :: swap(int i, int j) {
#ifdef DEBUG0
	printf ("Inside Heap swap() with %d and %d .\n", i, j);
#endif
		vertices temp;
		temp.vertex	= heap[i].vertex;
		temp.key	= heap[i].key;
		heap[i].vertex	= heap[j].vertex;
		heap[i].key	= heap[j].key;
		heap[j].vertex	= temp.vertex;
		heap[j].key	= temp.key;
#ifdef DEBUG0
	printf ("Leaving Heap swap().\n");
#endif
}

void Graph :: MIN_HEAPIFY(int src) {
#ifdef DEBUG0
	printf ("Inside MIN_HEAPIFY() with %d.\n", src);
#endif
	int left	= 2 * src + 1;
	int right	= 2 * src + 2;
	int minimum = src ;
	if ((left < heap_size) && (heap[left].key < heap[src].key))
		minimum 	= left;
	else
		minimum		= src;
	if ((right < heap_size) && (heap[right].key < heap[minimum].key))
		minimum 	= right;
	if (minimum != src) {
#ifdef DEBUG2
	printf(" Swap : Minimum of (%d, %d, %d)-(%d, %d, %d) is %d, %d.\n", src, left, right,
			heap[src].key, heap[left].key, heap[right].key, heap[minimum].vertex, heap[minimum].key);
#endif 
		/* swap */
		swap(src, minimum);
		MIN_HEAPIFY(minimum);
	}	
#ifdef DEBUG0
	printf ("Leaving MIN_HEAPIFY().\n");
#endif
}

void Graph :: BUILD_MIN_HEAP() {
#ifdef DEBUG0
	printf ("Inside BUILD_MIN_HEAP().\n");
#endif
	heap_size = length;
	for (int i = length/2; i >= 0; i--) {
#ifdef DEBUG2
	printf("Calling MIN_HEAPIFY(%d).->(%d, 0)\n", i, length/2);
#endif
		MIN_HEAPIFY(i);
	}
	cout << "Calling min after BUILD_MIN_HEAP()"<< endl;
	display_heap();
#ifdef DEBUG0
	printf("Leaving BUILD_MIN_HEAP().\n");
#endif
}

int Graph :: EXTRACT_MIN() {
#ifdef DEBUG0
	printf ("Inside EXTRACT_MIN().\n");
#endif
	int ret = heap[0].vertex;
	key[ret] = heap[0].key;
	//cout << "Minimum is " << ret << endl;
#ifdef DEBUG2
	printf ("EXTRACT_MIN() -> (Vertex, Key)-> (%d, %d)\n", heap[0].vertex, heap[0].key);
#endif
	swap(heap_size - 1, 0);
	heap_size = heap_size - 1;
	MIN_HEAPIFY(0);
	return ret;
#ifdef DEBUG0
	printf ("Leaving EXTRACT_MIN().\n");
#endif
}
	 
void Graph :: display_heap() {
#ifdef DEBUG0
	printf("Inside display_heap().\n");
#endif
	cout << "Displaying heap  with heap_size :" << heap_size <<endl;
	for (int i =0; i < heap_size; i++) {
		cout << "(Vertex, key)" << "(" << heap[i].vertex<<","<<heap[i].key<<")"<<endl;
	}
#ifdef DEBUG0
	printf("Leaving display_heap().\n");
#endif
}

		
void Graph :: PRIM_MST(int src ) {
#ifdef DEBUG0
	printf("Inside PRIM_MST() with %d.\n", src);
#endif
	int u;
	list<edge *> :: iterator itr;
	for (int i = 0; i < V; i++) {
		pi[i] = NIL;
		key[i] = NIL;
		/* Nothing In MST set */
		A[i]	= 0;
		heap[i].vertex 	= i;
		heap[i].key	= INFINITY;
	}
	
	heap[src].key		= 0;
	key[src] 		= 0;
	display_heap();
	BUILD_MIN_HEAP();
	/* included in MST set */
	A[src]			= 1;	
	while (heap_size > 0) {
#ifdef DEBUG2
	printf ("Heapsize : %d.\n", heap_size);
#endif
		u = EXTRACT_MIN();
		cout << "Heap after extracting minimum " << u << endl;
		display_heap();

#ifdef DEBUG2 
	printf ("Minimum is %d.\n", u);
#endif
		int v, w;
		for (itr = AdjList[u].begin(); itr != AdjList[u].end(); itr++) {
			v	= (*itr)->get_dest();
			w	= (*itr)->get_weight();
			if ((A[v] == 0) && (w < heap[v].key)) {
				heap[v].key	= w;
				key[v]		= w;
				pi[v]		= u;
				MIN_HEAPIFY(v);
			}
		}
		cout << "keY Value Pair after doing operation with " << u << endl;
		for ( int i = 0; i < V; i++) 
		cout << "(vertex, Key)" <<"("<< i <<","<< key[i]<<")"<<endl;
		A[u] = 1;
		cout << "Heap after operations ." << endl;
		display_heap();
	}
	for ( int i = 0; i < V; i++) 
		cout << "(vertex, Key)" <<"("<< i <<","<< key[i]<<")"<<endl;
#ifdef DEBUG0
	printf ("Leaving MST() with %d.\n", src);
#endif
} 		

int main() {
#ifdef DEBUG0
	printf ("Inside main().\n");
#endif
	int src, dest, weight, V;
	Graph *G;
	cout<< "Enter the number of vertices .\n";
	cin >> V;
	G = new Graph(V);
	cout<< "Enter EOF to stop Inputting.\n";
	cout<< "Enter the src, dest and weight of edge" << endl;
	while (scanf("%d %d %d", &src, &dest, &weight) != EOF) {
		G->add_edge(src, dest, weight);
	}
	G->display_graph();
	G->PRIM_MST(0);
	return 0;
#ifdef DEBUG0
	printf("Leaving main().\n");
#endif
} 
			
		

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
	vector<int> heap;
	void BUILD_MIN_HEAP(); 
	void MIN_HEAPIFY(int i);
	int EXTRACT_MIN();
	void HEAPIFY(int pos);
	void swap(int i, int j);
	int find(int src);
	public :
		Graph(int vertex);
		void add_edge(int src, int dest, int weight);
		void display_graph();
		void display_heap(char *str);
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
		int temp;
		temp	= heap[i];
		heap[i]	= heap[j];
		heap[j]	= temp;
#ifdef DEBUG0
	printf ("Leaving Heap swap().\n");
#endif
}

void Graph :: MIN_HEAPIFY(int src) {
#ifdef DEBUG0
	printf ("Inside MIN_HEAPIFY() with %d.\n", src);
#endif
#ifdef DEBUG1
	cout << "------------------------------Start of MIN_HEAPIFY()--------------------------------" << endl;
	cout << "Min heapify with " << src << endl;
#endif
	int left	= 2 * src + 1;
	int right	= 2 * src + 2;
	int minimum 	= src ;
#ifdef DEBUG2
	cout << "src, left, right ,heap_size -> " << src << left << right << heap_size << endl;
	if (left < heap_size) {
		cout << "Left data " << key[left] << "src " << key[heap[src]] << endl;
	}
	if (right < heap_size) {
		cout << "Right _data " << key[right] << "src " << key[heap[src]]  << endl;
	}
#endif
	if ((left < heap_size) && (key[left] < key[heap[src]])) {
		minimum 	= left;
#ifdef DEBUG1
		cout << "Minimum is Left " << minimum << endl;
#endif
	}
	else {
		minimum		= src;
#ifdef DEBUG1
		cout << "Minimum  " << minimum << endl;
#endif
	}
	if ((right < heap_size) && (key[right] < key[minimum])) {
		minimum 	= right;
#ifdef DEBUG1
		cout << "Minimum is right " << minimum << endl;
#endif
	}
	if (minimum != src) {
#ifdef DEBUG1
		cout << "Swapping :" << src << minimum << endl;
#endif
		/* swap */
		swap(src, minimum);
		MIN_HEAPIFY(minimum);
	}	
#ifdef DEBUG1
	cout << "------------------------------ End of MIN_HEAPIFY()--------------------------------" << endl;
#endif
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
#ifdef DEBUG0
	printf("Leaving BUILD_MIN_HEAP().\n");
#endif
}

int Graph :: EXTRACT_MIN() {
#ifdef DEBUG0
	printf ("Inside EXTRACT_MIN().\n");
#endif
	int ret		= heap[0];
#ifdef DEBUG2
	printf ("EXTRACT_MIN() -> (Vertex, Key)-> (%d, %d)\n", heap[0], key[0]);
#endif
	swap(heap_size - 1, 0);
	heap_size = heap_size - 1;
#ifdef DEBUG1
	cout << "Calling Min_heapify from EXTRACT_MIN()" << endl;
#endif
	MIN_HEAPIFY(0);
#ifdef DEBUG1
	display_heap("From Extract Minimum");
#endif
	return ret;
#ifdef DEBUG0
	printf ("Leaving EXTRACT_MIN().\n");
#endif
}
	 
void Graph :: HEAPIFY(int pos) {
#ifdef DEBUG0
	printf ("Inside HEAPIFY().\n");
#endif
	int parent	= pos/2;
	while (parent >= 0) {
		if (key[parent] > key[pos]) {
			swap(parent, pos);
		}
		if (parent % 2 == 0)
			parent = (parent/2) - 1;
		else
			parent = (parent/2); 
	}
#ifdef DEBUG0
	printf ("Leaving HEAPIFY().\n");
#endif
}

void Graph :: display_heap(char *str) {
#ifdef DEBUG0
	printf("Inside display_heap().\n");
#endif
	cout <<"---------------------------------------------------------------------------"<<endl;
	cout << str << endl;
	cout << "Displaying heap  with heap_size :" << heap_size <<endl;
	for (int i =0; i < heap_size; i++) {
		cout << "Vertex " << heap[i]<<"<-->"<< key[heap[i]]<<endl;
	}
	cout <<"---------------------------------------------------------------------------"<<endl;
#ifdef DEBUG0
	printf("Leaving display_heap().\n");
#endif
}

int Graph :: find(int data) {
#ifdef DEBUG0
	printf("Inside find().\n");
#endif
	int ret = -1;
	for (int i = 0; i < heap_size; i++) {
		if (heap[i] == data) {
			ret = i;
			break;
		}
	}
#ifdef DEBUG0
	printf("Leaving find().\n");
#endif
	return ret;
}
		
		
void Graph :: PRIM_MST(int src ) {
#ifdef DEBUG0
	printf("Inside PRIM_MST() with %d.\n", src);
#endif
	int u;
	list<edge *> :: iterator itr;
	for (int i = 0; i < V; i++) {
		pi[i]	= NIL;
		key[i]	= INFINITY;
		/* Nothing In MST set */
		A[i]	= 0;
		heap[i] 	= i;
	}
	
	key[src] 		= 0;
	display_heap("Initial State");
	BUILD_MIN_HEAP();
#ifdef DEBUG1
	display_heap("After BUILD_MIN_HEAP");
#endif
	/* included in MST set */
	A[src]			= 1;	
	while (heap_size > 0) {
#ifdef DEBUG2
	printf ("Heapsize : %d.\n", heap_size);
#endif
		u = EXTRACT_MIN();
#ifdef DEBUG2
		cout << "Minimum is " << u << endl;
		display_heap("After Extract Minimim");
#endif

#ifdef DEBUG2 
	printf ("Minimum is %d.\n", u);
#endif
		int v, w, pos;
		for (itr = AdjList[u].begin(); itr != AdjList[u].end(); itr++) {
			v	= (*itr)->get_dest();
			w	= (*itr)->get_weight();
			if ((A[v] == 0) && (w < key[v])) {
				key[v]		= w;
				pi[v]		= u;
				pos		= find(v);
				HEAPIFY(pos);
			}
		}
#ifdef DEBUG1
		cout << "Calling MIN_HEAPIFY() after adjustment with " << heap[0] << endl;
#endif
		MIN_HEAPIFY(0);
#ifdef DEBUG1
		display_heap("After Adjustment");
#endif
#ifdef DEBUG2
		cout << "keY Value Pair after doing operation with " << u << endl;
		for ( int i = 0; i < V; i++) 
		cout << "(vertex, Key)" <<"("<< i <<","<< key[i]<<")"<<endl;
		A[u] = 1;
		cout << "Heap after operations from minimum" << u << endl;
		display_heap();
#endif
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
			
		

/*
 * Graph Representation In C 
 * Author = RajKamal<rajkamal2013@gmail.com>
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Vertex {
	int v;
	struct Vertex *next;
};

struct AdjList {
	struct Vertex *head;
};

struct Graph {
	int V;
	struct AdjList *node;
};

int intialize_graph(struct Graph **G, int vertex);
int create_graph(struct Graph *G, int src, int dest);
int display_graph(struct Graph *G, int vertex);
int display_list(struct Vertex *V);

int initialize_graph(struct Graph **G, int vertex) {
#ifdef DEBUG
	printf("Inside initialize_graph().\n");
#endif
	int i;
	int ret = 0;
	struct Graph *graph = *G;
	if (graph == NULL) {
		graph = (struct Graph *)malloc(sizeof(struct Graph));
		graph->V = vertex;
		graph->node = (struct AdjList *)malloc(vertex * sizeof(struct AdjList));
		for (i = 0; i < vertex; i++) {
			graph->node[i].head = NULL;
		}
		*G = graph;
	}
	
#ifdef DEBUG
	printf("Leaving initialize_graph().\n");
#endif
	return ret;
}

int create_graph(struct Graph *graph, int src, int dest) {
#ifdef DEBUG
	printf("Inside create_graph().\n");
#endif
	struct Vertex *V = (struct Vertex *) malloc (sizeof(struct Vertex));
	struct Vertex *head = graph->node[src].head;
	int ret = 0;
	V->v = dest;
	V->next = graph->node[src].head;
	graph->node[src].head = V;
#ifdef DEBUG
	printf("Leaving create_graph().\n");
#endif
	return ret;
}

int display_graph(struct Graph *G, int vertex) {
#ifdef DEBUG
	printf("Inside display_graph().\n");
#endif
	struct Graph *g = G;
	struct Vertex *ptr = NULL;
	int i = 0;
	int ret = 0;
	for (i = 0; i < vertex; i++) {
		printf ("%d -->", i);
		ptr = g->node[i].head;
		/*
		while(ptr!=NULL) {
			printf("%d--", ptr->v);
			ptr=ptr->next;
		}
		*/
		ret = display_list(g->node[i].head);
		printf ("NULL.\n");
	}
#ifdef DEBUG
	printf ("Leaving display_graph().\n");
#endif
	return ret;
}

int display_list(struct Vertex *V) {
#ifdef DEBUG
	printf("Inside display_list().\n");
#endif
	struct Vertex *ptr = V;
	int ret = 0;
	while(ptr!=NULL) {
		printf("%d<-->", ptr->v);
		ptr=ptr->next;
	}
#ifdef DEBUG 
	printf("Leaving display_list().\n");
#endif
	return ret;
}	
	
int main() {
#ifdef DEBUG
	printf ("Inside Main.\n");
#endif
	int count, src, dest;
	int edges = 0;
	int ret = 0;
	struct Graph *G = NULL;
	scanf("%d", &count);
	ret = initialize_graph(&G, count);
	if (ret!=0) {
		printf("Error : Unable to initialze Graph .\n");
		exit(1);
	}
	while(scanf("%d, %d", &src, &dest)!=EOF) {
#ifdef DEBUG
	printf("Creating Edge between %d and %d.\n", src, dest);
#endif
		ret = create_graph(G, src, dest);
		if (ret !=0) {
			printf ("Error:Unable to create edge between %d and %d.\n", src, dest);
			exit(1);
		}
	}
	ret = display_graph(G, count);
	if (ret != 0) {
		printf ("Error:Unable to display the Graph .\n");
		exit(1);
	}
	return 0;
}	

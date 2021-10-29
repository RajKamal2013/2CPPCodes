//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_GRAPH_H
#define GNU_GRAPH_H

/*
 * Graph
 * BFS
 * CC
 * DFS
 * Cycle
 * BiPartite
 */

/*
 * Digraph
 * BFS
 * DFS
 * SCC
 * Topological Sort
 */


/*
 * Weigted Graph
 * Djiskstra
 * Prim
 * Kruskal
 * BellmanFord
 */

class Graph {
private:
    int V;
    vector<int> *adj;
public:
    Graph(int v): V{v} {
        adj = new vector<int>[V];
        for(int i = 0; i < V; i++) {
            adj[i] = new vector<int>();
        }
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    vector<int> adj(int v) {
        return adj[v];
    }

    int V() {
        return V;
    }

    int E() {
        int count = 0;
        for (int src = 0; src < V; src++) {
            for (auto &dest:V) {
                count++;
            }
        }
        return count;
    }

    int degree(int v) {
        int count = 0;
        for (auto &w:G.adj[v]) {
            count++;
        }
        return count;
    }

    int maxDegree() {
        int max = -1;
        int count = 0;
        for (int i = 0; i < V; i++) {
            count = degree(i);
            if (max < count) {
                max = count;
            }
        }
        return count;
    }

    int numberOfselfLoops() {
        int count = 0;
        for (int src = 0; src < V; src++) {
            fot (auto &dest:adj[src]) {
                if (dest == src) {
                    count++;
                }
            }
        }
        return (count/2);
    }
};

class BFS {
private:
    bool  *marked;
    int *edgeTo;
    int *distTo;
    int src;

public:
    BFS(Graph G, int src) {
        this.src = src;
        edgeTo  = new int[G.V()];
        distTo  = new int[G.V()];
        marked = new int[G.V()];
        bfs(G, src);
    }

    void dfs(Graph G, int src) {
        Queue<int> Q;
        int u;
        marked[src] = true;
        distTo[src] = 0;
        Q.emplace(src);
        while (!Q.empty()) {
            u = Q.pop();
            for (auto &v:G.adj(u)) {
                if (!marked[v]) {
                    edgeTo[v] = u;
                    disto[v] = distTo[u] + 1;
                    Q.push(v);
                }
            }
        }
    }

    bool hasPathTo(int v) {
        return marked[v];
    }

    vector<int> pathTo(int v) {
        if (!hasPathTo(v)) {
            return {};
        }
        vector<int> path;
        for (int x = v; x != src; x = edgeTo(x)) {
            path.push_back(x);
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};

class DFS {
private:
    bool *marked;
    int *edgeTo;
    int src;

public:
    DFS(Graph G, int src) {
        marked = new bool[G.V()];
        edgeTo = new int[G.V()];
        this.src = src;
        dfs(G, src);
    }

    void dfs(Graph G, int src) {
        marked[src] = true;
        for (auto &w:G.adj(src)) {
            if (!marked[w]) {
                dfs(G, w);
                edgeTo[w] = src;
            }
        }
    }
    bool hasPathTo(int v) {
        return marked[v];
    }

    vector<int> pathTo(int v) {
        if (!hasPathTo(v)) {
            return {};
        }
        vector<int> path;
        for (int x = v; x != src; x = edgeTo(x)) {
            path.push_back(x);
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};

class CC {
private:
    bool *marked;
    int *id;
    int count;

    CC(Graph G) {
        marked = new bool[G.V()];
        id = new bool[G.V()];
        count = 0;

        for (int v = 0; v < G.V(); v++) {
            if (!marked[v]) {
                dfs(G,v);
                count++;
            }
        }
    }

    void dfs(Graph G, int src) {
        marked[v] = true;
        id[v] = count;
        for (auto &w:G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    int count() {
        return count;
    }

    int id(int v) {
        return id[v];
    }

    bool connected(int u, int v) {
        return (id[u] == id[v]);
    }
};

class cycle {
private:
    bool *marked;
    bool hasCycle;

    cycle(Graph G) {
        marked = new bool[G.V()];
        for (int v = 0; v < G.V(); v++) {
            dfs(G, v, v);
        }
    }

    void dfs(Graph G, int u, int v) {
        marked[u] = true;
        for (auto &w:G.V()) {
            if (!marked[w]) {
                dfs(G, w, u);
            } else if (w != v) {
                hasCycle = true;
            }
        }
    }

    bool hasCycle() {
        return hasCycle;
    }
};

/*--------------------------------- DIGRAPH ----------------------------------------- */
class DiGraph {
private:
    int V;
    int E;
    vector<int> *adj;
public:
    DiGraph(int v) : V(v) {
        E= 0;
        adj = new vector<int>[V];
        for (int i = 0;i < V; i++) {
            adj[i] = new vector<int>();
        }
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public void addEdge(int src, int dest) {
        adj[src] = dest;
        E++;
    }

    vector<int> adj(int src) {
        return adj[src];
    }

    Digraph reverse() {
        DiGraph R;
        for (int v = 0; v < V; v++) {
            for (auto &w:adj[V]) {
                R.addEdge(w, v);
            }
        }
        return R;
    }
};

 */
#endif //GNU_GRAPH_H

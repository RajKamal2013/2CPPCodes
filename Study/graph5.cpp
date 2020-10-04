#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

class Graph
{
   int V;
   int **adj;
   public:
   Graph(int );
   void addedge(int ,int );
   void DFS(int src);
 //  void display();
   bool isconnected(int ,int);
   ~Graph();
   
};

Graph :: Graph(int v)
{
   V=v;
   adj=new int *[v];
   for(int i=0;i<V;i++)
     adj[i]=new int[v];
   for(int i=0;i<V;i++)
     for(int j=0;j<V;j++)
        adj[i][j]=0;
}

void Graph :: addedge(int src,int dest)
{
   adj[src][dest]=1;
}

bool Graph :: isconnected(int src,int dest)
{
   return(adj[src][dest]==1);
}

void Graph :: DFS(int src)
{
   stack<int>s;
   bool *visited =new bool[V];
   for(int i=0;i<V;i++)
        visited[i]=false;
   s.push(src);
   visited[src]=true;
   cout<<"Depth First Tree \n";
   while(!s.empty())
   {
      int k=s.top();
      cout<<k<<" ";
      s.pop();
      for(int i=0;i<V;i++)
        if(isconnected(k,i) && !visited[i])
          {
                s.push(i);
                visited[i]=true;
           }
    }
    cout<<endl;
    delete [] visited;
}  
  

Graph ::~Graph()
{
  for(int i=0;i<V;i++)
   delete []  adj[i];
  delete [] adj;
}


int main()
{ 
  int v;
//  cout<<"Enter the number of vertices\n";
 // cin>>v;
  Graph g(6);
  g.addedge(0,1);
  g.addedge(0,3);
  g.addedge(1,4);
  g.addedge(2,4);
  g.addedge(2,5);
  g.addedge(3,1);
  g.addedge(4,3);
  g.addedge(5,5);
  g.DFS(0);
  return 0;
}

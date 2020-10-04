#include<iostream>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cstdlib>
using namespace std;

class Graph
{
  int V;
  list<int>*adj;
  
  public:
   Graph(int v);
   void addedge(int src,int dest);
   void DFS(int v,bool explored[],set<int>&X);
   void SCC();
};

Graph :: Graph(int V)
{
  this->V=V;
  adj=new list<int>[V];
}

void Graph :: addedge(int src,int dest)
{
  adj[src].push_back(dest);
}


void Graph ::DFS(int src,bool Explored[],set<int>&T)
{
   queue<int>q;
   q.push(src);
   Explored[src]=true;

   while(!q.empty())
    {
      src=q.front();
      T.insert(src);
      q.pop();
      list<int> :: iterator itr;
      for(itr=adj[src].begin();itr!=adj[src].end();itr++)
      {
         if(!Explored[*itr])
          {
              q.push(*itr);
              Explored[*itr]=true;
          }
      }
   }
}  
         


void Graph ::SCC()
{
  bool *explored=new bool[V];
  for(int i=0;i<V;i++)
    explored[i]=false;
  int k=0;
  set<int>*component= new set<int>[V];
  for(int i=0;i<V;i++)
  {
    if(!explored[i])
          DFS(i,explored,component[k++]);
  }
  for(int i=0;i<k;i++)
  {
    set<int> :: iterator itr;
    cout<<"Component "<<i<<endl;
    for(itr=component[i].begin();itr!=component[i].end();itr++)
      cout<<*itr<<"\t";
    cout<<"\n";
  }
}

int main()
{
  Graph G(6);
  G.addedge(0,1);
  G.addedge(0,3);
  G.addedge(1,4);
  G.addedge(2,5);
  G.addedge(3,1);
  G.addedge(4,3);
  G.addedge(5,5);
  G.SCC();
  return 0;
}

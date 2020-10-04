#include<iostream>
#include<list>
#include<queue>
#include<set>
#include<cstdlib>
using namespace std;

class Graph
{
  int V;
  list<int>*adj;
 
  public:
  Graph(int v);
  void addedge(int src,int dest);
  void BFS(int src,set<int>&S);
};

Graph :: Graph(int v)
{
   this->V=v;
   adj=new list<int>[v];
}

void Graph :: addedge(int src,int dest)
{
   adj[src].push_back(dest);
}

void Graph :: BFS(int src,set<int>&S)
{
  bool *visited=new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  queue<int>q;
  q.push(src);
  visited[src]=true;
  while(!q.empty())
   {
      src=q.front();
      S.insert(src);
      q.pop();
      list<int>::iterator itr;
      for(itr=adj[src].begin();itr!=adj[src].end();itr++)
       {
          if(!visited[*itr])
             {
                 visited[*itr]=true;
                 q.push(*itr);
             }
       }
    }
}

int main()
{
  Graph G1(6),G2(6);
  G1.addedge(0,1);
  G1.addedge(0,4);
  G1.addedge(1,4);
  G1.addedge(2,5);
  G1.addedge(2,4);
  G1.addedge(3,1);
  G1.addedge(4,3);
  G1.addedge(5,5);

  
  G2.addedge(1,0);
  G2.addedge(4,0);
  G2.addedge(4,1);
  G2.addedge(5,2);
  G2.addedge(4,2);
  G2.addedge(1,3);
  G2.addedge(3,4);
  G2.addedge(5,5);

  set<int>S1;
  set<int>S2;
  G1.BFS(0,S1);
  G1.BFS(0,S2);
  set<int>::iterator itr;
  cout<<"\nset S1 ={";
  for(itr=S1.begin();itr!=S1.end();itr++)
     cout<<" "<<*itr;
  cout<<"}";
  cout<<"\nset S2 ={";
  for(itr=S2.begin();itr!=S2.end();itr++)
     cout<<" "<<*itr;
  cout<<"}";
  if(S1==S2)
    cout<<"\nSCC"<<"\n";
  else
    cout<<"\nnot SCC"<<"\n";
  return 0;
}

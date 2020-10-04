#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<cstdlib>
#include<map>
using namespace std;

class Graph
{
  int V;
  int time;
  list<int>*adj;
  map<int ,int>finish;
  public:
  Graph(int v);
  void addedge(int,int);
  void DFS();
  void DFSvisit(int ,bool Explored[]);
  void top_sort();
};
  

Graph :: Graph(int v)
{
  time=0;
  this->V=v;
  adj=new list<int> [v];
}

void Graph :: addedge(int src,int dest)
 {
   adj[src].push_back(dest);
 }
 
void Graph ::DFS()
{
   bool *Explored=new bool[V];
   for(int i=0;i<V;i++)
       Explored[i]=false;
   for(int i=0;i<V;i++)
    {
      if(!Explored[i])
         DFSvisit(i,Explored);
    }
}

void Graph :: DFSvisit(int src,bool Explored[])
{
   Explored[src]=true;
   time=time+1;
  
   list<int>::iterator it;
   for(it=adj[src].begin();it!=adj[src].end();it++)
     if(!Explored[*it])
          DFSvisit(*it,Explored);
    time=time+1;
    finish.insert(pair<int,int>(time,src));
}

void Graph :: top_sort()
{
  map<int,int>::iterator itr;
  for(itr=finish.begin();itr!=finish.end();itr++)
     cout<<"<--"<<(*itr).first<<"-"<<(*itr).second<<"-->";
  cout<<endl;
 
}




int main()
{
  Graph G(6);
  G.addedge(0,1);
  G.addedge(1,2);
  G.addedge(2,3);
  G.addedge(3,4);
  G.addedge(4,5);
  G.DFS();
  G.top_sort();
  return 0;
}
  
  

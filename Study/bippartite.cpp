#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph
{
  int V;
  list<int> *adj;
  map<int,int> edge;

  public:
  Graph(int );
  void addedge(int,int);
  int bipartite(int s);
};

Graph :: Graph(int v)
{
   this->V=v;
   adj=new list<int>[v];
}

void Graph :: addedge(int src,int dest)
{
   adj[src].push_back(dest);
   edge.insert(pair<int,int>(src,dest));
}

int Graph :: bipartite(int src)
{
  queue<int>q;
  vector<int> color(V,WHITE);
  vector<int> d(V,0);
  vector<int> partition(V,0);
  set<int>partition1;
  set<int>partition2;
   q.push(src);
   color.at(src)=GRAY;
   d.at(src)=0;
   partition.at(src)=1;
   while(!q.empty())
   {
     src=q.front();
     list<int>::iterator itr;
     for(itr=adj[src].begin();itr!=adj[src].end();itr++)
     {
         if(partition.at(src)==partition.at(*itr))
            return 0;
         else
          {
             if(color.at(*itr)==WHITE)
                {
                  color.at(*itr)=GRAY;
                  d.at(*itr)=d.at(src)+1;
                  partition.at(*itr)=3-partition.at(src);
                  q.push(*itr);
                }
          }
          
    }
    q.pop();
    color.at(src)=BLACK;
   }
   for(int i=0;i<V;i++)
    {
      cout<<partition.at(i)<<"\t";
     if(partition.at(i)==1)
       {
          partition1.insert(i);
       }
     else
          partition2.insert(i);
    }
   set<int> :: iterator itr;
   cout<<"\npartion 1----:\t";
   for(itr=partition1.begin();itr!=partition1.end();itr++)
     cout<<*itr<<"\t";
   cout<<"\n";
   cout<<"partion 2----:\t";
   for(itr=partition2.begin();itr!=partition2.end();itr++)
     cout<<*itr<<"\t";
   cout<<endl;

   return 1;
}
     
     
int main()
{
  Graph G(8);
  G.addedge(0,4);
  G.addedge(4,0);
  G.addedge(0,5);
  G.addedge(5,0);
  G.addedge(1,6);
  G.addedge(2,6);
  G.addedge(6,2);
  G.addedge(6,1);
  G.addedge(3,7);
  G.addedge(7,3);
  G.addedge(4,1);
  G.addedge(1,4);
  G.addedge(5,1);
  G.addedge(1,5);
  G.addedge(6,3);
  G.addedge(3,6);
  G.addedge(7,0);
  G.addedge(0,7);
  int temp=  G.bipartite(0);
  if(temp==1)
    cout<<"BIPARTITE GRAPH\n";
  else
    cout<<"NOT BIPARTITE ODD CYCLE\n";
  return 0;
}

  



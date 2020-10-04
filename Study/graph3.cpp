#include<iostream>
#include<stack>
#include<map>
#include<list>
#include<cstdlib>
using namespace std;

class Graph
{
   int V,time;
   list <int> *adj;
   void DFSvisit(int u,bool visited[]);
   public:
   map<int,int>start;
   map<int,int>finish;
   Graph(int v);
   void addedge(int src,int dest);
   void DFS(int src);
   void starttime(int src);
   void finishtime(int src);
   void DFSall();
   
};


Graph :: Graph(int v)
{
   this->V=v;
   this->time=0;
   adj=new list<int>[v];
}

void Graph :: addedge(int src,int dest)
{
   adj[src].push_back(dest);
}

void Graph :: DFS(int src)
{
   bool *visited=new bool[V];
   for(int i=0;i<V;i++)
        visited[i]=false;
   time=0;
   DFSvisit(src,visited);
}

void Graph :: DFSall()
{
   bool *visited=new bool[V];
   for(int i=0;i<V;i++)
        visited[i]=false;
   for(int i=0;i<V;i++)
   {
      if(!visited[i])
       {  
           DFSvisit(i,visited);
        }
    }
}

void Graph :: DFSvisit(int src,bool visited[])
{
   time=time+1;
   start.insert(pair<int,int>(src,time));
   visited[src]=true;
   cout<<src<<" ";
   list<int> :: iterator itr;
   for(itr=adj[src].begin();itr!=adj[src].end();itr++)
        {
           if(!visited[*itr])
                DFSvisit(*itr,visited);
        }
   time=time+1;
   finish.insert(pair<int,int>(src,time));
}

void Graph :: starttime(int src)
{
   DFS(src);
   map<int,int>::iterator it;
   for(it=start.begin();it!=start.end();it++)
    {
      cout<<(*it).first<<"-----"<<(*it).second<<endl;
    }
   cout<<endl;
}
void Graph :: finishtime(int src)
{
   DFS(src);
   map<int,int>::iterator it;
   for(it=finish.begin();it!=finish.end();it++)
    {
       
      cout<<(*it).first<<"-----"<<(*it).second<<endl;
    }
   cout<<endl;
}

void menu()
{
   cout<<"1.Add Edge"<<"\t"<<"2.DFS visit "<<"\t"<<"3.DFS"<<"\t"<<"4.Start time\t" <<"5.Finish time\t"<<"6.Exit\n";
}

int main()
{
   int v,src,dest;
   cout<<"Enter the number of vertices\n";
   cin>>v;
   Graph G(v);
   int option;
   do
    {
      menu();
      cout<<"Enter the choice \n";
      cin>>option;
      switch(option)
       {
      
         case 1:
            cout<<"Enter the source and destination vertex\n";
            cin>>src>>dest;
            G.addedge(src,dest);
            break;
         case 2:
            cout<<"Enter the vertex for DFS visit\n";
            cin>>v;
            cout<<"DFS visit \n";
            G.DFS(v);
            cout<<endl;
            break;
         case 3:
            cout<<"Whole DFS visit \n";
            G.DFSall();
            cout<<"\n";
            break;
         case 4:
            cout<<"Enter the start vertex ,visiting node \n";
            cin>>v;
            G.starttime(v);
            break;
         case 5:
            cout<<"Enter the start vertex ,visiting node \n";
            cin>>v;
            G.finishtime(v);
            break;
         case 6:
            cout<<"Exiting\n";
            break;
         default:
            cout<<"invalid option! try again\n";
            break;
      }
    }while(option!=6);
  return 0;
}
            
 

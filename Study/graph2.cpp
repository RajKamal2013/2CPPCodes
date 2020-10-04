#include<iostream>
#include<cstdlib>
#include<list>
#include<queue>
#include<set>
#include<map>
using namespace std;

class Graph
{
   int V;
   list<int>*adj;
   public:
     Graph();
     Graph(int );
     void addedge(int,int);
     void connected(int v);
};

Graph:: Graph()
{
    V=0;
}

Graph::Graph(int V)
{
  adj=new list <int> [V];
  this->V=V;
}

void Graph :: addedge(int src,int dest)
 {
    adj[src].push_back(dest);
 //   adj[dest].push_back(src);  //do this incase of undirected graph
 }


void Graph :: connected(int v)
{
   bool *visited=new bool[V];
   for(int i=0;i<V;i++)
         visited[i]=false;
   set<int>S;
   list<int> :: iterator itr;
   queue<int> q;
   q.push(v);
   int temp;
   visited[v]=true;
   S.insert(v);
   while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(itr=adj[temp].begin();itr!=adj[temp].end();itr++)
           {
                 if(!visited[*itr])
                    {
                        q.push(*itr);
                        S.insert(*itr);
                        visited[*itr]=true;
                    }
           }
    }
   cout<<"connected component of the vertex"<<v<<endl;
   set<int> ::iterator itr1;
   cout<<"{";
   for(itr1=S.begin();itr1!=S.end();itr1++)
       cout<<*itr1<<",";

   cout<<"}"<<endl;
}

void menu()   
{
    cout<<"ENTER THE OPTION\n";
    cout<<"1.Add Edged\t"<<"2.Connected Component"<<"3.CLEAR\t"<<"4.EXIT\n";
}

int main()
{
 int v;
 cout<<"enter the number of vertices\n";
 cin>>v;
 Graph G(v);
 int option,src,dest;
 do
 {
     menu();
     cin>>option;
     switch(option)
     {
     case 1:
        cout<<"enter the source and destination vertex (source destination)\n";
        cin>>src>>dest;
        G.addedge(src,dest);
        break;
     case 2:
        cout<<"ENter the source vertex\n";
        cin>>src;
        cout<<"The BFS of the graph \n";
        G.connected(src);
        break;
     case 3:
        system("clear()");
        break;
     case 4:
        cout<<"Exiting\n";
        break;
     default:
        cout<<"Enter the option ...invalid option\n";
        break;
    }
 }while(option!=4);
 
return 0;
}     
 
   

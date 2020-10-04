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
    // void addvertex();
     void addedge(int,int);
     void BFS(int );
     void BFS2(int );
  //   void adjacency(int,int );
   //  void neighbour(int );
    // void remove_edge(int ,int );
   //  void remove_vertex(int );
     
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

void Graph :: BFS(int src)
{
   int temp;
   queue<int>q;
   bool *visited=new bool[V];
   for(int j=0;j<V;j++)
     visited[j]=false;
   list <int>:: iterator i;
   q.push(src);
   visited[src]=true;
   while(!q.empty())
    {
        temp=q.front();
        cout<<temp<<" ";
        q.pop();
        for(i=adj[temp].begin();i!=adj[temp].end();i++)
          {
              if(!visited[*i])
                {
                   visited[*i]=true;
                   q.push(*i);
                }
          }
     }
    cout<<endl;
}
          
      
void Graph:: BFS2(int src)
{
   
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
            visited[i]=false;
    multimap<int,int> BFT;
    list<int>*L;
    L=new list<int>[V];
    int i=0;
    L[i].push_back(src); 
    visited[src]=true;
    while(!L[i].empty())
     {
           list<int> ::iterator itr;
           list<int> ::iterator s;
           for (s=L[i].begin();s!=L[i].end();s++)
           {
           //    cout<<*s<<endl;
               for(itr=adj[*s].begin();itr!=adj[*s].end();itr++)
                {
                   cout<<*itr<<"**";
                   if(!visited[*itr])
                    {
                         L[i+1].push_back(*itr);
             //            cout<<"++"<<L[i+1].back()<<endl;
                         visited[*itr]=true;
                    }
               }  
           }
          i=i+1; 
      }
      cout<<endl;
      cout<<"BFT TREE \n";
      list<int> :: iterator itr;
      cout<<"Nodes at level 2\n";
      for(itr=L[2].begin();itr!=L[2].end();itr++)
        {
            // cout<<"BTF"<<endl;
             cout<<*itr<<"\t";
        }
      cout<<endl;
  }


void menu()
{
    cout<<"ENTER THE OPTION\n";
    cout<<"1.Add Edged\t"<<"2.BFS\t"<<"3>BFT \t"<<"4.CLEAR\t"<<"5.EXIT\n";
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
        G.BFS(src);
        break;
     case 3:
        cout<<"ENter the source vertex\n";
        cin>>src;
        cout<<"THE BFT of the graph \n";
        G.BFS2(src);
        break;
     case 4:
        system("clear()");
        break;
     case 5:
        cout<<"Exiting\n";
        break;
     default:
        cout<<"Enter the option ...invalid option\n";
        break;
    }
 }while(option!=5);
 
return 0;
}     
 
   

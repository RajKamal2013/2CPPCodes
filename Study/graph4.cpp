#include<iostream>
#include<list>
#include<stack>
#include<cstdlib>
using namespace std;

class Graph
{
   int V;
   list<int>*adj;
   
   public:
     Graph(int );
     void addedge(int src,int dest);
     void DFS(int);
     void DFSvisit(int src,bool Explored[]);
     void DFSpath(int,int);
     void Printpath(int,bool Explored[],int);
};


Graph :: Graph(int v)
{
   this->V=v;
   adj=new list<int> [V];
}

void Graph :: addedge(int src,int dest)
{
    adj[src].push_back(dest);
}

void Graph :: DFS(int src)
{
  bool *Explored = new bool[V];
  for(int i=0;i<V;i++)
   {
      Explored[i]=false;
   }

   DFSvisit(src,Explored);
        
}


void Graph :: DFSvisit(int src,bool Explored[])
{
   stack<int>s;
   s.push(src);
   Explored[src]=true;
   cout<<src<<" ";
   while(!s.empty())
   {
      src=s.top();
      s.pop();
      list<int> ::iterator itr;
      for(itr=adj[src].begin();itr!=adj[src].end();itr++)
      {
          if(!Explored[*itr])
              {
                 DFSvisit(*itr,Explored);
               }
      }
   }
}

void Graph :: DFSpath(int src,int dest)
{
  bool *Explored = new bool[V];
  for(int i=0;i<V;i++)
   {
      Explored[i]=false;
   }
   cout<<"Now path will be printed\n";
   Printpath(src,Explored,dest);
}

void Graph :: Printpath(int src,bool Explored[],int dest)
{
   stack<int>s;
   s.push(src);
   Explored[src]=true;
   cout<<src<<" ";
   while((!s.empty()) && (src!=dest))
   {
      src=s.top();
      s.pop();
      list<int> ::iterator itr;
      for(itr=adj[src].begin();itr!=adj[src].end();itr++)
      {
          if(!Explored[*itr])
              {
                 Printpath(*itr,Explored,dest);
              }
      }
   }
}
 
void menu()
{
   cout<<"1.addedge\t"<<"2.DFS\t"<<"3.path\t"<<"4.Exit\n";
}


int main()
{
   int v;
   cout<<"enter the number of the vertices\n";
   cin>>v;
   Graph G(v);
   int src,dest,option;
   do 
   {
     cout<<"Enter the option\n";
     menu();
     cin>>option;
     switch(option)
     {
      case 1:
         cout<<"enter the source and destination\n";
         cin>>src>>dest;
         G.addedge(src,dest);
         break;
      case 2:
         cout<<"Enter the vertex\n";
         cin>>v;
         cout<<"DFS visit\n";
         G.DFS(v);
         cout<<endl;
         break;
      case 3:
         cout<<"Enter the source and destination vertex \n";
         cin>>src>>dest;
         G.DFSpath(src,dest);
         cout<<endl;
         break;
       case 4:
          cout<<"exiting\n";
          break;
       default:
         cout<<"Invalid option enter again\n";
         break;
      }
   }while(option!=4);
  return 0;
}

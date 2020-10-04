#include<iostream>
#include<list>
//#include<queue>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

#define INFINITY 100000

struct edge
{
   int dest;
   int weight;
};

struct node
{
   int vertex;
   int parent;
   int weight;
};

class priority_queue
{
   public:
    priority_queue(int v);
    void insert_node(node &x);
    void deleteMin(node &x);
    void deleteMin();
    void display_node();
    bool isEmpty();
   private:
    int heapsize;
    vector<node > pqueue;
    void minheapify(int hole);
};

priority_queue :: priority_queue(int v)
 {
    heapsize=0;
    pqueue.resize(100);
 }

bool priority_queue :: isEmpty()
{
   if(heapsize==0)
     return true;
   else
     return false;
}

void priority_queue::insert_node(node &x)
{
   cout<<"inserting"<<x.vertex<<"--"<<x.parent<<"--"<<x.weight<<"\n";
        int hole=heapsize++;
        pqueue.push_back(x);
        node temp=x;
        for(;hole>=1 && pqueue.at(hole/2).weight > x.weight ; hole/=2)
         {
             pqueue.at(hole)=pqueue.at(hole/2);
         }
         pqueue.at(hole)=x;
 }
 //  display_node();}

void priority_queue :: deleteMin()
 {
    
    if(heapsize==0)
    {
      cout<<"Error :Queue is Empty\n";
    }
   else
     {
         pqueue[0]=pqueue[heapsize];
         heapsize--;
         minheapify(0);
     }
 }

  
void priority_queue :: deleteMin(node &x)
 {
    
    if(heapsize==0)
    {
      cout<<"Error :Queue is Empty\n";
      x.vertex=-1;
      x.parent=-1;
      x.weight=INFINITY;
    }
  else
     {
         x=pqueue[0];
         pqueue[0]=pqueue[heapsize];
         heapsize--;
         minheapify(0);
     }
 }
      

void priority_queue :: display_node()
 {
    cout<<"heapsize "<<heapsize<<"\n";
    for(int i=0;i<=heapsize;i++)
     {
      cout<<"parent"<<"\t"<<"node"<<"\t"<<"Weight"<<"\n";
      cout<<pqueue[i].parent<<"\t"<<pqueue[i].vertex<<"\t"<<pqueue[i].weight<<"\n";
     }
 }


void priority_queue :: minheapify(int hole)
{
    cout<<"min heapify\n";
    int child;
    node x=pqueue.at(hole);
    for(;hole*2 <= heapsize ;hole=child)
     {
           child=2*hole+1;
        
        if(child != heapsize && pqueue[child].weight > pqueue[child+1].weight)
             child=child+1;
        if(pqueue[child].weight < x.weight)
             pqueue[hole]=pqueue[child];
     }
    pqueue[hole]=x;
}
    















class Graph
{
   public:
     Graph(int v);
     void addedge(int src,int dest,int weight);
     void display_weight();
     int  cost(int src,int dest);
     void dijsktra(int src);
     void distance();
   private:
     int V;
     bool *Explored;
     list<edge >*adj;
     vector<int >dist;
     vector<int >vert;
     void relax(int src,int dest,/*queue<node >&Q*/priority_queue &Q);
};


Graph :: Graph(int v)
{
   this->V=v;
   vert.resize(v,0);
   Explored=new bool[v]; 
   adj=new list<edge> [v];
   for(int i=0;i<v;i++)
    {
     dist.push_back(INFINITY);
    }
}

void Graph :: addedge(int src,int dest,int weight)
{
  edge e;
  e.dest=dest;
  e.weight=weight;
  adj[src].push_back(e);
}

int  Graph :: cost(int src,int dest)
{
   int temp=-1;
   list < edge > :: iterator it;
   for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if((*it).dest==dest)
         {
           temp=(*it).weight;
         }
    }
    return temp;
 }

void Graph :: display_weight()
{
   list <edge > :: iterator it;
   for(int i=0;i<V;i++)
     {
       for(it=adj[i].begin();it!=adj[i].end();it++)
             {
                 cout<<i<<"-"<<(*it).dest<<"--->"<<(*it).weight<<"\n";
             }
     }
}

void Graph :: relax(int src,int dest,/*queue<node>&Q*/priority_queue &Q)
{
   // cout<<"in relax\n";
    int edge_cost=cost(src,dest);
    if(dist[dest]>dist[src]+edge_cost)
        dist[dest]=dist[src]+edge_cost;
    node x;
    x.vertex=dest;
    x.parent=src;
    x.weight=dist[dest];
    Q.insert_node(x);
   // Q.push(x);
   }

void Graph :: dijsktra(int src)
{
  for(int i=0;i<V;i++)
   {
      Explored[i]=false;
      dist[i]=1000000;
   }
   priority_queue Q(V);
  // queue<node >Q;
   dist[src]=0;
   node x;
   x.vertex=src;
   x.parent=-1;
   x.weight=dist[src];
//   cout<<"inserting passesd\n";
   Q.insert_node(x);
 //   Q.push(x);
   list<edge>::iterator it;
   int count=0;
  // cout<<"*********************\n";
   while(!Q.isEmpty() && count<V)
   {
      node x;
      Q.deleteMin(x);
      cout<<"minimum "<<x.vertex<<endl;
     // x=Q.front();
     // Q.pop();
      src=x.vertex;
      vert.push_back(src);
   for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(!Explored[(*it).dest])
          {
            int dest=(*it).dest;
            relax(src,dest,Q);
           
          }
    }
    cout<<"vertex explored "<<src<<"\n";
    Explored[src]=true;
    count++;
    }
  cout<<"******************************************\n";
  for(int i=0;i<dist.size();i++)
     cout<<i<<"\t"<<dist[i]<<"\n";

}
   
   
void Graph :: distance()
{
  for(int i=0;i<V;i++)
   cout<<"Distace of "<<i<<dist[i]<<"\n";
}

void menu()
{
   cout<<"1.Addedge \t";
   cout<<"2.Get Cost \t";
   cout<<"3.Display weight \t";
   cout<<"4.shortest path\t";
   cout<<"5.shortest path tree\t";
   cout<<"6.Distance \t";
   cout<<"7.exit\n";
}



int main()
{
   int v,src,dest,choice,weight;
   cout<<"Enter the number of vetices \t:";
   cin>>v;
   Graph G(v);
   do
   {
     menu();
     cout<<"Enter the choice \t:";
     cin>>choice;
     switch(choice)
     {
       case 1:
            cout<<"enter the source and destination vertex and weight of the edge:";
            cin>>src>>dest>>weight;
            G.addedge(src,dest,weight);
            break;
       case 2:
            int temp;
            cout<<"Enter the source and destination vertex :";
            cin>>src>>dest;
            temp=G.cost(src,dest);
            cout<<"Cost :"<<temp<<endl;
            break;
       case 3:
             cout<<"Displaying the cost \n";
             G.display_weight();
             break;
       case 4:
             cout<<"Shortest path \n";
             cout<<"Enter the source vertex :";
             cin>>src;
             G.dijsktra(src);
             break;
       case 6:
             cout<<"Distances\n";
             G.distance();
             break;
       case 7:
            cout<<"Exiting \n";
            break;
       default:
            cout<<"Invalid option,enter again\n";
            break;
      }
    }while(choice !=7);
   return 0;
}
   

#include<iostream>
#include<list>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
using namespace std;

#define INFINITY 100000

struct node 
{
  int vertex;
  int dist;
};

class priority_queue
{
  public:
  priority_queue();
  void insert_node(node &x);
  void display_node();
  void deleteMin(node &x);
  void deleteMin();
  bool isEmpty();
  
  private:
  int heapsize;
  vector<node>pqueue;
 // int capacity;
  void buildminheap();
  void minheapify(int v);
 };


priority_queue :: priority_queue()
{
   heapsize=0;
}

bool priority_queue ::isEmpty()
{
   if(heapsize==0)
     return true;
   else
     return false;
}

void priority_queue :: insert_node(node &x)
{
  if(heapsize==0)
    pqueue[heapsize]=x;
  else
  {
  int hole=heapsize++;
  for( ;hole>=1 && x.dist < pqueue[hole/2].dist ;hole/=2)
     pqueue[hole]=pqueue[hole/2];
  pqueue[hole]=x;
  }
}


void priority_queue :: display_node()
{
   for(int i=0;i<pqueue.size();i++)
     cout<<pqueue[i].dist<<"--"<<pqueue[i].vertex<<"\n";
}

void priority_queue :: deleteMin(node &x)
{
   x=pqueue[0];
   if(heapsize==1)
     {
       heapsize=0;
     }
   else
    {
        pqueue[0]=pqueue[heapsize--];
        minheapify(0);
    }
}


void priority_queue :: deleteMin()
{
   if(heapsize==1)
        heapsize=0;
   else
    {
        pqueue[0]=pqueue[heapsize--];
        minheapify(0);
    }
} 

void priority_queue :: buildminheap()
{
  for(int i=heapsize/2;i>0;i++)
     minheapify(i);
}


void priority_queue ::minheapify(int hole)
{
   int child;
   node temp=pqueue[hole];
   for(;hole*2 <=heapsize;hole/=2)
   {
      child=hole*2;
      if(child!=heapsize && pqueue[child].dist>pqueue[child+1].dist)
          child=child+1;
      if(pqueue[child].dist < pqueue[hole].dist)
          pqueue[hole]=pqueue[child];
      else
        break;
   }
   pqueue[hole]=temp;
}



   
class Graph
{
   public:
    Graph(int V);
    void addedge(int src,int dest,char temp[] ,int weight);
    void display_weight();     
    void dijkstra(int vertex);
  
   private:
    int V;
    list<int> *adj;
    map<char *,int>edge;
    set<int >s;
    vector<int>d;        
    void relax(int src,int dest,priority_queue &Q);
};

Graph :: Graph(int v)
{
   cout<<"here \n";
   this->V=v;
   adj=new list <int> [v];
   for(int i=0;i<v;i++)
     d.push_back(INFINITY);
}

void Graph :: addedge(int src,int dest,char temp[],int weight)
{
  edge.insert(pair<char *,int>(temp,weight));
  adj[src].push_back(dest);
  cout<<"my map size"<<edge.size()<<"\n";
}

void Graph :: display_weight()
{
   cout<<"displaying weights\n";
   map<char *,int> :: iterator it;
   for(it=edge.begin();it!=edge.end();it++)
     cout<<(*it).first<<"---"<<(*it).second<<"\n";
}

void Graph :: dijkstra(int vertex)
{
   priority_queue Q;
   node temp;
   temp.vertex=vertex;
   temp.dist=0;
   d[vertex]=0;
   Q.insert_node(temp);
   
   while(!Q.isEmpty())
   {
       node ptr;
       Q.deleteMin(ptr);
       s.insert(ptr.vertex);
       int src=ptr.vertex;
       list<int> :: iterator it;
       for(it=adj[src].begin();it!=adj[src].end();it++)
        {
            int dest=*it;
            relax(src,dest,Q);
        }
   }
}
       

void Graph :: relax(int src,int dest,priority_queue &Q)
{
   int temp;
   char a[10];
   sprintf(a,"%d-%d",src,dest);
   temp=edge.find(a)->second;
   if(d[dest]>d[src]+temp)
    {
      d[dest]=d[src]+temp;
    }
    node x;
    x.vertex=dest;
    x.dist=d[dest];
    
    Q.insert_node(x);
}

void menu()
{
   cout<<"1.Add vertex\t";
   cout<<"2.Display\t";
   cout<<"3.Shortest Path \t";
   cout<<"4.Shortest Path Tree \t";
   cout<<"5.Exit\n";
}

int main()
{
  priority_queue Q;
  int v,src,dest,weight,option;
  node x;
  cout<<"Enter the number of vertices :\n";
  cin>>v;
  Graph G(v);
  do
  {
    menu();
    cout<<"Enter the choice :";
    cin>>option;
    switch(option)
    {
    case 1:
         cout<<"enter the source vertex,destination vertex,weight  :";
         cin>>src>>dest>>weight;
         char temp[10];
         sprintf(temp,"%d-%d",src,dest);
         G.addedge(src,dest,temp,weight);
         
         cout<<endl;
         break;
    case 2:
         cout<<"weights are \n";
         G.display_weight();
         break;
    case 3:
         cout<<"enter the source vertex :";
         cin>>src;
         G.dijkstra(src);
         break;
   /* case 3:
   case 4:
   case 5:*/
   default :
         cout<<"Invalid option,Enter again \n";
         break;
   }
  }while(option!=5);
  return 0;
}      

       
    
    
      

#include<iostream>
#include<stack>
#include<list>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define gray 1
#define white 0 

class graph
{
  int v;
  stack <int>s;
  list<int> *adj;
  bool *found;
  int *color; 
  public:
    graph(int n);
    void colorize();
    void print();
    void addedge(int src,int dest);
    int findcount();
    void printcolor();
    void traverse(int src,int dest);
};


graph :: graph(int v)
 {
    this->v=v;
    adj=new list<int> [v];
    found=new bool[v];
    color=new int[v];
    for(int i=0;i<v;i++)
     {
          found[i]=false;
          color[i]=white;
     }
 }

void graph :: printcolor()
 {
    for(int i=0;i<v;i++)
       cout<<i<<"\t"<<found[i]<<endl;
 }

void graph :: addedge(int src,int dest)
  {
     adj[src].push_back(dest);
     adj[dest].push_back(src);
  }

void graph :: print()
 {
    stack <int > s3;
    for(int i=0;i<v;i++)
     {
         cout<<"vertex \t"<<i<<endl;
         list<int> :: iterator itr;
         for(itr=adj[i].begin();itr!=adj[i].end();itr++)
           cout<<" "<<*itr;
         cout<<"\n";
      }
 }


void graph :: colorize()
 {
    cout<<"call colorize\n";
    stack<int >temps;
    int temp;
    while(!s.empty())
     {
         temp=s.top();
//         cout<<temp<<"****"<<endl;
         found[temp]=true;
         s.pop();
         temps.push(temp);
     }
    while(!temps.empty())
     {
         temp=temps.top();
         temps.pop();
         s.push(temp);
     }
 }   
 



void graph :: traverse(int src,int dest)
 {
       int temp=0;
   //    printf("traverse call with %d\n",src);

       s.push(src);
       color[src]=gray;
       list<int> :: iterator itr;
       for(itr=adj[src].begin();itr!=adj[src].end();itr++)
         {
 //              cout<<"item\t"<<*itr<<endl;
               if(*itr==dest)
                 {
                    temp=1;
                    colorize();
                 }
               else if (color[*itr]!=gray)
                 {
                    traverse(*itr,dest);
                 } 
        }
        if(temp==0)
           s.pop();
        color[src]=white;
 }

int graph :: findcount()
  {
    int count=0;
    for(int i=0;i<v;i++)
     {
        if(found[i]==true)
           count++;
     }
     return count+1; 
                   
  }             


int main()
 {
    int vertices,edges,src,dest,v1,v2;
    cin>>vertices>>edges>>src>>dest;
    graph g(vertices);
    for(int i=0;i<edges;i++)
        {
           cin>>v1>>v2;
           g.addedge(v1,v2);
        }
//    g.print();
   g.traverse(src,dest);
   int temp=g.findcount();
   g.printcolor();
   cout<<"NUMBER OF PLACES :\t"<<temp<<endl;
    return 0;
  }
    

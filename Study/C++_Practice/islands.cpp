#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

class tempvector
 {
    int n;
    public:
       int *arr;
       tempvector(int );
       int size();
       friend istream & operator >>(istream &din,tempvector &);
       friend ostream & operator <<(ostream &dout,tempvector &);
       int *put();
 };

tempvector :: tempvector(int n)
  {
    this->n=n;
    arr=new int [n];
  }

int tempvector :: size()
  {
    return n;
  }

istream & operator >> (istream &din,tempvector &v)
 {
    int n=v.size();
    for(int i=0;i<n;i++)
    {
       din>>v.arr[i];
    }
    return din;
 }

ostream & operator << (ostream &dout,tempvector &v)
  {
       int n=v.size();
       dout<<"{";
       for(int i=0;i<n;i++)
          dout<<v.arr[i]<<",";
        dout<<"}"<<endl;
       return dout;
 }

int * tempvector :: put()
 {
    return arr;
 }

class Graph
{
   int **adj;
   int m,n;
   int count;
   bool *explored;
   public:
     Graph(int ,int );
     void addedge(int ,int *);
     int print_island();
     void bfs(int );
};

Graph :: Graph(int m,int n)
{
   this->m=m;
   this->n=n;
   count=0;
   adj=new int*[m];
   explored=new bool[m];
   for(int i=0;i<m;i++)
       {
          explored[i]=false;
          adj[i]=new int[n];
       }
}

void Graph :: addedge(int src,int *list)
 {
    for(int i=0;i<n;i++)
       adj[src][i]=list[i];
 }


int Graph ::  print_island()
 {
    for(int i=0;i<m;i++)
     {
        if(!explored[i])
          {
              bfs(i);
              count++;
          }
     }
    cout<<"The number of island"<<count<<endl;
    return count;
 }
    

void Graph :: bfs(int src)
 {
    printf("here in bfs\n");
    queue <int> q;
    explored[src]=true;
    q.push(src);
    printf("pushed\n");
    int temp;
    while(!q.empty())
    {
       temp=q.front();
       q.pop();
       for(int i=0;i<n;i++)
        {           
              if(i!=temp && adj[temp][i]!=0)
               {
                 if(explored[i]==false)
                    {
                     explored[i]=true;
                     q.push(i);
                    }
               }
           }
       } 
  }
               
     
int main()
{
    int m,n;
    int *list;
    cin>>m>>n;
    Graph g(m,n);
    tempvector v(n);
    list=new int[n];
    int count =0;
    while(count < m)
    {
             cin >> v;
             list=v.put();
             g.addedge(count,list);
             count++;
    }
    count=g.print_island();
    return 0;
}
         



      
    


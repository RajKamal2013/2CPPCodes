#include<iostream>
#include<cstdio>
using namespace std;

class vector
 {
    int n;
    public:
       int *arr;
       vector(int );
       int size();
       friend istream & operator >>(istream &din,vector &);
       friend ostream & operator <<(ostream &dout,vector &);
       int *put();
 };

vector :: vector(int n)
  {
    this->n=n;
    arr=new int [n];
  }

int vector :: size()
  {
    return n;
  }

istream & operator >> (istream &din,vector &v)
 {
    int n=v.size();
    for(int i=0;i<n;i++)
    {
       din>>v.arr[i];
    }
    return din;
 }

ostream & operator << (ostream &dout,vector &v)
  {
       int n=v.size();
       dout<<"{";
       for(int i=0;i<n;i++)
          dout<<v.arr[i]<<",";
        dout<<"}"<<endl;
       return dout;
 }

int * vector :: put()
 {
    return arr;
 }
class test
 {
    int **list;
    int m,n;
    public:
     test(int,int );
     void get (int ,int *);
     void print();
 };

test :: test(int m,int n)
 {
    this->m=m;
    this->n=n;
    list=new int *[m];
    for(int i=0;i<m;i++)
       list[i]=new int[n];
 }

void test :: print()
  {
    for(int i=0;i<m;i++)
     {
      cout<<"{";
      for(int j=0;j<n;j++)
        cout<<list[i][j]<<"\t";
      cout<<"}"<<endl;
     }
    
  }
    
void test :: get (int src,int *arr)
   {
     for(int i=0;i<n;i++)
        {
           list[src][i]=arr[i];
        }
   }

int main()
 {
    int m,n,count(0);
    int *arr;
    cin>>m>>n;
    vector v(n);
    test t(m,n);
    arr=new int[n];
    while(count < m)
      {
        cin >> v;
        arr=v.put();
        t.get(count,arr);
        count++;
      }
    t.print();
    cout<<endl;
    return 0;
 }

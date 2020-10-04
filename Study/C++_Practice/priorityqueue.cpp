#include<iostream>
#include<list>
#include<vector>
#include<cstdlib>
using namespace std;

struct node
{
   int data;
   int key;
};

class heap
{
   public:
    heap(int capacity=100);
    
        bool isEmpty() ;
//      node &findmin() const;
    
    void insert_node(node &x);
    void display();
    void deleteMin();
    void deleteMin( node &minitem);
   // void makeempty();

   private:
    int capacity;
    int heapsize;
    int currentsize;
   // list<node *>array;        this was creating not appropriate output
      list<node >arr;
      vector<node > adj;
    void buildheap();
    void minheapify(int key);
};

//template<typename Comaparable>
heap :: heap(int capacity)
  {
     this->heapsize=0;
     this->currentsize=0;
     this->capacity=capacity;
  }


void heap :: insert_node(node &x )
{
  list<node > ::iterator it;
  it=arr.end();
   arr.insert(it++,x);
   adj.push_back(x);
   int hole=currentsize++;
   heapsize++;
   for( ;hole >=1 && x.key < (adj.at(hole/2)).key;hole/=2)
   {
       adj.at(hole)=adj.at(hole/2);
   }
   adj.at(hole)=x;
}
    
void heap:: display()
{
  list<node >:: iterator itr;
  for(itr=arr.begin();itr!=arr.end();itr++)
    cout<<(*itr).data<<"=>"<<(*itr).key<<"\n";
  cout<<"heapified\n";
  for(int i=0;i<adj.size();i++)
    cout<<adj[i].data<<"--"<<adj[i].key<<"\n";
}

bool heap :: isEmpty()
{
   if(currentsize==0)
     return true;
   else
      return false;
}

void  heap :: deleteMin()
{
  if(currentsize==0)
   {
     cout<<"Heap is full \n";
   }
  else
   {
   adj[0]=adj[currentsize];
  //adj.pop_back();
  currentsize=currentsize-1;
  minheapify(0);
   }
}
   
void heap :: deleteMin(node &minitem)      //remove the minimum and place in the minitem .....nice yaaaa
{
   
  if(isEmpty())
  {
     cout<<"Heap is full \n";
    
  }
  else
  {
  minitem=adj.at(1);
  adj.at(0)=adj.at(currentsize);
  adj.pop_back();
  currentsize=currentsize-1;
 // minheapify(1);
  }
}

/*void heap :: minheapify(int hole)
 {
    int left=2*hole+1;
    int right=2*hole +2;
    node temp=adj[hole];
    int smallest;
    if((left <= currentsize)&&(adj[left].key < adj[hole].key)) 
        smallest=left;
    else
        smallest=hole;
    
    if((right <= currentsize)&&(adj[right].key < adj[smallest].key)) 
        smallest=right;
    adj[hole]=adj[smallest];
    adj[smallest]=temp;
    cout<<"**";
    minheapify(smallest);
 }*/

void heap :: minheapify(int hole)
{
  int child;
  node temp=adj[hole];
  for( ; hole*2 <=currentsize;hole=child)
   {
      child=2*hole;
      if(child!=currentsize && adj[child+1].key < adj[child].key)
           child++;
      if(adj[child].key < temp.key)
         adj[hole]=adj[child];
      else
         break;
   }
   adj[hole]=temp;
}


void heap :: buildheap()
{
   for(int i=currentsize/2;i>0;i--)
     minheapify(i);
}
   
int main()
{
   heap h(10);
   node x;
   x.data=1;
   x.key=1;
   h.insert_node(x);
   x.key=23;
   x.data=12;
   h.insert_node(x);
   x.data=25;
   x.key=2;
   h.insert_node(x);
   x.data=2;
   x.key=5;
   h.insert_node(x);
   x.data=50;
   x.key=4;
   h.insert_node(x);
   h.display();
   h.deleteMin();
//   cout<<"minimum item deleted and the element is "<<x.data<<"--"<<x.key<<endl;
   h.display();
   
   return 0;
}

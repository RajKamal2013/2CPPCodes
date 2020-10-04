#include<iostream>
#include<map>
using namespace std;

int main()
{
   multimap<int,int>mymap;
   multimap<int,int> :: iterator it;
   mymap.insert(pair<int,int>(0,1));
   mymap.insert(pair<int,int>(1,2));
   mymap.insert(pair<int,int>(1,3));
   mymap.insert(pair<int,int>(1,4));
   mymap.insert(pair<int,int>(2,3));
   mymap.insert(pair<int,int>(3,5));
   for(it=mymap.begin();it!=mymap.end();it++)
    {   
     cout<<(*it).first<<" => "<< (*it).second <<"\n";
    }
    int temp;
    for(it=mymap.equal_range(1).first;it!=mymap.equal_range(1).second;it++)
       cout<<" "<<(*it).second<<"\t";
         
   cout<<endl;
    return 0;
}

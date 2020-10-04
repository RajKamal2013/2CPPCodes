#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    vector<string>ss;
    ss.push_back("Raj Kamal");
    ss.push_back("Ravi Kaushal");
    ss.push_back("Ankita Suman");

    cout<<"\nLoop by index \n";
    int i;
    for(i=0;i<ss.size();i++)
        cout<<ss[i]<<endl;
    
    cout<<"\n Loop by iterator \n";
    vector<string>::const_iterator cii;
    for(cii=ss.begin();cii!=ss.end();cii++)
      {
            cout<<*cii<<endl;
      }
     
    cout<<"\n Reverse Iterator \n";
    vector<string>::reverse_iterator rii;
    for(rii=ss.rbegin();rii!=ss.rend();++rii)
        {
            cout<<*rii<<endl;
        }

     cout<<"sample output:"<<endl;

     cout<<ss.size()<<endl;
     cout<<ss[2]<<endl;
     cout<<ss[0]<<endl;
     swap(ss[0],ss[2]);
     cout<<ss[2]<<endl;
     cout<<ss[0]<<endl;
   return 0;
}

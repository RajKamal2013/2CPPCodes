#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector< vector<int> >v12matrix;
   vector<int> A,B;
   vector< vector<int> > :: iterator iter_ii;
   vector<int> :: iterator iter_jj;
   A.push_back(10);
   A.push_back(20);
   A.push_back(30);
   B.push_back(100);
   B.push_back(200);
   B.push_back(300);
   
   v12matrix.push_back(A);
   v12matrix.push_back(B);
   
   for(iter_ii=v12matrix.begin();iter_ii!=v12matrix.end();iter_ii++)
      {
         for(iter_jj=(*iter_ii).begin();iter_jj!=(*iter_ii).end();iter_jj++)
          {
               cout<< *iter_jj << endl;
          }
      }
    cout<<"**"<<v12matrix[0][2]<<endl;
    cout<<"++"<<v12matrix.size()<<endl; 
   return 0;

}
       

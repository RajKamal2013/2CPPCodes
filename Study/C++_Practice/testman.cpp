#include<iostream>
using namespace std;

ostream & symbol(ostream &output)
 {
    return output << "\tRs";
 }
int main()
{
  cout<<"cost is "<<symbol<<"5"<<endl;
  return 0;
} 

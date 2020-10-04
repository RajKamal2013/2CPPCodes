#include<iostream>
#include<vector>
using namespace std;

template<class T>
void bogosort(vector <T> &array)
{
   while(!is_Sorted(array))
    {
      random_shuffle(array.begin(),array.end());
    }
}

template<class T>
bool is_Sorted(vector<T> &array)
{
   for(int i=0;i<array.size();++i)
     {
        if(array[i]>arrray[i+1])
           {
             return false;
           }
     }
   return true;
}

int main()
{
   

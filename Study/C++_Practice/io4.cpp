#include<iostream>
using namespace std;

int main()
{
   int size =20;
   char city[20],city1[20];
   cout<<"enter the city name "<<endl;
   cin>>city;
   cout<<"city name entered is "<<city<<endl;
   cout<<"enter the another city name "<<endl;
   cin.getline(city1,size);
   cout<<"city name entered is "<<city1<<endl;
   cout<<"enter the another city name "<<endl;
   cin.getline(city,size);
   cout<<"city name entered is "<<city<<endl;
   return 0;
 }

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
   stack<string>mystack;
   mystack.push("Raj Kamal");
   mystack.push("Ankita Suman");
   mystack.push("Ravi Kaushal");
   mystack.push("Ankesh Kumar Suman");
   string raj;
   raj=mystack.top();
   mystack.top()="Sonu";
   while(!mystack.empty())
    {
       cout<<mystack.top()<<"\n";
       mystack.pop();
    }
   return 0;
}

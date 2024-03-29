#include<iostream>
using namespace std;

void pass_by_value(int* p)
{
    //Allocate memory for int and store the address in p
    p = new int;
}

void pass_by_reference(int*& p)
{
    p = new int;
}

int main()
{
    int* p1 = NULL;
    int* p2 = NULL;

    pass_by_value(p1); //p1 will still be NULL after this call
    pass_by_reference(p2); //p2 's value is changed to point to the newly allocate memory

    if (p1 == NULL) {
      cout << "P1 is still null " << endl;
    }
    
    if (p2 == NULL) {
      cout << "P2 is still null " << endl;
    }

    return 0;
}

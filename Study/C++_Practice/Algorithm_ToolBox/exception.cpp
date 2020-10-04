#include<iostream>
using namespace std;

void divide(double x, double y) {
    try {
        if (y == 0.0)
            throw y;
        else
            cout << "Division = " << x/y << endl;
    }
    catch(double) {
        cout << "Cought Double Inside function" << endl;
        throw;
    }
    cout << "End of Function" << endl;
}

int main() {
    cout << "Inside Main" << endl;
    try {
        divide (10.5, 2.0);
        divide (20.0, 0.0);
    }
    catch (double) {
        cout << "Caught Double Inside Main " << endl;
    }

    cout << "End of Main" << endl;
}
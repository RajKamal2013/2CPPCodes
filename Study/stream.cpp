#include <iostream>
using namespace std;

ostream & symbol (ostream & output){
	return output << "\tRs";
}

int main(){
	cout << symbol << endl;
return 0;
}


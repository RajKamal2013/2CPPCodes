#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define max_line 180;
#define max_length 80;

int getrandom_number( int num) {
	int i = rand() % num;
	return i;
}
	

char * getrandom_string(int line_len) {
	char *string = new char[line_len + 1];
	char *ptr = string;
	static const char alphanum []=
	"ABCDEFGHIJKLAMNOPQRSTUVWXYZ "
	"abcdefghijklmnopqrstuvwxyz "
	"1234567890"
	"~!@#$%^&*()_+=-[]{}||<>?/,.:;"
	" ";
	int size = sizeof(alphanum) - 1;	

	for (int i = 0; i < line_len; i++) {
		*ptr = alphanum[rand() % (size)];
		 ptr++;
	}
	*ptr = '\0';
	return string;
}
		
		
	

int main() {
	ofstream fout ("temp.txt", ios::trunc);
	int line_count, line_length;
	line_count = rand() % max_line;
	char *string = new char[80];
	for (int i=0 ; i < line_count; i++ ){
		line_length = rand() % max_length;
		string = getrandom_string(line_length);
		fout << string;
		fout << "\n";
	}
	fout.close();

	ifstream fin ("temp.txt", ios::in);
	fout.open("temp1.txt", ios::trunc);
	char c, line[80];
	int count = 0 ;
	
	while(fin){
		fin.getline(line, 80);
	/*
		fin >> line;
		cout << line << endl;
		fout << line;
		fout << "\n";
	*/
		cout << line << endl;
		fout << line;
		fout << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}

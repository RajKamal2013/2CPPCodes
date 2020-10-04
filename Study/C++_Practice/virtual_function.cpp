#include <iostream>
#include <cstring>
using namespace std;

class media {
	protected:
		char title[50];
		float price;
	public:
		media(char *, float );
		virtual void display();
};

class book : public media {
	private:
		int pages;
	public:
		book (char *s, float p, int pa ):media(s, p) {
			pages = pa;
		}
		void display();
};

class tape : public media {
	private:
		int playtime;
	public:
		tape (char *s, float p, int pl):media(s, p) {
			playtime = pl;
		}
		void display();
};

media :: media (char*  title, float price ){
	strcpy(this->title, title);
	this->price = price;
}

void media :: display() {}

void book :: display(){
	cout << "Book Detials: ";
	cout << "\n Title: " <<  title;
	cout << "\n Price: " <<  price;
	cout << "\n Pages: " <<  pages;
	cout << endl;
}	

void tape :: display() {
	cout << "Tape Detials: ";
	cout << "\n Title: " <<  title;
	cout << "\n Price: " <<  price;
	cout << "\n Playtime in Minutes: " << playtime;
	cout << endl;
}


int main() {
	char *title = new char[50];
	float price;
	int playtime;
	int pages;

	/*
		book details
	*/
	book book1(" Rage of Angel ", 129, 600),
		book2("Wise and otherwise", 98, 400);
		
	/*
		tape details
	*/
	tape tape1("porcupine tree ", 66, 30),
		tape2("ColdPlay ", 70, 90);
	
	media *list[4];
	list[0] = &book1;
	list[1] = &book2;
	list[2] = &tape1;
	list[3] = &tape2;

	cout << "Media Details " << endl;
	for (int i = 0; i < 4; i++ ) {
		list[i]->display();
	}
	
	return 0;
}

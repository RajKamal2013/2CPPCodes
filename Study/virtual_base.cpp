#include <iostream> 
using namespace std;

class student {
	protected:
		int roll_number;
	public:
		void get_number(int a);
		void put_number(void);
};

class test : virtual public student {
	protected:
		float part1, part2;
	public:
		void get_marks (float, float);
		void put_marks();
};

class sports : public virtual student {
	protected:
		float score;
	public:
		void get_score(float );
		void put_score();
};

class result : public test, public sports {
	protected:
		float total;
	public:	
		void display();
};

void student :: get_number(int a){
	roll_number = a ;
}

void student :: put_number(){
	cout << "Roll Number = " << roll_number;
}

void test :: get_marks (float a, float b){
	part1 = a;
	part2 = b;
}

void test :: put_marks (){
	cout << "Part1 Mark = " << part1 << endl;
	cout << "Part2 Mark = " << part2 << endl;
}

void sports :: get_score (float a){
	score = a;
}

void sports :: put_score (){
	cout << "Score = " << score;
}

void result :: display() {
	total = part1 + part2 + score;
	put_number();
	put_marks();
	put_score();
	
	cout << "total Marks obtained = " << total << endl;
}

int main(){
	result student1;
	student1.get_number(34);
	student1.get_marks(30.5, 25.5);
	student1.get_score(7.0);
	student1.display();
	return 0;
}

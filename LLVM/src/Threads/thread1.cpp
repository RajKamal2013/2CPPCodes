#include <iostream>
#include <thread>


void func1()
{
	std::cout << "hello \n";

}


void func2()
{
	std::cout << "Second \n";
}

void func3(std::string str)
{
	std::cout << "Third with Argument :" << str;
}

int main()
{
	std::string str = "Hi";
	std::thread t(func3, str);
	t.join();
	return 0;
}

#include "easyfind.template.hpp"

int main()
{
	srand(time(NULL));
	int size = rand() % 500;
	std::cout << std::endl << "The size of the int container is ";
	std::cout << size;
	std::cout << std::endl;

	std::vector<int> test;
	std::list<int> test2;
	std::deque<int> test3;
	std::array<int, 42> test4;
	std::forward_list<int> test5;

	// std::stack<int, std::vector<int> > test6;
	
	testMain(test, size);
	sleep(2);
	testMain(test2, size);
	sleep(2);
	testMain(test3, size);
	sleep(2);
	testArray(test4, 42);
	sleep(2);
	testForwardList(test5, size);
	// sleep(2);
	// testAdaptors(test6, size);
	return 0;
}
#include "easyfind.template.hpp"

int main()
{
	srand(time(NULL));
	std::vector<int> test;
	std::list<int> test2;
	std::deque<int> test3;

	testMain(test);
	testMain(test2);
	testMain(test3);


	return 0;
}
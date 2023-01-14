
#include "Data.class.hpp"
#include "utils.hpp"

int main()
{
	Data	test;

	std::cout << "address de data : " << &test << std::endl;
	std::cout << "serialize = " << serialize(&test) << std::endl;
	std::cout << "deserialize = " << deserialize(serialize(&test)) << std::endl;
	std::cout << "address " << &test << " egale a " << deserialize(serialize(&test))<<std::endl;
	return 0;
}
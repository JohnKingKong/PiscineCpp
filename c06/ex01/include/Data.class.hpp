
#pragma once

#include <iostream>

class Data {
	public:

		Data();
		Data(const Data& other);
		~Data();

		Data& operator=(Data const & rhs);

		const void *getPointer() const;

		std::string		stringTest;

	private:
		const void		*_pointer;

};

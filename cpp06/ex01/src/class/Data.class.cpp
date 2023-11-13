
#include "Data.class.hpp"


Data::Data() {
	_pointer = (&(*this));
	stringTest = "Default";
}

Data::Data(const Data& other){
	_pointer = &(*this);
	stringTest = other.stringTest;
	*this = other;
}

Data::~Data(){}

Data& Data::operator=(Data const & rhs){
	_pointer = rhs.getPointer();
	stringTest = rhs.stringTest;
	return *this;
}

const void *Data::getPointer() const {
	return this->_pointer;
}


#include "Data.class.hpp"


Data::Data() {
	_pointer = (&(*this));
}

Data::Data(const Data& other){
	_pointer = &(*this);
	*this = other;
}

Data::~Data(){}

Data& Data::operator=(Data const & rhs){
	_pointer = rhs.getPointer();
	return *this;
}

const void *Data::getPointer() const {
	return this->_pointer;
}

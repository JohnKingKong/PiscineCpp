
#pragma once

class Data {
	public:

		Data();
		Data(const Data& other);
		~Data();

		Data& operator=(Data const & rhs);

		const void *getPointer() const;

	private:
		const void	*_pointer;

};

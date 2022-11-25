
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"
#include "Base.class.hpp"
#include "utils.hpp"

int	main(void)
{
	Base *pointer = generate();
	Base &reference = static_cast<Base &>((*pointer));

	identify(pointer);
	identify(reference);
	delete (pointer);
	return (0);
}

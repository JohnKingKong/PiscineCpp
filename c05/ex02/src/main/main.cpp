
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int main()
{
	try {
		ShrubberyCreationForm	shrub("Paul");
		Bureaucrat			Paul("Paul", 1);

		shrub.execute(Paul);
	}
	catch(std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}
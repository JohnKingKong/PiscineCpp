
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include "Intern.class.hpp"

int main()
{
	Intern	Paul;
	AForm	*RobotomyRequest = Paul.makeForm("RobotomyRequest", "Paul");
	AForm	*PresidentialPardon = Paul.makeForm("PresidentialPardon", "Robert");
	AForm	*ShrubberyCreation = Paul.makeForm("ShrubberyCreation", "Jardins");

	Bureaucrat	Master("Master", 1);
	try {
		Master.signForm(*RobotomyRequest);
		Master.signForm(*ShrubberyCreation);
		Master.signForm(*PresidentialPardon);
		Master.executeForm(*RobotomyRequest);
		Master.executeForm(*PresidentialPardon);
		Master.executeForm(*ShrubberyCreation);
	}
	catch(const std::exception& exception) {
		if (RobotomyRequest)
			delete(RobotomyRequest);
		if (PresidentialPardon)
			delete(PresidentialPardon);
		if (ShrubberyCreation)
			delete(ShrubberyCreation);
		std::cerr << exception.what() << std::endl;
	}
	try {
		AForm	*Error = Paul.makeForm("Error", "Paul");

		Master.signForm(*Error);
	}
	catch(const std::exception& exception) {
		if (RobotomyRequest)
			delete(RobotomyRequest);
		if (PresidentialPardon)
			delete(PresidentialPardon);
		if (ShrubberyCreation)
			delete(ShrubberyCreation);
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
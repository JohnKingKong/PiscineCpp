
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int main()
{
	try {
		PresidentialPardonForm	form("Paul");
		RobotomyRequestForm		form2("Paul");
		ShrubberyCreationForm	form3("Jardins");
		Bureaucrat				Paul("Paul", 1);
		PresidentialPardonForm	fakeForm("Jayjay");

		Paul.signForm(form);
		Paul.executeForm(form);
		Paul.signForm(form2);
		Paul.executeForm(form2);
		Paul.signForm(form3);
		Paul.executeForm(form3);
		Paul.executeForm(fakeForm);
	}
	catch(std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	try {
		ShrubberyCreationForm		fakeForm1("salon");
		Bureaucrat					Jeremie("Jeremie", 150);
		Bureaucrat					Jr("Jr", 1);

		Jr.signForm(fakeForm1);
		Jeremie.executeForm(fakeForm1);
	}
	catch(std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	try {
		RobotomyRequestForm	fakeForm2("paul");
		Bureaucrat			Robert("Robert", 150);

		Robert.signForm(fakeForm2);
	}
	catch(std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}
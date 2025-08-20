#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm for: " << this->target << " has ben destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
		this->target = other.target;
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if(this != &other)
	{
		this->target = other.target;
		std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm",145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm with target " << target << " was created" << std::endl;
}

// to change
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream outfile((target + "_shrubbery").c_str());

	if(!outfile)
	{
		std::cout << "Failed to create file!" << std::endl;
		return;
	}

outfile <<
"    /|\\        /|\\\n"
"   //|\\\\      //|\\\\\n"
"  ///|\\\\\\    ///|\\\\\\\n"
" ////|\\\\\\\\  ////|\\\\\\\\\n"
"     |          |\n"
<< std::endl;
	
	outfile.close();
}

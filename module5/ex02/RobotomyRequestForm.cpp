#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm for: " << this->target << " has ben destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other)
{
		this->target = other.target;
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if(this != &other)
	{
		this->target = other.target;
		std::cout << "RobotomyRequestForm assignment operator called" << std::endl;

	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm",72, 45), target(target)
{
	std::cout << "RobotomyRequestForm with target " << target << " was created" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
if (this->getIsSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	srand(time(NULL));

    std::cout << "Bzzzzz bzzzzz... " << std::endl;
	if ((rand() % 2) == 0) 
        std::cout << "robotomized failed!" << std::endl;
	else
        std::cout << this->target << " has been robotomized" << std::endl;
}

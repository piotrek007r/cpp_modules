#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"),gradeToSign(1), gradeToExecute(1), isSigned(false)
{
    std::cout << "AForm default construcor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name),
    gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm: " << name << " with grades: " << gradeToSign << " " << gradeToExecute 
        << " was created" << std::endl;
}

AForm::~AForm() 
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), 
    gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade is to high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade is to low!";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "form is not signed!";
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->gradeToSign)
    {
        this->isSigned = true;
        std::cout << "Bureaucrat: " << bureaucrat.getName() << " has signed " << this->name
            << " form" << std::endl;
    }
    else
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm &form)
{
    os << form.getName() << " form with grade: " << form.getGradeToSign() << " is"
        << (form.getIsSigned() ? " signed" : " not signed");
    return os; 
}




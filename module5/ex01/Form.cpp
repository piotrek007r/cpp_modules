#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"),gradeToSign(1), gradeToExecute(1), isSigned(false)
{
    std::cout << "Form default construcor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name),
    gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form: " << name << " with grades: " << gradeToSign << " " << gradeToExecute 
        << " was created" << std::endl;
}

Form::~Form() 
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), 
    gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "grade is to high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "grade is to low!";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
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

std::string Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form &form)
{
    os << form.getName() << " Form with grade: " << form.getGradeToSign() << " is"
        << (form.getIsSigned() ? " signed" : " not signed");
    return os; 
}

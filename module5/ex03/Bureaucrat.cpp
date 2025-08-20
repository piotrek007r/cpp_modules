#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Random"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
};

Bureaucrat::~Bureaucrat() 
{
    std::cout << this->name << " destructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
        std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(&other != this)
        this->grade = other.grade;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{   
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << name << " is graded to: " << grade << std::endl;
}

int Bureaucrat::getGrade() const 
{
    return this->grade; 
} 

std::string Bureaucrat::getName() const
{
    return this->name;
} 

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn’t sign " << form.getName() << " becouse " 
            << e.what() << std::endl;
    }
}

// <bureaucrat> couldn’t sign <form> because <reason>.


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is to high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is to low!";
}

void Bureaucrat::incraseGrade()
{
    if(this->grade <= 1)
        throw GradeTooHighException();
    else
        this->grade--; 
}
void Bureaucrat::decraseGrade()
{
    if(this->grade >= 150)
        throw GradeTooLowException();
    else
        this->grade++; 
}

void Bureaucrat::executeForm(AForm const & form)
{
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
}
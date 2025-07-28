#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form 
{
    private:
        const std::string name;
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
    
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat &bureaucrat);


        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 
        };
        
};

std::ostream& operator<<(std::ostream& os, const Form &form); 

#endif
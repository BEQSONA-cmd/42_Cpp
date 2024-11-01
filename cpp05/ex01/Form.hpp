#ifndef FORM_HPP
#define FORM_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "Bureaucrat.hpp"
#include "Exception.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string name;
        bool is_signed;
        int signGrade;
        int execGrade;
    public:
        Form();
        Form(const Form &form);
        Form &operator=(const Form &form);
        friend std::ostream &operator<<(std::ostream &out, const Form &form);
        ~Form();

        Form(std::string name, int signGrade, int execGrade);

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat &bureaucrat);

        Exception FormIsAlreadySignedException() { return Exception(RED "Form is already signed" RESET ); }

        Exception GradeTooHighException() { return Exception(RED "Grade too high" RESET); }
        Exception GradeTooLowException() { return Exception(RED "Grade too low" RESET); }
};

#endif

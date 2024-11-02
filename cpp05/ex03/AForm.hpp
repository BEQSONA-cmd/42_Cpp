#ifndef AFORM_HPP
#define AFORM_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Exception.hpp"

class Bureaucrat;

class AForm
{
    protected:
        std::string name;
        bool is_signed;
        int signGrade;
        int execGrade;

        std::string target;

    public:
        AForm();
        AForm(const AForm &form);
        AForm &operator=(const AForm &form);
        friend std::ostream &operator<<(std::ostream &out, const AForm &form);
        virtual ~AForm();

        AForm(std::string name, int signGrade, int execGrade);

        std::string getName() const;
        std::string getTarget() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;

        virtual void action() const;

        Exception FormIsAlreadySignedException() { return Exception(RED "Form is already signed" RESET ); }
        Exception GradeTooHighException() { return Exception(RED "Grade too high" RESET); }
        Exception GradeTooLowException() { return Exception(RED "Grade too low" RESET); }
};

#endif

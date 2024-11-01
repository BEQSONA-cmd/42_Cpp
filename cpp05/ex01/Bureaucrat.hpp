#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void incrementGrade(int n);
        void decrementGrade(int n);

        Exception GradeTooHighException() { return Exception("Grade too high"); }
        Exception GradeTooLowException() { return Exception("Grade too low"); }

        void signForm(Form &form);
};

#endif

#ifndef INTERN_HPP
#define INTERN_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    private:
    public:
        Intern();
        Intern(const Intern &intern);
        Intern &operator=(const Intern &intern);
        ~Intern();

        AForm *makeForm(std::string form, std::string target);
        void clear_forms(AForm *forms[], int i);
        
        Exception FormNotFoundException() { return Exception(RED "Form not found" RESET); }
};

#endif

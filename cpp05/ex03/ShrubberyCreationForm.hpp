#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberycreationform);
        ~ShrubberyCreationForm();
        
        ShrubberyCreationForm(std::string target);
        void action() const;
};

#endif

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialpardonform);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string target);
        void action() const;
};

#endif

#include "Intern.hpp"

Intern::Intern()
{
    // std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
    if(this == &intern)
        return *this;
    return *this;
}

Intern::~Intern()
{
    // std::cout << "Intern destructor" << std::endl;
}

void Intern::clear_forms(AForm *forms[], int i)
{
    int j = 0;
    while(j < 3)
    {
        if (j != i)
            delete forms[j];
        j++;
    }
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string forms_name[3] = {
        "presidential pardon", 
        "robotomy request", 
        "shrubbery creation"
    };
    
    
    AForm *forms[3] = {
        new PresidentialPardonForm(target), 
        new RobotomyRequestForm(target), 
        new ShrubberyCreationForm(target)
    };

    int i = 0;

    while(i < 3)
    {
        if (form == forms_name[i])
        {
            clear_forms(forms, i);
            return (forms[i]);
        }
        i++;
    }
    clear_forms(forms, i);
    throw FormNotFoundException();
}

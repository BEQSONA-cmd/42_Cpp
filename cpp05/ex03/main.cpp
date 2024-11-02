#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void subject(void)
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    Bureaucrat emanuel("Emanuel", 1);

    std::cout << *rrf << std::endl;
    emanuel.signForm(*rrf);
    emanuel.executeForm(*rrf);
    delete rrf;
}

void intern_catch()
{
    AForm *form1;
    AForm *form2;
    try
    {
        Intern intern;
        
        form1 = intern.makeForm("presidential pardon", "target1");
        form2 = intern.makeForm("unknow", "target2");
        (void)form2;

        delete form1;
    }
    catch (std::exception &err)
    {
        delete form1;
        std::cerr << err.what() << std::endl;
    }
}

void intern_execute()
{
    AForm *form1;
    AForm *form2;
    AForm *form3;

    Bureaucrat emanuel("Emanuel", 5);
    try
    {
        Intern intern;
        
        form1 = intern.makeForm("presidential pardon", "target1");
        form2 = intern.makeForm("robotomy request", "target2");
        form3 = intern.makeForm("shrubbery creation", "target3");

        emanuel.signForm(*form1);
        emanuel.signForm(*form2);
        emanuel.signForm(*form3);

        emanuel.executeForm(*form1);
        emanuel.executeForm(*form2);
        emanuel.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &err)
    {
        delete form1;
        delete form2;
        delete form3;
        std::cerr << err.what() << std::endl;
    }
}

int main()
{   
    std::cout << YELLOW << "\nSubject test: " << RESET << std::endl;
    subject();
    std::cout << YELLOW << "\nIntern catch test: " << RESET << std::endl;
    intern_catch();
    std::cout << YELLOW << "\nIntern execute test: " << RESET << std::endl;
    intern_execute();
    return 0;
}

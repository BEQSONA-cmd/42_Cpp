#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void sign_form()
{
    try
    {
        Bureaucrat emanuel("emanuel", 5);

        AForm some_form("some_form", 10, 10);

        emanuel.signForm(some_form);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

void already_signed()
{
    try
    {
        Bureaucrat emanuel("emanuel", 5);

        AForm some_form("some_form", 10, 10);

        emanuel.signForm(some_form);

        Bureaucrat tobi("tobi", 1);

        tobi.signForm(some_form);

    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

void low_grade_to_sign(void)
{
        try
    {
        Bureaucrat emanuel("emanuel", 15);

        AForm some_form("some_form", 10, 10);

        emanuel.signForm(some_form);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

void form_exceptions(void)
{
    try
    {
        AForm some_form("some_form", 0, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        AForm some_form("some_form", 10, 0);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
        try
    {
        AForm some_form("some_form", 151, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        AForm some_form("some_form", 10, 151);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

// ShrubberyCreationForm = signGrade 145, execGrade 137
void shrubbery_creation_form()
{
    try
    {
        Bureaucrat emanuel("emanuel", 135);

        ShrubberyCreationForm sh_form = ShrubberyCreationForm("home");

        emanuel.signForm(sh_form);
        emanuel.executeForm(sh_form);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

// RobotomyRequestForm = signGrade 72, execGrade 45
void robotomy_request_form()
{
    try
    {
        Bureaucrat emanuel("emanuel", 45);

        RobotomyRequestForm robotomy_form = RobotomyRequestForm("home");

        emanuel.signForm(robotomy_form);
        emanuel.executeForm(robotomy_form);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}

// PresidentialPardonForm = signGrade 25, execGrade 5
void presidential_pardon_form()
{
    try
    {
        Bureaucrat emanuel("emanuel", 5);

        PresidentialPardonForm president_form = PresidentialPardonForm("home");

        emanuel.signForm(president_form);
        emanuel.executeForm(president_form);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
}


int main()
{   
    std::cout << YELLOW << "Sign form: " << RESET << std::endl;
    sign_form();
    std::cout << YELLOW << "\nLow grade to sign: " << RESET << std::endl;
    low_grade_to_sign();
    std::cout << YELLOW << "\nAlready signed: " << RESET << std::endl;
    already_signed();
    std::cout << YELLOW << "\nAForm exceptions: " << RESET << std::endl;
    form_exceptions();
    std::cout << YELLOW << "\nshrubbery creation form: " << RESET << std::endl;
    shrubbery_creation_form();
    std::cout << YELLOW << "\nrobotomy request form: " << RESET << std::endl;
    robotomy_request_form();
    std::cout << YELLOW << "\npresidential pardon form: " << RESET << std::endl;
    presidential_pardon_form();
    return 0;
}
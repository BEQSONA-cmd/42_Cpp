#include "Bureaucrat.hpp"
#include "Form.hpp"

void sign_form()
{
    try
    {
        Bureaucrat emanuel("emanuel", 5);

        Form some_form("some_form", 10, 10);

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

        Form some_form("some_form", 10, 10);

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

        Form some_form("some_form", 10, 10);

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
        Form some_form("some_form", 0, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        Form some_form("some_form", 10, 0);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
        try
    {
        Form some_form("some_form", 151, 10);
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    try
    {
        Form some_form("some_form", 10, 151);
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
    std::cout << YELLOW << "\nForm exceptions: " << RESET << std::endl;
    form_exceptions();
    return 0;
}
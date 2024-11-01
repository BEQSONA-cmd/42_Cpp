#include "Form.hpp"

Form::Form()
{
    std::cout << YELLOW << "Form: Default constructor called" << RESET << std::endl;
}

Form::Form(const Form &form)
{
    this->operator=(form);
    std::cout << YELLOW << "Form: Copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &form)
{
    this->name = form.name;
    this->is_signed = form.is_signed;
    this->signGrade = form.signGrade;
    this->execGrade = form.execGrade;
    std::cout << YELLOW << "Form: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade() << ", is_signed: " << form.getIsSigned();
    return out;
}

Form::~Form()
{
    // std::cout << RED << "Form: Destructor called" << RESET << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
{
    this->name = name;
    this->is_signed = false;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    this->signGrade = signGrade;
    this->execGrade = execGrade;
}

std::string Form::getName() const{
    return this->name;
}

bool Form::getIsSigned() const{
    return this->is_signed;
}

int Form::getSignGrade() const{
    return this->signGrade;
}

int Form::getExecGrade() const{
    return this->execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
    {
        std::string message = RED + bureaucrat.getName() + " cannot sign " + this->name + " because his grade is too low" + RESET;
        throw Exception(message);
    }
    else if (this->is_signed)
        throw FormIsAlreadySignedException();
    else
    {
        this->is_signed = true;
        std::cout << GREEN << bureaucrat.getName() << " signs " << this->name << RESET << std::endl;
    }
}

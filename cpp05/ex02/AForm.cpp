#include "AForm.hpp"

AForm::AForm()
{
}

AForm::AForm(const AForm &form)
{
    this->operator=(form);
}

AForm &AForm::operator=(const AForm &form)
{
    this->name = form.name;
    this->is_signed = form.is_signed;
    this->signGrade = form.signGrade;
    this->execGrade = form.execGrade;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm: " << form.getName() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade() << ", is_signed: " << form.getIsSigned();
    return out;
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int signGrade, int execGrade)
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

std::string AForm::getName() const{
    return this->name;
}

std::string AForm::getTarget() const{
    return this->target;
}

bool AForm::getIsSigned() const{
    return this->is_signed;
}

int AForm::getSignGrade() const{
    return this->signGrade;
}

int AForm::getExecGrade() const{
    return this->execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
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

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->execGrade)
    {
        std::string message = RED + executor.getName() + " cannot execute " + this->name + " because his grade is too low" + RESET;
        throw Exception(message);
    }
    if (!this->is_signed)
    {
        std::string message = RED + executor.getName() + " cannot execute " + this->name + " because the form is not signed" + RESET;
        throw Exception(message);
    }
    this->action();
}

void AForm::action() const
{
    std::cout << "AForm: " << this->name << " action" << std::endl;
}
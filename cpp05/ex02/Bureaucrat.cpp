#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    this->name = bureaucrat.name;
    this->grade = bureaucrat.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->name = bureaucrat.name;
    this->grade = bureaucrat.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

// Custom constructor

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->name = name;
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::incrementGrade(int n)
{
    if (this->grade - n < 1)
        throw GradeTooHighException();
    this->grade -= n;
}

void Bureaucrat::decrementGrade(int n)
{
    if (this->grade + n > 150)
        throw GradeTooLowException();
    this->grade += n;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << BLUE << "Bureaucrat: " << bureaucrat.getName() << ", grade " << bureaucrat.getGrade() << RESET;
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) const
{
    form.execute(*this);
}
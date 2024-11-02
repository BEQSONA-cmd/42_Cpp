#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    this->name = "PresidentialPardonForm";
    this->is_signed = false;
    this->signGrade = 25;
    this->execGrade = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform) : AForm(presidentialpardonform)
{
    this->operator=(presidentialpardonform);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialpardonform)
{
    this->name = presidentialpardonform.name;
    this->is_signed = presidentialpardonform.is_signed;
    this->signGrade = presidentialpardonform.signGrade;
    this->execGrade = presidentialpardonform.execGrade;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->target = target;
    this->name = "PresidentialPardonForm";
    this->is_signed = false;
    this->signGrade = 25;
    this->execGrade = 5;
}

void PresidentialPardonForm::action() const
{
    std::cout << BLUE << this->getTarget() << GREEN << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}
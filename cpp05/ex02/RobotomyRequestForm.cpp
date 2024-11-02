#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->name = "RobotomyRequestForm";
    this->is_signed = false;
    this->signGrade = 72;
    this->execGrade = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform) : AForm(robotomyrequestform)
{
    this->operator=(robotomyrequestform);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyrequestform)
{
    this->name = robotomyrequestform.name;
    this->is_signed = robotomyrequestform.is_signed;
    this->signGrade = robotomyrequestform.signGrade;
    this->execGrade = robotomyrequestform.execGrade;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    this->target = target;
    this->name = "RobotomyRequestForm";
    this->is_signed = false;
    this->signGrade = 72;
    this->execGrade = 45;
}

int get_random_number()
{
    int random_number = 0;
    srand(time(0));
    random_number = rand();
    return random_number;
}

void RobotomyRequestForm::action() const
{
    std::cout << YELLOW << "Drilling noises..." << RESET << std::endl;
    if (get_random_number() % 2)
        std::cout << BLUE << this->getTarget() << GREEN << " has been robotomized successfully." << RESET << std::endl;
    else
        std::cout << BLUE << this->getTarget() << RED << " robotomization failed." << RESET << std::endl;
}
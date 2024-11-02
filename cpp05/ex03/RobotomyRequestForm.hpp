#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyrequestform);
        ~RobotomyRequestForm();

        RobotomyRequestForm(std::string target);
        void action() const;
};

#endif

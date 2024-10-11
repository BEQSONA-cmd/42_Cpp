#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << YELLOW << "WrongCat: Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal(wrongcat) 
{
    this->type = wrongcat.type;
    std::cout << YELLOW << "WrongCat: Copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    this->type = wrongcat.type;
    std::cout << YELLOW << "WrongCat: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << RED << "WrongCat: Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << BLUE << "WOEM WOEM WOEM\n" << RESET << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}

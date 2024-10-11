#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << YELLOW << "WrongAnimal: Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
    this->type = wronganimal.type;
    std::cout << YELLOW << "WrongAnimal: Copy constructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
    this->type = wronganimal.type;
    std::cout << YELLOW << "WrongAnimal: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal: Destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << BLUE << "the WRONG SOUND\n" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

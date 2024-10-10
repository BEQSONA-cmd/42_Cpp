#include "Brain.hpp"

Brain::Brain()
{
    std::cout << YELLOW << "Brain: Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &brain)
{
    this->operator=(brain);
    std::cout << YELLOW << "Brain: Copy constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    std::cout << YELLOW << "Brain: Assignment operator called" << RESET << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << RED << "Brain: Destructor called" << RESET << std::endl;
}

void Brain::new_idea(std::string idea)
{
    int i = 0;
    while(i < 100)
    {
        if (this->ideas[i] == "")
        {
            this->ideas[i] = idea;
            break;
        }
        i++;
    }
}

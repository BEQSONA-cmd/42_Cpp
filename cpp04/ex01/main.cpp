#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <vector>

// subject main
// int main(void)
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;
//     delete i;
//     return 0;
// }


// my main

int main(void)
{
    // // testing Brain class
    // std::cout << CYAN "\nBrain class test\n" RESET << std::endl;

    // Brain *brain = new Brain();
    // Brain *brain1 = new Brain(*brain);
    // Brain *brain2 = new Brain();

    // *brain2 = *brain1;

    // delete brain;
    // delete brain1;
    // delete brain2;

    // // testing Animal class
    // std::cout << CYAN "\nAnimal class test" RESET << std::endl;
    // std::cout << CYAN "While Animal class does not have brain, it should not call Brain constructor or destructor\n" RESET << std::endl;
    // Animal *animal = new Animal();

    // delete animal;

    int i = 0;
    std::vector<std::string> ideas;

    while(i < 10)
    {
        ideas.push_back("new idea");
        i++;
    }
    i = 0;

    Cat cat;
    Dog dog;

    while(i < 10)
    {
        // std::cout << ideas[i] << std::endl;
        cat.get_brain()->new_idea(ideas[i]);
        i++;
    }
    i = 0;
    while(i < 10)
    {
        std::cout << GREEN "this is cat brain idea:" BLUE << cat.get_brain()->ideas[i] << RESET << std::endl;
        std::cout << GREEN "this is dog brain idea:" BLUE << dog.get_brain()->ideas[i] << RESET << std::endl;
        i++;
    }
    return 0;
}
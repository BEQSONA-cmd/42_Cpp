#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <vector>

int main(void)
{
    // Animal *animal = new Animal();

    // delete animal;

    // Animal test;

    Animal *dog = new Dog();
    Animal *cat = new Cat();

    // makesound 

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;
}
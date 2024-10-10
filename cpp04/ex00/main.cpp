#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }

// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat();
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete i;

//     return 0;
// }


int main(void)
{
    // Testing without polymorphism

    // getType test:
    std::cout << CYAN "\ngetType() test" RESET << std::endl;
    WrongAnimal *Frog = new WrongAnimal();
    std::cout << GREEN "\ntype of Frog is: " BLUE << Frog->getType() << std::endl << std::endl;
    WrongAnimal *wrongcat = new WrongCat();
    std::cout << GREEN "\nif WrongCat is inherits from WrongAnimal, it should still have type but it should be 'WrongCat'"  << std::endl << std::endl;
    std::cout << "type of wrongcat is: " BLUE << wrongcat->getType() << RESET << std::endl << std::endl;

    delete Frog;
    delete wrongcat;

    // makeSound test
    std::cout << CYAN "\nmakeSound() test" RESET << std::endl;
    WrongAnimal *frog1 = new WrongAnimal();
    std::cout << GREEN "\nfrog1 makes sound" << std::endl;
    frog1->makeSound();
    WrongAnimal *wrongcat1 = new WrongCat();
    std::cout << GREEN "\nwrongcat1 makes sound, while its not polymorphism it will not access a derived class function" << std::endl;
    wrongcat1->makeSound();

    delete frog1;
    delete wrongcat1;

    // Testing with polymorphism

    // getType test:
    std::cout << CYAN "\ngetType() test" RESET << std::endl;
    Animal *animal = new Animal();
    std::cout << GREEN "\ntype of animal is: " BLUE << animal->getType() << std::endl << std::endl;
    Animal *cat = new Cat();
    std::cout << GREEN "\nif Cat is inherits from Animal, it should still have type but it should be 'Cat'"  << std::endl << std::endl;
    std::cout << "type of cat is: " BLUE << cat->getType() << RESET << std::endl << std::endl;

    delete animal;
    delete cat;

    // makeSound test
    std::cout << CYAN "\nmakeSound() test" RESET << std::endl;
    Animal *animal1 = new Animal();
    std::cout << GREEN "\nanimal1 makes sound" << std::endl;
    animal1->makeSound();
    Animal *cat1 = new Cat();
    std::cout << GREEN "\ncat1 makes sound, while its polymorphism it will access a derived class function" << std::endl;
    cat1->makeSound();

    delete animal1;
    delete cat1;
}
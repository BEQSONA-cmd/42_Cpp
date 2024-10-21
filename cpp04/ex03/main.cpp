#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// subject main
// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");

//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

void clone_tests(void)
{
    Ice ice;
    Cure cure;

    AMateria *ice_clone = ice.clone();
    AMateria *cure_clone = cure.clone();

    std::cout << GREEN "Ice clone type: " BLUE << ice_clone->getType() << RESET << std::endl;
    std::cout << GREEN "Cure clone type: " BLUE << cure_clone->getType() << RESET << std::endl;

    delete ice_clone;
    delete cure_clone;
}

void interface_tests(void)
{
    IMateriaSource* src = new MateriaSource();

    std::cout << GREEN "Materia Source interface tests passed." << RESET << std::endl;

    ICharacter* emanuel = new Character("Emanuel");

    std::cout << GREEN "Character interface tests passed." << RESET << std::endl;

    delete emanuel;
    delete src;
}

void use_tests(void)
{
    std::cout << YELLOW "basic use test" << RESET << std::endl;
    Ice ice;
    Cure cure;

    ICharacter* emanuel = new Character("Emanuel");

    ice.use(*emanuel);
    cure.use(*emanuel);

    delete emanuel;

    std::cout << YELLOW "\nuse tests with multiple materia" << RESET << std::endl;

    AMateria *ice2 = new Ice();
    AMateria *cure2 = new Cure();
    AMateria *ice3 = new Ice();
    AMateria *cure3 = new Cure();

    ICharacter* emanuel2 = new Character("Emanuel");

    emanuel2->equip(ice2);
    emanuel2->equip(cure2);
    emanuel2->equip(ice3);
    emanuel2->equip(cure3);

    std::cout << YELLOW "\nshould use cure" << RESET << std::endl;
    emanuel2->use(3, *emanuel2);

    std::cout << YELLOW "\nshould use ice" << RESET << std::endl;
    emanuel2->use(0, *emanuel2);

    std::cout << YELLOW "\nshould use cure" << RESET << std::endl;
    emanuel2->use(1, *emanuel2);

    std::cout << YELLOW "\nshould use ice" << RESET << std::endl;
    emanuel2->use(2, *emanuel2);

    delete emanuel2;
}

void equip_unequip_tests(void)
{
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    ICharacter* emanuel = new Character("Emanuel");

    emanuel->equip(ice);
    emanuel->equip(cure);

    emanuel->use(0, *emanuel);
    emanuel->use(1, *emanuel);
    std::cout << GREEN "equip tests passed.\n" << RESET << std::endl;

    emanuel->unequip(0);
    emanuel->unequip(1);
    
    emanuel->use(0, *emanuel);
    emanuel->use(1, *emanuel);
    std::cout << GREEN "unequip tests passed." << RESET << std::endl;

    AMateria *ice2 = new Ice();
    AMateria *ice3 = new Ice();
    AMateria *ice4 = new Ice();
    AMateria *ice5 = new Ice();
    AMateria *cure2 = new Cure();

    emanuel->equip(ice2);
    emanuel->equip(ice3);
    emanuel->equip(ice4);
    emanuel->equip(ice5);
    emanuel->equip(cure2);

    std::cout << YELLOW "\n last added is 'ice' the cure is at index 4" << RESET << std::endl;
    emanuel->use(3, *emanuel);

    std::cout << YELLOW "\n use(4) should not work" << RESET << std::endl;
    emanuel->use(4, *emanuel);

    emanuel->unequip(0);
    emanuel->unequip(1);
    emanuel->unequip(2);
    emanuel->unequip(3);

    std::cout << YELLOW "\n unequip(4) should not work" << RESET << std::endl;
    emanuel->unequip(4);

    delete emanuel;
    delete ice;
    delete cure;

    delete ice2;
    delete ice3;
    delete ice4;
    delete ice5;
    delete cure2;
}


int main(void)
{
    // std::cout << YELLOW "tests for clone function" RESET << std::endl;
    // clone_tests();

    // std::cout << YELLOW "\ntests for interface functions" RESET << std::endl;
    // interface_tests();

    // std::cout << YELLOW "\ntests for use function" RESET << std::endl;
    // use_tests();

    std::cout << YELLOW "\ntests for equip and unequip functions" RESET << std::endl;
    equip_unequip_tests();

    return 0;
}
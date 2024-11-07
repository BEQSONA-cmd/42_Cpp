#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

int get_random_number(int min, int max)
{
    srand(time(0));
    int random_number = rand() % (max - min + 1) + min;
    return random_number;
}

Base *generate(void)
{
    int random_number = get_random_number(1, 3);
    Base *ptr = NULL;
    switch (random_number)
    {
        case 1: ptr = new A(); break;
        case 2: ptr = new B(); break;
        case 3: ptr = new C(); break;
    }
    return ptr;
}

int get_ptr(Base *ptr[3])
{
    int i = 0;
    while (i < 3)
    {
        if (ptr[i] != NULL)
            return i;
        i++;
    }
    return -1;
}

void identify(Base* p)
{
    Base *ptr[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
    int num = get_ptr(ptr);

    switch (num)
    {
        case 0: std::cout << YELLOW << "Base pointer is pointing to A" << RESET << std::endl; break;
        case 1: std::cout << GREEN << "Base pointer is pointing to B" << RESET << std::endl; break;
        case 2: std::cout << CYAN << "Base pointer is pointing to C" << RESET << std::endl; break;
        default: std::cout << RED << "Base pointer is pointing to unknown class" << RESET << std::endl; break;
    }
}

void identify(Base& p)
{
    try
    {
        if(&p == dynamic_cast<A*>(&p))
            std::cout << YELLOW << "Base reference is pointing to A" << RESET << std::endl;
        else if(&p == dynamic_cast<B*>(&p))
            std::cout << GREEN << "Base reference is pointing to B" << RESET << std::endl;
        else if(&p == dynamic_cast<C*>(&p))
            std::cout << CYAN << "Base reference is pointing to C" << RESET << std::endl;
        else
            throw std::exception();
    }
    catch(const std::exception& err)
    {
        std::cerr << RED << "Base reference is pointing to unknown class" << RESET << std::endl;
    }
}
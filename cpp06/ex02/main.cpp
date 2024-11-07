#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void basic_case(void)
{
    Base *ptr = new A();
    identify(ptr);
    identify(*ptr);
    delete ptr;

    ptr = new B();
    identify(ptr);
    identify(*ptr);
    delete ptr;

    ptr = new C();
    identify(ptr);
    identify(*ptr);
    delete ptr;
}

void undefiend_class(void)
{
    Base *ptr = new Base();
    identify(ptr);
    identify(*ptr);
    delete ptr;
}

int main(void)
{
    std::cout << YELLOW "Generate random class\n" << std::endl;
    Base *ptr = generate();
    // void identify(Base *p);
    identify(ptr);
    // void identify(Base& p);
    identify(*ptr);

    std::cout << YELLOW "\nBasic cases\n" << RESET << std::endl;
    basic_case();

    std::cout << YELLOW "\nUndefined class\n" << RESET << std::endl;
    undefiend_class();
    
    delete ptr;
    return 0;
}
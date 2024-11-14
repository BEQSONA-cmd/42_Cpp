#include "MutantStack.hpp"
#include <vector>
#include <list>

void stack_constructor(void)
{
    std::cout << YELLOW << "Stack constructors" << RESET << std::endl;
    std::stack<int> stack;
    stack.push(5);

    std::cout << GREEN << stack.top() << RESET << std::endl;

    std::stack<int> stack2(stack);

    std::cout << GREEN << stack2.top() << RESET << std::endl;

    stack2 = stack;

    std::cout << GREEN << stack2.top() << RESET << std::endl;


    std::cout << YELLOW << "MutantStack constructors" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);

    std::cout << GREEN << mstack.top() << RESET << std::endl;

    MutantStack<int> mstack2(mstack);

    std::cout << GREEN << mstack2.top() << RESET << std::endl;

    mstack2 = mstack;

    std::cout << GREEN << mstack2.top() << RESET << std::endl;
}

void vector_iter(void)
{
    std::vector<int> vec;

    int i = 0;
    while(i < 10)
    {
        vec.push_back(i);
        i++;
    }

    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator ite = vec.end();

    while(it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void list_iter(void)
{
    std::list<int> lst;

    int i = 0;
    while(i < 10)
    {
        lst.push_back(i);
        i++;
    }

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    while(it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
}


// void stack_iter(void)
// {
//     std::stack<int> stack;

//     int i = 0;
//     while(i < 10)
//     {
//         stack.push(i);
//         i++;
//     }

//     std::stack<int>::iterator it = stack.begin();
//     std::stack<int>::iterator ite = stack.end();

//     while(it != ite)
//     {
//         std::cout << *it << std::endl;
//         it++;
//     }
// }

void mutantstack_iter(void)
{
    MutantStack<int> stack;

    int i = 0;
    while(i < 10)
    {
        stack.push(i);
        i++;
    }

    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator ite = stack.end();

    while(it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
}

int main(void)
{
    std::cout << GREEN << "Constructor test: " << RESET << std::endl;
    stack_constructor();

    std::cout << GREEN << "Vector iterator: " << RESET << std::endl;
    vector_iter();

    std::cout << GREEN << "List iterator: " << RESET << std::endl;
    list_iter();

    std::cout << GREEN << "MutantStack iterator: " << RESET << std::endl;
    mutantstack_iter();

    return 0;
}

// void subject_m_stack()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
// }

// void subject_list()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::list<int> s(mstack);
// }

// int main(void)
// {
//     std::cout << GREEN << "Subject MutantStack" << RESET << std::endl;
//     subject_m_stack();
//     std::cout << GREEN << "Subject List" << RESET << std::endl;
//     subject_list();
//     return 0;
// }

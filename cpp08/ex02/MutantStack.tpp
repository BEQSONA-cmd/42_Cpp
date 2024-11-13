#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mutantstack)
{
    *this = mutantstack;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &mutantstack)
{
    if (this == &mutantstack)
        return *this;
    std::stack<T>::operator=(mutantstack);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() 
{

}
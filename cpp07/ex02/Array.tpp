#include "Array.hpp"
#include <limits>

template <typename T> 
Array<T>::Array(unsigned int n)
{
    this->array = new T[n];
    this->_size = n;
}

template <typename T> 
Array<T>::Array(void)
{
    this->array = new T[0];
    this->_size = 0;
}
template <typename T> 
Array<T>::Array(const Array &array){
    this->array = NULL;
    this->_size = 0;
    this->operator=(array);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array)
{
    unsigned int i = 0;
    if (this != &array) 
    {
        if(this->_size > 0)
        {
            std::cout << this->_size << std::endl;
            delete[] this->array;
        }
        this->_size = array._size;
        this->array = new T[this->_size];
        while (i < this->_size)
        {
            this->array[i] = array.array[i];
            i++;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(){
    delete[] this->array;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
    out << array;
    return out;
}

template <typename T>
T &Array<T>::operator[](unsigned int iter)
{
    if (iter >= this->_size)
        throw this->outOfBoundsException();
    return this->array[iter];
}

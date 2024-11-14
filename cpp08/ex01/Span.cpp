#include "Span.hpp"

Span::Span()
{
    this->len = 0;
}

Span::Span(unsigned int N)
{
    this->len = N;
}

Span::Span(Span const &other)
{
    this->operator=(other);
}

Span &Span::operator=(Span const &other)
{
    this->len = other.len;
    this->arr = other.arr;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (this->arr.size() >= this->len)
        throw ArrayIsFull();
    this->arr.push_back(n);
}

void Span::addNumber(int n, unsigned int times)
{
    unsigned int i = 0;
    while (i < times)
    {
        this->addNumber(n);
        i++;
    }
}

int Span::longestSpan(void)
{
    std::sort(this->arr.begin(), this->arr.end());
    if (this->arr.size() < 2)
        throw NotEnoughElements();
    if  (this->arr.size() == 2)
        return this->arr[1] - this->arr[0];
    int first = this->arr.front();
    int last = this->arr.back();
    int span = last - first;
    return span;
}

int Span::shortestSpan(void)
{
    std::sort(this->arr.begin(), this->arr.end());
    if (this->arr.size() < 2)
        throw NotEnoughElements();
    if  (this->arr.size() == 2)
        return this->arr[1] - this->arr[0];
    int min = 0;
    size_t i = 0;
    while (i < this->arr.size() - 1)
    {
        int diff = this->arr[i + 1] - this->arr[i];
        if (i == 0 || diff < min)
            min = diff;
        i++;
    }
    return min;
}
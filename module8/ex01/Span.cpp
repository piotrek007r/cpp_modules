#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        this->N = other.N;
        this->numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(unsigned int num)
{
    if(this->numbers.size() < this->N)
    {
        this->numbers.push_back(num);
    }
    else
        throw std::runtime_error("container is full and u cant add more numbers!");
}

unsigned int Span::longestSpan() const
{
    if(this->numbers.size() < 2)
        throw std::runtime_error("container has not enough elements!");

    t_vector::const_iterator start = this->numbers.begin();
    t_vector::const_iterator end = this->numbers.end();
    t_vector::const_iterator min = std::min_element(start, end);
    t_vector::const_iterator max = std::max_element(start, end);

    return *max - *min;
}

unsigned int Span::shortestSpan() const
{
    if(this->numbers.size() < 2)
        throw std::runtime_error("container has not enough elements!");

    t_vector tmp = this->numbers;
    unsigned int diff = 0;
    unsigned int mindiff = tmp[1] - tmp[0];

    std::sort(tmp.begin(), tmp.end());
    for(unsigned int i = 1; i < tmp.size(); i++)
    {
        diff = tmp[i] - tmp[i - 1];
        if(diff < mindiff)
            mindiff = diff;
    }
    return mindiff;
}

unsigned int randomGen()
{
    return rand() % 100;
}

void Span::fiilCon(unsigned int num)
{   
    this->numbers.resize(num);
    std::generate(numbers.begin(), numbers.end(), randomGen);
}

unsigned int Span::getNumbersIter(unsigned int num) const
{
    return this->numbers[num];
}
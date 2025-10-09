#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <algorithm>

class Span 
{
    private:
        typedef std::vector<unsigned int> t_vector;
        unsigned int N;
        t_vector numbers;

    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(unsigned int num);
        void fiilCon(unsigned int num);
        unsigned int longestSpan() const;
        unsigned int shortestSpan() const;
        unsigned int getNumbersIter(unsigned int num) const;
};

#endif
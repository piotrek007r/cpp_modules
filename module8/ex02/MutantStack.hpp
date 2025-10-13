#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <cstddef>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        iterator begin(); 
        iterator end();
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack &operator=(const MutantStack& other);
};

#include "MutantStack.tpp"

#endif

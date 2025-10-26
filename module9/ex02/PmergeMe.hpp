#ifndef PMERFRME_HPP
#define PMERFRME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <iterator>
#include <cmath>

#define c std::cout
#define e std::endl

struct listEl {
    size_t number;
    std::list<listEl>::iterator loseTo;  
    std::list<listEl>::iterator winTo;   
};
struct vectorEl {
    size_t number;
    size_t loseTo;
    size_t winTo;
};

typedef std::list<listEl>::iterator iterLst;
typedef std::vector<vectorEl>::iterator iter; 

class PmergeMe
{
    private:
        std::vector<vectorEl> vector;
        std::vector<vectorEl> loserVector;
        std::list<listEl> list;
        size_t level;
        
        public:
        PmergeMe(std::vector<int> vec, std::list<int> lst);
        void mergeList();
        void insertionList();
        void mergeVector();
        void main();
    };

    #endif
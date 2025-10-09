#include "Span.hpp"

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        Span *span;
        srand(time(NULL));
        std::istringstream iss(argv[1]);
        unsigned int N;
        if(!(iss >> N))
        {
            std::cout << "type integer to specify length of container" << std::endl;
            return 1;
        }
        span = new Span(N);
        // test for filling vector with N number of elements
        span->fiilCon(N);
        for(unsigned int i = 0; i < N; i++)
            std::cout << span->getNumbersIter(i) << std::endl;
        // test for pushing vector over the limit
        try
        {
            span->addNumber(static_cast<unsigned int>(rand() % 100));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        // display longest span
        try
        {
            int min = span->longestSpan();
            std::cout << "longest span is: " << min << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        // display shortest span
        try
        {
            int max = span->shortestSpan();
            std::cout << "shortest span is: " << max << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete span;
        return 0;
    }
    else
    {
        std::cout << "type integer to specify length of container" << std::endl;
        return 1;
    }
}
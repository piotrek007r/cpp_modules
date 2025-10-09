#include "easyfind.hpp"

int main()
{
    {
        int el = 2;
        int array[] = {1, 2, 3, 4, 5};
        std::vector<int> numbers(array, array + 5);
        easyfind(numbers, el);
        easyfind(numbers, el + 20);
    }
    std::cout << "------------\n";
    {
        char el = 'b';
        char array[] = "abcde";
        std::list<char> numbers(array, array + 5);
        easyfind(numbers, el);
        easyfind(numbers, el + 20);
    }

    return 0;
}
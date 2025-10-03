#include "iter.hpp"

int main()
{
    Point a = {1, 2};
    Point b = {3, 4};
    Point c = {5, 6};
    
    Point pointArr[3] = {a, b, c};
    int intArr[4] = {1, 2, 3, 4};
    char str[5] = "abcd";

    iter(intArr, 4, foo<int>);
    iter(str, 4, foo<char>);
    iter(pointArr, 3, foo<Point>);

    return 0;
}
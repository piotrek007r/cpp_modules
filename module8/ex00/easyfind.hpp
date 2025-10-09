#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iostream>


template <typename T>
void easyfind(T& con, int el)
{
	typename T::iterator iter =  std::find(con.begin(), con.end(), el);
	if(iter == con.end())
		std::cout << "could not find given element in container\n";
	else
		std::cout << "given element is: " << *iter << std::endl;
}

#endif

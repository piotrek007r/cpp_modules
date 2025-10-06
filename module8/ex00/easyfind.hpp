#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <array>
#include <list>>
#include <deque>
#include <forward_list>


template <typename T>
T easyfind(T con, int el)
{
	std::find(con.begin(), con.end(), el)
}

#endif

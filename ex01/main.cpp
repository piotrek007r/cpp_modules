#include "repertory.hpp"

Phonebook::Phonebook()
{
	limit = 8;
	cur_nb = 0;
	counter = 0;
}

Phonebook::~Phonebook() {};

int	main(void)
{
	Phonebook	phonebook;
	str			line;
	str			add;
	str			search;
	str			exit;

	add = "ADD";
	search = "SEARH";
	exit = "EXIT";
	while (1)
	{
		std::cout << "please type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, line);
		if (!line.compare(add))
			phonebook.add();
		if (!line.compare(search))
			phonebook.search();
		if (!line.compare(exit))
			break ;
	}
	system("clear");
}

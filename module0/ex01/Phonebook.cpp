#include "repertory.hpp"

str fillField()
{
	str input;

	std::getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "This field cannot be left empty!"	<< std::endl;
		std::getline(std::cin, input);
	}
	return input;
}

void Phonebook::add()
{
	str	name;
	str	last_name;
	str	nick_name;
	str	phone_number;
	str	darkest_secret;


	if (cur_nb == limit)
		cur_nb = 0;
	system("clear");
	std::cout << "type a first name :" << std::endl;
	name = fillField();
	contact_arr[cur_nb].setName(name);
	system("clear");

	std::cout << "type a last name" << std::endl;
	last_name = fillField();
	contact_arr[cur_nb].setSurname(last_name);
	system("clear");

	std::cout << "type a nickname" << std::endl;
	nick_name = fillField();
	contact_arr[cur_nb].setNickname(nick_name);
	system("clear");

	std::cout << "type a phone number" << std::endl;
	phone_number = fillField();
	contact_arr[cur_nb].setPhone(phone_number);
	system("clear");

	std::cout << "type a darkest secret" << std::endl;
	darkest_secret = fillField();
	contact_arr[cur_nb].setSecret(darkest_secret);
	system("clear");

	if((cur_nb < limit) && (counter < limit))
		counter++;
	cur_nb++;
}

str trunkStr(str str)
{
	if(str.length() > 9)
	 	str = str.substr(0, 9) + ".";
	return str;
}

void	Phonebook::search(void)
{
	str	input;
	int index = 0;
	int	i = 0;

	system("clear");
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "Name" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	while(i < counter)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << trunkStr(contact_arr[i].getName()) << "|";
		std::cout << std::setw(10) << trunkStr(contact_arr[i].getSurname())  << "|";
		std::cout << std::setw(10) << trunkStr(contact_arr[i].getNickname())  << std::endl;
		i++;
	}

	if(counter == 0)
	{
		std::cout << std::endl;
		std::cout << "List is empty, unable to search for anytching!" << std::endl;
		return;
	}

    std::cout << std::endl;
	std::cout << "type a index of chosen contact" << std::endl;

	while(1)
	{
		std::getline(std::cin, input);
		index = atoi(input.c_str());
		if(index <= 0 || index > counter)
			std::cout << "please type proper index number from 1 to 8" << std::endl;
		else
			break;
	}
	system("clear");
	std::cout << "First Name :" << contact_arr[index - 1].getName() << std::endl;
	std::cout << "Last Name :" << contact_arr[index - 1].getSurname() << std::endl;
	std::cout << "Nick Name :" << contact_arr[index - 1].getNickname() << std::endl;
	std::cout << "Phone Number :" << contact_arr[index - 1].getPhone() << std::endl;
	std::cout << "Darkest Secret :" << contact_arr[index - 1].getSecret() << std::endl;
    std::cout << std::endl;
}

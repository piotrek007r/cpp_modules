#include "repertory.hpp"

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();

	void add();
	void search();

	void getContact()
	{
		std::cout << contact_arr[cur_nb - 1].getName() << std::endl;
		std::cout << contact_arr[cur_nb - 1].getSurname() << std::endl;
		std::cout << contact_arr[cur_nb - 1].getPhone() << std::endl;
		std::cout << contact_arr[cur_nb - 1].getSecret() << std::endl;

	}

  private:
	int limit;
	int cur_nb;
	int counter;

	Contact contact_arr[8];
};
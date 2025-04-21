#include "repertory.hpp"

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();

	void add();
	void search();

  private:
	int limit;
	int cur_nb;
	int counter;

	Contact contact_arr[8];
};
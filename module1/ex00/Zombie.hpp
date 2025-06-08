#include "repertory.hpp"

class Zombie
{
  public:
	Zombie();
	~Zombie();

	void setName(std::string name);
	void announce(void);

  private:
	std::string name;
};


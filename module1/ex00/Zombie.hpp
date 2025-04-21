#include "repertory.hpp"

class Zombie
{
  public:
	Zombie();
	~Zombie();

	void setName(str name);
	void announce(void);

  private:
	str name;
};


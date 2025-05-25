#include "repertory.hpp"

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(str name);
        void annouce();

    private:
        str name;
        int index;
};
#include "repertory.hpp"

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void annouce();

    private:
        std::string name;
        int index;
};
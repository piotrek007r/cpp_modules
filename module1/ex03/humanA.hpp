#include "repertory.hpp"

class HumanA
{
    public:
        HumanA(str name, Weapon &weapon);
        ~HumanA();
        void attack();

    private:
        str name;
        Weapon &weapon;
};

#include "repertory.hpp"

class HumanB
{
    public:
        HumanB(str name);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();

    private:
        str name;
        Weapon *weapon;
};
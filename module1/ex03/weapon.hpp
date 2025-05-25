#include "repertory.hpp"

class Weapon
{
    public:
        Weapon(str type);
        ~Weapon();
        void setType(str type);
        str getType();

    private:
        str type;
};
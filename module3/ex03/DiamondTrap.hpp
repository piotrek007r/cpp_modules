#include "repertory.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        std::string getName();
        void attack(const std::string& target);
        void whoAmI();
};
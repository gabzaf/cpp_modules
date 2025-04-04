
#include "HumanA.hpp"

HumanA::HumanA(std::string aname, Weapon &aweapon) : name(aname), weapon(aweapon){}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

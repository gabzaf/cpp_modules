
#include "HumanB.hpp"

HumanB::HumanB(std::string bname) : name(bname), weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &bweapon)
{
	this->weapon = &bweapon;
}

void	HumanB::attack()
{
	if (!this->weapon)
	{
		std::cout << "HumanB " << this->name << "does not have a weapon." << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

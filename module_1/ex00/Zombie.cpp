
#include "Zombie.hpp"

Zombie::Zombie(std::string zname) : name(zname)
{
	std::cout << "Zombie " << this->name << " created!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

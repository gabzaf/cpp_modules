
#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = newZombie("Zumbido");
	z->announce();
	randomChump("Bolado");
	z->announce();
	delete z;
}

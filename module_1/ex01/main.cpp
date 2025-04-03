
#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies = zombieHorde(4, "Zumbido");
	if (zombies)
	{
		for (int i = 0; i < 4; i++)
			zombies[i].announce();
		delete [] zombies;
	}
	std::cout << std::endl << std::endl;
	zombies = zombieHorde(12, "Boladao");
	if (zombies)
	{
		for (int i = 0; i < 12; i++)
			zombies[i].announce();
		delete [] zombies;
	}
	std::cout << std::endl << std::endl;
	zombies = zombieHorde(0, "Guna");
	if (zombies)
	{
		for (int i = 0; i < 0; i++)
			zombies[i].announce();
		delete [] zombies;
	}




}

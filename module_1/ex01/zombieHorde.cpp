
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i;
	Zombie	*zombies;

	i = 0;
	if (N < 1)
		return (NULL);
	zombies = new Zombie[N];
	while (i < N)
	{
		zombies[i].set_name(name);
		i++;
	}
	return (zombies);
}

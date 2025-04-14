
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap Clap("Maria");
	Clap.attack("Joao");
	Clap.takeDamage(3);
	Clap.beRepaired(2);

	std::cout << std::endl;

	ScavTrap scav("Joao");
	scav.attack("target2");
	scav.takeDamage(20);
 	scav.beRepaired(10);
 	scav.guardGate();

	std::cout << std::endl;

	FragTrap frag("Fraggy");
	frag.attack("target3");
	frag.takeDamage(50);
	frag.beRepaired(40);
	frag.highFivesGuys();

	std::cout << std::endl;
    
	FragTrap fragCopy(frag);
	FragTrap fragAssign;
	fragAssign = frag;

	return (0);
}


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "---- DEFAULT CONSTRUCTOR ----" << std::endl;
	ScavTrap a;
	std::cout << std::endl << "---- ASSIGNMENT CONSTRUCTOR ----" << std::endl;
	ScavTrap m("Menino");
	std::cout << std::endl << "---- COPY CONSTRUCTOR ----" << std::endl;
	ScavTrap s(m);
	std::cout << std::endl << "---- ATTACK AND TAKE DAMAGE METHODS ----" << std::endl;
	ScavTrap b("Ney");
	ScavTrap j("Jorge");
	b.attack("Jorge");
	j.takeDamage(10);
	j.beRepaired(3);
	j.guardGate();



	return (0);
}

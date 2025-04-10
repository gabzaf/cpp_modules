
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Neymar");
	ClapTrap b("Messi");
	
	a.attack("Messi");
	b.takeDamage(3);
	b.beRepaired(2);

	b.attack("Neymar");
	a.takeDamage(6);
	a.beRepaired(8);

	a.attack("Messi");
	b.takeDamage(6);
	b.beRepaired(2);
	a.attack("Messi");
	b.takeDamage(5);

	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << std::endl;

	ClapTrap c = a;
	c.attack("Ronaldo");

	ClapTrap d;
	d = b;

	std::cout << std::endl << "------------------------------------------" << std::endl;
	
	ClapTrap e("Vini");
	d.attack("Vini");
	e.takeDamage(-7);
	e.beRepaired(-2);

	return (0);
}

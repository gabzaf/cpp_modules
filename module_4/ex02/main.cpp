#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		j->makeSound();
		i->makeSound();
		delete j;
		delete i;
	}
	std::cout << "\n" << std::endl;
	{
		const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
		for ( int i = 0; i < 4; i++ ) {
			delete animals[i];
		}
	}
	std::cout << "\n" << std::endl;
	{
		Dog myDog;
		Dog otherDog = myDog;
	}
	std::cout << "\n" << std::endl;
	{
		Cat myCat;
		Cat otherCat = myCat;
	}
	
	return 0;
}

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	
	std::cout << "---------SUBJECT TEST---------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "The type of this animal is " << j->getType() << " " << std::endl;
	std::cout << "The type of this animal is " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	
	
	std::cout << "\n" << std::endl;

	std::cout << "-------WRONG SUBJECT TEST-------" << std::endl;
	const WrongAnimal* cat = new WrongCat();
	std::cout << "The type of this animal is " << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!

	delete cat;
	
	return (0);
}

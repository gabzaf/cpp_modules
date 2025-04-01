#include <iostream>

char my_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
        	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        	return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; av[i][j] != '\0'; ++j)
		{
			std::cout << my_toupper(av[i][j]);
		}
		if (i < ac - 1 && av[i][0] != ' ')
            		std::cout << " ";
	}
	std::cout << " ";
	std::cout << std::endl;
	return (0);
}

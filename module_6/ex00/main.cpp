#include "scalarConverter.hpp"

int main(int ac, char **av)
{
    std::string input;
    if (ac  == 2)
    {
	input = av[1];
	//ScalarConverter c;
	//c.convert(input);
	ScalarConverter::convert(input);
	return (0);
    }
    std::cout << "Input one argument!" << std::endl;
    return (-1);
}

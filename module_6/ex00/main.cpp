#include "scalarConverter.hpp"

int main(int ac, char **av)
{
    std::string input;
    if (ac  == 2)
    {
        try
        {
            input = av[1];
            ScalarConverter c;
            c.convert(input);
            return (0);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;  
        }
    }

    std::cout << "Input one argument!" << std::endl;
    return (-1);
}
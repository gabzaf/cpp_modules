
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of str: " << &str << std::endl;
 	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
 	std::cout << "memory address of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "str: "<< str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}

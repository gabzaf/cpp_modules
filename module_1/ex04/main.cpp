

#include <iostream>
#include <string>
#include <fstream>

void	errMsg(const std::string& message)
{
	std::cerr << message << std::endl;
}

bool	doesFileExist(const std::string& input_file)
{
	std::ifstream	file(input_file.c_str());
	return (file.is_open());
}

int	isFileEmpty(const std::string input_file)
{
	std::ifstream	file(input_file.c_str());
	if (!file)
		return (1);
	return file.peek() == std::ifstream::traits_type::eof();
}

int	checkInputs(const std::string input_file, const std::string s1, const std::string s2)
{
	if (!doesFileExist(input_file))
	{
		errMsg("Err: File does not exist!");
		return (1);	
	}
	if (isFileEmpty(input_file))
	{
		errMsg("Err: Empty file!");
		return (1);
	}
	if (s1.empty() || s2.empty())
	{
		errMsg("Err: Empty s1 or s2!");
		return (1);
	}
	return (0);
}	

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string input_file = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		if (checkInputs(input_file, s1, s2))
			return (1);
	}
	else
	{
		errMsg("Err: Not enough inputs!");
		return (1);
	}
	return (0);
}

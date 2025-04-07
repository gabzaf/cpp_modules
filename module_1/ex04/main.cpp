

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

void	ft_replace(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::string	output_filename = filename + ".replace";
	std::ofstream	output(output_filename.c_str());
	if (!output.is_open())
	{
		errMsg("Err: Output file creation error.");
		return ;
	}
	std::ifstream	input_file(filename.c_str());
	std::string	line;
	while (std::getline(input_file, line))
	{
		size_t	locale = line.find(s1, 0);
		while (locale != std::string::npos)
		{
			line.erase(locale, s1.length());
			line.insert(locale, s2);
			locale += s2.length();
			locale = line.find(s1, locale);
		}
		output << line << std::endl;
	}
	input_file.close();
	output.close();
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
		ft_replace(input_file, s1, s2);
	}
	else
	{
		errMsg("Err: Not enough inputs!");
		return (1);
	}
	return (0);
}

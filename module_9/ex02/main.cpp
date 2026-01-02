#include "PmergeMe.hpp"
#include <cstring> 
#include <ctime> 
#include <iomanip> 

void	printInput(int ac, char** av)
{
	for (int i = 1; i < ac; i++)
		std::cout <<  av[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void	checkIfSorted(const T &container)
{
	typename T::const_iterator	it;
	for (it = container.begin(); it != container.end() - 1; it++)
	{
		if (*it > *(it + 1))
		{
			std::cerr << "--->Error: Not sorted numbers." << std::endl;
			return ;
		}
	}
	std::cout << "Sorted numbers" << std::endl;
}

template <typename T>
void	checkIfCorrectCount(const T &container, int count)
{
	if (container.size() != static_cast<size_t>(count))
	{
		std::cerr << "--->Error: Incorrect number of elements." << std::endl;
		return ;
	}
	std::cout << "--->Correct number of elements." << std::endl;
}

int	main (int ac, char** av)
{
	if (ac < 2)
		return (1);
	try
	{
		PmergeMe	sortMe;

		std::clock_t	startVec = std::clock();
		sortMe.parseInputVec(ac, av);
		sortMe.sortVector();
		std::clock_t endVec = std::clock();

		std::cout << "Before: ";
		printInput(ac, av);
		std::cout << "After: ";
		sortMe.print(sortMe.getVector());

		std::clock_t startDeq = std::clock();
		sortMe.parseInputDeq(ac, av);
		sortMe.sortDeque();
		std::clock_t endDeq = std::clock();
		
		double	timeVecSec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
		double	timeDeqSec = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << ac - 1
					<< " elements with std::vector : " << std::fixed << std::setprecision(5) 
					<< timeVecSec << " s" << std::endl;
		std::cout << "Time to process a range of " << ac - 1
					<< " elements with std::deque : " << std::fixed << std::setprecision(5) 
					<< timeDeqSec << " s" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) : _v_values(other._v_values), _d_values(other._d_values){}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_v_values = other._v_values;
		_d_values = other._d_values;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

std::vector<int>	PmergeMe::getVector() const{return (_v_values);}

std::deque<int>		PmergeMe::getDeque() const {return (_d_values);}

void	PmergeMe::parseInputVec(int ac, char** av)
{
	for (int i = 1; i < ac; i++)
	{
		if (std::string(av[i]).empty())
			throw (std::invalid_argument("Empty number."));
		char	*end;
		long	value = std::strtol(av[i], &end, 10);
		if (*end != '\0' || value > INT_MAX || value <= 0) 
			throw (std::invalid_argument("Invalid number: " + std::string(av[i])));
		if (std::find(_v_values.begin(), _v_values.end(), static_cast<int>(value)) != _v_values.end())
			throw (std::invalid_argument("Duplicate number: " + std::string(av[i])));
        	_v_values.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::parseInputDeq(int ac, char** av)
{
	for (int i = 1; i < ac; i++)
	{
		if (std::string(av[i]).empty())
			throw (std::invalid_argument("Empty number."));
		char	*end;
		long	value = std::strtol(av[i], &end, 10);
		if (*end != '\0' || value > INT_MAX || value <= 0)
			throw (std::invalid_argument("Invalid number: " + std::string(av[i])));
		if (std::find(_d_values.begin(), _d_values.end(), static_cast<int>(value)) != _d_values.end())
			throw (std::invalid_argument("Duplicate number: " + std::string(av[i])));
		_d_values.push_back(static_cast<int>(value));
	}
}

std::vector<long>	PmergeMe::generateJacobSequence(int n)
{
	std::vector<long>	jacob;    
	jacob.push_back(1);
	jacob.push_back(3);
	long	nextNumber = 5;
	for (size_t i = 3; nextNumber < n; i++)
	{
		jacob.push_back(nextNumber);
		nextNumber = 2 * jacob[i - 2] + jacob[i - 1];
	}
	jacob.erase(jacob.begin());
	return (jacob);
}

template <typename T>
void	PmergeMe::binarySearchInsert(T &cont, int element, size_t maxI)
{
	size_t	min = 0;
	size_t	max = std::min(maxI, cont.size());
	size_t	mid = 0;
	while (min < max)
	{
		mid = min + (max - min) / 2;
		if (element < cont[mid])
			max = mid;
		else
			min = mid + 1;
	}
	cont.insert(cont.begin() + min, element);
}

template <typename T>
void	PmergeMe::insertByJacob(T &mainChain, T &smallChain)
{
	std::vector<long>	jacob = generateJacobSequence(smallChain.size());
	binarySearchInsert(mainChain, smallChain[0], 0);
	size_t	insertedElements = 1;
	int	prevJacob = 1;

	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t	currJacob = jacob[i];
		if (currJacob <= smallChain.size())
		{
			for (int j = currJacob - 1; j >= prevJacob; j--)
			{
				binarySearchInsert(mainChain, smallChain[j], insertedElements + currJacob);
				insertedElements++;
			}
			prevJacob = currJacob;
		}
	}
	for (size_t i = prevJacob; i < smallChain.size(); i++)
	{
		binarySearchInsert(mainChain, smallChain[i], insertedElements + i);
		insertedElements++;
	}
}

template <typename T>
void	PmergeMe::swapPairs(T &cont)
{
	for (size_t i = 0; i < cont.size() - 1; i += 2)
	{
		if (cont[i] > cont[i + 1])
			std::swap(cont[i], cont[i + 1]);
	}
}

template <typename T>
T	PmergeMe::mergeInsertionSort(T &cont)
{
	if (cont.size() <= 1)
		return cont;
	swapPairs(cont);
	T	mainChain, smallChain;
	T	smallIdx;
	for (size_t i = 0; i < cont.size() - 1; i += 2)
	{
		mainChain.push_back(cont[i + 1]);
		smallChain.push_back(cont[i]);
		smallIdx.push_back(smallChain.size() - 1);
	}
	int	unpairedElement = 0;
	bool	unpaired = cont.size() % 2 != 0 ;
	if (unpaired)
		unpairedElement = cont.back();
	mainChain = mergeInsertionSort(mainChain);
	T	reorderedSmallIdx;
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < mainChain.size(); j++)
		{
			if (mainChain[i] == cont[j * 2 + 1])
			{
				reorderedSmallIdx.push_back(smallIdx[j]);
				break;
			}
		}
	}
	T	reorderedSmallChain(reorderedSmallIdx.size());
	for (size_t i = 0; i < reorderedSmallIdx.size(); i++)
		reorderedSmallChain[i] = smallChain[reorderedSmallIdx[i]];
	smallChain = reorderedSmallChain;
	insertByJacob(mainChain, smallChain);
	if (unpaired)
		binarySearchInsert(mainChain, unpairedElement, mainChain.size());
	return (mainChain);
}

void PmergeMe::sortVector(){_v_values = mergeInsertionSort(_v_values);}

void PmergeMe::sortDeque(){_d_values = mergeInsertionSort(_d_values);}

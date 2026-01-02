#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <algorithm>

class 	PmergeMe 
{
	private:
		std::vector<int>	_v_values;
		std::deque<int>		_d_values;

 		std::vector<long> generateJacobSequence(int n);
		template <typename T>
		void binarySearchInsert(T &cont, int element, size_t maxI);
		template <typename T>
		void insertByJacob(T &mainChain, T &smallChain);
		template <typename T>
		void swapPairs(T &cont);
		template <typename T>
		T mergeInsertionSort(T &cont);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);

		void	parseInputVec(int ac, char** av);
		void	parseInputDeq(int ac, char** av);
		void	sortVector();
		void	sortDeque();

		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;

		template <typename T>
		void	print(const T &container) const;
};

template <typename T>
void	PmergeMe::print(const T& container) const
{
	typename T::const_iterator	it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

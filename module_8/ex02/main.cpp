#include "MutantStack.hpp"

int	main()
{
	MutantStack<int>    mstack;
	std::cout << "=== Push 5 ===" << std::endl;
	mstack.push(5);
	std::cout << "=== Push 17 ===" << std::endl;
	mstack.push(17);
	std::cout << "\n=== Top element ===" << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "\n=== Pop top element ===" << std::endl;
	mstack.pop();
	std::cout << "\n=== Size after pop ===" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "\n=== Push more elements (3, 5, 737, 0) ===" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "\n=== Iterate over MutantStack ===" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n=== Copy MutantStack into std::stack ===" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Copied stack size: " << s.size() << std::endl;
	std::cout << "Top of copied stack: " << s.top() << std::endl;
	return (0);
}

#include "Span.hpp"

void	printString(std::string stg)
{
	std::cout << stg << std::endl;
}

int main()
{
        printString("SUBJECT TEST");
        Span test1 = Span(5);
	try
	{
		test1.addNumber(6);
		test1.addNumber(3);
		test1.addNumber(17);
		test1.addNumber(9);
		test1.addNumber(11);
		test1.printNbrs();
		printString("===== Shortest Span =====");
		std::cout << test1.shortestSpan() << std::endl;
		printString("===== Longest Span =====");
		std::cout << test1.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	{
		srand(time(0));
		std::vector<int> bigVec;
		for (size_t i = 0; i < 15000; ++i)
			bigVec.push_back(rand());
		std::cout << "BigSpan fill" << std::endl;
		Span	BigSpan(bigVec.size());
		try
		{
			BigSpan.insertManyNbrs(bigVec.begin(), bigVec.end());
		}
		catch(const std::exception &e)
		{	
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest span is " << BigSpan.shortestSpan() << std::endl;
			std::cout << "Longest span is " << BigSpan.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "Trying to add one more number..." << std::endl;
			BigSpan.addNumber(6);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "===== EMPTY ARRAY PRINT TEST =====" << std::endl;

	Span emptySpan(5);
	emptySpan.printNbrs(); // MUST print only "Empty array"
	
	std::cout << "===== NOT ENOUGH NUMBERS TEST =====" << std::endl;

	try
	{
		Span s1(5);
		std::cout << "Calling shortestSpan() with 0 elements..." << std::endl;
		s1.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout  << e.what() << std::endl;
	}

	try
	{
		Span s2(5);
		s2.addNumber(42);
		std::cout << "Calling longestSpan() with 1 element..." << std::endl;
		s2.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

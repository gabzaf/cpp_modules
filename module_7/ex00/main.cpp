#include "whatever.hpp"

int	main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
 	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

 	float e = 42.1;
	float f = 42.1;

	std::cout << "\n[FLOAT]" << std::endl;
	std::cout << "e = " << e << ", f = " << f <<std::endl;
	std::cout << "\n[MIN AND MAX TEST]" << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( f, e ) = " << ::max( f, e ) << std::endl;

    return 0;
}

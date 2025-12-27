#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}

void printPseudo(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (input[input.size() - 1] == 'f')
    {
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
}

bool isPseudo(const std::string &input)
{
    if (input == "nan" || input == "nanf" ||
            input == "+inf" || input == "+inff" ||
            input == "-inf" || input == "-inff" ||
            input == "inf"  || input == "inff")
    {return true;}
    else
        return false;
}

void    charConversion(const std::string &input, int minus)
{
    char            c;
    int             i;
    float           f;
    double          d;

    c = input[0];   
    if (std::isdigit(c))
    {
        std::cout << "char: Non displayable" << std::endl;
        i = std::atoi(input.c_str());
    }
    else
    {
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        i = static_cast<int>(c);
    }
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    if (minus)
    {
        i = -i; f = -f; d = -d;
    }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl; 
}

bool    is_int(const std::string &input)
{
    size_t  i;

    i = 0;
    while (i < input.length())
    {
        if (!std::isdigit(input[i]))
            return (false);
        i++;
    }
    return (true);
}

void     float_double_conversion(const std::string &input, int minus)
{
    const char  *str = input.c_str();
    int         i = std::atoi(str);
    double      d = std::atof(str);
    if (minus)
    {
        i = -i;
        d = -d;
    }
    if (d < DOUBLE_MIN || d > DOUBLE_MAX)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    char c = static_cast<char>(i);
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (d < FLOAT_MIN || d > FLOAT_MAX)
        std::cout << "float: impossible" << std::endl;
    else if (d == i)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == i)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void    is_float_or_double(const std::string &input, int minus)
{
    int             len;
    std::string     temp;

    len = static_cast<int>(input.length() - 1;
    temp = input;

    if (input.find_first_of('.') == input.find_last_of('.'))
    {
        if ((input.find_first_of('f') == input.find_last_of('f')) && (input[len] == 'f'))
        {
            temp.erase(temp.find('f'));
            float_double_conversion(temp, minus);
        }
        else
            float_double_conversion(input, minus);
    }   
}

int     sign_parser(std::string &input)
{
    int         minus;
    size_t      first_non_sign_pos;

    minus = 0;
    first_non_sign_pos = input.find_first_not_of("+-");
    if (first_non_sign_pos == std::string::npos || ((input.find('+') != std::string::npos) && (input.find('-') != std::string::npos)))
        throw ScalarConverter::NotAcceptedFormatException();
    if (first_non_sign_pos > 0)
    {
        for (size_t i = 0; i < first_non_sign_pos; ++i)
        {
            if (input[i] == '-')
                minus = 1;
        }
        input.erase(0, first_non_sign_pos);
    }
    if (!std::isdigit(input[0]) && input.find('.') == std::string::npos)
        throw ScalarConverter::NotAcceptedFormatException();
    return (minus);
}

void    ScalarConverter::convert(const std::string &input)
{
    int             minus;
    std::string     processed_input;

    processed_input = input;
    minus = 0;
    try
    {
        if (isPseudo(processed_input))
        {
            printPseudo(processed_input);
            return;
        }
        if (input.find('+') != std::string::npos || input.find('-') != std::string::npos)
            minus = sign_parser(processed_input);
        if (processed_input.length() == 1)
            charConversion(processed_input, minus);
        else if (input.find('.')!= std::string::npos)
            is_float_or_double(processed_input, minus);
        else if (is_int(processed_input))
        {
            float_double_conversion(processed_input, minus);
        }
        else
            throw NotAcceptedFormatException();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char  *ScalarConverter::NotAcceptedFormatException::what() const throw()
{
    return ("Not accepted format!");
};

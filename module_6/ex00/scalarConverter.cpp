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

void    charConversion(const std::string &input, int minus)
{
    char            c;
    int             i;
    float           f;
    double          d;

    c = input[0];   
    if (std::isdigit(c))
    {
        std::cout << "Char: Non displayable" << std::endl;
        i = std::atoi(input.c_str());
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else
    {
        std::cout << c << std::endl;
        i = static_cast<int>(c);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    if (minus == 1)
    {
        std::cout << "Int: -" << i << std::endl;
        std::cout << "Float: -" << f << ".0f" << std::endl;
        std::cout << "Double: -" << d << ".0" << std::endl; 
    }
    else
    {
        std::cout << "Int: " << i << std::endl;
        std::cout << "Float: " << f << ".0f" << std::endl;
        std::cout << "Double: " << d << ".0" << std::endl; 
    }
}

void    intConversion(const std::string &input)
{
    (void)input;
    std::cout << "intConversion";
}

bool    is_int(const std::string &input)
{
    size_t          i;
    const size_t    len = input.length();
    size_t          signCount = 0;

    for (i = 0; i < len && (input[i] == '+' || input[i] == '-'); ++i)
        signCount++;
    if (i == len && signCount > 0) 
        return false;
    while (input[signCount])
    {
        if (!(input[signCount] > '0' && input[signCount] < '9'))
        {
            signCount++;
            continue;
        }
        if (signCount == len)
            std::cout << "oa0";
    }
    return false;
}

void     float_double_conversion(const std::string &input, int minus)
{
    const char  *str = input.c_str();
    int         i = std::atoi(str);
    double      d = std::atof(str);
    float       f = static_cast<float>(d);
    char        c = static_cast<float>(i);
    char        last = (int)input.length() - 1;

    
    if (minus == 1)
    {
        std::cout << "Char: Non displayable" << std::endl;
        std::cout << "Int: -" << i << std::endl;
        if (input[last] == '0')
            std::cout << "Float: -" << f << ".0f"<<std::endl;
        else
            std::cout << "Float: -" << f << "f"<<std::endl;
        std::cout << "Double: -" << d << std::endl; 
    }
    else
    {
        std::cout << "Char: " << c << std::endl;
        std::cout << "Int: " << i << std::endl;
        if (input[last] == '0')
            std::cout << "Float: " << f << ".0f"<<std::endl;
        else
            std::cout << "Float: " << f << "f"<<std::endl;
        std::cout << "Double: " << d << std::endl;
    }
}

void    is_float_or_double(const std::string &input, int minus)
{
    int             len;
    std::string     temp;

    len = (int)input.length() - 1;
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
    return (minus);
}

void    ScalarConverter::convert(const std::string &input)
{
    int             minus;
    std::string     processed_input;

    processed_input = input;
    try
    {
        if (input.find('+') || input.find('-'))
            minus = sign_parser(processed_input);
        if (processed_input.length() == 1)
            charConversion(processed_input, minus);
        else if (input.find('.')!= std::string::npos)
            is_float_or_double(processed_input, minus);
        /*else if (is_int(input))
            intConversion(input);*/
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
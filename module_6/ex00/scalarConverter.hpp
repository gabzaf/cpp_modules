#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
    public:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &other);
            ScalarConverter &operator=(const ScalarConverter &other);
            ~ScalarConverter();

            void convert(const std::string &input);

    class NotAcceptedFormatException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif
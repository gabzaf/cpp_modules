#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <cstdlib>
#include <limits>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define FLOAT_MIN -(std::numeric_limits<float>::max())
#define FLOAT_MAX std::numeric_limits<float>::max()
#define DOUBLE_MIN -(std::numeric_limits<double>::max())
#define DOUBLE_MAX std::numeric_limits<double>::max()

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
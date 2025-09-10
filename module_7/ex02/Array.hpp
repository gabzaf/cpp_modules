#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>

class Array
{
    private:
            T               *_array;
            unsigned int    _size;

    public:
            Array();
            Array(unsigned int n);
            Array(const Array &other);
            Array &operator=(const Array &other);
            ~Array();

            T &operator[](unsigned int i) const;

            unsigned int size() const;

            class OutOfBounds : public std::exception
	        {
	        	public:
	        		virtual const char *what() const throw();
	        };
            class EmptyArray : public std::exception
	        {
	        	public:
	        		virtual const char *what() const throw();	
	        };
};

#include "Array.tpp"

#endif
#include "Array.hpp"

template <class T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <class T>
Array<T>::Array(const Array<T> &other)
{
    if (this == &other)
        return;

    this->_size = other._size;
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        if (this->_array)
            delete[] this->_array;
        this->_size = other._size;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i]; 
    }
    return (*this);
}

template <class T>
T &Array<T>::operator[](unsigned int index) const
{
    if (this->_size == 0)
        throw EmptyArray();
    if (index >= this->_size)
        throw OutOfBounds();
    return (this->_array[index]);
}

template <class T>
unsigned int Array<T>::size() const { return (_size); }

template <class T>
Array<T>::~Array()
{
    delete[] this->_array;
}

template <class T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds!";
}

template <class T>
const char* Array<T>::EmptyArray::what() const throw()
{
	return "Empty Array!";
}



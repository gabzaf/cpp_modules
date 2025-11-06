#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack<T> &operator=(const MutantStack<T> &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type wraped_cntnr;
        typedef typename wraped_cntr::iterator it;
        typedef typename wraped_cntnr::const_iterator const_iterator;

        iterator begin();
        iterator end();
        const iterator begin();
        const iterator end();
};

#include "MutantStack.tpp"

#endif
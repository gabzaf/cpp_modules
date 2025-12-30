#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack<T> &operator=(const MutantStack<T> &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type wraped_cntnr;
        typedef typename wraped_cntnr::iterator iterator;
        typedef typename wraped_cntnr::const_iterator const_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

#include "MutantStack.tpp"

#endif

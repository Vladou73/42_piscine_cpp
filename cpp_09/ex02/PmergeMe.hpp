// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://wiki.sei.cmu.edu/confluence/display/cplusplus/CTR53-CPP.+Use+valid+iterator+ranges

// https://en.cppreference.com/w/cpp/container/stack
//https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators

#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>
#include <list>
#include <cmath>
#include <cstring>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(std::string const &);
        ~PmergeMe();
        PmergeMe(PmergeMe const &);
        PmergeMe const &operator=(PmergeMe const &);

        int     CheckStoreInput(int const &, char ** const &);
        void    MakePairs(void);

    private:
        std::list<int>                      _to_sort;
        std::list<std::pair<int, char> >    _list;

};

#endif

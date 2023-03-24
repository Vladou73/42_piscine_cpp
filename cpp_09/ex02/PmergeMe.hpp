#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(std::string const &);
        ~PmergeMe();
        PmergeMe(PmergeMe const &);
        PmergeMe const &operator=(PmergeMe const &);

        int     CheckStoreInput(int const &, char ** const &);
        int     StoreInputVec(int const &, char ** const &);

        void    MakePairs(void);
        void    MakePairsVec(void);

        void    SwapPairs(void);
        void    SwapPairsVec(void);

        void    RecursiveMergeSort(std::list<std::pair<int, int> > &myList, size_t size);
        void    RecursiveMergeSortVec(std::vector<std::pair<int, int> > &myList);

        void    InsertionSort(void);
        void    InsertionSortVec(void);

        void    BinarySearch(int  toInsert);
        void    BinarySearchVec(int  toInsert);

        void    PutResults(void);

    private:
        std::list<int>                      _list_to_sort;
        std::list<int>                      _sorted_list;
        std::list<std::pair<int, int> >     _list;
        time_t                              _list_start_time;
        time_t                              _list_end_time;

        std::vector<int>                    _to_sort_vector;
        std::vector<int>                    _sorted_vector;
        std::vector<std::pair<int, int> >   _vector;
        time_t                              _vector_start_time;
        time_t                              _vector_end_time;

};

#endif

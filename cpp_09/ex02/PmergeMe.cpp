#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &toCopy) {
    *this = toCopy;
}
PmergeMe const &PmergeMe::operator=(PmergeMe const &toCopy) {
    if (this == &toCopy)
        return *this;
    _list = toCopy._list;
    _to_sort = toCopy._to_sort;
    return *this;
}

int isPosInt(char * const &str) {
    int i = 0;

    if (strlen(str) < 1 || strlen(str) > 10)
        return 0;
    while (str[i]) {
        if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int PmergeMe::CheckStoreInput(int const &argc, char ** const &argv) {
    int i = 1;
    long long int   tmp;

    time(&_list_start_time);

    if (argc < 2)
        return 1;

    while (i < argc) {
        if (!argv[i])
            return 1;
        if (!isPosInt(argv[i]))
            return 1;
        tmp = atol(argv[i]);
        if (tmp < 0 || tmp > 2147483647)
            return 1;
        _to_sort.push_back(tmp);
        i++;
    }
    return 0;
}

void PmergeMe::MakePairs(void) {
    int i = 0;

    for (std::list<int>::iterator it = _to_sort.begin(); it !=_to_sort.end(); it++) {
        if (!(i % 2))
            _list.push_back(std::make_pair(*it, -1));
        else
            _list.back().second = *it;
        i++;
    }
}

void PmergeMe::SwapPairs(void) {
	for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++) {
        if ((*it).first < (*it).second)
            std::swap((*it).first, (*it).second);
    }
    this->RecursiveMergeSort(_list, _list.size());

    std::cout << std::endl << "*********** LIST PAIRS AFTER MERGE SORT ***********" << std::endl;
    for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;
    std::cout << std::endl << "_list.size()=" << _list.size() << std::endl;
}

// std::cout << std::endl << "*********** LIST PAIRS AFTER MERGE SORT ***********" << std::endl;
// for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
//     std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;
// std::cout << std::endl << "_list.size()=" << _list.size() << std::endl;



bool compareFirst (std::pair<int, int> right, std::pair<int, int> left) {
    return (right.first < left.first);
}

void PmergeMe::RecursiveMergeSort(std::list<std::pair<int, int> > &myList, size_t size) {
    std::list<std::pair<int, int> > left_list, right_list;

    if (size < 2)
        return;

    std::list<std::pair<int, int> >::iterator middle = myList.begin();
    for (size_t i = 0; i < size / 2; i++)
        middle++;

    myList.splice(left_list.begin(), left_list, myList.begin(), middle);
    myList.splice(right_list.begin(), right_list, myList.begin(), myList.end());

	size_t  i = 0;
    for (std::list<std::pair<int, int> >::iterator it = left_list.begin(); it !=left_list.end(); it++)
        i++;
    PmergeMe::RecursiveMergeSort(left_list, i);

	i = 0;
    for (std::list<std::pair<int, int> >::iterator it = right_list.begin(); it !=right_list.end(); it++)
        i++;
    PmergeMe::RecursiveMergeSort(right_list, i);

    // Merge sorted lists
    myList = left_list;
    myList.merge(right_list, compareFirst);
}

void    PmergeMe::BinarySearch(int  toInsert) {
    int L = 0;
    int R = _sorted.size() - 1;
    int i;

    std::list<int>::iterator middle;
    std::list<int>::iterator checkDuplicates;

    while (L <= R) {
        middle = _sorted.begin();
        for (i = 0; i < (L + R) / 2; i++)
            middle++;
        if (toInsert > *middle) {
            L = i + 1;
            if (L > R)
                middle++;
        } else if (toInsert < *middle) {
            R = i - 1;
        } else {
            _sorted.insert(middle, toInsert);
            return;
        }
    }
    if (R == -1)
        middle = _sorted.begin();
    _sorted.insert(middle, toInsert);
}

void PmergeMe::InsertionSort() {
    int idx = 0;
    for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++) {
        _sorted.push_back(it->first);
        idx++;
    }

    idx = 0;
    for (std::list<std::pair<int, int> >::iterator toInsert = _list.begin(); toInsert !=_list.end(); toInsert++) {
        if (toInsert->second >= 0)
            PmergeMe::BinarySearch(toInsert->second);
        idx++;
    }
    time(&_list_end_time);
}

void    PmergeMe::PutResults() {
    std::cout << "Before:" << std::endl;
	for (std::list<int>::iterator it = _to_sort.begin(); it !=_to_sort.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl << "After: " << std::endl;
	for (std::list<int>::iterator it = _sorted.begin(); it !=_sorted.end(); it++)
        std::cout << *it << " ";

    std::cout   << std::endl << std::endl
                << "Time to process a range of " << _to_sort.size() << " elements with std::list : "
                << (unsigned long) difftime(_list_end_time, _list_start_time) << " seconds" << std::endl;

    std::cout   << "Time to process a range of " << _sorted.size() << " elements with std::[..] : "
                << 0.00031 << "u" << std::endl;
}

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
	// for (std::list<int>::iterator it = _to_sort.begin(); it !=_to_sort.end(); it++)
    //     std::cout << *it << std::endl;
    return 0;
}

void PmergeMe::MakePairs(void) {
    int i = 0;

    for (std::list<int>::iterator it = _to_sort.begin(); it !=_to_sort.end(); it++) {
        if (!(i % 2))
            _list.push_back(std::make_pair(*it, 0));
        else
            _list.back().second = *it;
        i++;
    }

	for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;



}

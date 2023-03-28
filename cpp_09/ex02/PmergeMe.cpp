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
    _list_to_sort = toCopy._list_to_sort;
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

    _list_time = clock();

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
        _list_to_sort.push_back(tmp);
        i++;
    }
    return 0;
}

int PmergeMe::StoreInputVec(int const &argc, char ** const &argv) {
    int i = 1;
    long long int   tmp;

    _vector_time = clock();

    while (i < argc) {
        tmp = atol(argv[i]);
        _to_sort_vector.push_back(tmp);
        i++;
    }
    return 0;
}

void PmergeMe::MakePairs(void) {
    int i = 0;

    for (std::list<int>::iterator it = _list_to_sort.begin(); it !=_list_to_sort.end(); it++) {
        if (!(i % 2))
            _list.push_back(std::make_pair(*it, -1));
        else
            _list.back().second = *it;
        i++;
    }
}

void PmergeMe::MakePairsVec(void) {
    int i = 0;

    for (std::vector<int>::iterator it = _to_sort_vector.begin(); it !=_to_sort_vector.end(); it++) {
        if (!(i % 2))
            _vector.push_back(std::make_pair(*it, -1));
        else
            _vector.back().second = *it;
        i++;
    }
}

void PmergeMe::SwapPairs(void) {
	for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++) {
        if ((*it).first < (*it).second)
            std::swap((*it).first, (*it).second);
    }
    this->RecursiveMergeSort(_list, _list.size());
}

void PmergeMe::SwapPairsVec(void) {
	for (std::vector<std::pair<int, int> >::iterator it = _vector.begin(); it !=_vector.end(); it++) {
        if ((*it).first < (*it).second)
            std::swap((*it).first, (*it).second);
    }
    this->RecursiveMergeSortVec(_vector);
}

bool compareFirst(std::pair<int, int> right, std::pair<int, int> left) {
    return (right.first < left.first);
}

std::vector<std::pair<int, int> >    mergeSortedVecs(
    std::vector<std::pair<int, int> > &left_arr,
    std::vector<std::pair<int, int> > &right_arr
)
{
    std::vector<std::pair<int, int> >::iterator r = right_arr.begin();
    std::vector<std::pair<int, int> >::iterator l = left_arr.begin();
    std::vector<std::pair<int, int> > res;

    while ((r != right_arr.end())) {
        if (l == left_arr.end())
            break;
        if (r->first < l->first) {
            res.push_back(*r);
            r++;
        }
        else {
            res.push_back(*l);
            l++;
        }
    }
    while (r != right_arr.end()) {
        res.push_back(*r);
        r++;
    }
    while (l != left_arr.end()) {
        res.push_back(*l);
        l++;
    }
    return res;
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

void PmergeMe::RecursiveMergeSortVec(std::vector<std::pair<int, int> > &myArr) {

    std::vector<std::pair<int, int> > left_arr, right_arr;

    if (myArr.size() < 2)
        return;

    std::vector<std::pair<int, int> >::iterator middle = myArr.begin();
    for (size_t i = 0; i < myArr.size() / 2; i++)
        middle++;

    left_arr.assign(myArr.begin(), middle);
    right_arr.assign(middle, myArr.end());

    PmergeMe::RecursiveMergeSortVec(left_arr);
    PmergeMe::RecursiveMergeSortVec(right_arr);

    // Merge sorted lists
    myArr = mergeSortedVecs(left_arr, right_arr);

}

void    PmergeMe::BinarySearch(int  toInsert) {
    int L = 0;
    int R = _sorted_list.size() - 1;
    int i;

    std::list<int>::iterator middle;

    while (L <= R) {
        middle = _sorted_list.begin();
        for (i = 0; i < (L + R) / 2; i++)
            middle++;
        if (toInsert > *middle) {
            L = i + 1;
            if (L > R)
                middle++;
        } else if (toInsert < *middle) {
            R = i - 1;
        } else {
            _sorted_list.insert(middle, toInsert);
            return;
        }
    }
    if (R == -1)
        middle = _sorted_list.begin();
    _sorted_list.insert(middle, toInsert);
}

void    PmergeMe::BinarySearchVec(int  toInsert) {
    int L = 0;
    int R = _sorted_vector.size() - 1;
    int i;

    std::vector<int>::iterator middle;

    while (L <= R) {
        middle = _sorted_vector.begin();
        for (i = 0; i < (L + R) / 2; i++)
            middle++;
        if (toInsert > *middle) {
            L = i + 1;
            if (L > R)
                middle++;
        } else if (toInsert < *middle) {
            R = i - 1;
        } else {
            _sorted_vector.insert(middle, toInsert);
            return;
        }
    }
    if (R == -1)
        middle = _sorted_vector.begin();
    _sorted_vector.insert(middle, toInsert);
}

void PmergeMe::InsertionSort() {
    for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
        _sorted_list.push_back(it->first);

    for (std::list<std::pair<int, int> >::iterator toInsert = _list.begin(); toInsert !=_list.end(); toInsert++) {
        if (toInsert->second >= 0)
            PmergeMe::BinarySearch(toInsert->second);
    }
    _list_time = clock() - _list_time;
}

void PmergeMe::InsertionSortVec() {
    for (std::vector<std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++)
        _sorted_vector.push_back(it->first);

    for (std::vector<std::pair<int, int> >::iterator toInsert = _vector.begin(); toInsert !=_vector.end(); toInsert++) {
        if (toInsert->second >= 0)
            PmergeMe::BinarySearchVec(toInsert->second);
    }
    _vector_time = clock() - _vector_time;
}

void    PmergeMe::PutResults() {
    std::cout << "Before:" << std::endl;
	for (std::list<int>::iterator it = _list_to_sort.begin(); it !=_list_to_sort.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl << "After: " << std::endl;
	for (std::list<int>::iterator it = _sorted_list.begin(); it !=_sorted_list.end(); it++)
        std::cout << *it << " ";

    std::cout   << std::endl << std::endl
                << "Time to process a range of " << _list_to_sort.size() << " elements with std::list : "
                << (float)_list_time/CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cout   << "Time to process a range of " << _sorted_list.size() << " elements with std::vector : "
                << (float)_vector_time/CLOCKS_PER_SEC << " seconds" << std::endl;
}


// std::cout << std::endl << "*********** LIST PAIRS AFTER MERGE SORT ***********" << std::endl;
// for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
//     std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;
// std::cout << std::endl << "_list.size()=" << _list.size() << std::endl;

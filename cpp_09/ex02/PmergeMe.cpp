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
}

void PmergeMe::SwapPairs(void) {
	for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++) {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

    std::cout << std::endl << "*********** MAIN LIST ***********" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;

    this->RecursiveMergeSort(_list);

    // std::cout << std::endl << "*********** MAIN LIST AFTER REC MERGE SORT***********" << std::endl;
	// for (std::list<std::pair<int, int> >::iterator it = _list.begin(); it !=_list.end(); it++)
    //     std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;



}

// mergeSort(arr, size)
// If  size > 1

// Step 1: Find the size of the leftSubArray and rightSubArray so that we can divide the array into two-part
// leftSize = size / 2;
// rightSize = size - leftSize;

// Step 2: Call the mergesort for the leftSubArray
// mergeSort(leftSubArray, leftSize);

// Step 3: Call the mergesort for the rightSubArray
// mergeSort(rightSubArray, rightSize);

// Step 4: Call the merge function to merge these two halves       mergeTwoSortedArray(leftSubArray, rightSubArray, arr,
// leftSize, rightSize)

bool compareFirst (std::pair<int, int> right, std::pair<int, int> left) {
    return (right.first < left.first);
}

void PmergeMe::RecursiveMergeSort(std::list<std::pair<int, int> > myList) {
    if (myList.size() < 2)
        return;

    std::list<std::pair<int, int> > left_list, right_list;

    std::list<std::pair<int, int> >::iterator middle = myList.begin();
    for (size_t i = 0; i < myList.size() / 2; i++)
        middle++;

    myList.splice(left_list.begin(), left_list, myList.begin(), middle);
    myList.splice(right_list.begin(), right_list, myList.begin(), myList.end());

    std::cout <<  std::endl << "*********** LEFT LIST ***********" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = left_list.begin(); it !=left_list.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;

    std::cout<< std::endl << "*********** RIGHT LIST ***********" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = right_list.begin(); it !=right_list.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second <<  std::endl;


    PmergeMe::RecursiveMergeSort(left_list);
    PmergeMe::RecursiveMergeSort(right_list);

    // Merge sorted lists
    left_list.merge(right_list, compareFirst);
    myList = left_list;

    std::cout << std::endl << "right_list.size()=" << right_list.size() << std::endl;

    std::cout << std::endl << "*********** MAIN LIST AFTER REC MERGE SORT***********" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = myList.begin(); it !=myList.end(); it++)
        std::cout << "first =" <<(*it).first << ", second =" <<(*it).second << std::endl;

}




// std::list::merge
// Merge sorted lists
// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered).

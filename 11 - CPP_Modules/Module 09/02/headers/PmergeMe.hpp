#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    template <typename Container>
    Container mergeInsertSort(const Container &inputSequence);

private:
    template <typename Container>
    void merge(Container &left, Container &right, Container &result);

    template <typename Container>
    void insertionSort(Container &container);
};

#endif
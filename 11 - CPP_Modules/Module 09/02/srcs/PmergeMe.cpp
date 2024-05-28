#include "../headers/PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void)other; // Suppress unused parameter warning
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other; // Suppress unused parameter warning
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container>
Container PmergeMe::mergeInsertSort(const Container &inputSequence) {
    if (inputSequence.size() <= 10) {
        Container result(inputSequence);
        insertionSort(result);
        return result;
    }

    typename Container::const_iterator middle = inputSequence.begin() + (inputSequence.size() / 2);
    Container left(inputSequence.begin(), middle);
    Container right(middle, inputSequence.end());

    left = mergeInsertSort(left);
    right = mergeInsertSort(right);

    Container result;
    merge(left, right, result);
    return result;
}

template <typename Container>
void PmergeMe::merge(Container &left, Container &right, Container &result) {
    typename Container::iterator itLeft = left.begin();
    typename Container::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft < *itRight) {
            result.push_back(*itLeft);
            ++itLeft;
        } else {
            result.push_back(*itRight);
            ++itRight;
        }
    }

    while (itLeft != left.end()) {
        result.push_back(*itLeft);
        ++itLeft;
    }

    while (itRight != right.end()) {
        result.push_back(*itRight);
        ++itRight;
    }
}

template <typename Container>
void PmergeMe::insertionSort(Container &container) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        typename Container::iterator minIt = std::min_element(it, container.end());
        std::iter_swap(it, minIt);
    }
}

// Explicit template instantiation
template std::vector<int> PmergeMe::mergeInsertSort(const std::vector<int> &inputSequence);
template std::deque<int> PmergeMe::mergeInsertSort(const std::deque<int> &inputSequence);
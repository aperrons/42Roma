#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include "headers/PmergeMe.hpp"

void printError(const std::string &message) {
    std::cerr << "Error: " << message << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printError("Invalid number of arguments.");
        return 1;
    }

    try {
        std::vector<int> inputSequence;
        for (int i = 1; i < argc; ++i) {
            int num = ::atoi(argv[i]);
            if (num <= 0) {
                printError("Invalid number in input sequence.");
                return 1;
            }
            inputSequence.push_back(num);
        }

        std::cout << "Before: ";
        for (std::vector<int>::iterator it = inputSequence.begin(); it != inputSequence.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        PmergeMe sorter;
        std::vector<int> sortedVector;
        std::deque<int> sortedDeque;

        clock_t start = clock();
        sortedVector = sorter.mergeInsertSort<std::vector<int> >(inputSequence);
        clock_t end = clock();
        double vectorTime = double(end - start) / CLOCKS_PER_SEC;

        std::deque<int> inputDeque(inputSequence.begin(), inputSequence.end());

        start = clock();
        sortedDeque = sorter.mergeInsertSort<std::deque<int> >(inputDeque);
        end = clock();
        double dequeTime = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "After: ";
        for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::vector: " << vectorTime << " s" << std::endl;
        std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::deque: " << dequeTime << " s" << std::endl;
    } catch (const std::exception &e) {
        printError(e.what());
        return 1;
    }

    return 0;
}
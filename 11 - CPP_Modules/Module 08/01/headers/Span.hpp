#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw std::out_of_range("Not enough space to add all elements");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

#endif
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
public:
    // Default constructor
    Array() : _size(0), _array(NULL) {}

    // Constructor with size
    Array(unsigned int n) : _size(n), _array(new T[n]()) {}

    // Copy constructor
    Array(const Array& other) : _size(0), _array(NULL) {
        *this = other;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _array;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    }

    // Size function
    unsigned int size() const {
        return _size;
    }

private:
    unsigned int _size;
    T* _array;
};

#endif
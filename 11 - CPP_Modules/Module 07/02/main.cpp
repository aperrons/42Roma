#include "headers/Array.hpp"

#include <iostream>
#include <string>

int main() {
    try {
        Array<int> arr1;
        Array<int> arr2(5);
        Array<std::string> arr3(3);

        arr3[0] = "Hello";
        arr3[1] = "World";
        arr3[2] = "!";

        std::cout << "Array arr2 size: " << arr2.size() << std::endl;
        for (unsigned int i = 0; i < arr2.size(); i++) {
            arr2[i] = i * 2;
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        std::cout << "Array arr3 size: " << arr3.size() << std::endl;
        for (unsigned int i = 0; i < arr3.size(); i++) {
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
        }

        Array<int> arr4(arr2); // Copy constructor test
        std::cout << "Array arr4 (copy of arr2) size: " << arr4.size() << std::endl;
        for (unsigned int i = 0; i < arr4.size(); i++) {
            std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl;
        }

        arr4[0] = 42; // Modifying arr4 should not affect arr2
        std::cout << "After modifying arr4[0], arr2[0] = " << arr2[0] << std::endl;

        // Assignment operator test
        Array<int> arr5 = arr2;
        std::cout << "Array arr5 (assigned from arr2) size: " << arr5.size() << std::endl;
        for (unsigned int i = 0; i < arr5.size(); i++) {
            std::cout << "arr5[" << i << "] = " << arr5[i] << std::endl;
        }

        // Test out-of-bounds access
        std::cout << "Attempting out-of-bounds access: " << std::endl;
        std::cout << arr2[10] << std::endl; // Should throw exception

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

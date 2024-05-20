#include <iostream>
#include "headers/Serializer.hpp"
#include "headers/Data.hpp"

int main() {
    Data data;
    data.intValue = 42;
    data.floatValue = 3.14f;
    data.stringValue = "Test string";

    std::cout << "Original Data:" << std::endl;
    std::cout << "intValue: " << data.intValue << std::endl;
    std::cout << "floatValue: " << data.floatValue << std::endl;
    std::cout << "stringValue: " << data.stringValue << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "intValue: " << deserializedData->intValue << std::endl;
    std::cout << "floatValue: " << deserializedData->floatValue << std::endl;
    std::cout << "stringValue: " << deserializedData->stringValue << std::endl;

    if (&data == deserializedData) {
        std::cout << "\nSerialization and deserialization successful: pointers match." << std::endl;
    } else {
        std::cout << "\nSerialization and deserialization failed: pointers do not match." << std::endl;
    }

    return 0;
}
#include "../headers/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other; 
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    return !*end && errno == 0 && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    char* end;
    errno = 0;
    (void)std::strtof(literal.c_str(), &end); // Valore ignorato
    return *end == 'f' && end[1] == '\0' && errno == 0;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    char* end;
    errno = 0;
    (void)std::strtod(literal.c_str(), &end); // Valore ignorato
    return !*end && errno == 0;
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    } else if (isInt(literal)) {
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(val));
        printInt(static_cast<int>(val));
        printFloat(static_cast<float>(val));
        printDouble(static_cast<double>(val));
    } else if (isFloat(literal)) {
        float val = std::strtof(literal.c_str(), NULL);
        if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max() || std::isnan(val))
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(val));
        if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || std::isnan(val))
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(val));
        printFloat(val);
        printDouble(static_cast<double>(val));
    } else if (isDouble(literal)) {
        double val = std::strtod(literal.c_str(), NULL);
        if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max() || std::isnan(val))
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(val));
        if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || std::isnan(val))
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(val));
        printFloat(static_cast<float>(val));
        printDouble(val);
    } else {
        std::cerr << "Error: Invalid literal" << std::endl;
    }
}

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
public:
    // Constructor
    Warlock(const std::string& name, const std::string& title);
    
    // Destructor
    ~Warlock();
    
    // Getters
    const std::string& getName() const;
    const std::string& getTitle() const;
    
    // Setter
    void setTitle(const std::string& title);
    
    // Introduce method
    void introduce() const;

private:
    // Disable copy constructor and assignment operator
    Warlock(const Warlock&);
    Warlock& operator=(const Warlock&);
    
    std::string name;
    std::string title;
};

#endif // WARLOCK_HPP

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string fullName; 

public:
    Person() : fullName("Unknown") {}
    Person(std::string name) : fullName(name) {}
    virtual ~Person() {}

    virtual void display() const = 0; 
    
    void setFullName(std::string name) { fullName = name; }
    std::string getFullName() const { return fullName; }
};

#endif
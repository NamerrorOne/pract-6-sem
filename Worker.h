#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
#include <iostream>

class Worker : public Person {
private:
    std::string position; 
    double salary;        
    int hireYear;         

public:
    Worker();
    Worker(std::string name, std::string pos, double sal, int year);
    ~Worker();

    void setPosition(std::string pos);
    void setSalary(double sal);
    void setHireYear(int year);

    std::string getPosition() const;
    double getSalary() const;
    int getHireYear() const;

    void display() const override; 
    int getExperience(int currentYear) const; 
};

#endif
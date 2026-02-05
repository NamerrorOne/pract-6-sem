#include "Worker.h"

Worker::Worker() : Person("Unknown"), position("None"), salary(0.0), hireYear(2026) {}

Worker::Worker(std::string name, std::string pos, double sal, int year) 
    : Person(name), position(pos), salary(sal), hireYear(year) {}

Worker::~Worker() {}

void Worker::setPosition(std::string pos) { position = pos; }
void Worker::setSalary(double sal) { salary = sal; }
void Worker::setHireYear(int year) { hireYear = year; }

std::string Worker::getPosition() const { return position; }
double Worker::getSalary() const { return salary; }
int Worker::getHireYear() const { return hireYear; }

void Worker::display() const {
    std::cout << "Сотрудник Сбера: " << fullName 
              << " | Должность: " << position 
              << " | Зарплата: " << salary 
              << " | Год поступления: " << hireYear << std::endl;
}

int Worker::getExperience(int currentYear) const {
    return currentYear - hireYear;
}
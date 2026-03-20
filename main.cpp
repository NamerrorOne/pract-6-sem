#include <iostream>
#include <vector>
#include <string>
#include "Worker.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Worker> synergyStaff;

    synergyStaff.emplace_back("Иванов А.А.", "Ректор", 350000, 2010);
    synergyStaff.emplace_back("Сидоров Б.В.", "Декан факультета информационных технологий", 150000, 2018);
    synergyStaff.emplace_back("Абрамов И.М.", "Стажёр кафедры программирования", 12000, 2026);


    int count;
    std::cout << "--- Система управления персоналом Университет Синергия ---\n";
    std::cout << "Сколько новых сотрудников добавить в базу? ";

    if (!(std::cin >> count)) return 1;

    for (int i = 0; i < count; ++i) {
        std::string name, pos;
        double sal;
        int year;

        std::cout << "\nСотрудник #" << i + 1 << ":" << std::endl;
        std::cout << "ФИО: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Должность: ";
        std::getline(std::cin, pos);
        std::cout << "Зарплата: ";
        std::cin >> sal;
        std::cout << "Год поступления: ";
        std::cin >> year;

        synergyStaff.emplace_back(name, pos, sal, year);
    }

    int searchExp;
    std::cout << "\nВведите стаж для поиска (выведу тех, у кого стаж больше): ";
    std::cin >> searchExp;

    int currentYear = 2026;
    bool found = false;

    std::cout << "\nРезультаты поиска:" << std::endl;
    for (const auto& worker : synergyStaff) {
        if (worker.getExperience(currentYear) > searchExp) {
            std::cout << "- " << worker.getFullName() << " (Стаж: " 
                      << worker.getExperience(currentYear) << " лет)" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Работников со стажем более " << searchExp << " лет не найдено." << std::endl;
    }

    return 0;
}
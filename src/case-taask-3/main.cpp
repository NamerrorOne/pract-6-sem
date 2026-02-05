#include <iostream>
#include <vector>
#include <string>
#include "Worker.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Worker> sberPulseTeam;

    sberPulseTeam.emplace_back("Сидоров А.П.", "Senior React Native Developer", 350000, 2020);
    sberPulseTeam.emplace_back("Петров К.М.", "HR-аналитик (Pulse)", 150000, 2023);
    sberPulseTeam.emplace_back("Абрамов И.М.", "Trainee React Native Developer (Pulse, catalog)", 100000000000, 2026);


    int count;
    std::cout << "--- Система управления персоналом Сбер Пульс ---\n";
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

        sberPulseTeam.emplace_back(name, pos, sal, year);
    }

    int searchExp;
    std::cout << "\nВведите стаж для поиска (выведу тех, у кого стаж больше): ";
    std::cin >> searchExp;

    int currentYear = 2026;
    bool found = false;

    std::cout << "\nРезультаты поиска:" << std::endl;
    for (const auto& worker : sberPulseTeam) {
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
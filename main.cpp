#include <iostream>
#include <vector>
#include <string>
#include "./database.h"

int main() {
    std::setlocale(LC_ALL, "rus");
    std::vector<Student> database;

    int choice;
    std::string major;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести список студентов по специальности\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 3:
            std::cout << "Выберите специальность: ";
            std::cin >> major;
            displayStudentsByMajor(database, major);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

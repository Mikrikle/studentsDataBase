#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для вывода студента в консоль
void displayStudent(const Student& student) {
    std::cout << "Имя: " << student.name << "\n";
    std::cout << "Возраст: " << student.age << "\n";
    std::cout << "Специальность: " << student.major << "\n";
    std::cout << "Средний балл: " << student.gpa << "\n\n";
}

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        displayStudent(student);
    }
}

// Функция для вывода списка студентов по названию специальности.
void displayStudentsByMajor(const std::vector<Student>& database, std::string major) {
    for (const Student& student : database) {
        if (student.major != major) {
            continue;
        }
        displayStudent(student);
    }
}
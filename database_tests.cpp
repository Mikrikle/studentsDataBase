#include "gtest/gtest.h"
#include "./database.h"

// Тестовый класс для функции displayStudentsByMajor
class DisplayStudentsByMajorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Подготовка данных для теста
        database.push_back({ "John", 20, "Computer Science", 3.5 });
        database.push_back({ "Alice", 22, "Physics", 3.8 });
        database.push_back({ "Bob", 21, "Computer Science", 3.2 });
        database.push_back({ "Eve", 19, "Mathematics", 3.9 });
    }

    void TearDown() override {
        // Очистка данных после теста
        database.clear();
    }

    std::vector<Student> database;
};

// Test 1: Пустая база данных, нет студентов
TEST(DisplayStudentsByMajorTest, NoStudentsWithMajor) {
    std::vector<Student> testdatabase;
    std::string major = "Computer Science";
    std::stringstream expected_output;
    testing::internal::CaptureStdout();
    displayStudentsByMajor(testdatabase, major);
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual_output, expected_output.str());
}

// Test 2: В базе данных один студент с выбранной специальностью
TEST(DisplayStudentsByMajorTest, OneStudentWithMajor) {
    std::vector<Student> database;
    database.push_back({ "John", 20, "Computer Science", 3.5 });
    std::string major = "Computer Science";
    std::stringstream expected_output;
    expected_output << "Имя: John" << "\n";
    expected_output << "Возраст: 20" << "\n";
    expected_output << "Специальность: Computer Science" << "\n";
    expected_output << "Средний балл: 3.5" << "\n\n";
    testing::internal::CaptureStdout();
    displayStudentsByMajor(database, major);
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual_output, expected_output.str());
}

// Test 3: В базе данных несколько студентов с выбранной специальностью
TEST(DisplayStudentsByMajorTest, MultipleStudentsWithMajor) {
    std::vector<Student> database;
    database.push_back({ "John", 20, "Computer Science", 3.5 });
    database.push_back({ "Alice", 22, "Computer Science", 3.8 });
    database.push_back({ "Bob", 21, "Mathematics", 3.2 });
    std::string major = "Computer Science";
    std::stringstream expected_output;
    expected_output << "Имя: John" << "\n";
    expected_output << "Возраст: 20" << "\n";
    expected_output << "Специальность: Computer Science" << "\n";
    expected_output << "Средний балл: 3.5" << "\n\n";
    expected_output << "Имя: Alice" << "\n";
    expected_output << "Возраст: 22" << "\n";
    expected_output << "Специальность: Computer Science" << "\n";
    expected_output << "Средний балл: 3.8" << "\n\n";
    testing::internal::CaptureStdout();
    displayStudentsByMajor(database, major);
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual_output, expected_output.str());
}

// Test 4: В базе данных есть студенты, но нет студентов с выбранной специальностью
TEST(DisplayStudentsByMajorTest, MajorNotFound) {
    std::vector<Student> database;
    database.push_back({ "John", 20, "Computer Science", 3.5 });
    std::string major = "Physics";
    std::stringstream expected_output;
    testing::internal::CaptureStdout();
    displayStudentsByMajor(database, major);
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual_output, expected_output.str());
}

// Test 5: Проверка зависимости регистра на поиск
TEST(DisplayStudentsByMajorTest, CaseInsensitiveMajor) {
    std::vector<Student> database;
    database.push_back({ "John", 20, "Computer Science", 3.5 });
    std::string major = "computer science";
    std::stringstream expected_output;
    expected_output << "Имя: John" << "\n";
    expected_output << "Возраст: 20" << "\n";
    expected_output << "Специальность: Computer Science" << "\n";
    expected_output << "Средний балл: 3.5" << "\n\n";
    testing::internal::CaptureStdout();
    displayStudentsByMajor(database, major);
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_NE(actual_output, expected_output.str());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
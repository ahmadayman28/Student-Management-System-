#include "Student.h"
#include "Course.h"
#include "Rational.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor
Student::Student() : level(1), noOfCourses(0), name(""), id("") {
    for (int i = 0; i < 6; ++i) {
        courseList[i] = nullptr;
    }
}

Student::Student(const std::string& name, const std::string& id, int level)
        : name(name), id(id), level(level), noOfCourses(0) {
    for (int i = 0; i < 6; ++i) {
        courseList[i] = nullptr;
    }
}

// Accessors and Mutators
std::string Student::getName() const {
    return name;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

std::string Student::getId() const {
    return id;
}

void Student::setId(const std::string& id) {
    this->id = id;
}

int Student::getLevel() const {
    return level;
}

void Student::setLevel(int level) {
    this->level = level;
}

// Member functions
void Student::printRegisteredCourses() const {
    for (int i = 0; i < noOfCourses; ++i) {
        if (courseList[i] != nullptr) {
            std::cout << *courseList[i] << " Grade: " << grades[i].toString() << "\n";
        }
    }
}


double Student::getCourseGPA(const Rational& grade) const {
    double percentage = grade.doubleValue() * 100;

    if (percentage >= 98) return 4.00;
    else if (percentage >= 93) return 4.00;
    else if (percentage >= 90) return 3.70;
    else if (percentage >= 87) return 3.30;
    else if (percentage >= 83) return 3.00;
    else if (percentage >= 80) return 2.70;
    else if (percentage >= 77) return 2.30;
    else if (percentage >= 73) return 2.00;
    else if (percentage >= 70) return 1.70;
    else if (percentage >= 67) return 1.30;
    else if (percentage >= 63) return 1.00;
    else if (percentage >= 60) return 0.70;
    else return 0.00;
}

double Student::getTotalGPA() const {
    double totalGPA = 0.0;
    int totalCreditHours = 0;

    for (int i = 0; i < noOfCourses; ++i) {
        if (courseList[i] != nullptr) {
            double courseGPA = getCourseGPA(grades[i]);
            int creditHours = courseList[i]->getCreditHours();
            totalGPA += courseGPA * creditHours;
            totalCreditHours += creditHours;
        }
    }

    if (totalCreditHours == 0) {
        return 0.0;
    }

    return totalGPA / totalCreditHours;
}

// Operator overloads
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student Name: " << student.getName() << "\n";
    os << "Student ID: " << student.getId() << "\n";
    os << "Level: " << student.getLevel() << "\n";
    os << "Registered Courses and Grades:\n";
    student.printRegisteredCourses();
    os << "Total GPA: " << student.getTotalGPA() << "\n";
    return os;
}

bool Student::RegisterCourse(Course* course, const Rational& grade) {
    if (noOfCourses >= 6) {
        return false;
    }
    courseList[noOfCourses] = course;
    grades[noOfCourses] = grade;
    noOfCourses++;
    return true;
}
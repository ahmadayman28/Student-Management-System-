#include "SpecialProgramStudent.h"
#include <bits/stdc++.h>
using namespace std;

SpecialProgramStudent::SpecialProgramStudent() : Student() {}

SpecialProgramStudent::SpecialProgramStudent(const string& name, const string& id, int level)
        : Student(name, id, level) {}

bool SpecialProgramStudent::RegisterCourse(Course* course) {
    if (noOfCourses >= 6) {
        return false;  // Registration failed due to max courses limit
    }
    courseList[noOfCourses] = course;
    noOfCourses++;
    return true;
}

float SpecialProgramStudent::CalculateExpenses() const {
    int totalCreditHours = 0;
    for (int i = 0; i < noOfCourses; ++i) {
        totalCreditHours += courseList[i]->getCreditHours();
    }
    return totalCreditHours * 500.0f;  // Expenses = Sum of credit hours * 500 EGP
}
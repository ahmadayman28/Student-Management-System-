#include "GeneralProgramStudent.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor
GeneralProgramStudent::GeneralProgramStudent()
        : Student() {}

GeneralProgramStudent::GeneralProgramStudent(const string& name, const string& id, int level)
        : Student(name, id, level) {}

// Member function to register a course
bool GeneralProgramStudent::RegisterCourse(Course* course) {
    if (noOfCourses >= 6) {
        return false; // Cannot register more than 6 courses
    }
    if (course->getMinStudentLevel() > level) {
        return false; // Student level is lower than the minimum required
    }
    courseList[noOfCourses] = course;
    noOfCourses++;
    return true;
}

// Member function to calculate expenses
float GeneralProgramStudent::CalculateExpenses() const {
    return getLevel() * 1000.0f; // Expenses = Student Level * 1000 EGP
}
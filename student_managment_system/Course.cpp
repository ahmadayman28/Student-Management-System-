#include "Course.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor
Course::Course() : name(""), code(""), minStudentLevel(0), creditHours(0) {}

Course::Course(const string& name, int minStudentLevel, int creditHours)
: name(name), minStudentLevel(minStudentLevel), creditHours(creditHours){}

// Destructor
Course::~Course() {
}

// Getters
string Course::getName() const {
    return name;
}

string Course::getCode() const {
    return code;
}

int Course::getMinStudentLevel() const {
    return minStudentLevel;
}

int Course::getCreditHours() const {
    return creditHours;
}

ostream &operator<<(ostream &os, const Course &course) {
    os << "Name: " << course.name << "\n";
    os << "Code: " << course.code << "\n";
    os << "Credit Hours: " << course.creditHours << "\n";
    os << "Min Student Level: " << course.minStudentLevel << "\n";
    return os;
}


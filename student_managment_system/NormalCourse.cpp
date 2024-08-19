#include "NormalCourse.h"
#include <bits/stdc++.h>
using namespace std;

// Default Constructor
NormalCourse::NormalCourse() : Course() {
    generateCode();
}

// Parameterized Constructor
NormalCourse::NormalCourse(const string& name, int level, int creditHours)
        : Course(name, level, creditHours) {
    generateCode();
}

// Generate Code for NormalCourse
void NormalCourse::generateCode() {
    code = name + "_N" + std::to_string(minStudentLevel);
}
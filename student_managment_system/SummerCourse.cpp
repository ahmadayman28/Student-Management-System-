#include "SummerCourse.h"
#include <bits/stdc++.h>
using namespace std;

// Default Constructor
SummerCourse::SummerCourse() : Course() {
    generateCode();
}

// Parameterized Constructor
SummerCourse::SummerCourse(const string& name, int level, int creditHours)
        : Course(name, level, creditHours) {
    generateCode();
}

// Generate Code for SummerCourse
void SummerCourse::generateCode() {
    code = name + "_S" + std::to_string(minStudentLevel);
}
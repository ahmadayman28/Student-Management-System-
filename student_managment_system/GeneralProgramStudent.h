#ifndef STUDENT_MANAGMENT_SYSTEM_GENERALPROGRAMSTUDENT_H
#define STUDENT_MANAGMENT_SYSTEM_GENERALPROGRAMSTUDENT_H
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

class GeneralProgramStudent : public Student{
    public:
        // Constructor
        GeneralProgramStudent();
        GeneralProgramStudent(const string& name, const string& id, int level);

        // Member functions
        bool RegisterCourse(Course* course) override;
        float CalculateExpenses() const override;
};
#endif //STUDENT_MANAGMENT_SYSTEM_GENERALPROGRAMSTUDENT_H

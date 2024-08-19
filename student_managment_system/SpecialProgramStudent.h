#ifndef STUDENT_MANAGMENT_SYSTEM_SPECIALPROGRAMSTUDENT_H
#define STUDENT_MANAGMENT_SYSTEM_SPECIALPROGRAMSTUDENT_H

#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

class SpecialProgramStudent : public Student {
public:
    SpecialProgramStudent();
    SpecialProgramStudent(const string& name, const string& id, int level);

    bool RegisterCourse(Course* course) override;
    float CalculateExpenses() const override;
};

#endif //STUDENT_MANAGMENT_SYSTEM_SPECIALPROGRAMSTUDENT_H

#ifndef STUDENT_MANAGMENT_SYSTEM_NORMALCOURSE_H
#define STUDENT_MANAGMENT_SYSTEM_NORMALCOURSE_H
#include <bits/stdc++.h>
using namespace std;
#include "Course.h"

class NormalCourse : public Course{
    public:
        NormalCourse();
        NormalCourse(const std::string& name, int level, int creditHours);

        void generateCode() override;
};

#endif //STUDENT_MANAGMENT_SYSTEM_NORMALCOURSE_H

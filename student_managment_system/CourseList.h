#ifndef STUDENT_MANAGMENT_SYSTEM_COURSELIST_H
#define STUDENT_MANAGMENT_SYSTEM_COURSELIST_H
#include "Course.h"
#include <bits/stdc++.h>
using namespace std;
class CourseList{
    public:
        // Static member to hold the list of courses
        static vector<Course*> courses;

        // Static function to search for a course by code
        static Course* SearchCourse(const string& code);

};
#endif //STUDENT_MANAGMENT_SYSTEM_COURSELIST_H
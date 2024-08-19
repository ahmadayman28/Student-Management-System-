#include <bits/stdc++.h>
using namespace std;
#include "CourseList.h"

// Initialize the static member variable
vector<Course*> CourseList::courses;

// Define the SearchCourse function
Course* CourseList::SearchCourse(const string& code) {
    for (Course* course : courses) {
        if (course->getCode() == code) {
            return course;
        }
    }
    return nullptr;  // Return nullptr if the course is not found
}

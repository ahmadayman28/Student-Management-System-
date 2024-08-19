#include <bits/stdc++.h>
using namespace std;
#include "Student.h"
#include "Rational.h"
#include "NormalCourse.h"
#include "SummerCourse.h"
#include "GeneralProgramStudent.h"
#include "SpecialProgramStudent.h"
#include "CourseList.h"

int main() {
    // Initialize the course list
    CourseList::courses = {
            new NormalCourse("Math", 1, 2),
            new NormalCourse("Programming_1", 1, 3),
            new NormalCourse("Technical_Writing", 1, 3),
            new NormalCourse("Electronics", 2, 4),
            new NormalCourse("Data_Structures", 2, 3),
            new NormalCourse("OOP", 2, 3),
            new NormalCourse("Algorithms", 3, 2),
            new NormalCourse("Operating_Systems", 3, 3),
            new NormalCourse("Databases", 3, 3),
            new NormalCourse("Machine_Learning", 4, 3),
            new NormalCourse("Compilers", 4, 4),
            new NormalCourse("Programming_Concepts", 4, 4),
            new SummerCourse("Math", 1, 2),
            new SummerCourse("Compilers", 4, 4),
            new SummerCourse("Algorithms", 3, 2),
            new SummerCourse("OOP", 2, 3)
    };

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<Student*> students;

    for (int i = 0; i < numStudents; ++i) {
        string name, id;
        int level, numCourses, studentType;

        cout << "\nEnter student type (0: general, 1: special): ";
        cin >> studentType;
        cout << "\nEnter student name: ";
        cin >> name;
        cout << "\nEnter student ID: ";
        cin >> id;
        cout << "\nEnter student level (1-4): ";
        cin >> level;
        cout << "\nEnter the number of courses to register (max 6): ";
        cin >> numCourses;

        // Limit the number of courses to 6
        if (numCourses > 6) {
            cout << "Error: Cannot register for more than 6 courses." << endl;
            numCourses = 6;
        }

        Student* student = nullptr;
        if (studentType == 0) {
            student = new GeneralProgramStudent(name, id, level);
        } else {
            student = new SpecialProgramStudent(name, id, level);
        }

        int validCourses = 0;

        while (validCourses < numCourses) {
            string courseCode;
            Rational grade;
            cout << "\nEnter course code: ";
            cin >> courseCode;
            Course* course = CourseList::SearchCourse(courseCode);

            if (course == nullptr) {
                cout << "Course not found!" << endl;
            } else if (studentType == 0 && course->getMinStudentLevel() > level) {
                cout << "Error: You cannot register in this course" << endl;
                validCourses++;  // Increment count for this failed attempt
            } else {
                cout << "Enter grade for course " << course->getCode() << ": ";
                cin >> grade;

                if (student->RegisterCourse(course, grade)) {
                    validCourses++;
                } else {
                    cout << "\nCourse registration failed!" << endl;
                }
            }
        }

        students.push_back(student);
    }

    for (Student* student : students) {
        cout << *student;
        cout << "Student Expenses: " << student->CalculateExpenses() << " EGP" << endl;
    }

    // Clean up memory
    for (Course* course : CourseList::courses) {
        delete course;
    }
    for (Student* student : students) {
        delete student;
    }

    return 0;
}
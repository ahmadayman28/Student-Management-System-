#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include "Course.h"
#include "Rational.h"
using namespace std;

class Student {
protected:
    string name;
    string id;
    int level;
    int noOfCourses;
    Course* courseList[6];
    Rational grades[6];

public:
    Student();
    Student(const string& name, const string& id, int level);

    string getName() const;
    void setName(const string& name);

    string getId() const;
    void setId(const string& id);

    int getLevel() const;
    void setLevel(int level);

    bool RegisterCourse(Course* course, const Rational& grade);
    // Define a new RegisterCourse method for the derived classes to override
    virtual bool RegisterCourse(Course* course) {
        return false;
    }
    virtual float CalculateExpenses() const = 0; // Pure virtual function
    void printRegisteredCourses() const;
    double getCourseGPA(const Rational& grade) const;
    double getTotalGPA() const;

    friend ostream& operator<<(ostream& os, const Student& student);
};

#endif // STUDENT_H
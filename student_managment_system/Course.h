#ifndef STUDENT_MANAGMENT_SYSTEM_COURSE_H
#define STUDENT_MANAGMENT_SYSTEM_COURSE_H
#include <bits/stdc++.h>
using namespace std;

class Course{
    protected:
        string name;
        string code;
        int minStudentLevel;
        int creditHours;
    public:
        // Constructors and Destructor
        Course();
        Course(const string& name, int minStudentLevel, int creditHours);
        ~Course();
        // Getters
        string getName() const;
        string getCode() const;
        int getMinStudentLevel() const;
        int getCreditHours() const;

        virtual void generateCode() = 0; // Pure virtual function to enforce derived classes to implement code generation

        // Operator overloads
        friend ostream& operator<<(ostream& os, const Course& course);
};
#endif //STUDENT_MANAGMENT_SYSTEM_COURSE_H

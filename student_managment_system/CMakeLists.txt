cmake_minimum_required(VERSION 3.23)
project(student_managment_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(student_managment_system main.cpp Rational.h Rational.cpp Student.h Student.cpp Course.h Course.cpp NormalCourse.h NormalCourse.cpp SummerCourse.h SummerCourse.cpp GeneralProgramStudent.h GeneralProgramStudent.cpp SpecialProgramStudent.h SpecialProgramStudent.cpp CourseList.h CourseList.cpp)

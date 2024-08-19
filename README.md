# Student Management System

## Project Overview
The Student Management System is a C++ application that simulates the registration process for students in various courses within a university. The system supports different types of courses (Normal and Summer courses) and different types of students (General Program Students and Special Program Students). Each student can register for up to six courses, and the system ensures that the registration process adheres to certain constraints, such as student level and course availability.

## Classes Overview
The project is composed of the following main classes:

- **Course**: An abstract base class representing a course. Derived classes must implement the `generateCode()` method.
- **NormalCourse**: A class derived from `Course` representing standard courses offered during regular semesters.
- **SummerCourse**: A class derived from `Course` representing courses offered during the summer semester.
- **Rational**: A class that encapsulates rational numbers, supporting arithmetic operations and simplification.
- **Student**: An abstract base class representing a student. It manages course registration and grade storage.
- **GeneralProgramStudent**: A class derived from `Student` representing students in a general program.
- **SpecialProgramStudent**: A class derived from `Student` representing students in a special program.
- **CourseList**: A utility class that manages the list of all available courses and provides a search functionality.

## OOP Concepts Applied
The project implements several Object-Oriented Programming (OOP) concepts:

- **Encapsulation**: Each class encapsulates its data and provides public methods for interaction. For example, the `Rational` class encapsulates numerator and denominator with appropriate getter methods.
- **Inheritance**: The project uses inheritance to create a hierarchy of classes. The `NormalCourse` and `SummerCourse` classes inherit from the `Course` base class.
- **Polymorphism**: The project employs polymorphism through the use of virtual methods. For example, the `generateCode()` method in the `Course` class is overridden by derived classes.
- **Abstraction**: The `Course` and `Student` classes are abstract, meaning they define interfaces that must be implemented by derived classes.

## SOLID Principles Applied
The project follows several SOLID principles:

- **Single Responsibility Principle (SRP)**: Each class has a single responsibility. For instance, the `CourseList` class only manages the list of courses, while the `Rational` class only manages rational numbers.
- **Open/Closed Principle (OCP)**: The system is open for extension but closed for modification. New types of courses or students can be added by extending the existing base classes without modifying them.
- **Liskov Substitution Principle (LSP)**: Objects of derived classes can be used wherever objects of the base class are expected. For example, a `NormalCourse` or `SummerCourse` can be used wherever a `Course` is expected.
- **Interface Segregation Principle (ISP)**: The project avoids fat interfaces. The `Course` and `Student` classes define minimal, specific interfaces that their derived classes implement.
- **Dependency Inversion Principle (DIP)**: High-level modules (e.g., `Student` class) do not depend on low-level modules but rather on abstractions (e.g., `Course` class).

## Design Patterns Used
The project incorporates the following design patterns:

- **Factory Method Pattern**: The `generateCode()` method in the `Course` class acts as a factory method that is overridden in derived classes to generate specific course codes.
- **Strategy Pattern**: The system uses different strategies for calculating expenses in the `GeneralProgramStudent` and `SpecialProgramStudent` classes, allowing for different algorithms to be used based on the student type.
- **Template Method Pattern**: The abstract `Course` and `Student` classes define the skeleton of algorithms (e.g., course registration) and defer some steps to subclasses.

## How to Run the Project
To run the project, follow these steps:

1. Ensure that you have a C++ compiler installed on your system.
2. Clone the project repository or download the source code.
3. Compile the source code using a C++ compiler. For example:

    ```bash
    g++ -std=c++11 main.cpp Student.cpp Rational.cpp NormalCourse.cpp SummerCourse.cpp GeneralProgramStudent.cpp SpecialProgramStudent.cpp CourseList.cpp -o StudentManagementSystem
    ```

4. Run the compiled executable:

    ```bash
    ./StudentManagementSystem
    ```

## Future Enhancements
Possible future enhancements for the project include:

- Adding support for more types of courses (e.g., online courses, lab courses).
- Implementing a GUI for the registration process.
- Integrating the system with a database to store and retrieve student and course data.

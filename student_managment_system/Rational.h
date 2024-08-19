#ifndef STUDENT_MANAGMENT_SYSTEM_RATIONAL_H
#define STUDENT_MANAGMENT_SYSTEM_RATIONAL_H

#include <bits/stdc++.h>
using namespace std;

class Rational {
    private:
        int numerator;
        int denominator;

        void simplify(); // Helper function to simplify the rational number

    public:
        // Constructors
        Rational();
        Rational(int numerator, int denominator);

        // Accessors
        int getNumerator() const;
        int getDenominator() const;

        // Operator overloads for arithmetic operations
        Rational operator+(const Rational& rhs) const;
        Rational operator-(const Rational& rhs) const;
        Rational operator*(const Rational& rhs) const;
        Rational operator/(const Rational& rhs) const;

        // Operator overload for equality check
        bool operator==(const Rational& rhs) const;

        // Other member functions
        int compareTo(const Rational& rhs) const;
        int intValue() const;
        double doubleValue() const;
        string toString() const;

        // Static utility function
        static int gcd(int n, int d);
        // Friend functions for input and output
        friend ostream& operator<<(ostream& os, const Rational& r);
        friend istream& operator>>(istream& is, Rational& r);
};

#endif //STUDENT_MANAGMENT_SYSTEM_RATIONAL_H

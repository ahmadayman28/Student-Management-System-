#include "Rational.h"
#include <bits/stdc++.h>
using namespace std;

// Private helper function to simplify the rational number
void Rational::simplify() {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue;
    if (denominator < 0) { // Handle negative denominator
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Constructors
Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    simplify();
}

// Accessors
int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

// Arithmetic operations
Rational Rational::operator+(const Rational& rhs) const {
    int newNumerator = numerator * rhs.denominator + rhs.numerator * denominator;
    int newDenominator = denominator * rhs.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-(const Rational& rhs) const {
    int newNumerator = numerator * rhs.denominator - rhs.numerator * denominator;
    int newDenominator = denominator * rhs.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator*(const Rational& rhs) const {
    int newNumerator = numerator * rhs.numerator;
    int newDenominator = denominator * rhs.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator/(const Rational& rhs) const {
    if (rhs.numerator == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    int newNumerator = numerator * rhs.denominator;
    int newDenominator = denominator * rhs.numerator;
    return Rational(newNumerator, newDenominator);
}

// Equality check
bool Rational::operator==(const Rational& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

// Comparison
int Rational::compareTo(const Rational& rhs) const {
    Rational diff = *this - rhs;
    if (diff.numerator > 0) return 1;
    if (diff.numerator < 0) return -1;
    return 0;
}

// Conversion to integer
int Rational::intValue() const {
    return numerator / denominator;
}

// Conversion to double
double Rational::doubleValue() const {
    return static_cast<double>(numerator) / denominator;
}

// Conversion to string
string Rational::toString() const {
    if (denominator == 1) return to_string(numerator);
    return to_string(numerator) + "/" + to_string(denominator);
}

// Static utility function to calculate gcd
int Rational::gcd(int n, int d) {
    if (d == 0) return n;
    return gcd(d, n % d);
}

// Overload << operator
ostream& operator<<(ostream& os, const Rational& r) {
    os << r.toString();
    return os;
}

// Overload >> operator
istream& operator>>(istream& is, Rational& r) {
    string input;
    is >> input;

    // Check if input contains a slash
    if (input.find('/') != string::npos) {
        stringstream ss(input);
        char slash;
        ss >> r.numerator >> slash >> r.denominator;
    } else {
        // Convert integer percentage to Rational (e.g., 90 -> 90/100)
        r.numerator = stoi(input);
        r.denominator = 100;
    }

    r.simplify();
    return is;
}
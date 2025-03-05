#include "Fraction.h"
#include <iostream>
#include <stdexcept>

// Helper function to simplify the fraction using the Euclidean Algorithm (GCD)
void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a; // GCD is stored in 'a' after loop exits

    num /= gcd;
    den /= gcd;

    // Ensure the denominator is positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// Default constructor initializes to 0/1
Fraction::Fraction() : num(0), den(1) {}

// Parameterized constructor
Fraction::Fraction(int n, int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    num = n;
    den = d;
    simplify();
}

// Getter for numerator
int Fraction::getNumerator() const {
    return num;
}

// Getter for denominator
int Fraction::getDenominator() const {
    return den;
}

// Setter for numerator
void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

// Setter for denominator
void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

// Arithmetic operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den + rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    Fraction result(newNum, newDen);
    return result;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den - rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    Fraction result(newNum, newDen);
    return result;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.num;
    int newDen = lhs.den * rhs.den;
    Fraction result(newNum, newDen);
    return result;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Division by zero");
    int newNum = lhs.num * rhs.den;
    int newDen = lhs.den * rhs.num;
    Fraction result(newNum, newDen);
    return result;
}

// Overload stream operator to print fractions
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;
    return out;
}

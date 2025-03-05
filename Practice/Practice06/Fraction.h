#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept> // For exception handling

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator

    void simplify(); // Helper function to simplify the fraction

public:
    // Constructors
    Fraction(); // Default constructor
    Fraction(int n, int d); // Parameterized constructor

    // Getter and setter functions
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d); // Throws exception if d == 0

    // Arithmetic operator overloads
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs); // Throws exception if division by zero

    // Stream operator overload for printing fractions
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
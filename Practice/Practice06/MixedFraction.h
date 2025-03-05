#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole; // Whole part of the mixed fraction

public:
    // Constructors
    MixedFraction(int whole, int n, int d); // From whole and fractional part
    MixedFraction(const Fraction& f); // Converts a fraction to mixed form

    // Override the stream operator to print as a mixed fraction
    friend std::ostream& operator<<(std::ostream& out, const MixedFraction& mf);
};

#endif
MixedFraction.cpp
cpp
Copy
#include "MixedFraction.h"
#include <iostream>
#include <cmath>

// Constructor that converts a fraction into a mixed fraction
MixedFraction::MixedFraction(int w, int n, int d) : Fraction(n, d), whole(w) {}

// Constructor that converts a Fraction to a mixed fraction
MixedFraction::MixedFraction(const Fraction& f) {
    int absNumerator = std::abs(f.getNumerator());
    whole = absNumerator / f.getDenominator();
    int newNumerator = absNumerator % f.getDenominator();
    Fraction frac(newNumerator, f.getDenominator());
    *this = frac; // Simplify the fraction part
}

// Overload the stream operator to print mixed fractions
std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    if (mf.whole != 0) {
        out << mf.whole << " ";
    }
    if (mf.getNumerator() != 0) {
        out << mf.getNumerator() << "/" << mf.getDenominator();
    }
    return out;
}

#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

void enterFraction(Fraction& currentFraction) {
    int n, d;
    cout << "Enter numerator and denominator: ";
    cin >> n >> d;
    if (d == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
    } else {
        currentFraction = Fraction(n, d);
    }
}

void addFraction(Fraction& currentFraction) {
    int n, d;
    cout << "Enter numerator and denominator to add: ";
    cin >> n >> d;
    if (d == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
    } else {
        Fraction f(n, d);
        currentFraction = currentFraction + f;
    }
}

void subtractFraction(Fraction& currentFraction) {
    int n, d;
    cout << "Enter numerator and denominator to subtract: ";
    cin >> n >> d;
    if (d == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
    } else {
        Fraction f(n, d);
        currentFraction = currentFraction - f;
    }
}

void multiplyFraction(Fraction& currentFraction) {
    int n, d;
    cout << "Enter numerator and denominator to multiply: ";
    cin >> n >> d;
    if (d == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
    } else {
        Fraction f(n, d);
        currentFraction = currentFraction * f;
    }
}

void divideFraction(Fraction& currentFraction) {
    int n, d;
    cout << "Enter numerator and denominator to divide: ";
    cin >> n >> d;
    if (d == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
    } else {
        Fraction f(n, d);
        if (f.getNumerator() == 0) {
            cout << "Error: Division by zero." << endl;
        } else {
            currentFraction = currentFraction / f;
        }
    }
}

void displayMixedFraction(const Fraction& currentFraction) {
    MixedFraction mf(currentFraction);
    cout << "Mixed Fraction: " << mf << endl;
}

void clearFraction(Fraction& currentFraction) {
    currentFraction = Fraction(0, 1); // Reset to 0/1
}

int main() {
    Fraction currentFraction(0, 1); // Starting with 0/1
    int option = 0;

    cout << "\nCurrent Fraction: " << currentFraction << endl;

    cout << "Options:\n";
    cout << "1. Enter a fraction manually\n";
    cout << "2. Add a fraction\n";
    cout << "3. Subtract a fraction\n";
    cout << "4. Multiply by a fraction\n";
    cout << "5. Divide by a fraction\n";
    cout << "6. Display as Mixed Fraction\n";
    cout << "7. Clear Fraction\n";
    cout << "8. Exit\n";

    // Prompt the user for their choice
    cout << "Choose an option: ";
    cin >> option;

    // Perform the selected operation
    if (option == 1) {
        enterFraction(currentFraction);
    }
    else if (option == 2) {
        addFraction(currentFraction);
    }
    else if (option == 3) {
        subtractFraction(currentFraction);
    }
    else if (option == 4) {
        multiplyFraction(currentFraction);
    }
    else if (option == 5) {
        divideFraction(currentFraction);
    }
    else if (option == 6) {
        displayMixedFraction(currentFraction);
    }
    else if (option == 7) {
        clearFraction(currentFraction);
    }
    else if (option == 8) {
        cout << "Exiting program." << endl;
        return 0;
    }
    else {
        cout << "Invalid option. Please try again.\n";
    }

    return 0;
}
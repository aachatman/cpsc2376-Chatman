#include <iostream>
#include <string>
#include <type_traits>
#include <iomanip>  // For formatting output

template <typename T>
T calculate(T a, T b, char op) {
    T result;

    // Handle the operation using if-else
    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b != 0) {
            result = a / b;
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0;
        }
    } else {
        std::cerr << "Invalid operation!" << std::endl;
        return 0;
    }

    return result;
}

template <typename T>
void promptAndCalculate() {
    T num1, num2;
    char op;

    // Get user input for the first number, second number, and operation
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    // Perform the calculation
    T result = calculate(num1, num2, op);

    // Output result
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << "Result: " << result << std::endl;
    }
}

int main() {
    // Ask user for type of numbers (int or double)
    std::string typeChoice;
    std::cout << "Do you want to use integers or floating-point numbers (type 'int' or 'float')? ";
    std::cin >> typeChoice;

    if (typeChoice == "int") {
        promptAndCalculate<int>();  // Use template for int
    } else if (typeChoice == "float" || typeChoice == "double") {
        promptAndCalculate<double>();  // Use template for double
    } else {
        std::cerr << "Invalid type choice!" << std::endl;
    }

    return 0;
}
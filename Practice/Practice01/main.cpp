#include <iostream>
#include <vector>

// Function prototypes
void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main() {
    std::vector<int> numbers;
    int choice;

    // Loop for continuous menu interaction (uses a for loop)
    for (;;) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a number\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Use for loop for each menu choice handling
        if (choice == 1) {
            int num;
            std::cout << "Enter a number to add to the vector: ";
            std::cin >> num;
            numbers.push_back(num);
        }
        else if (choice == 2) {
            printVector(numbers);
        }
        else if (choice == 3) {
            doubleVector(numbers);
        }
        else if (choice == 4) {
            std::cout << "The sum of the vector is: " << calculateSum(numbers) << std::endl;
        }
        else if (choice == 5) {
            int multiple;
            std::cout << "Enter a number to find its multiples in the vector: ";
            std::cin >> multiple;
            printMultiples(numbers, multiple);
        }
        else if (choice == 6) {
            std::cout << "Exiting the program.\n";
            break;  // Exit the for loop (and the program)
        }
        else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Function to print the vector
void printVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
    }
    else {
        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec.at(i) << " ";  // Use .at() for safe element access
        }
        std::cout << std::endl;
    }
}

// Function to double the values in the vector
void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec.at(i) *= 2;  // Double each value
    }
    std::cout << "The vector has been doubled.\n";
}

// Function to calculate the sum of the vector
int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec.at(i);  // Add each element to the sum
    }
    return sum;
}

// Function to print multiples of a given number from the vector
void printMultiples(const std::vector<int>& vec, int multiple) {
    bool found = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % multiple == 0) {
            std::cout << vec.at(i) << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No multiples of " << multiple << " found in the vector.\n";
    }
    std::cout << std::endl;
}

#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello") {
    std::cout << prefix << ", " << name << "!" << std::endl;
}

int main() {
    int choice;
    std::string name, prefix;

    // Display menu
    do {
        std::cout << "1. Default Greeting" << std::endl;
        std::cout << "2. Greet by Name" << std::endl;
        std::cout << "3. Custom Greeting" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        // Handle user choice using if-else
        if (choice == 1) {
            // Default Greeting (no input needed)
            greet();
        } else if (choice == 2) {
            // Greet by Name
            std::cout << "Enter name: ";
            std::cin.ignore(); // To ignore any extra newline character from previous input
            std::getline(std::cin, name);
            greet(name);  // Uses default prefix "Hello"
        } else if (choice == 3) {
            // Custom Greeting
            std::cout << "Enter greeting prefix: ";
            std::cin.ignore(); // To clear any leftover input from previous case
            std::getline(std::cin, prefix);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name, prefix);  // Uses custom greeting and name
        } else {
            std::cout << "Invalid choice, please try again." << std::endl;
        }

        // Optional: Ask if the user wants to continue
        std::cout << "\nDo you want to choose again? (1 for Yes, 0 for No): ";
        std::cin >> choice;

    } while (choice == 1);

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
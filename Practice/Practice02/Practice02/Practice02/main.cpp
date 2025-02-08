#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

// Function prototypes
void displayMenu();
void checkBalance(double& balance);
void deposit(double& balance);
void withdraw(double& balance);
bool readBalanceFromFile(double& balance);
bool writeBalanceToFile(double balance);

int main() {
    double balance = 0.0;

    // Try to read balance from the file, or initialize if not found
    if (!readBalanceFromFile(balance)) {
        // If file doesn't exist or fails to read, initialize balance to 100.00
        balance = 100.00;
        std::cout << "Welcome to Your Bank Account!\n";
        std::cout << "Initializing account with $100.00...\n";
        writeBalanceToFile(balance); // Save the initial balance to the file
    }
    else {
        std::cout << "Welcome to Your Bank Account!\n";
        std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    displayMenu();
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Validate input
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid choice. Please try again.\n";
        return 0; // Exit program if input is invalid
    }

    if (choice == 1) {
        checkBalance(balance);
    }
    else if (choice == 2) {
        deposit(balance);
    }
    else if (choice == 3) {
        withdraw(balance);
    }
    else if (choice == 4) {
        std::cout << "Thank you for using Your Bank Account. Goodbye!\n";
    }
    else {
        std::cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n";
}

// Function to check the balance
void checkBalance(double& balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

// Function to deposit money
void deposit(double& balance) {
    double amount;
    std::cout << "Enter deposit amount: $";
    std::cin >> amount;

    // Validate deposit amount
    if (std::cin.fail() || amount <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Deposit amount must be positive.\n";
    }
    else {
        balance += amount;
        if (!writeBalanceToFile(balance)) {
            std::cout << "Error: Could not update balance in the file.\n";
        }
        else {
            std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
        }
    }
}

// Function to withdraw money
void withdraw(double& balance) {
    double amount;
    std::cout << "Enter withdrawal amount: $";
    std::cin >> amount;

    // Validate withdrawal amount
    if (std::cin.fail() || amount <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Withdrawal amount must be positive.\n";
    }
    else if (amount > balance) {
        std::cout << "Error: Insufficient funds. Your balance is $" << std::fixed << std::setprecision(2) << balance << ".\n";
    }
    else {
        balance -= amount;
        if (!writeBalanceToFile(balance)) {
            std::cout << "Error: Could not update balance in the file.\n";
        }
        else {
            std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
        }
    }
}

// Function to read balance from the file
bool readBalanceFromFile(double& balance) {
    std::ifstream inputFile("account_balance.txt");
    if (!inputFile) {
        return false; // File doesn't exist or cannot be opened
    }

    inputFile >> balance;
    inputFile.close();
    return true;
}

// Function to write balance to the file
bool writeBalanceToFile(double balance) {
    std::ofstream outputFile("account_balance.txt");
    if (!outputFile) {
        return false; // File cannot be opened
    }

    outputFile << balance;
    outputFile.close();
    return true;
}
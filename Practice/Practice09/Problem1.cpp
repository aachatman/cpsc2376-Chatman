#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};  // Amount of red potion in mL
    float bluePotion{0.0f}; // Amount of blue potion in mL
    float* flask{nullptr};   // Pointer to the selected potion

    std::string potionChoice;
    float potionAmount;

    while (true) {
        // Ask the user which potion to add liquid to
        std::cout << "Which potion to add liquid to (Red/Blue)? Type 'Done' to finish: ";
        std::cin >> potionChoice;

        // Check if the user wants to exit
        if (potionChoice == "Done" || potionChoice == "done") {
            break;
        }

        // Update the flask pointer based on the user's choice
        if (potionChoice == "Red" || potionChoice == "red") {
            flask = &redPotion;
        } else if (potionChoice == "Blue" || potionChoice == "blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid choice. Please type 'Red' or 'Blue'.\n";
            continue;
        }

        // Ask how many milliliters to add and update the flask pointer
        std::cout << "How many milliliters to add? ";
        std::cin >> potionAmount;

        // Add the potion to the selected flask
        *flask += potionAmount;

        // Display both potion levels
        std::cout << "Current potion levels: Red = " << redPotion << " mL, Blue = " << bluePotion << " mL\n";
    }

    return 0;
}

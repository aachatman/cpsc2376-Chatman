#include <iostream>
#include <deque>
#include <string>

class UndoableTextEditor {
public:
    void addText(const std::string& text) {
        // Add new text to the deque
        content.push_back(text);
        std::cout << "Text added!" << std::endl;
    }

    void undo() {
        // Undo the last edit
        if (!content.empty()) {
            content.pop_back();
            std::cout << "Undo successful!" << std::endl;
        } else {
            std::cout << "No edits to undo!" << std::endl;
        }
    }

    void showContent() {
        // Show current content
        if (content.empty()) {
            std::cout << "No content available!" << std::endl;
        } else {
            std::cout << "Current Content: ";
            for (const auto& line : content) {
                std::cout << line << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::deque<std::string> content;  // Deque to store text edits
};

void showMenu(UndoableTextEditor& editor) {
    int choice;
    std::string inputText;

    // Display the menu options
    std::cout << "1. Add Text" << std::endl;
    std::cout << "2. Undo Last Edit" << std::endl;
    std::cout << "3. Show Content" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();  // Ignore leftover newline character

    if (choice == 1) {
        // Add text
        std::cout << "Enter text: ";
        std::getline(std::cin, inputText);
        editor.addText(inputText);
    } else if (choice == 2) {
        // Undo last edit
        editor.undo();
    } else if (choice == 3) {
        // Show content
        editor.showContent();
    } else if (choice == 4) {
        // Exit
        std::cout << "Exiting..." << std::endl;
        return;  // End recursion, effectively exiting the program
    } else {
        std::cout << "Invalid choice! Please try again." << std::endl;
    }

    // Recursive call to show the menu again after performing an action
    showMenu(editor);
}

int main() {
    UndoableTextEditor editor;

    // Start the menu system by calling the recursive function
    showMenu(editor);

    return 0;
}
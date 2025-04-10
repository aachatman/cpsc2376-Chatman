# **Design.md**

## **Program Specification**

The program is designed to help manage a local board game café by tracking the games available for borrowing, who has borrowed them, and when they are due to be returned. The tool will allow users to view a list of available games, check out games to customers, and track the return of games. It is lightweight and straightforward, specifically tailored for the lending operations of a small board game café.

### **Key Entities Involved**:
1. **Game**: Represents a board game available in the café's inventory.
2. **Customer**: Represents a customer borrowing a game from the café.
3. **Loan**: Represents a borrowing transaction, including the game borrowed and the return date.

### **Functionality**:
- **View available games**: Display a list of games and the number of available copies.
- **Check out games**: Lend a game to a customer and update the available copies.
- **Track returns**: Mark a game as returned and update the inventory.
- **Track due dates**: Keep track of when games are due to be returned.

---

## **Key Nouns and Verbs**

### **Nouns**:
- **Game**: A board game in the café’s collection.
- **Customer**: A person who borrows a game.
- **Loan**: A transaction that represents a game borrowed by a customer.
- **Inventory**: The collection of games available in the café.

### **Verbs**:
- **Check out**: To lend a game to a customer.
- **Return**: To mark a borrowed game as returned.
- **Track**: To monitor the availability of games and loan due dates.
- **List**: To display all games and their availability.

---

## **Class Design**

### **Class 1: `Game`**

```cpp
class Game {
public:
    string name;          // Name of the game
    int totalCopies;      // Total number of copies of the game
    int availableCopies;  // Number of available copies for borrowing

    Game(string name, int totalCopies);
    void checkOutGame();
    void returnGame();
};

class Customer {
public:
    string name;              // Name of the customer
    int customerID;           // Unique identifier for the customer
    vector<Game> borrowedGames; // List of games currently borrowed by the customer

    Customer(string name, int customerID);
    void borrowGame(Game &game);
    void returnGame(Game &game);
};

class Loan {
public:
    Game game;               // The game being borrowed
    Customer customer;       // The customer borrowing the game
    string dueDate;          // The date the game is due back

    Loan(Game game, Customer customer, string dueDate);
    void extendLoan(string newDueDate);
};

classDiagram
    class Game {
        +string name
        +int totalCopies
        +int availableCopies
        +Game(string name, int totalCopies)
        +void checkOutGame()
        +void returnGame()
    }

    class Customer {
        +string name
        +int customerID
        +vector~Game~ borrowedGames
        +Customer(string name, int customerID)
        +void borrowGame(Game &game)
        +void returnGame(Game &game)
    }

    class Loan {
        +Game game
        +Customer customer
        +string dueDate
        +Loan(Game game, Customer customer, string dueDate)
        +void extendLoan(string newDueDate)
    }

    Game "1" -- "0..*" Loan : has a
    Customer "1" -- "0..*" Loan : has a
    Game "1" -- "0..*" Customer : used by

#pragma once

#include <iostream>
#include <vector>

class Game {
public:
    enum class Status {
        ONGOING,
        PLAYER_1_WINS,
        PLAYER_2_WINS,
        DRAW
    };

    enum class Cell {
        EMPTY,
        PLAYER_1,
        PLAYER_2
    };

    Game();  // Constructor to initialize the game

    void play(int move);  // Executes a move for the current player
    Status status() const;  // Returns the game status
    void display() const;  // Prints the current board

    friend std::ostream& operator<<(std::ostream& os, const Game& game);  // Friend function to display the board

private:
    std::vector<std::vector<Cell>> board;  // 2D vector representing the game board
    Status currentStatus;  // Current game status
    Cell currentPlayer;  // Whose turn it is
    int rows;  // Number of rows in the board
    int cols;  // Number of columns in the board

    bool checkWin() const;  // Check if the current player has won
    bool checkDraw() const;  // Check if the game is a draw
    bool isValidMove(int move) const;  // Validate if the move is valid
};
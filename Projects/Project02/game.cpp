#include "game.h"
#include <iostream>
#include <vector>

Game::Game() : rows(6), cols(7), currentPlayer(Cell::PLAYER_1), currentStatus(Status::ONGOING) {
    board.resize(rows, std::vector<Cell>(cols, Cell::EMPTY));  // Initialize the board with EMPTY cells
}

void Game::play(int move) {
    if (currentStatus != Status::ONGOING || !isValidMove(move)) {
        return;  // Don't make a move if the game is over or the move is invalid
    }

    // Drop the piece in the appropriate row of the selected column
    for (int row = rows - 1; row >= 0; --row) {
        if (board.at(row).at(move) == Cell::EMPTY) {
            board.at(row).at(move) = currentPlayer;
            break;
        }
    }

    // Check for win or draw
    if (checkWin()) {
        currentStatus = (currentPlayer == Cell::PLAYER_1) ? Status::PLAYER_1_WINS : Status::PLAYER_2_WINS;
    } else if (checkDraw()) {
        currentStatus = Status::DRAW;
    }

    // Switch player
    currentPlayer = (currentPlayer == Cell::PLAYER_1) ? Cell::PLAYER_2 : Cell::PLAYER_1;
}

Game::Status Game::status() const {
    return currentStatus;
}

void Game::display() const {
    std::cout << *this;  // Delegate to the friend operator<<
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int i = 0; i < game.rows; ++i) {
        for (int j = 0; j < game.cols; ++j) {
            if (game.board.at(i).at(j) == Game::Cell::EMPTY) {
                os << ". ";  // Empty cell
            } else if (game.board.at(i).at(j) == Game::Cell::PLAYER_1) {
                os << "X ";  // Player 1 piece
            } else {
                os << "O ";  // Player 2 piece
            }
        }
        os << "\n";
    }
    return os;
}

bool Game::checkWin() const {
    // Check horizontal, vertical, and diagonal lines for a winner
    // Check horizontal
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (board.at(row).at(col) == currentPlayer && 
                board.at(row).at(col) == board.at(row).at(col + 1) && 
                board.at(row).at(col) == board.at(row).at(col + 2) && 
                board.at(row).at(col) == board.at(row).at(col + 3)) {
                return true;
            }
        }
    }

    // Check vertical
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows - 3; ++row) {
            if (board.at(row).at(col) == currentPlayer &&
                board.at(row).at(col) == board.at(row + 1).at(col) && 
                board.at(row).at(col) == board.at(row + 2).at(col) && 
                board.at(row).at(col) == board.at(row + 3).at(col)) {
                return true;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (board.at(row).at(col) == currentPlayer && 
                board.at(row).at(col) == board.at(row - 1).at(col + 1) && 
                board.at(row).at(col) == board.at(row - 2).at(col + 2) && 
                board.at(row).at(col) == board.at(row - 3).at(col + 3)) {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int row = 0; row < rows - 3; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (board.at(row).at(col) == currentPlayer && 
                board.at(row).at(col) == board.at(row + 1).at(col + 1) && 
                board.at(row).at(col) == board.at(row + 2).at(col + 2) && 
                board.at(row).at(col) == board.at(row + 3).at(col + 3)) {
                return true;
            }
        }
    }

    return false;
}

bool Game::checkDraw() const {
    // Check if the board is full and there's no winner
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board.at(row).at(col) == Cell::EMPTY) {
                return false;  // There's still an empty cell
            }
        }
    }
    return true;  // All cells are filled and there's no winner
}

bool Game::isValidMove(int move) const {
    // Check if the move is within the valid column range
    if (move < 0 || move >= cols) {
        return false;
    }

    // Check if there's space in the column
    if (board.at(0).at(move) != Cell::EMPTY) {
        return false;
    }

    return true;
}

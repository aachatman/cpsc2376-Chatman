#include "game.h"
#include <iostream>

Game::Game() : rows(6), cols(7), currentPlayer(Cell::PLAYER_1), currentStatus(Status::ONGOING) {
    board.resize(rows, std::vector<Cell>(cols, Cell::EMPTY));
}

void Game::play(int col) {
    if (currentStatus != Status::ONGOING || !isValidMove(col)) return;

    for (int row = rows - 1; row >= 0; --row) {
        if (board[row][col] == Cell::EMPTY) {
            board[row][col] = currentPlayer;
            break;
        }
    }

    if (checkWin()) {
        currentStatus = (currentPlayer == Cell::PLAYER_1) ? Status::PLAYER_1_WINS : Status::PLAYER_2_WINS;
    }
    else if (checkDraw()) {
        currentStatus = Status::DRAW;
    }
    else {
        currentPlayer = (currentPlayer == Cell::PLAYER_1) ? Cell::PLAYER_2 : Cell::PLAYER_1;
    }
}

Game::Status Game::status() const {
    return currentStatus;
}

bool Game::checkWin() const {
    // Horizontal, vertical, and diagonal checks
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            Cell c = board[row][col];
            if (c != Cell::EMPTY &&
                c == board[row][col + 1] &&
                c == board[row][col + 2] &&
                c == board[row][col + 3])
                return true;
        }
    }
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows - 3; ++row) {
            Cell c = board[row][col];
            if (c != Cell::EMPTY &&
                c == board[row + 1][col] &&
                c == board[row + 2][col] &&
                c == board[row + 3][col])
                return true;
        }
    }
    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            Cell c = board[row][col];
            if (c != Cell::EMPTY &&
                c == board[row - 1][col + 1] &&
                c == board[row - 2][col + 2] &&
                c == board[row - 3][col + 3])
                return true;
        }
    }
    for (int row = 0; row < rows - 3; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            Cell c = board[row][col];
            if (c != Cell::EMPTY &&
                c == board[row + 1][col + 1] &&
                c == board[row + 2][col + 2] &&
                c == board[row + 3][col + 3])
                return true;
        }
    }
    return false;
}

bool Game::checkDraw() const {
    for (int col = 0; col < cols; ++col)
        if (board[0][col] == Cell::EMPTY)
            return false;
    return true;
}

bool Game::isValidMove(int col) const {
    return col >= 0 && col < cols && board[0][col] == Cell::EMPTY;
}

void Game::draw(SDL_Renderer* renderer) const {
    const int cellSize = 100;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            SDL_Rect rect = { col * cellSize, row * cellSize, cellSize, cellSize };
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue background
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black border
            SDL_RenderDrawRect(renderer, &rect);

            // Draw piece
            Cell c = board[row][col];
            if (c != Cell::EMPTY) {
                SDL_SetRenderDrawColor(renderer,
                    c == Cell::PLAYER_1 ? 255 : 255,
                    c == Cell::PLAYER_1 ? 0 : 255,
                    0, 255); // Red or Yellow
                SDL_Rect circle = { col * cellSize + 10, row * cellSize + 10, 80, 80 };
                SDL_RenderFillRect(renderer, &circle);
            }
        }
    }
}

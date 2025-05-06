#pragma once

#include <vector>
#include <SDL2/SDL.h>

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

    Game();

    void play(int col);
    Status status() const;
    void draw(SDL_Renderer* renderer) const;

private:
    std::vector<std::vector<Cell>> board;
    Status currentStatus;
    Cell currentPlayer;
    int rows;
    int cols;

    bool checkWin() const;
    bool checkDraw() const;
    bool isValidMove(int col) const;
};

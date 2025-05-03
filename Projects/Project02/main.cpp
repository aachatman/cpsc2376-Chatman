#include "game.h"

int main() {
    Game game;

    int move;
    while (game.status() == Game::Status::ONGOING) {
        game.display();
        std::cout << "Player " << (game.status() == Game::Status::ONGOING ? (game.status() == Game::Status::PLAYER_1_WINS ? "1" : "2") : "Draw") << "'s turn. Enter column (0-6): ";
        std::cin >> move;

        game.play(move);
    }

    game.display();

    if (game.status() == Game::Status::PLAYER_1_WINS) {
        std::cout << "Player 1 wins!\n";
    } else if (game.status() == Game::Status::PLAYER_2_WINS) {
        std::cout << "Player 2 wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}
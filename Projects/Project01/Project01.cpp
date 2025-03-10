#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <cctype> // For toupper

enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE,
    ORANGE,
    COUNT // For array sizes
};

enum class GameState {
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

class FloodItGame {
private:
    std::vector<std::vector<Color>> board;
    int boardSize;
    Color player1Color;
    Color player2Color;

public:
    FloodItGame(int size) : boardSize(size), player1Color(Color::RED), player2Color(Color::RED) {}

    void makeBoard() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, static_cast<int>(Color::COUNT) - 2);

        board.assign(boardSize, std::vector<Color>(boardSize));
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                board.at(i).at(j) = static_cast<Color>(distrib(gen));
            }
        }
        player1Color = board.at(0).at(0);
        player2Color = board.at(boardSize - 1).at(boardSize - 1);
    }

    void printBoard() const {
        for (const auto& row : board) {
            for (const auto& color : row) {
                switch (color) {
                    case Color::RED: std::cout << "R "; break;
                    case Color::GREEN: std::cout << "G "; break;
                    case Color::BLUE: std::cout << "B "; break;
                    case Color::YELLOW: std::cout << "Y "; break;
                    case Color::PURPLE: std::cout << "P "; break;
                    case Color::ORANGE: std::cout << "O "; break;
                    default: std::cout << "? "; break;
                }
            }
            std::cout << std::endl;
        }
    }

    void floodFill(int x, int y, Color oldColor, Color newColor) {
        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize || board.at(x).at(y) != oldColor || oldColor == newColor) {
            return;
        }

        board.at(x).at(y) = newColor;

        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }

    void play(int player, Color newColor) {
        if (player == 1) {
            floodFill(0, 0, player1Color, newColor);
            player1Color = newColor;
        } else {
            floodFill(boardSize - 1, boardSize - 1, player2Color, newColor);
            player2Color = newColor;
        }
    }

    GameState gameStatus() const {
        bool player1Wins = true;
        bool player2Wins = true;

        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (board.at(i).at(j) != player1Color) {
                    player1Wins = false;
                }
                if(board.at(i).at(j) != player2Color){
                    player2Wins = false;
                }
            }
        }

        if (player1Wins) {
            return GameState::PLAYER_1_WINS;
        } else if(player2Wins){
            return GameState::PLAYER_2_WINS;
        }
        else {
            return GameState::ONGOING;
        }
    }

    Color getColorFromInput() const {
        char colorChar;
        while (true) {
            std::cout << "Enter color (R/G/B/Y/P/O): ";
            std::cin >> colorChar;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            colorChar = toupper(colorChar);

            switch (colorChar) {
                case 'R': return Color::RED;
                case 'G': return Color::GREEN;
                case 'B': return Color::BLUE;
                case 'Y': return Color::YELLOW;
                case 'P': return Color::PURPLE;
                case 'O': return Color::ORANGE;
                default:
                    std::cout << "Invalid color. Please try again." << std::endl;
            }
        }
    }

    void printRules() const {
        std::cout << "Welcome to Flood It!\n";
        std::cout << "Players take turns selecting a color to flood their territory.\n";
        std::cout << "The flood effect only applies to horizontally and vertically adjacent tiles that are already the same color.\n";
        std::cout << "Player 1 starts at the top-left corner, and Player 2 at the bottom-right.\n";
        std::cout << "The goal is to turn the entire board to your color.\n";
        std::cout << "Colors: R (Red), G (Green), B (Blue), Y (Yellow), P (Purple), O (Orange)\n";
        std::cout << std::endl;
    }
};

int main() {
    int boardSize = 10;
    FloodItGame game(boardSize);
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        game.makeBoard();
        game.printRules();
        game.printBoard();

        GameState gameState = GameState::ONGOING;
        int currentPlayer = 1;

        while (gameState == GameState::ONGOING) {
            std::cout << "Player " << currentPlayer << "'s turn." << std::endl;
            Color newColor = game.getColorFromInput();
            game.play(currentPlayer, newColor);
            game.printBoard();
            gameState = game.gameStatus();

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

        if (gameState == GameState::PLAYER_1_WINS) {
            std::cout << "Player 1 wins!" << std::endl;
        } else if (gameState == GameState::PLAYER_2_WINS) {
            std::cout << "Player 2 wins!" << std::endl;
        } else {
            std::cout << "Draw!" << std::endl;
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
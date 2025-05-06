#include "game.h"
#include <SDL2/SDL.h>
#undef main
#include <iostream>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Connect Four",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        700, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Game game;
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                if (event.key.keysym.sym == SDLK_r)
                    game = Game(); // Reset game
            }

            else if (event.type == SDL_MOUSEBUTTONDOWN && game.status() == Game::Status::ONGOING) {
                int x = event.button.x;
                int col = x / 100;
                game.play(col);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Clear white
        SDL_RenderClear(renderer);

        game.draw(renderer);

        // Display result if game ended
        Game::Status s = game.status();
        if (s != Game::Status::ONGOING) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect banner = { 0, 0, 700, 50 };
            SDL_RenderFillRect(renderer, &banner);
            // For full text rendering, SDL_ttf is recommended (optional)
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

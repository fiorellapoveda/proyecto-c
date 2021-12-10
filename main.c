/* Proyecto de C: Tic Tac Toe - Código principal.
The code for this game its divided in multiple file to make the comprehension
of it easier and avoid having just one archive with a relly long extension.

The list of files are:
- game_logic.c: Contains all the funtions related to the playability of the game.
- game_logic.h: Header file derivated from the game_logic.c
- game_const.h: Header file thats contains all the constants defined and needed for the game.
- rendering.c: Constains all the funtions related to the manage of elements in the gui of the game.
- rendering.h: Header file derivated from the game_logi.c

In this file are all the funtions related to the creation of the main space for
tha game, the handle of events of the game and some error handling.

This code was made in a virtual machine with Ubuntu 20.04 made with Oracle.

Estudiantes:
- Fiorella Poveda Chaves (B86145).
- Luis Ricardo Carmona Mora (B91646).
- Julián Zamora Villalobos (B07025).
*/

#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "./game_const.h"
#include "./game_logic.h"
#include "./rendering.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char *argv[]) {

    // Error handling in case of an iniciatization fail
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      fprintf(stderr, "The sdl2 could not be initialized: %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

    // Creation of the game window
    SDL_Window *window = SDL_CreateWindow("Procedural", 100, 100,
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // Error handling in case of an error with the window's creation
    if (window == NULL) {
      fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

    // Rendering of the window
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Error handling in case of a rendering fail
    if (renderer == NULL) {
      SDL_DestroyWindow(window);
      fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

    // Creation of the initial state of the game
    game_t game = {
      // The initial board are nine empty cells
      .board = { EMPTY, EMPTY, EMPTY,
                 EMPTY, EMPTY, EMPTY,
                 EMPTY, EMPTY, EMPTY },
      // The first player will be X
      .player = PLAYER_X,
      .state = RUNNING_STATE
    };

    // To organize and handle the event loop
    SDL_Event e;
    while (game.state != QUIT_STATE) {
      while (SDL_PollEvent(&e)) {
        switch (e.type) {
          // To exit the game
          case SDL_QUIT:
            game.state = QUIT_STATE;
            break;
          // Now its necessary to handle the click of the mouse button
          case SDL_MOUSEBUTTONDOWN:
            /* To convert the mouse position into the cell coordinates, we divide
            each component of the mouse position by the size of the cell */
            click_on_cell(&game, e.button.y / CELL_HEIGHT, e.button.x / CELL_WIDTH);
            /* We call the function, provide the current state of the game,
            and the cell information */
            break;
          default: {}
        }
      }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // To render the game each frame
    render_game(renderer, &game);
    SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

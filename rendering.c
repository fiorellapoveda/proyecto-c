/* Proyecto de C: Tic Tac Toe - Rendering File.
In this file are all the functions related to the rendering and drawing of the
objects of the gui; the cells, the symbols, the colors, etc.

This code was made in a virtual machine with Ubuntu 20.04 made with Oracle.

Estudiantes:
- Fiorella Poveda Chaves (B86145).
- Luis Ricardo Carmona Mora (B91646).
- Julián Zamora Villalobos (B07025).
*/


#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
/* This last header is for an extension of SDL2 for drawing the player's symbol
with a thick line using a function called thicklineRGBA */

#include "./game_const.h"
#include "./rendering.h"

// Colors for game over states
const SDL_Color GRID_COLOR = { .r = 255, .g = 255, .b = 255 };
const SDL_Color PLAYER_X_COLOR = { .r = 255, .g = 50, .b = 50 };
const SDL_Color PLAYER_O_COLOR = { .r = 50, .g = 100, .b = 255 };
const SDL_Color TIE_COLOR = { .r = 100, .g = 100, .b = 100 };

/* Both functions for rendering will use the same building blocks;
they nedd to be able to render the grid and the board */
void render_grid(SDL_Renderer *renderer, const SDL_Color *color) {
  SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);
  // For drawing a line between cells
  for (int i = 1; i < N; ++i) {
    // Divides the colums
    SDL_RenderDrawLine(renderer, i * CELL_WIDTH, 0, i * CELL_WIDTH, SCREEN_HEIGHT);
    // Divides the rows
    SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, SCREEN_WIDTH, i * CELL_HEIGHT);
    }
}

/* For drawing the symbol of each player, a square its going to be drawn in each
cell; the measures of this square are going to be obteined from the original
cell's sizes (height and width). After dividing both measures, height and width,
by half, the minimum of this two will be divided by half again, and finally that
result its the one that is going to be used to define the corners of the
internal square */

/* Functions for drawing the player's symbols in the board; to both functions,
the coordenates of cell where the symbol has to be drawn, will be passed as parameters */

// Function for rendering the X symbol
void render_x(SDL_Renderer *renderer, int row, int column, const SDL_Color *color) {
  // Calculation for the internal square of each cell to draw the X symbol
  const float half_box_side = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
  // Calculation of the center of the internal square of each cell
  const float center_x = CELL_WIDTH * 0.5 + column * CELL_WIDTH;
  const float center_y = CELL_HEIGHT * 0.5 + row * CELL_HEIGHT;

  // Functions for each line of the X
  /* The third and fourth parameter are for the beginnng od the line and the
  fifth and sixth the end; then the thickness and the color */
  thickLineRGBA(renderer, center_x - half_box_side, center_y - half_box_side,
                center_x + half_box_side, center_y + half_box_side,
                10, color->r, color->g, color->b, 255);
  thickLineRGBA(renderer, center_x + half_box_side, center_y - half_box_side,
                center_x - half_box_side, center_y + half_box_side,
                10, color->r, color->g, color->b, 255);
}

// Function for rendering the O symbol
void render_o(SDL_Renderer *renderer, int row, int column, const SDL_Color *color) {
  // Calculation for the internal square of each cell to draw the X symbol
  const float half_box_side = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
  // Calculation of the center of the internal square
  const float center_x = CELL_WIDTH * 0.5 + column * CELL_WIDTH;
  const float center_y = CELL_HEIGHT * 0.5 + row * CELL_HEIGHT;

  /* SDL does not have a function to draw an empty circle; for this reason,
  two circles will be drawn. The smallest will be of the same color as the
  grid, to have the ilussion that the circle its empty */

  //Biggest circle
  filledCircleRGBA(renderer, center_x, center_y, half_box_side + 5,
                   color->r, color->g, color->b, 255);
  // Smallest circle
  filledCircleRGBA(renderer, center_x, center_y, half_box_side - 5,
                   0, 0, 0, 255);
}

/* Function to render the render the board and the cells; it does it by
iterating each cell */
void render_board(SDL_Renderer *renderer, const int *board,
  const SDL_Color *player_x_color, const SDL_Color *player_o_color) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            switch (board[i * N + j]) {
              case PLAYER_X:
                render_x(renderer, i, j, player_x_color);
                break;
              case PLAYER_O:
                render_o(renderer, i, j, player_o_color);
                break;
              default: {}
            }
        }
    }
}

// Function for running state
void render_running_state(SDL_Renderer *renderer, const game_t *game)
{
    render_grid(renderer, &GRID_COLOR);
    render_board(renderer, game->board, &PLAYER_X_COLOR, &PLAYER_O_COLOR);
}

// Function for game over states
void render_game_over_state(SDL_Renderer *renderer,
                            const game_t *game,
                            const SDL_Color *color) {
    render_grid(renderer, color);
    render_board(renderer, game->board, color, color);
}

// Renders the game but not its state
void render_game(SDL_Renderer *renderer, const game_t *game) {
  // The rendering of the game will depend of its state
  switch (game->state) {
    case RUNNING_STATE:
      render_running_state(renderer, game);
      break;
    /* When the game reaches one of the three states of game over, the idea is
    to render as the running state but colour it with an apecific colour */
    case PLAYER_X_WON_STATE:
      render_game_over_state(renderer, game, &PLAYER_X_COLOR);
      break;
    case PLAYER_O_WON_STATE:
      render_game_over_state(renderer, game, &PLAYER_O_COLOR);
      break;
    case TIE_STATE:
      render_game_over_state(renderer, game, &TIE_COLOR);
      break;
    default: {}
    }
}

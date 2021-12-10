/* Proyecto de C: Tic Tac Toe - Game Logic File
This file contains all the functions related with the manage of the game and
its logic, the states of the game, the turns of the players, etc.

This code was made in a virtual machine with Ubuntu 20.04 made with Oracle.

Estudiantes:
- Fiorella Poveda Chaves (B86145).
- Luis Ricardo Carmona Mora (B91646).
- Julián Zamora Villalobos (B07025).
*/

#include "./game_const.h"
#include "./game_logic.h"

// FUnction to switch between the players
void switch_player(game_t *game) {
  if (game->player == PLAYER_X) {
    game->player = PLAYER_O;
  } else if (game->player == PLAYER_O) {
    game->player = PLAYER_X;
  }
}

// Function that currently checks if some player has won
int check_player_won(game_t *game, int player) {
  int row_count = 0;
  int column_count = 0;
  int diag1_count = 0;
  int diag2_count = 0;

  // It would check if there's a full row or column of one of the symbols
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (game->board[i * N + j] == player) {
        row_count++;
      }
      if (game->board[j * N + i] == player) {
        column_count++;
      }
    }
    if (row_count >= N || column_count >= N) {
      return 1;
    }
    /* In case that there's isn't a full row or column, the counters
    will be restart*/
    row_count = 0;
    column_count = 0;

    // Now, to check the diagonals
    if (game->board[i * N + i] == player) {
      diag1_count++;
    }
    if (game->board[i * N + N - i - 1] == player) {
      diag2_count++;
    }
  }
  return diag1_count >= N || diag2_count >= N;
}

// Function that currently checks the tie state
int count_cells(const int *board, int cell) {
  int count = 0;
  for (int i = 0; i < N * N; ++i) {
    if (board[i] == cell) {
      count++;
    }
  }
  return count;
}

// Function to define the diferent game over conditions
void game_over_condition(game_t *game) {
  if (check_player_won(game, PLAYER_X)) {
    game->state = PLAYER_X_WON_STATE;
  } else if (check_player_won(game, PLAYER_O)) {
    game->state = PLAYER_O_WON_STATE;
  } else if (count_cells(game->board, EMPTY) == 0) {
    game->state = TIE_STATE;
  }
}

void player_turn(game_t *game, int row, int column) {
  // Checks ythat the cell that is clicked does not have something already
  if (game->board[row * N + column] == EMPTY) {
    game->board[row * N + column] = game->player;
    switch_player(game);
    game_over_condition(game);
  }
}

/* All the cells are returned to the initial state; once the game is in a game
state, if the window is clicked everywhere, the grid will be white again and
the cells will be empty */
void reset_game(game_t *game) {
  game->player = PLAYER_X;
  game->state = RUNNING_STATE;
  for (int i = 0; i < N * N; ++i) {
    game->board[i] = EMPTY;
  }
}

// Handles single turn of the game; it modifies the state of the game
void click_on_cell(game_t *game, int row, int column) {
  /* While the state of the game is running, it has to be the turn of one of
  the players */
  if (game->state == RUNNING_STATE) {
    player_turn(game, row, column);
  } else {
    reset_game(game);
  }
}

/* Proyecto de Python: Tic Tac Toe - Game Constants File.
This header file contains all the defined ans needed constants for the development of
the game.

This code was made in a virtual machine with Ubuntu 20.04 made with Oracle.

Estudiantes:
- Fiorella Poveda Chaves (B86145).
- Luis Ricardo Carmona Mora (B91646).
- Julián Zamora Villalobos (B07025).
*/

#ifndef GAME_CONST_H_
#define GAME_CONST_H_

#define N 3
// Size of the game's window
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Cells size
#define CELL_WIDTH (SCREEN_WIDTH / N)
#define CELL_HEIGHT (SCREEN_HEIGHT / N)

// Possible values to player
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

// All the possible values to the state of the game
#define RUNNING_STATE 0
// The game over state has the substates
#define PLAYER_X_WON_STATE 1
#define PLAYER_O_WON_STATE 2
#define TIE_STATE 3
// State of quit
#define QUIT_STATE 4

// Estructura del juego
typedef struct {
    int board[N * N];
    int player;
    int state;
} game_t;

#endif  // GAME_CONST_H_

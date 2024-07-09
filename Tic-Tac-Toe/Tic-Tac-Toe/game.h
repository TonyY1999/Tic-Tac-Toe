#pragma once

#define ROW 3
#define COL 3
#define WIN_LEN 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the board
void init_board(char board[ROW][COL], int row, int col);

// Print the board
void print_board(char board[ROW][COL], int row, int col);

// Player move
void player_move(char board[ROW][COL], int row, int col);

// Computer move
void computer_move(char board[ROW][COL], int row, int col);

// Check winning status
// Player win --- *
// Computer win --- #
// No wins --- q
// No wins and continue --- c
char is_win(char board[ROW][COL], int row, int col);

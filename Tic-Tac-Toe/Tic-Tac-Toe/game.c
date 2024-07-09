#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// Initialize the board
void init_board(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

// Print the board
void print_board(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

// Player move
void player_move(char board[ROW][COL], int row, int col) {
	printf("Player move, please enter the location u want to go: ");

	while (1)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("Invalid location, please enter again: ");
		}
	}
}

// Computer move
void computer_move(char board[ROW][COL], int row, int col) {
	printf("Computer move: \n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// Check if the board if full
int is_full(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}

// Check winning status
// Player win --- *
// Computer win --- #
// Tie --- q
// Nobody wins and continue --- c
char is_win(char board[ROW][COL], int row, int col) {
	int i, j, k;

	// Check rows
	for (i = 0; i < row; i++)
	{
		// Iterate every possible start column
		for (j = 0; j <= col - WIN_LEN; j++)
		{
			char first_point = board[i][j];

			if (first_point != ' ')
			{
				for (k = 0; k < WIN_LEN; k++)
				{
					if (board[i][j + k] != first_point)
					{
						break;
					}
				}

				if (k == WIN_LEN)
				{
					return first_point;
				}
			}
		}
	}

	// Check columns
	for (j = 0; j < col; j++)
	{	
		// Iterate every possible start row
		for (i = 0; i <= row - WIN_LEN; i++)
		{
			char first_point = board[i][j];

			if (first_point != ' ')
			{
				for (k = 0; k < WIN_LEN; k++)
				{
					if (board[i + k][j] != first_point)
					{
						break;
					}
				}

				if (k == WIN_LEN)
				{
					return first_point;
				}
			}
		}
	}

	// Check diagonals (left up to right down)
	// Iterate every possible start row
	for (i = 0; i <= row - WIN_LEN; i++)
	{
		for (j = 0; j <= col - WIN_LEN; j++)
		{
			char first_point = board[i][j];

			if (first_point != ' ')
			{
				for (k = 0; k < WIN_LEN; k++)
				{
					if (board[i + k][j + k] != first_point)
					{
						break;
					}
				}

				if (k == WIN_LEN)
				{
					return first_point;
				}
			}
		}
	}

	// Check diagonals (right up to left down)
	// Iterate every possible start row
	for (i = 0; i <= row - WIN_LEN; i++)
	{
		for (j = col - 1; j >= WIN_LEN - 1; j--)
		{
			char first_point = board[i][j];

			if (first_point != ' ')
			{
				for (k = 0; k < WIN_LEN; k++)
				{
					if (board[i + k][j - k] != first_point)
					{
						break;
					}
				}

				if (k == WIN_LEN)
				{
					return first_point;
				}
			}
		}
	}

	// Check for Draw
	if (is_full(board, row, col) == 1)
	{
		return 'q';
	}

	// Continue
	return 'c';
}
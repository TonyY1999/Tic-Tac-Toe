#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// Print the game menu
void menu() {
	printf("***************************\n");
	printf("***** 1.Play the game *****\n");
	printf("***** 0.Exit the game *****\n");
	printf("***************************\n");
}

// Start of the game
void game() {
	// Create a board to store moves
	char board[ROW][COL];

	// Game result
	char res = 0;

	// Initialize board and print it
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	printf("\n");
	
	// Game start
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		printf("\n");
		res = is_win(board, ROW, COL);
		// If res is not 'c', game over
		if (res != 'c')
		{
			break;
		}

		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		printf("\n");
		res = is_win(board, ROW, COL);
		// If res is not 'c', game over
		if (res != 'c')
		{
			break;
		}
	}

	// Print winner
	if (res == '*')
	{
		printf("Winner is player!\n");
	}
	else if (res == '#')
	{
		printf("Winner is computer!\n");
	}
	else
	{
		printf("Draw!\n");
	}
}

// Control function for the game
void control() {
	srand((unsigned int)time(NULL));

	int input = 0;

	do
	{
		menu();
		printf("Please select: ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit game, thx for playing!");
			break;
		default:
			printf("Invalid input, please enter again.\n");
			//break;
		}

	} while (input);

	
}

// Main function
int main() {
	control();
	return 0;
}
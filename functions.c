#include "mastermind.h"
/**
 * masterMind - function to start the game
 * Return: void
 */
void masterMind(void)
{
	title();
	instructions();
}
/**
 * initializeBoard - function to initialize the board
 * Return: void
 */
void initializeBoard(void)
{
	int i, j;

	for (j = 0; j < 4; j++)
		hiden[j] = '?';
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			rows[i][j] = '_';
			tries[i][j] = '_';
		}
	}
}
/**
 * startGame - function with the main loop to game
 * Return: void
 */
void startGame(void)
{
	int chances = 7;

	generateSecretCode();
	initializeBoard();
	while (1 && chances >= 0)
	{
		system("clear");
		title();
		printBoard();
		motor(chances);
		chances--;
	}
	lose();
}
/**
 * congratulations - function to congrats the player when guess the secret code
 * Return: void
 */
void congratulations(void)
{
	char *cgrts1 = ANSI_COLOR_RED "\t  ______   ______   .__   __.   _______ .______           ___      .___________. __    __   __           ___      .___________. __    ______   .__   __.      _______.\n" ANSI_COLOR_RESET;
	char *cgrts2 = ANSI_COLOR_RED "\t /      | /  __  \\  |  \\ |  |  /  _____||   _  \\         /   \\     |           ||  |  |  | |  |         /   \\     |           ||  |  /  __  \\  |  \\ |  |     /       |\n" ANSI_COLOR_RESET;
	char *cgrts3 = ANSI_COLOR_RED "\t|  ,----'|  |  |  | |   \\|  | |  |  __  |  |_)  |       /  ^  \\    `---|  |----`|  |  |  | |  |        /  ^  \\    `---|  |----`|  | |  |  |  | |   \\|  |    |   (----`\n" ANSI_COLOR_RESET;
	char *cgrts4 = ANSI_COLOR_RED "\t|  |     |  |  |  | |  . `  | |  | |_ | |      /       /  /_\\  \\       |  |     |  |  |  | |  |       /  /_\\  \\       |  |     |  | |  |  |  | |  . `  |     \\   \\    \n" ANSI_COLOR_RESET;
	char *cgrts5 = ANSI_COLOR_RED "\t|  `----.|  `--'  | |  |\\   | |  |__| | |  |\\  \\----. /  _____  \\      |  |     |  `--'  | |  `----. /  _____  \\      |  |     |  | |  `--'  | |  |\\   | .----)   |   \n" ANSI_COLOR_RESET;
	char *cgrts6 = ANSI_COLOR_RED "\t \\______| \\______/  |__| \\__|  \\______| | _| `._____|/__/     \\__\\     |__|      \\______/  |_______|/__/     \\__\\     |__|     |__|  \\______/  |__| \\__| |_______/    \n" ANSI_COLOR_RESET;

	system("clear");
	printf("%s%s%s%s%s%s", cgrts1, cgrts2, cgrts3, cgrts4, cgrts5, cgrts6);
	exit(EXIT_SUCCESS);
}
/**
 * check_input - function to avoid no numeric characters as input
 * @number: the number from the input of the player
 * Return: 0 if all the characters are numbers, otherwise -1
 */
int check_input(char *number)
{
	int i;

	for (i = 0; i < 4; i++)
		if (!isdigit(number[i]))
			return (0);
	return (1);
}

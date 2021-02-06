#include "mastermind.h"
/**
 * generateSecretCode - function to generate the secret code
 * Return: void
 */
void generateSecretCode(void)
{
	int i, n;

	srand(time(0));
	for (i = 0; i < 4; i++)
	{
		n = (rand() % 6) + 49;
		if (secretCode[0] == n || secretCode[1] == n
		|| secretCode[2] == n || secretCode[3] == n)
			i--;
		else
			secretCode[i] = n;
	}
}
/**
 * motor - function to get the input from the user
 * @chances: counter for the amount of chances that the player has
 * Return: void
 */
void motor(int chances)
{
	char *number = NULL;
	size_t size = 0;
	int c, length;

	if (number)
		free(number);
	c = getline(&number, &size, stdin);
	if (c == EOF)
	{
		free(number);
		good_bye();
	}
	length = strlen(number);
	if (length > 5)
	{
		combo();
		printf("\t\t\t\t\t\t\t\tNo more than four digits\n");
		motor(chances);
	}
	else if (length < 5)
	{
		combo();
		printf("\t\t\t\t\t\t\t\tNo less than four digits\n");
		motor(chances);
	}
	else
		if (check_input(number))
			compare(chances, number);
		else
		{
			combo();
			printf("\t\t\t\t\t\t\t     Please type only numeric digits\n");
			motor(chances);
		}
	free(number);
}
/**
 * combo - function to clear screen, print the title and the board
 * Return: void
 */
void combo(void)
{
	system("clear");
	title();
	printBoard();
}
/**
 * compare - function to compare the input of the player and the secret Code
 * @chances: counter for the amount of chances that the player has
 * @number: the number from the input of the player
 * Return: void
 */
void compare(int chances, char *number)
{
	int i, j, k, black_asserts = 0, white_asserts = 0;
	char *copy = NULL;

	copy = strdup(secretCode);
	/* compare black key pegs */
	for (i = 0; i < 4; i++)
		if (number[i] == copy[i])
		{
			black_asserts++;
			copy[i] = '0';
		}
	if (black_asserts == 4)
		congratulations();
	/* compare white key pegs */
	for (j = 0; j < 4; j++)
	{
		for (k = 0; k < 4; k++)
		{
			if (copy[j] == number[k] && copy[j] != '0')
			{
				white_asserts++;
				copy[j] = '0';
				break;
			}
		}
	}
	for (i = 0; i < 4; i++)
		tries[chances][i] = number[i];
	free(copy);
	fill_rows(chances, black_asserts, white_asserts);
}
/**
 * fill_rows - function to fill the slot of the game
 * @chances: counter for the amount of chances that the player has
 * @black: the amount of correct matches that the player made
 * @white: the amount of numbers in the secret code but does not matche
 * Return: void
 */
void fill_rows(int chances, int black, int white)
{
	int i, j;

	for (i = 0; i < black; i++)
		rows[chances][i] = 'X';
	for (j = 0; j < white; i++, j++)
		rows[chances][i] = 'O';
}

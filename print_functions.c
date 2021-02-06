#include "mastermind.h"
/**
 * title - function to print the main title of the game
 * Return: void
 */
void title(void)
{
	char *title1 = ANSI_COLOR_GREEN ".___  ___.      ___           _______.___________. _______ .______      .___  ___.  __  .__   __.  _______       _______      ___      .___  ___.  _______ \n" ANSI_COLOR_RESET;
	char *title2 = ANSI_COLOR_GREEN "|   \\/   |     /   \\         /       |           ||   ____||   _  \\     |   \\/   | |  | |  \\ |  | |       \\     /  _____|    /   \\     |   \\/   | |   ____|\n" ANSI_COLOR_RESET;
	char *title3 = ANSI_COLOR_GREEN "|  \\  /  |    /  ^  \\       |   (----`---|  |----`|  |__   |  |_)  |    |  \\  /  | |  | |   \\|  | |  .--.  |   |  |  __     /  ^  \\    |  \\  /  | |  |__   \n" ANSI_COLOR_RESET;
	char *title4 = ANSI_COLOR_GREEN "|  |\\/|  |   /  /_\\  \\       \\   \\       |  |     |   __|  |      /     |  |\\/|  | |  | |  . `  | |  |  |  |   |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n" ANSI_COLOR_RESET;
	char *title5 = ANSI_COLOR_GREEN "|  |  |  |  /  _____  \\  .----)   |      |  |     |  |____ |  |\\  \\----.|  |  |  | |  | |  |\\   | |  '--'  |   |  |__| |  /  _____  \\  |  |  |  | |  |____ \n" ANSI_COLOR_RESET;
	char *title6 = ANSI_COLOR_GREEN "|__|  |__| /__/     \\__\\ |_______/       |__|     |_______|| _| `._____||__|  |__| |__| |__| \\__| |_______/     \\______| /__/     \\__\\ |__|  |__| |_______|\n" ANSI_COLOR_RESET;
	char *title7 = ANSI_COLOR_GREEN "\t\t\t\t\t             _   _     _                                     _                         \n" ANSI_COLOR_RESET;
	char *title8 = ANSI_COLOR_GREEN "\t\t\t\t\t __      __ (_) | |_  | |__      _ __    _   _   _ __ ___   | |__     ___   _ __   ___ \n" ANSI_COLOR_RESET;
	char *title9 = ANSI_COLOR_GREEN "\t\t\t\t\t \\ \\ /\\ / / | | | __| | '_ \\    | '_ \\  | | | | | '_ ` _ \\  | '_ \\   / _ \\ | '__| / __|\n" ANSI_COLOR_RESET;
	char *title10 = ANSI_COLOR_GREEN "\t\t\t\t\t  \\ V  V /  | | | |_  | | | |   | | | | | |_| | | | | | | | | |_) | |  __/ | |    \\__ \\\n" ANSI_COLOR_RESET;
	char *title11 = ANSI_COLOR_GREEN "\t\t\t\t\t   \\_/\\_/   |_|  \\__| |_| |_|   |_| |_|  \\__,_| |_| |_| |_| |_.__/   \\___| |_|    |___/" ANSI_COLOR_RESET;

	system("clear");
	printf("%s%s%s%s%s%s%s%s%s%s%s\n\n\n", title1, title2, title3, title4, title5, title6, title7, title8, title9, title10, title11);
}
/**
 * printBoard - function to print the board
 * Return: void
 */
void printBoard(void)
{
	int i, j;

	printf("\t\t\t\t\t\t\t\t");
	for (j = 0; j < 4; j++)
		printf("%c	 ", hiden[j]);
	putchar(10);
	for (i = 0; i < 8; i++)
	{
		printf("\t\t\t\t\t\t\t\t");
		for (j = 0; j < 4; j++)
			printf("%c	 ", rows[i][j]);
		putchar(10);
		printf("\t\t\t\t\t\t\t\t");
		for (j = 0; j < 4; j++)
			printf(ANSI_COLOR_CYAN "%c	 " ANSI_COLOR_RESET, tries[i][j]);
		putchar(10);
	}
	printf("\n\t\t\t\t\t\tEvery X means that one of your numbers is in the right place,\n");
	printf("\t\t\t\tand every O means that one of your numbers is in the secret Code but in the wrong place\n");
	printf("\n\t\t\t\t\t\t    X --> CORRECT POSITION      O --> WRONG POSITION");
	printf("\n\n\t\t\t\t\t\t\t      Write a number of four digits\n");
}
/**
 * instructions - function to explain the game at the beginning
 * Return: void
 */
void instructions(void)
{
	char next;

	printf("\n\n\t\t\t\tHow to play: The computer will select a secret number with four different (unique) digits.\n");
	puts("\t\t\t\tThe object of the game is to guess that secret number, it will be composed from 1 to 6\n");
	puts("\t\t\t\t\t     Each guess is answered by the number of digits in the guess");
	puts("\t\t\t\tnumber that match or occur in the secret number. You will also be told how many of the digits");
	puts("\t\t\t\t\t\t    are in the correct position in the secret number.");
	puts("\t\t\t\tThrough a process of elimination, you should be able to deduce the correct digits using logic.");
	printf("\n\t\t\t\t\t\t    X --> CORRECT POSITION      O --> WRONG POSITION");
	printf("\n\t\t\t\t\t    You will have only eight chances. Press Enter to start the game!");
	printf("\n\n\t\t\t\t\t\t\t\tPress Ctrl + D to exit any moment\n");
	next = getchar();
	if (next == EOF)
	{
		system("clear");
		good_bye();
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else if (next == 10)
		startGame();
}
/**
 * good_bye - function to say good bye to the player
 * Return: void
 */
void good_bye(void)
{
	char *bye1 = ANSI_COLOR_BLUE "\t\t                              _     _                      _ \n" ANSI_COLOR_RESET;
	char *bye2 = ANSI_COLOR_BLUE "\t\t   __ _    ___     ___     __| |   | |__    _   _    ___  | |\n" ANSI_COLOR_RESET;
	char *bye3 = ANSI_COLOR_BLUE "\t\t  / _` |  / _ \\   / _ \\   / _` |   | '_ \\  | | | |  / _ \\ | |\n" ANSI_COLOR_RESET;
	char *bye4 = ANSI_COLOR_BLUE "\t\t | (_| | | (_) | | (_) | | (_| |   | |_) | | |_| | |  __/ |_|\n" ANSI_COLOR_RESET;
	char *bye5 = ANSI_COLOR_BLUE "\t\t  \\__, |  \\___/   \\___/   \\__,_|   |_.__/   \\__, |  \\___| (_)\n" ANSI_COLOR_RESET;
	char *bye6 = ANSI_COLOR_BLUE "\t\t  |___/                                     |___/            " ANSI_COLOR_RESET;

	system("clear");
	printf("%s%s%s%s%s%s\n\n\n\n\n", bye1, bye2, bye3, bye4, bye5, bye6);
	exit(EXIT_SUCCESS);
}
/**
 * lose - function to show when the player lose a game
 * Return: void
 */
void lose(void)
{
	char *try1 = ANSI_COLOR_RED "\t\t\t\t     _____                                            _           _ \n" ANSI_COLOR_RESET;
	char *try2 = ANSI_COLOR_RED "\t\t\t\t    |_   _|  _ __   _   _      __ _    __ _    __ _  (_)  _ __   | |\n" ANSI_COLOR_RESET;
	char *try3 = ANSI_COLOR_RED "\t\t\t\t      | |   | '__| | | | |    / _` |  / _` |  / _` | | | | '_ \\  | |\n" ANSI_COLOR_RESET;
	char *try4 = ANSI_COLOR_RED "\t\t\t\t      | |   | |    | |_| |   | (_| | | (_| | | (_| | | | | | | | |_|\n" ANSI_COLOR_RESET;
	char *try5 = ANSI_COLOR_RED "\t\t\t\t      |_|   |_|     \\__, |    \\__,_| \\__,  |  \\__,_| |_| |_| |_| (_)\n" ANSI_COLOR_RESET;
	char *try6 = ANSI_COLOR_RED "\t\t\t\t                    |___/             |___/                         " ANSI_COLOR_RESET;
	char next;
	int i;

	system("clear");
	printf("%s%s%s%s%s%s\n", try1, try2, try3, try4, try5, try6);
	printf("\n\t\t\t\t\t\t\tThe Secret Code was ");
	for (i = 0; i < 4; i++)
		printf("%c", secretCode[i]);
	printf("\n\t\t\t\t\t    Press Ctrl + D to exit or Enter to start a new game!\n");
	next = getchar();
	if (next == EOF)
	{
		system("clear");
		good_bye();
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
		startGame();
}

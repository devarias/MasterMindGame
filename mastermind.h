#ifndef MASTERMIND_H
#define MASTERMIND_H

/*		Libraries		*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include <string.h>
#include <ctype.h>

/*		MACROS		*/
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*		Global Variables		*/
char secretCode[4];
char rows[8][4];
char tries[8][4];
char hiden[4];

/*		Function Prototypes		*/
void masterMind(void);
void title(void);
void generateSecretCode(void);
void printBoard(void);
void instructions(void);
void good_bye(void);
void initializeBoard(void);
void startGame(void);
void motor(int chances);
int check_input(char *number);
void combo(void);
void lose(void);
void compare(int chances, char *number);
void congratulations(void);
void fill_rows(int chances, int black, int white);

#endif

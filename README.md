# MasterMindGame
Develop a Mastermind game version in C language. The mastermind game consists in that the codemaker secretly creates a code consisting of four colors or numbers from a specific set, such as red, yellow, green, blue, purple, and orange for one or from 1 to 9 for the other. Then, the codebreaker tries to guess the exact position of the sequence in the secret code. For each guess that the codebreaker makes, the codemaker gives feedback with white and black pegs that will work as hints or clues for the codebreaker. For example, the number of black hits will indicate the number of colors or numbers that are right and are in the correct position, and the number of white clues will indicate the number of colors or numbers that are correct but are in the wrong place.

## Table of Content
* [Environment](#environment)
* [Installation](#installation)
* [File Descriptions](#file-descriptions)
* [FlowChart](#FlowChart)
* [Usage](#Usage)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Environment
This project is compiled on Ubuntu 14.04 LTS using C language `gcc compiler version 4.8.5`

## Installation
* Clone this repository: `git clone "https://github.com/devarias/MasterMindGame"`
* Access MasterMindGame directory: `cd MasterMindGame`
* Compile all the source files with the command: `gcc -Wall -Wextra -Werror -pedantic *.c -o MasterMind`
* Run the game: `./MasterMind`

## File Descriptions
[core.c](core.c) - The core file contains the functions to process the most important parts of the MasterMind Game.
* generateSecretCode - Function  that generates a random sequence of four unique numbers as the secret code. 
* motor - Function to get and validate the input data from the user.
* compare - Function that compares the input data from the usr with the secret code.
* fill_rows - Function to fill the board game rows with the amount of matches and almost matches found in the compare function.


[main.c](main.c) - The main function of the Mastermind game
* main - Initialize the Mastermind Game.


[functions.c](functions.c) -The functions file contains the side functions to processs the MasterMind Game.
* masterMind - Function to display titles and instructions at the start of the game.
* initializeBoard - Function to initialize the board game.
* startGame - Function to Start the game with the main loop.
* congratulations - Function to display a congratulations title when user input matches the secret code.


[print_functions.c](print_functions.c) - The print_functions file contains all the messages to display during the game.
* title - Function to display titles of the MasterGame.
* instructions - Function to the instructions of the game
* lose - Function to display the lose message when user loses.
* good_bye - Function to display a good bye message at the end of the game.
* printBoard - Function to display a the game board at the start.


[mastermind.h](mastermind.h) - Header of the mastermind game
* Libraries - Includes the libraries used.
* Macros - Define the colors used in the messages.
* Global Variables - Define the set of global variables used.
* Functions - Describe the functions prototypes of each function in the files.


## FlowChart
Flow of the Mastermind Game

![MasterMind FlowChart](https://i.imgur.com/SQym2Yy.png)


## Usage

Just after running the MasterMind program, the next message will appear. Read it carefully, before start to play.

![](https://miro.medium.com/max/700/1*jYideFoZXP2d_LKvI09Cvg.jpeg)

Now, to star playing the MasterMind Game you have to enter your first guess of sequence of four numbers from one to six, and hit the enter key.

```
1462
```
After that you will be able to see how was your guess. The X's stand for correct numbers in the right place, and the O's stand for the correct numbers, but in the wrong position.

![](https://miro.medium.com/max/700/1*XZfLYZC7FaemQyXaIjd0jQ.jpeg)

Keep guessing until you find the secret code, if you find it you will be congratulated! And the game will be over.

![](https://miro.medium.com/max/700/1*x-J8aYoJCQI1BSkDxSi_rg.jpeg)

However, rememeber you only have eight chances to find out the secre code, so if you couldn't guessed it the next message will be shown.

![](https://miro.medium.com/max/700/1*gHhA8B9a6bJGd6_u-KPNzg.jpeg)

Here you can choose to keep playing or exit the game with `CTRL + D`

![](https://miro.medium.com/max/700/1*DNF9nIJis_BTJw12xpysxg.jpeg)

## Bugs
Don't enter characteres. Only numbers or you will lose a chance.

## Authors
Vaentina Jaramillo Ramirez - [Github](https://github.com/valen2510) / [Twitter](https://twitter.com/DaftVal)
David Arias Fuentes - [Github](https://github.com/devarias) / [Twitter](https://twitter.com/DavidDevArias)


## License
Public Domain. No copy rights protection.

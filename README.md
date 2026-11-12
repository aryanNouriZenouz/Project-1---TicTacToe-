# Project 1
# Tic-Tac-Toe vs. the Computer


# Description:
This project is a C program that lets a person play tic-tac-toe against the computer. The user plays as O and goes first. The computer plays as X and randomly selects an empty square.

The goal is to get three of the same symbols in a row, column, or diagonal. If all nine squares are filled without a winner, the game ends in a draw. After each game, the user can choose to play again or quit.

The program demonstrates basic concepts in C, including:
- Using a one-dimensional character array to represent the board
- Using functions to organize the program
- Using Boolean values and conditional statements
- Using for, while, and do...while loops
- Generating random moves with rand() and srand()
- Validating user input

  
# Code Overview
The project is structured around small functions:
- init_board – Sets all nine squares to empty.
- display_board – Prints the board, showing the number of each empty square.
- is_winner – Checks rows, columns, and diagonals for a win.
- other_player – Returns the other player's symbol.
- read_choice – Reads a single input choice and checks for extra characters.
- get_human_move – Asks the user for a valid, empty square.
- get_computer_move – Randomly chooses an empty square.
- take_turn – Places the current player's symbol on the board.
- play_game – Runs one complete game and reports the result.
- play_again – Asks whether to play another game.
The board is displayed after each move. Invalid input and occupied squares produce an error message so the user can try again.

# How to Run:
1. Download this repository.
2. Open TicTacToe.c in a C IDE, then build and run it. Alternatively, compile it with GCC:
3. Enter a number from 0-8, choose empty boxes if the selected box is not empty
4. After the game ends in a draw or someone wins, pick y/q, y to play again q to quit

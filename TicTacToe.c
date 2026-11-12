/*
Name: Aryan Nouri Zenouz
2026/10/20-11/11
Project: Tic-Tac-Toe
Course: COMP 120
Instructor: Alice, Wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPTY ' '
#define USER 'O'
#define COMPUTER 'X'

void init_board(char board[]); //9 empty squares
void display_board(char board[]); // prints board
bool is_winner(char board[], char player); // returns true if 3 in any row 
char other_player(char player); 
int read_choice(void);
int get_human_move(char board[]); // asks human for move
int get_computer_move(char board[]);  // computer picks a random square
bool take_turn(char board[], char player); //lets the player take their turn
void play_game(void); //starts game
bool play_again(void); //ask for true/false to play another game

int main(void)
{
    srand(time(NULL));


    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O, the computer is X. You are first\n");
    printf("Type the number of an empty box on your turn\n");

    do
    {
        play_game();
    } while (play_again());

    printf("Thanks for playing!\n");
    return 0;
}

void init_board(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = EMPTY;
    }
}



void display_board(char board[])
{
    char c[9];

    // shows each boxes number if it is empty
    for (int i = 0; i < 9; i++)
    {
        c[i] = board[i];
        if (c[i] == EMPTY)
        {
            c[i] = '0' + i;
        }
    }

    printf("\n %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", c[6], c[7], c[8]);
}

bool is_winner(char board[], char player)
{
    // checking 3 in one row
    for (int i = 0; i < 9; i = i + 3)
    {
        if (board[i] == player && board[i + 1] == player &&
            board[i + 2] == player)
        {
            return true;
        }
    }

    // checks for 3 in one column
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == player && board[i + 3] == player &&
            board[i + 6] == player)
        {
            return true;
        }
    }

    // check for 3 in diagonal, boxes 048 or 246
    if (board[0] == player && board[4] == player && board[8] == player)
    {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player)
    {
        return true;
    }

    return false;
}



char other_player(char player)
{
    if (player == USER)
    {
        return COMPUTER;
    }
    return USER;
}





int read_choice(void)
{
    int choice = getchar();
    int next;
    bool valid = true;

    if (choice == EOF || choice == '\n')
    {
        return choice;
    }

    next = getchar();
    while (next != '\n' && next != EOF)
    {
        if (next != ' ' && next != '\t' && next != '\r')
        {
            valid = false;
        }
        next = getchar();
    }

    if (!valid)
    {
        return '\n';
    }
    return choice;
}



//human move function, checks if the box is empty and if it isnt asks for another box
int get_human_move(char board[])
{
    int choice;
    int move = -1;
    bool valid = false;

    while (!valid)
    {
        printf("Your turn (O). Enter a square number (0-8): ");
        choice = read_choice();

        if (choice == EOF)
        {
            return -1;
        }
        if (choice < '0' || choice > '8')
        {
            printf("  Please enter one whole number from 0 to 8.\n");
        }
        else
        {
            move = choice - '0';
            if (board[move] != EMPTY)
            {
                printf("  That square is already taken. Choose an empty one.\n");
            }
            else
            {
                valid = true;
            }
        }
    }
    return move;
}


// computer's move function, checks if box is empty picks another if not
int get_computer_move(char board[])
{
    int move;

    do
    {
        move = rand() % 9;
    } while (board[move] != EMPTY);

    return move;
}



// turn function, lets the player take their turn
bool take_turn(char board[], char player)
{
    int move;

    if (player == USER)
    {
        move = get_human_move(board);
        if (move == -1)
        {
            return false;
        }
    }
    else
    {
        printf("Computer (X) is thinking...\n");
        move = get_computer_move(board);
        printf("Computer (X) chose square %d.\n", move);
    }

    board[move] = player;
    return true;
}



//play game function, starts the game and loops until winner or draw
void play_game(void)
{
    char board[9];
    char player = USER;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9; turn++)
    {
        if (!take_turn(board, player))
        {
            return;
        }
        display_board(board);

        if (is_winner(board, player))
        {
            if (player == USER)
            {
                printf("You (O) won!\n");
            }
            else
            {
                printf("Computer (X) won!\n");
            }
            return;
        }
        player = other_player(player);
    }

    printf("It's a draw!\n");
}



//play again function returns true if they want to play again, false if not
bool play_again(void)
{
    int choice;
    bool valid = false;

    while (!valid)
    {
        printf("Play again (y) or quit (q): ");
        choice = read_choice();

        if (choice == EOF)
        {
            return false;
        }
        valid = (choice == 'y' || choice == 'q');
        if (!valid)
        {
            printf("  Please enter y or q.\n");
        }
    }
    return choice == 'y';
}

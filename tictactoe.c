#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char SECOND = 'O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void secondMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';
    char play = ' ';

    printf("Made By Pranjal Rimal\n\n");

    // printf("Do you want to play against Computer or Human?\n");
    // printf("H = Human\tC = Computer ");
    // scanf(" %c", &play);
    // play = toupper(play);


    do
    {
        winner = ' ';
        response = ' ';

        printf("Do you want to play against Computer or Human?\n");
        printf("H = Human\tC = Computer ");
        scanf(" %c", &play);
        play = toupper(play);

        resetBoard();

        while (winner == ' ' && checkFreeSpace() != 0)
        {
            printBoard();

            playerMove();
            winner=checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
            {
                break;
            }

        if (play == 'C')
        {
            computerMove();
            winner=checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
            {
                break;
            }
        }
        else
        {
            printBoard();
            secondMove();
            winner=checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
            {
                break;
            }
        }

        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    
    } while (response == 'Y');

    printf("Thanks For Playing!");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpace()
{
    int freeSpace = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpace--;
            }
            
        }
        
    }
    
    return freeSpace;
}

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3) for 'X': ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3) for 'X': ");
        scanf("%d", &y);
        y--;

        if (board[x][y] !=' ')
        {
            printf("Invalid Move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    
    } while (board[x][y] != ' ');
}

void secondMove(){
    int x;
    int y;

    if (checkFreeSpace() > 0)
    {
        do
        {
            printf("Enter row #(1-3) for 'O': ");
            scanf("%d", &x);
            x--;
            printf("Enter column #(1-3) for 'O': ");
            scanf("%d", &y);
            y--;

            if (board[x][y] !=' ')
            {
                printf("Invalid Move!\n");
            }
            else
            {
                board[x][y] = SECOND;
                break;
            }
        } while (board[x][y] != ' ');
    }
}

void computerMove()
{
    //create a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpace() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }

    else
    {
        printWinner(' ');
    }
    
    
}

char checkWinner()
{
   //check rows
   for (int i = 0; i < 3; i++)
   {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
        return board[i][0];
    }
   }
   //check column
   for (int i = 0; i < 3; i++)
   {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
        return board[0][i];
    } 
   }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2    ] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You Win!");
    }
    else if (winner == COMPUTER)
    {
        printf("You Lose!");
    }
    else
    {
        printf("It's A Draw");
    }
    
}

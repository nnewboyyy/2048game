#include "ui.h"
#include <stdio.h> /* print_board 用 printf，需要它 */
// 打印棋盘
void print_board(int board[SIZE][SIZE])
{
    printf("move:w/a/s/d restar:r quit:q\n\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("+------+------+------+------+\n");
        printf("|");
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                printf("      |");
            }
            else
            {
                printf("%6d|", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("+------+------+------+------+\n");
}

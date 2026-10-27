#include "board.h"
// 棋盘所有格清零，重启游戏
void rester_board(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

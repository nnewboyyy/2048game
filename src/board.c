#include "board.h"
// rester_board的参数变成Board *b
// 循环条件SIZE变成b->size
// 数组访问从board[i][j]变成 b->cell[i][j]

// board_init负责记录尺寸，用rester_board清空棋盘
void board_init(Board *b, int size)
{
    b->size = size;
    rester_board(b);
}

// 棋盘所有格清零，重启游戏
void rester_board(Board *b)
{
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            b->cell[i][j] = 0;
        }
    }
}

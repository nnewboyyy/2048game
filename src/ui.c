#include "ui.h"
#include <stdio.h>

// 打印棋盘
void print_board(const Board *b)
{
    printf("move:w/a/s/d undo:u switch: t restar:r quit:q\n\n");

    for (int i = 0; i < b->size; i++)
    {
        // 动态打印上边框
        for (int j = 0; j < b->size; j++)
        {
            printf("+------");
        }
        printf("+\n");

        // 打印数据行
        printf("|");
        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] == 0)
            {
                printf("      |");
            }
            else
            {
                printf("%6d|", b->cell[i][j]);
            }
        }
        printf("\n");
    }

    // 打印底边框
    for (int j = 0; j < b->size; j++)
    {
        printf("+------");
    }
    printf("+\n");
}

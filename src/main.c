// 2048.2.0
// 打印棋盘、四个方向移动（遍历、合并、遍历）、随机数字、游戏结束

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#include "board.h"
#include "game.h"
#include "ui.h"

int main(void)
{
    Board board;
    board_init(&board, 4); // 默认初始化为 4x4 棋盘

    int gamevoer = 0;
    // 设置随机种子
    srand((unsigned int)time(NULL));

    addrand(&board);
    addrand(&board);
    print_board(&board);

    while (1)
    {
        char key = _getch();
        // 大小写切换
        if (key >= 'A' && key <= 'Z')
        {
            key = (char)(key - 'A' + 'a');
        }

        if (key == 'q')
        {
            break;
        }

        if (key == 'r')
        {
            board_init(&board, board.size); // 重置时保留当前尺寸
            addrand(&board);
            addrand(&board);
            gamevoer = 0;
            system("cls");
            print_board(&board);
            continue;
        }

        if (gamevoer == 1)
        {
            continue;
        }

        // 现在的 Board 结构体可以直接整体赋值拷贝，不需要再写两层 for 循环
        Board oldboard = board;

        if (key == 'a')
        {
            left_move(&board);
        }
        else if (key == 'd')
        {
            right_move(&board);
        }
        else if (key == 'w')
        {
            up_move(&board);
        }
        else if (key == 's')
        {
            down_move(&board);
        }
        else
        {
            continue;
        }

        int moved = board_changed(&board, &oldboard);
        if (moved == 1)
        {
            addrand(&board);
        }

        system("cls");
        print_board(&board);

        if (game_over(&board) == 1)
        {
            printf("\nGAME OVER!\nPress R to restart or Q to quit.\n");
            gamevoer = 1;
        }
    }

    printf("\nTHANKS FOR PLAYING~!\n");
    system("pause"); // 等待输入任意键以退出
    return 0;
}

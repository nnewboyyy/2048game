// 2048.2.0
// 打印棋盘、四个方向移动（遍历、合并、遍历）、随机数字、游戏结束

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 4

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

// 添加随机数2或4
int addrand(int board[SIZE][SIZE])
{
    int emptycount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                emptycount++;
            }
        }
    }

    if (emptycount == 0)
    {
        return 0;
    }
    // 随机选择一个空格
    int target = rand() % emptycount;
    // 保存行
    int row = 0;
    // 保存列
    int col = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                if (target == 0)
                {
                    row = i;
                    col = j;
                    i = SIZE;
                    break;
                }
                target--;
            }
        }
    }
    int number = (rand() % 2 == 0) ? 2 : 4;
    board[row][col] = number;

    return 1;
}

// 比较两个棋盘，不同返回1，相同返回0
int board_changed(int board[SIZE][SIZE], int oldboard[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != oldboard[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

// 左移动
void left_move(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        int temp[SIZE] = {0};
        int index = 0;

        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
        }

        for (int j = 0; j < SIZE - 1; j++)
        {
            if (temp[j] != 0 && temp[j] == temp[j + 1])
            {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++;
            }
        }
        index = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (temp[j] != 0)
            {
                temp[index] = temp[j];
                index++;
            }
        }
        while (index < SIZE)
        {
            temp[index] = 0;
            index++;
        }
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = temp[j];
        }
    }
}

// 右移动
void right_move(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        int temp[SIZE] = {0};
        int index = SIZE - 1;

        for (int j = SIZE - 1; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }

        for (int j = SIZE - 1; j >= 1; j--)
        {
            if (temp[j] != 0 && temp[j] == temp[j - 1])
            {
                temp[j] *= 2;
                temp[j - 1] = 0;
                j--;
            }
        }
        index = SIZE - 1;
        for (int j = SIZE - 1; j >= 0; j--)
        {
            if (temp[j] != 0)
            {
                temp[index] = temp[j];
                index--;
            }
        }
        while (index >= 0)
        {
            temp[index] = 0;
            index--;
        }
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = temp[j];
        }
    }
}

// 上移动
void up_move(int board[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        int temp[SIZE] = {0};
        int index = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }
        }
        index = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (temp[i] != 0)
            {
                temp[index] = temp[i];
                index++;
            }
        }

        while (index < SIZE)
        {
            temp[index] = 0;
            index++;
        }

        for (int i = 0; i < SIZE; i++)
        {
            board[i][j] = temp[i];
        }
    }
}

// 下移动
void down_move(int board[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        int temp[SIZE] = {0};
        int index = SIZE - 1;

        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }

        for (int i = SIZE; i >= 1; i--)
        {
            if (temp[i] != 0 && temp[i] == temp[i - 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i--;
            }
        }
        index = SIZE - 1;
        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (temp[i] != 0)
            {
                temp[index] = temp[i];
                index--;
            }
        }

        while (index >= 0)
        {
            temp[index] = 0;
            index--;
        }

        for (int i = 0; i < SIZE; i++)
        {
            board[i][j] = temp[i];
        }
    }
}

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

// 游戏结束
int game_over(int board[SIZE][SIZE])
{
    // 棋盘内存在空格，继续游戏
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    // 如果棋盘内行中，还有相同的项，游戏继续
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                return 0;
            }
        }
    }
    // 如果列内还有相同的项，游戏继续
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == board[i + 1][j])
            {
                return 0;
            }
        }
    }
    return 1; // 棋盘满了，游戏结束
}

int main()
{
    int board[SIZE][SIZE] = {0};
    int gamevoer = 0;
    // 设置随机种子
    srand((unsigned int)time(NULL));

    addrand(board);
    addrand(board);
    print_board(board);

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
            rester_board(board);
            addrand(board);
            addrand(board);
            gamevoer = 0;
            system("cls");
            print_board(board);
            continue;
        }

        if (gamevoer == 1)
        {
            continue;
        }

        int oldboard[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                oldboard[i][j] = board[i][j];
            }
        }

        if (key == 'a')
        {
            left_move(board);
        }
        else if (key == 'd')
        {
            right_move(board);
        }
        else if (key == 'w')
        {
            up_move(board);
        }
        else if (key == 's')
        {
            down_move(board);
        }
        else
        {
            continue;
        }

        int moved = board_changed(board, oldboard);
        if (moved == 1)
        {
            addrand(board);
        }

        system("cls");
        print_board(board);

        if (game_over(board) == 1)
        {
            printf("\nGAME OVER!\nPress R to restart or Q to quit.\n");
            gamevoer = 1;
        }
    }

    printf("\nTHANKS FOR PLAYING~!\n");
    system("pause"); // 等待输入任意键以退出
    return 0;
}

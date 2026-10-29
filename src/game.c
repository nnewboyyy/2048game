#include "game.h"
#include <stdlib.h> /* addrand 用 rand()，需要它 */

// 游戏结束
int game_over(const Board *b)
{
    // 棋盘内存在空格，继续游戏
    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] == 0)
            {
                return 0;
            }
        }
    }
    // 如果棋盘内行中，还有相同的项，游戏继续
    for (int i = 0; i < b->size; i++)
    {
        // 注意：这里 j < b->size - 1，防止 b->cell[i][j + 1] 越界
        for (int j = 0; j < b->size - 1; j++)
        {
            if (b->cell[i][j] == b->cell[i][j + 1])
            {
                return 0;
            }
        }
    }
    // 如果列内还有相同的项，游戏继续
    for (int i = 0; i < b->size - 1; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] == b->cell[i + 1][j])
            {
                return 0;
            }
        }
    }
    return 1; // 棋盘满了，游戏结束
}

// 添加随机数2或4
int addrand(Board *b)
{
    int emptycount = 0;

    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] == 0)
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
    int row = 0;
    int col = 0;

    for (int i = 0; i < b->size; i++)
    {
        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] == 0)
            {
                if (target == 0)
                {
                    row = i;
                    col = j;
                    i = b->size; // 跳出外层循环
                    break;
                }
                target--;
            }
        }
    }
    int number = (rand() % 2 == 0) ? 2 : 4;
    b->cell[row][col] = number;

    return 1;
}

// 比较两个棋盘，不同返回1，相同返回0
int board_changed(const Board *a, const Board *b)
{
    for (int i = 0; i < a->size; i++)
    {
        for (int j = 0; j < a->size; j++)
        {
            if (a->cell[i][j] != b->cell[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

// 左移动
void left_move(Board *b)
{
    for (int i = 0; i < b->size; i++)
    {
        int temp[MAX_SIZE] = {0}; // 必须用 MAX_SIZE 分配，不能写 b->size
        int index = 0;

        for (int j = 0; j < b->size; j++)
        {
            if (b->cell[i][j] != 0)
            {
                temp[index] = b->cell[i][j];
                index++;
            }
        }

        for (int j = 0; j < b->size - 1; j++)
        {
            if (temp[j] != 0 && temp[j] == temp[j + 1])
            {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++;
            }
        }
        index = 0;
        for (int j = 0; j < b->size; j++)
        {
            if (temp[j] != 0)
            {
                temp[index] = temp[j];
                index++;
            }
        }
        while (index < b->size)
        {
            temp[index] = 0;
            index++;
        }
        for (int j = 0; j < b->size; j++)
        {
            b->cell[i][j] = temp[j];
        }
    }
}

// 右移动
void right_move(Board *b)
{
    for (int i = 0; i < b->size; i++)
    {
        int temp[MAX_SIZE] = {0};
        int index = b->size - 1;

        for (int j = b->size - 1; j >= 0; j--)
        {
            if (b->cell[i][j] != 0)
            {
                temp[index] = b->cell[i][j];
                index--;
            }
        }

        for (int j = b->size - 1; j >= 1; j--)
        {
            if (temp[j] != 0 && temp[j] == temp[j - 1])
            {
                temp[j] *= 2;
                temp[j - 1] = 0;
                j--;
            }
        }
        index = b->size - 1;
        for (int j = b->size - 1; j >= 0; j--)
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
        for (int j = 0; j < b->size; j++)
        {
            b->cell[i][j] = temp[j];
        }
    }
}

// 上移动
void up_move(Board *b)
{
    for (int j = 0; j < b->size; j++)
    {
        int temp[MAX_SIZE] = {0};
        int index = 0;

        for (int i = 0; i < b->size; i++)
        {
            if (b->cell[i][j] != 0)
            {
                temp[index] = b->cell[i][j];
                index++;
            }
        }

        for (int i = 0; i < b->size - 1; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }
        }
        index = 0;
        for (int i = 0; i < b->size; i++)
        {
            if (temp[i] != 0)
            {
                temp[index] = temp[i];
                index++;
            }
        }

        while (index < b->size)
        {
            temp[index] = 0;
            index++;
        }

        for (int i = 0; i < b->size; i++)
        {
            b->cell[i][j] = temp[i];
        }
    }
}

// 下移动
void down_move(Board *b)
{
    for (int j = 0; j < b->size; j++)
    {
        int temp[MAX_SIZE] = {0};
        int index = b->size - 1;

        for (int i = b->size - 1; i >= 0; i--)
        {
            if (b->cell[i][j] != 0)
            {
                temp[index] = b->cell[i][j];
                index--;
            }
        }

        // 修正了原来的越界 bug 和合并逻辑
        for (int i = b->size - 1; i >= 1; i--)
        {
            if (temp[i] != 0 && temp[i] == temp[i - 1])
            {
                temp[i] *= 2;
                temp[i - 1] = 0;
                i--;
            }
        }

        index = b->size - 1;
        for (int i = b->size - 1; i >= 0; i--)
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

        for (int i = 0; i < b->size; i++)
        {
            b->cell[i][j] = temp[i];
        }
    }
}

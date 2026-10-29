#include <stdio.h>
#include <assert.h>
#include "board.h"
#include "game.h"

static void test_rester_board(void)
{
    Board b;
    // 先初始化为 4x4
    board_init(&b, 4);

    /* 先填一些非零值，确保重置真的清空 */
    for (int i = 0; i < b.size; i++)
        for (int j = 0; j < b.size; j++)
            b.cell[i][j] = 2;

    rester_board(&b);

    for (int i = 0; i < b.size; i++)
        for (int j = 0; j < b.size; j++)
            assert(b.cell[i][j] == 0);

    printf("test_rester_board: OK\n");
}

static void test_addrand(void)
{
    Board b;
    board_init(&b, 4);

    int non_zero_before = 0, non_zero_after = 0;
    for (int i = 0; i < b.size; i++)
        for (int j = 0; j < b.size; j++)
            if (b.cell[i][j] != 0)
                non_zero_before++;

    addrand(&b);

    for (int i = 0; i < b.size; i++)
        for (int j = 0; j < b.size; j++)
            if (b.cell[i][j] != 0)
                non_zero_after++;

    assert(non_zero_after == non_zero_before + 1);
    printf("test_addrand: OK\n");
}

static void test_variable_size(void)
{
    Board b;
    // 测试 5x5 尺寸
    board_init(&b, 5);

    assert(b.size == 5);
    for (int i = 0; i < b.size; i++)
        for (int j = 0; j < b.size; j++)
            assert(b.cell[i][j] == 0);

    printf("test_variable_size: OK\n");
}

int main(void)
{
    test_rester_board();
    test_addrand();
    test_variable_size();
    printf("All tests passed.\n");
    return 0;
}

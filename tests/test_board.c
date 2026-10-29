#include <stdio.h>
#include <assert.h>
#include "board.h"
#include "game.h"

static void test_rester_board(void)
{
    int b[SIZE][SIZE];
    /* 先填一些非零值，确保重置真的清空 */
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            b[i][j] = 2;

    rester_board(b);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            assert(b[i][j] == 0);

    printf("test_rester_board: OK\n");
}

static void test_addrand(void)
{
    int b[SIZE][SIZE];
    rester_board(b);

    int non_zero_before = 0, non_zero_after = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (b[i][j] != 0)
                non_zero_before++;

    addrand(b);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (b[i][j] != 0)
                non_zero_after++;

    assert(non_zero_after == non_zero_before + 1);
    printf("test_addrand: OK\n");
}

int main(void)
{
    test_rester_board();
    test_addrand();
    printf("All tests passed.\n");
    return 0;
}

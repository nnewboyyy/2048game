#ifndef BOARD_H /* 防止重复包含：如果没定义 BOARD_H 才继续 */
#define BOARD_H

#define MAX_SIZE 5 /* ← 改成你第1步看到的值 */

typedef struct
{
    int cell[MAX_SIZE][MAX_SIZE];
    int size;
} Board;

// 初始化size*size全0
void board_init(Board *b, int size);
void rester_board(Board *b);

#endif

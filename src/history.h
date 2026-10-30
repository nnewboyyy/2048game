#ifndef HISTORY_H
#define HISTORY_H

#include "board.h"

#define MAX_HISTORY 100 // 最多能撤销 100 步

typedef struct
{
    Board stack[MAX_HISTORY];
    int top; // 栈顶指针：0 表示没有历史
} History;

void history_init(History *h);
int history_push(History *h, const Board *b); // 成功返回 1，栈满返回 0
int history_pop(History *h, Board *b);        // 成功返回 1，栈空返回 0

#endif

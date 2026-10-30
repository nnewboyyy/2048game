#include "history.h"

// 初始化历史栈
void history_init(History *h)
{
    h->top = 0;
}

// 压栈：保存当前棋盘状态
int history_push(History *h, const Board *b)
{
    if (h->top >= MAX_HISTORY)
    {
        return 0; // 栈满，丢弃或拒绝
    }
    h->stack[h->top] = *b; // 整个结构体直接拷贝
    h->top++;
    return 1;
}

// 出栈：恢复上一个棋盘状态
int history_pop(History *h, Board *b)
{
    if (h->top <= 0)
    {
        return 0; // 栈空，没有可撤销的
    }
    h->top--;
    *b = h->stack[h->top]; // 把栈里的拷贝回棋盘
    return 1;
}

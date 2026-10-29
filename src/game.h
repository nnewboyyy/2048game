#ifndef GAME_H
#define GAME_H

#include "board.h" /* game 用到 SIZE，从 board.h 拿 */

int addrand(Board *b);
int board_changed(const Board *a, const Board *b);
void left_move(Board *b);
void right_move(Board *b);
void up_move(Board *b);
void down_move(Board *b);
int game_over(const Board *b);

#endif

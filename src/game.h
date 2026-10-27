#ifndef GAME_H
#define GAME_H

#include "board.h" /* game 用到 SIZE，从 board.h 拿 */

int addrand(int board[SIZE][SIZE]);
int board_changed(int board[SIZE][SIZE], int oldboard[SIZE][SIZE]);
void left_move(int board[SIZE][SIZE]);
void right_move(int board[SIZE][SIZE]);
void up_move(int board[SIZE][SIZE]);
void down_move(int board[SIZE][SIZE]);
int game_over(int board[SIZE][SIZE]);

#endif

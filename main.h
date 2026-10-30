#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

int check_game_over(int board[15][15], int step);  // 返回值: 0 未结束, 1 黑胜, 2 白胜, 3 和局

int evaluate(int board[15][15]);  // 评估函数: 正数黑棋优势, 负数白棋优势, 绝对值越大优势越大

int find_node(int board[15][15]);  // 节点生成函数, 寻找可以落子的位置

int * search(int board[15][15], int step);  // 搜索算法, 返回包含x, y坐标的数组

void print_board(int board[15][15]);  // 打印棋盘

#include "game_administrator.c"
#include "interface.c"
#include "machine/search.c"
#include "machine/evaluate.c"

#endif
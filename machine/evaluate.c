/*
 * 评估函数: 评估当前局面, 对黑棋有利的棋型为正, 对白棋有利的棋型为负
 * (以下为绝对值)
 * 连五: 10000
 * 活四: 1000
 * 活三/冲四: 100
 * 活二/冲三: 10
 * 活一/冲二: 1
 */
#include "../main.h"

int settle(int color, int length, int block) {
    // printf("(Debug)结算结果(color: %d, length: %d, block: %d).\n", color, length, block);

    if (length >= 5) {
        return color == 1 ? 10000 : -10000;
    }
    switch (block) {
        case 1:
            switch(length) {
                case 1:
                    return 0;
                    break;
                case 2:
                    return color == 1 ? 1 : -1;
                    break;
                case 3:
                    return color == 1 ? 10 : -10;
                    break;
                case 4:
                    return color == 1 ? 100 : -100;
                    break;
            }
            break;
        case 0:
            switch(length) {
                case 1:
                    return color == 1 ? 1 : -1;
                    break;
                case 2:
                    return color == 1 ? 10 : -10;
                    break;
                case 3:
                    return color == 1 ? 100 : -100;
                    break;
                case 4:
                    return color == 1 ? 1000 : -1000;
                    break;
            }
            break;
        case 2:
            return 0;
            break;
    }
}

void judge(_Bool is_edge,int new_color, int * color, int * length, int * block, int * score) {
    int debug;

    switch (*color) {
        case 0:
            switch (new_color) {
                case 0:
                    break;
                case 1:
                    *color = 1;
                    *length = 1;
                    *block = is_edge ? 1 : 0;
                    break;
                case 2:
                    *color = 2;
                    *length = 1;
                    *block = is_edge ? 1 : 0;
                    break;
            }
            break;
        case 1:
            switch (new_color) {
                case 0:
                    debug = settle(*color, *length, *block);
                    // printf("(Debug)得分为: %d.\n", debug);
                    *score += debug;
                    *color = 0;
                    *length = 0;
                    *block = 0;
                    break;
                case 1:
                    (*length)++;
                    break;
                case 2:
                    (*block)++;
                    debug = settle(*color, *length, *block);
                    // printf("(Debug)得分为: %d.\n", debug);
                    *score += debug;
                    *color = 2;
                    *length = 1;
                    *block = 1;
                    break;
            }
            break;
        case 2:
            switch (new_color) {
                case 0:
                    debug = settle(*color, *length, *block);
                    // printf("(Debug)得分为: %d.\n", debug);
                    *score += debug;
                    *color = 0;
                    *length = 0;
                    *block = 0;
                    break;
                case 1:
                    (*block)++;
                    debug = settle(*color, *length, *block);
                    // printf("(Debug)得分为: %d.\n", debug);
                    *score += debug;
                    *color = 1;
                    *length = 1;
                    *block = 1;
                    break;
                case 2:
                    (*length)++;
                    break;
            }
            break;
    }
}

int evaluate(int board[15][15]) {
    int i, j;
    int color = 0;
    int length = 0;
    int block = 0;
    int score = 0;
    int debug;

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            // printf("(Debug)[%d,%d]color:%d,new_color:%d,length:%d,block:%d,score:%d.\n", \
                i=1, j+1, color, board[i][j], length, block, score);
            judge(j == 0, board[i][j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            score += settle(color, length, block);
        }
        color = 0;
        length = 0;
        block = 0;
    }

    for (j = 0; j < 15; j++) {
        for (i = 0; i < 15; i++) {
            judge(i == 0, board[i][j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            score += settle(color, length, block);
        }
        color = 0;
        length = 0;
        block = 0;
    }

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 15-i; j++) {
            // printf("(Debug)[%d,%d]color:%d,new_color:%d,length:%d,block:%d,score:%d.\n", \
                i+j+1, j+1, color, board[i+j][j], length, block, score);
            judge(j == 0, board[i+j][j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            score += settle(color, length, block);
        }
        color = 0;
        length = 0;
        block = 0;
    }

    for (j = 1; j < 11; j++) {
        for (i = 0; i < 15-j; i++) {
            // printf("(Debug)[%d,%d]color:%d,new_color:%d,length:%d,block:%d,score:%d.\n", \
                i+1, i+j+1, color, board[i][i+j], length, block, score);
            judge(i == 0, board[i][i+j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            score += settle(color, length, block);
        }
        color = 0;
        length = 0;
        block = 0;
    }

    for (i = 4; i < 15; i++) {
        for (j = 0; j < i+1; j++) {
            // printf("(Debug)[%d,%d]color:%d,new_color:%d,length:%d,block:%d,score:%d.\n", \
                i-j+1, j+1, color, board[i-j][j], length, block, score);
            judge(j == 0, board[i-j][j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            debug = settle(color, length, block);
            // printf("(Debug)得分为: %d.\n", debug);
            score += debug;
        }
        color = 0;
        length = 0;
        block = 0;
    }

    for (j = 1; j < 11; j++) {
        for (i = 0; i < 15-j; i++) {
            // printf("(Debug)[%d,%d]color:%d,new_color:%d,length:%d,block:%d,score:%d.\n", \
                14-i+1, i+j+1, color, board[14-i][i+j], length, block, score);
            judge(i == 0, board[14-i][i+j], &color, &length, &block, &score);
        }
        if (color) {
            block++;
            debug = settle(color, length, block);
            // printf("(Debug)得分为: %d.\n", debug);
            score += debug;
        }
        color = 0;
        length = 0;
        block = 0;
    }

    return score;
}
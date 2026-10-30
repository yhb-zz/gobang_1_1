#include "main.h"
/*
 * 黑棋 ●
 * 白棋 ○
 * 空地 ·
 */
#include "main.h"

void print_board(int board[15][15]) {

    // 打印列数
    printf("   ");
    for (int i = 0; i < 15; i++) {
        printf(" %d ", (i+1) % 10);
    }
    printf("\n");

    for (int i = 0; i < 15; i++) {
        printf(" %d ", (i+1) % 10);
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == 0) {
                printf(" · ");
            } else if (board[i][j] == 1) {
                printf(" ● ");
            } else if (board[i][j] == 2) {
                printf(" ○ ");
            }
        }
        printf("\n");
    }
    printf("The score of current situation: %d.\n", evaluate(board));
}

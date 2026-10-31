#define DEPTH 4
#include "../main.h"

/*
int * machine(int board[15][15], int step) {
    ;
}


int search(int board[15][15], _Bool is_max_layer, ) {
    ;
}
*/

// 临时测试
int * machine(int board[15][15], int step) {
    int * result = malloc(sizeof(int) * 2);
    if (result == NULL) {
        perror("machine/search.c: malloc error");
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == 0) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
}
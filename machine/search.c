#define DEPTH 4
#include "../main.h"

/*
int * search(int board[15][15], int step) {
    ;
}
int node(int board[15][15], _Bool is_max_layer, ) {
    ;
}
*/

// 临时测试
int * search(int board[15][15], int step) {
    int * result = (int *)malloc(sizeof(int) * 2);
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
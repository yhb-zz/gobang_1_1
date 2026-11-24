#include <stdio.h>
#include "node_generation.h"
#include "linked_list.h"
#include "tools.h"

const int surround[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},\
{0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
const int extend[8][2] = {{2, 2}, {2, 0}, {2, -2}, {0, 2},\
                           {0, -2}, {-2, 2}, {-2, 0}, {-2, -2}};

int score(int board[15][15], int x, int y);

// 搜寻可供落子的位置
struct Node *node_generation(int board[15][15]) {
    struct Node *head = NULL;
    int x, y;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == 0) {
                for (int k = 0; k < 8; k++) {
                    x = i + surround[k][0];
                    y = j + surround[k][1];
                    if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && board[x][y]) {
                        head = sort_insert(head, i, j, score(board, i, j));
                        break;
                    }
                }
            }
        }
    }

    return head;
}

int convert(int seq[5], int length) {
    int encoding = 0;
    for (int i = 0; i < length; i++) {
        if (seq[i]) encoding += rec_pow(2, i);
    }
    return encoding;
}

int score(int board[15][15], int x, int y) {
    int result[16];  // 前 8 个为按照黑棋提取的数据, 后 8 个为白棋, 每组分别为 左 右 上 下 左上 右下 左下 右上
    int seq[5];
    int length = 0;

    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && board[x-i][y] != 2) {
            seq[length] = board[x-i][y];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[0] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && board[x+i][y] != 2) {
            seq[length] = board[x+i][y];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[1] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( y - i >= 0 && board[x][y-i] != 2) {
            seq[length] = board[x][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[2] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( y + i <= 14 && board[x][y+i] != 2) {
            seq[length] = board[x][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[3] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && y - i >= 0 && board[x-i][y-i] != 2) {
            seq[length] = board[x-i][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[4] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && y + i <= 14 && board[x+i][y+i] != 2) {
            seq[length] = board[x+i][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[5] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && y + i <= 14 && board[x-i][y+i] != 2) {
            seq[length] = board[x-i][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[6] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && y - i >= 0 && board[x+i][y-i] != 2) {
            seq[length] = board[x+i][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[7] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && board[x-i][y] != 1) {
            seq[length] = board[x-i][y];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[8] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && board[x+i][y] != 1) {
            seq[length] = board[x+i][y];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[9] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( y - i >= 0 && board[x][y-i] != 1) {
            seq[length] = board[x][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[10] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( y + i <= 14 && board[x][y+i] != 1) {
            seq[length] = board[x][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[11] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && y - i >= 0 && board[x-i][y-i] != 1) {
            seq[length] = board[x-i][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[12] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && y + i <= 14 && board[x+i][y+i] != 1) {
            seq[length] = board[x+i][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[13] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x - i >= 0 && y + i <= 14 && board[x-i][y+i] != 1) {
            seq[length] = board[x-i][y+i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[14] = convert(seq, length);

    length = 0;
    for (int i = 1; i <= 4; i++) {
        if ( x + i <= 14 && y - i >= 0 && board[x+i][y-i] != 1) {
            seq[length] = board[x+i][y-i];
            length++;
        } else {
            seq[length] = 1;
            length++;
            break;
        }
    }
    result[15] = convert(seq, length);

    int grade = 0;
    for (int i = 0; i < 8; i++) {
        grade += table[ result[2*i] ][ result[2*i+1] ];
    }
}

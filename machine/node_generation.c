#include "machine.h"

static const int surround[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},\
{0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
static const int extend[8][2] = {{2, 2}, {2, 0}, {2, -2}, {0, 2},\
                           {0, -2}, {-2, 2}, {-2, 0}, {-2, -2}};

// 搜寻可供落子的位置
struct Node *node_generation(int board[15][15]) {
    struct Node *head = NULL;
    struct Node *node_ptr = head;
    int x, y;

    // 防止重复, 这样会不会太消耗算力? 待优化
    int record_board[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            record_board[i][j] = 0;
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j]) {
                for (int k = 0; k < 8; k++) {
                    x = i + surround[k][0];
                    y = j + surround[k][1];
                    if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && board[x][y] == 0 && record_board[x][y] == 0) {
                        node_ptr = new_node(x, y, node_ptr);
                        record_board[x][y] = 1;
                        if (head == NULL) {
                            head = node_ptr;
                        }
                    }
                }
            }
        }
    }

    return head;
}

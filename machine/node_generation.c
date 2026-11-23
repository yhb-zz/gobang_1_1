#include <stdio.h>
#include "node_generation.h"
#include "linked_list.h"

const int surround[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},\
{0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
const int extend[8][2] = {{2, 2}, {2, 0}, {2, -2}, {0, 2},\
                           {0, -2}, {-2, 2}, {-2, 0}, {-2, -2}};

// 搜寻可供落子的位置
struct Node *node_generation(int board[15][15]) {
    struct Node *head = NULL;
    struct Node *node_ptr = head;
    int x, y;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == 0) {
                for (int k = 0; k < 8; k++) {
                    x = i + surround[k][0];
                    y = j + surround[k][1];
                    if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && board[x][y]) {
                        node_ptr = new_node(x, y, node_ptr);
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

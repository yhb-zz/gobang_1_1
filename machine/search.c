#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "node_generation.h"
#include "linked_list.h"
#include "evaluate.h"
#include "../game_administrator.h"

int search(int board[15][15], int depth, int color, int step);

int * machine(int board[15][15], int color, int step) {
    if (step == 0) {
        int * pos = malloc(sizeof(int) * 2);
        pos[0] = 7;
        pos[1] = 7;
        return pos;
    }

    struct Node * head = node_generation(board);
    struct Node * node_ptr = head;
    if (node_ptr == NULL) {
        perror("node_ptr == NULL");
    }

    while (node_ptr != NULL) {
        board[node_ptr->x][node_ptr->y] = color;
        node_ptr->score = search(board, 1, color == 1 ? 2 : 1, step + 1);
        board[node_ptr->x][node_ptr->y] = 0;
        node_ptr = node_ptr->next;
    }
    return pos_find(head, color == 1);
}

int search(int board[15][15], int depth, int color, int step) {
    int game_over = check_game_over(board, step);
    if (game_over) {
        return evaluate(board);
    }

    if (depth == DEPTH) {
        return evaluate(board);
    }
    struct Node * head = node_generation(board);
    struct Node * node_ptr = head;
    if (node_ptr == NULL) {
        perror("node_ptr == NULL");
    }

    while (node_ptr != NULL) {
        board[node_ptr->x][node_ptr->y] = color;
        node_ptr->score = search(board, depth + 1, color == 1 ? 2 : 1, step + 1);
        board[node_ptr->x][node_ptr->y] = 0;
        node_ptr = node_ptr->next;
    }
    int score = score_find(head, color == 1);
    free_linked_list(head);
    return score;
}


/*
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
*/
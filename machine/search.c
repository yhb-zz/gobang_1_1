#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "node_generation.h"
#include "linked_list.h"
#include "evaluate.h"
#include "../game_administrator.h"

int search(int board[15][15], int depth, int color, int step, int alpha_or_beta, _Bool is_first_node);

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

    int max = 0, min = 0;
    _Bool is_first_loop = 1;
    while (node_ptr != NULL) {
        board[node_ptr->x][node_ptr->y] = color;
        node_ptr->score = search(board, 1, color == 1 ? 2 : 1, step + 1,\
            color == 1 ? max : min, is_first_loop);
        board[node_ptr->x][node_ptr->y] = 0;

        if (is_first_loop) {
            max = node_ptr->score;
            min = node_ptr->score;
            is_first_loop = 0;
        } else {
            if (color == 1) {
                max = node_ptr->score > max ? node_ptr->score : max;
            } else {
                min = node_ptr->score < min ? node_ptr->score : min;
            }
        }
        node_ptr = node_ptr->next;
    }
    return pos_find(head, color == 1);
}

int search(int board[15][15], int depth, int color, int step, int alpha_or_beta, _Bool is_first_node) {
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

    int max = 0, min = 0;
    _Bool is_first_loop = 1;
    while (node_ptr != NULL) {
        board[node_ptr->x][node_ptr->y] = color;
        node_ptr->score = search(board, depth + 1, color == 1 ? 2 : 1, step + 1,\
            color == 1 ? max : min, is_first_loop);
        board[node_ptr->x][node_ptr->y] = 0;

        if (!is_first_node) {
            if (color == 1 && node_ptr->score > alpha_or_beta) {
                int final_score = node_ptr->score;
                free_linked_list(head);
                return final_score;
            }
            if (color == 2 && node_ptr->score < alpha_or_beta) {
                int final_score = node_ptr->score;
                free_linked_list(head);
                return final_score;
            }
        }

        if (is_first_loop) {
            max = node_ptr->score;
            min = node_ptr->score;
            is_first_loop = 0;
        } else {
            if (color == 1) {
                max = node_ptr->score > max ? node_ptr->score : max;
            } else {
                min = node_ptr->score < min ? node_ptr->score : min;
            }
        }
        node_ptr = node_ptr->next;
    }
    free_linked_list(head);
    return color == 1 ? max : min;
}

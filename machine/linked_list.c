#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// 链表节点生成: last 可以为 NULL, 也可以为任意节点. 会在链表后面新增节点, 并返回该节点
struct Node *new_node(int x, int y, struct Node * last) {
    if (last == NULL) {
        struct Node *head = malloc(sizeof(struct Node));
        if (head == NULL) {
            perror("machine/linked_list.c: malloc error1");
        }
        head->x = x;
        head->y = y;
        head->next = NULL;
        return head;
    }

    struct Node *node_ptr = last;
    while (node_ptr->next != NULL) {
        node_ptr = node_ptr->next;
    }
    node_ptr->next = malloc(sizeof(struct Node));
    if (node_ptr->next == NULL) {
        perror("machine/linked_list.c: malloc error2");
    }
    node_ptr = node_ptr->next;
    node_ptr->x = x;
    node_ptr->y = y;
    node_ptr->next = NULL;

    return node_ptr;
}

void free_linked_list(struct Node *head) {
    if (head == NULL) {
        return;
    }
    struct Node *node_ptr1, *node_ptr2;
    node_ptr1 = head;
    while (node_ptr1->next != NULL) {
        node_ptr2 = node_ptr1->next;
        free(node_ptr1);
        node_ptr1 = node_ptr2;
    }
    free(node_ptr1);
}

int score_find(struct Node * head, _Bool is_max) {
    if (head == NULL) {
        perror("head == NULL");
    }
    struct Node * node_ptr = head;
    int max = node_ptr->score;
    int min = node_ptr->score;

    while (node_ptr != NULL) {
        if (is_max) {
            if (node_ptr->score > max) {
                max = node_ptr->score;
            }
        } else {
            if (node_ptr->score < min) {
                min = node_ptr->score;
            }
        }
        node_ptr = node_ptr->next;
    }

    return is_max ? max : min;
}

int * pos_find(struct Node * head, _Bool is_max) {
    if (head == NULL) {
        perror("head == NULL");
    }
    struct Node * node_ptr = head;
    int max = node_ptr->score;
    int min = node_ptr->score;
    int x = node_ptr->x;
    int y = node_ptr->y;

    while (node_ptr != NULL) {
        if (is_max) {
            if (node_ptr->score > max) {
                max = node_ptr->score;
                x = node_ptr->x;
                y = node_ptr->y;
            }
        } else {
            if (node_ptr->score < min) {
                min = node_ptr->score;
                x = node_ptr->x;
                y = node_ptr->y;
            }
        }
        node_ptr = node_ptr->next;
    }

    int * result = malloc(sizeof(int) * 2);
    if (result == NULL) {
        perror("malloc error");
    }
    result[0] = x;
    result[1] = y;
    return result;
}
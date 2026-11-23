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
        head->score = 0;
        head->pre_score = 0;
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
    node_ptr->score = 0;
    node_ptr->pre_score = 0;
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

// 测试数据 10 7 5 20 10 15 20
// 按照 pre_score 由大到小的顺序插入, 如果 head 为 NULL 则创建新链表, 返回值为链表的 head
struct Node * sort_insert(struct Node *head, int x, int y, int pre_score) {
    if (head == NULL) {
        struct Node *new_head = malloc(sizeof(struct Node));
        if (new_head == NULL) {
            perror("machine/linked_list.c: malloc error3");
        }
        new_head->x = x;
        new_head->y = y;
        new_head->score = 0;
        new_head->pre_score = pre_score;
        new_head->next = NULL;
        return new_head;
    }

    struct Node *node_ptr = head, *last = NULL;
    while (node_ptr != NULL) {
        if (node_ptr->pre_score <= pre_score) {
            if (last != NULL) {
                struct Node * insert = malloc(sizeof(struct Node));
                if (insert == NULL) {
                    perror("machine/linked_list.c: malloc error4");
                }
                insert->x = x;
                insert->y = y;
                insert->score = 0;
                insert->pre_score = pre_score;
                insert->next = node_ptr;
                last->next = insert;
                return head;
            } else {
                struct Node * new_head = malloc(sizeof(struct Node));
                if (new_head == NULL) {
                    perror("machine/linked_list.c: malloc error5");
                }
                new_head->x = x;
                new_head->y = y;
                new_head->score = 0;
                new_head->pre_score = pre_score;
                new_head->next = head;
                return new_head;
            }
        }
        last = node_ptr;
        node_ptr = node_ptr->next;
    }
    struct Node * end_node = malloc(sizeof(struct Node));
    if (end_node == NULL) {
        perror("machine/linked_list.c: malloc error6");
    }
    end_node->x = x;
    end_node->y = y;
    end_node->score = 0;
    end_node->pre_score = pre_score;
    end_node->next = NULL;
    last->next = end_node;
    return head;
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
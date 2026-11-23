#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int x, y, pre_score, score;
    struct Node *next;
};

struct Node *new_node(int x, int y, struct Node * last);

void free_linked_list(struct Node *head);

int score_find(struct Node * head, _Bool is_max);

int * pos_find(struct Node * head, _Bool is_max);

struct Node * sort_insert(struct Node *head, int x, int y, int pre_score);

#endif // LINKED_LIST_H

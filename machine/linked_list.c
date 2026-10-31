#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x, y;
    struct Node *next;
};

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
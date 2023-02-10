#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clang -Wall -Wextra -o llist llist.c

int main(int argc, char *argv[])
{

    struct node *n = node_alloc(1);
    struct node *head = NULL;
    llist_insert_head(&head, n);
    printf("After adding node 1:\n");
    llist_print(head);
    struct node *m = node_alloc(2);
    llist_insert_head(&head, m);
    printf("After adding node 2 as head:\n");
    llist_print(head);
    struct node *l = node_alloc(3);
    llist_insert_tail(&head, l);
    printf("After adding node 3 as tail:\n");
    llist_print(head);
    llist_delete_head(&head);
    printf("After deleting the head:\n");
    llist_print(head);
    llist_free(&head);
    printf("After freeing the list:\n");
    llist_print(head);

    for(int i = 1; i < argc; ) {
      
        // printf("argv[i] for i = %d is %s\n", i, argv[i]);
        
        // struct node *head = NULL;

        if (strcmp(argv[i], "ih") == 0) {
            i += 2;
        }
        else if (strcmp(argv[i], "it") == 0) {
            i += 2;
        }
        else if (strcmp(argv[i], "dh") == 0) {
            i ++;
        }
        else if (strcmp(argv[i], "p") == 0) {
            i ++;
        }
        else if (strcmp(argv[i], "f") == 0) {
            i ++;
        }
        else {
            printf("Error: command \"%s\" not recognized. \nPlease limit to the following options: ih, it, dh, p, or f.\n", argv[i]);
            exit(0);
        }
    }
}


void llist_insert_head(struct node **head, struct node *n) {
    struct node *old_head = *head;
    *head = n;
    n->next = old_head;
}

struct node *llist_delete_head(struct node **head) {
    if (!*head) {
        return NULL;
    }
    else {
        struct node *old_head = *head;
        *head = (**head).next;
        return old_head;
    }
}

void llist_insert_tail(struct node **head, struct node *n) {
    if (!*head) {
        llist_insert_head(head, n);
    }
    else {
        struct node *curr_node = *head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = n;
    }
}

void llist_print(struct node *head) {
    if (!head) {
        printf("[EMPTY]\n");
    }
    else {
        struct node *curr_node = head;
        while (curr_node->next != NULL) {
            printf("%d -> ", curr_node->value);
            curr_node = curr_node->next;
        }
        printf("%d\n", curr_node->value);
    }
}

void llist_free(struct node **head) {
    struct node *curr_node = *head;
    while (curr_node->next != NULL) {
        struct node *temp = curr_node->next;
        node_free(curr_node);
        curr_node = temp;
    }
    node_free(curr_node);
    *head = NULL;
}

struct node *node_alloc(int value) {
    struct node *n;
    n = malloc(sizeof(*n));
    n->value = value;
    n->next = NULL;
    return n;
}

void node_free(struct node *n) {
    free(n);
}


// TESTING CODE
//
//
// --- example node creation ---
//
// struct node *n = node_alloc(13);
// printf("node 1 before node 2: pointer=%p, value=%d, next=%p\n", n, n->value, n->next);
//
// struct node *m = node_alloc(5);
// n->next = m;
// printf("node 1 after node 2: pointer=%p, value=%d, next=%p\n", n, n->value, n->next);
// printf("node 2: pointer=%p, value=%d, next=%p\n", m, m->value, m->next);
//
//
// --- node_alloc and node_free ---
//
// struct node *p = node_alloc(12);
// printf("printing node address: %p\n", p);
// node_free(p);
// printf("printing node address: %p\n", p);

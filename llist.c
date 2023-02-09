#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clang -Wall -Wextra -o llist llist.c

int main(int argc, char *argv[])
{

    struct node *n = node_alloc(13);
    struct node *head = n;
    llist_insert_head(&head, n);
    printf("node 1: pointer=%p, value=%d, next=%p\n", n, n->value, n->next);
    llist_print(head);

    // printf("After adding node 2:\n");
    // struct node *m = node_alloc(5);
    // llist_insert_head(head, m);
    // llist_print(*head);
    


    for(int i = 1; i < argc; ) {
      
        // printf("argv[i] for i = %d is %s\n", i, argv[i]);
        if (strcmp(argv[i], "ih") == 0) {
            i += 2;
        }
        // else if ()
        // ih
        // it
        // dh
        // p
        // f
    }
}


void llist_insert_head(struct node **head, struct node *n) {
    struct node *old_head = *head;
    *head = n;
    n->next = old_head;
}

struct node *llist_delete_head(struct node **head);

void llist_insert_tail(struct node **head, struct node *n);

void llist_print(struct node *head) {
    struct node *curr_add = head;
    while (curr_add->next != NULL) {
        printf("%d -> ", curr_add->value);
        curr_add = curr_add->next;
    }
    printf("%d\n", curr_add->value);
}

void llist_free(struct node **head);

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

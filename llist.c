#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clang -Wall -Wextra -o llist llist.c

// function declarations
// void llist_insert_head(struct node **head, struct node *n);
// struct node *llist_delete_head(struct node **head);
// void llist_insert_tail(struct node **head, struct node *n);
// void llist_print(struct node *head);
// void llist_free(struct node **head);
// struct node *node_alloc(int value);
// void node_free(struct node *n);

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; ) {
        // look at argv[i] and see if it's one of the commands
        // maybe we want to increment i differently depending on the if statement / kind of command
        printf("argv[i] for i = %d is %s\n", i, argv[i]);
        if (strcmp(argv[i], "ih") == 0) {
            printf("hey the number %d command was %s\n", i, argv[i]);
            printf("and the argument passed was %s\n", argv[i+1]);
            i += 2;
            printf("and now i is %d\n", i);
        }
        printf("printing node address: %d\n", node_alloc(12));
        // else if ()
        // ih
        // it
        // dh
        // p
        // f
    }
}

// function definitions
void llist_insert_head(struct node **head, struct node *n);
struct node *llist_delete_head(struct node **head);
void llist_insert_tail(struct node **head, struct node *n);
void llist_print(struct node *head);
void llist_free(struct node **head);
struct node *node_alloc(int value) {
    struct node *n;
    n = malloc(sizeof(*n));
    (*n).value = value;
    return n;
}
void node_free(struct node *n); 


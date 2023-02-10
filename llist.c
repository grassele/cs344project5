#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clang -Wall -Wextra -o llist llist.c

int main(int argc, char *argv[])
{
    struct node *head = NULL;

    for(int i = 1; i < argc; ) {
          
        //  ih
        if (strcmp(argv[i], "ih") == 0) {
            int val = atoi(argv[i+1]);
            struct node *new_node = node_alloc(val);
            llist_insert_head(&head, new_node);
            i += 2;
        }
        //  it
        else if (strcmp(argv[i], "it") == 0) {
            int val = atoi(argv[i+1]);
            struct node *new_node = node_alloc(val);
            llist_insert_tail(&head, new_node);
            i += 2;
        }
        //  dh  
        else if (strcmp(argv[i], "dh") == 0) {
            llist_delete_head(&head);
            i ++;
        }
        //  p  
        else if (strcmp(argv[i], "p") == 0) {
            llist_print(head);
            i ++;
        }
        //  f  
        else if (strcmp(argv[i], "f") == 0) {
            llist_free(&head);
            i ++;
        }
        //  unrecognized command  
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
        printf("[empty]\n");
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
    if (*head == NULL) {
        exit(0);
    }
    else {
        while (curr_node->next != NULL) {
            struct node *temp = curr_node->next;
            node_free(curr_node);
            curr_node = temp;
        }
        node_free(curr_node);
        *head = NULL;
    }
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

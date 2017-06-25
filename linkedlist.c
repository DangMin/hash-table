#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "app.h"

int add_to_list(linkedlist *list, char *string) {
    // Return -1 if string is empty
    if (*string == '\0') {
        return -1;
    }

    struct linkedlist *head = list;
    // If first node is not assigned yet, assign it
    if (head->data == NULL) {
        head->data = string;
        return 0;
    }

    // Iterate through list
    while (head->next) {
        head = head->next;
    }

    head->next = (linkedlist*) malloc(sizeof(linkedlist));
    head = head->next;
    head->data = string;
    return 1;
}

int add_with_pos(linkedlist *list, char *string, int position) {
    // Return -1 if string is empty
    if (*string == '\0') {
        return -1;
    }

    struct linkedlist *head = list;
    // If first node is not assigned yet, assign it
    if (head->data == NULL) {
        head->data = string;
        head->repeat = 1;
        head->position[0] = position;
        for(int i = 1; i < 20; ++i) {
            head->position[i] = 0;
        }
        return 0;
    }

    // Iterate through list
    while (head) {
        if (strcmp(head->data, string) == 0) {
            head->repeat += 1;
            add_position(head->position, position);
            return 1;
        }

        if (!head->next)
            break;

        head = head->next;
    }

    head->next = (linkedlist*) malloc(sizeof(linkedlist));
    head = head->next;
    head->repeat += 1;
    head->data = string;
    add_position(head->position, position);
    head->next = NULL;
    return 1;
}

int display_item(linkedlist *list) {
    if (list) {
        if (list->position != 0) {
            printf("Item:\t%s - Repeat: \t%d- Position: ", list->data, list->repeat);
            display_position(list->position);
        } else {
            printf("Item:\t%s\n", list->data);
        }
        return 0;
    }

    printf("Node not found!\n");
    return -1;
}

int display_list(linkedlist *list) {
    struct linkedlist *head = list;
    printf("\nDisplay list:\n");
    while (head) {
        display_item(head);
        head = head->next;
    }
    return 0;
}

linkedlist * search(linkedlist *list, char *string) {
    struct linkedlist *head = list;
    while (head) {
        if (strcmp(head->data, string)) {
            display_item(head);
            return head;
        }
        head = head->next;
    }

    printf("Item not found!");
    return NULL;
}

void add_position(int position[], int num) {
    for(int i = 0; i < 20; ++i) {
        if (position[i] == 0) {
            position[i] = num;
            return;
        }
    }
}

void display_position(int position[]) {
    for(int i = 0; i< 20; ++i) {
        if (position[i] != 0) {
            printf("%d\t", position[i]);
        }
    }
    printf("\n");
}
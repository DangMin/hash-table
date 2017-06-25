#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "linkedlist.h"
#include "app.h"

int hash(char *string) {
    int sum = 0;
    char *c = string;
    while (*c != '\0') {
        sum += (int)*(c+1);
        ++c;
    }

    return sum%1024;
}

int add_to_table(hash_element *table[], char *string, int position) {
    if (*string == '\0') {
        return -1;
    }

    int index = hash(string);
    
    if (!table[index]->list) {
        struct linkedlist *node = (linkedlist*)malloc(sizeof(linkedlist));
        node->data = string;
        add_position(node->position,position);
        node->next = NULL;

        return 0;
    }

    int num = add_with_pos(table[index]->list, string, position);
    
    return index;
}

void init(hash_element *table[]) {
    for(int i = 0; i < 1024; ++i) {
        table[i] = (hash_element*)malloc(sizeof(hash_element));
        table[i]->list = (linkedlist*)malloc(sizeof(linkedlist));
    }
}

void print_table(hash_element *table[]) {
    for(int i = 0; i < 1024; ++i) {    
        if (table[i]->list->data != NULL) {
            printf("\nIndex %d:", i+1);
            display_list(table[i]->list);
        }
    }
}
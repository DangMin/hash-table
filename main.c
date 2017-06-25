#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "app.h"
#include "hash.h"
#include "linkedlist.h"

void main(int argc, char argv[]) { 
    struct hash_element *table[1024];
    init(table);
    int pos = 0;
    FILE *f;

    read_file(f, table, (int*) &pos);
    printf("Number of words: %d\n",pos);
    print_table(table);
    exit(0);
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "app.h"

void read_file(FILE *f, hash_element *table[],int *pos) {
    int num = 0;
    f = fopen("sample.txt", "r");
    
    while (!feof(f)) {
        char *buff = (char*)malloc(20*sizeof(char));
        fscanf(f, "%s", buff);
        trim(buff);
        num = add_to_table(table, buff, ++*pos);
    }

    return;
}

void trim(char *s) {
    char *d = s;
    for (int i = 0; *(s+i) != '\0'; ++i) {
        if (isspace((int)*(s+i))) {
            *(s+i) = '\0';
        }
    }
    return;
}
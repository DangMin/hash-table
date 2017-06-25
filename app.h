#ifndef __APP_H__
#define __APP_H__ 1
typedef struct hash_element hash_element;
typedef struct linkedlist linkedlist;

struct hash_element {
    linkedlist *list;
};

struct linkedlist {
    char *data;
    int repeat;
    int position[20];
    struct linkedlist *next;
};
#endif

void trim(char *s);
void read_file(FILE *f, hash_element *table[],int *pos);
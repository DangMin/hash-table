#include "app.h"

int add_to_list(linkedlist *list, char *string);
int add_with_pos(linkedlist *list, char *string, int position);
int display_item(linkedlist *list);
int display_list(linkedlist *list);
linkedlist * search(linkedlist *list, char *string);

void add_position(int position[], int num);
void display_position(int position[]);
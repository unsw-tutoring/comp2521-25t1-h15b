#include <stdlib.h>

#include "Set.h"

struct node {
    int val;
    struct node *next;
};

struct set {
    struct node *list;
    int size;
};

Set SetNew(void) {
    Set s = malloc(sizeof(struct set));
    s->list = NULL;
    s->size = 0;

    return s;
}

static void doSetFree(struct node *list) {
    if (list == NULL) return;
    doSetFree(list->next);
    free(list);
}

void SetFree(Set s) {
    doSetFree(s->list);
    free(s);
}

void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    struct node *new = malloc(sizeof(struct node));
    new->val = elem;
    new->next = s->list;
    s->list = new;

    s->size++;
}

int SetSize(Set s) {
    return s->size;
}
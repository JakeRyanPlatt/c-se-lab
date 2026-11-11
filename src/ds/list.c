#include "list.h"
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

struct List {
    Node *head;
    Node *tail;
    size_t size;
    FreeFn free_fn;
};

List *list_create(FreeFn free_fn) {
    List *list = calloc(1, sizeof(List));
    if (!list) return NULL;
    list->free_fn = free_fn;
    return list;
}

size_t list_size(const List *list) {
    return list ? list->size: 0;
}

void list_destroy(List **list_ptr) {
    if (!list_ptr || !*list_ptr) return;

    List *list = *list_ptr;
    free(list);
    *list_ptr = NULL; // Zeros out the caller's pointer
}

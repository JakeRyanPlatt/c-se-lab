#ifndef C_SE_LAB_LIST_H
#define C_SE_LAB_LIST_H

#include <stddef.h>

// Opaque pointer: callers know 'List' exists, but cannot see its fields
typedef struct List List;

// Function pointer for cleaning up payload data later
typedef void (*FreeFn)(void *data);

List *list_create(FreeFn freeFn);
size_t list_size(const List *list);
void list_destroy(List **list);

#endif // C_SE_LAB_LIST_H

#include "list.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    List *my_list = list_create(NULL);
    assert(my_list != NULL);
    assert(list_size(my_list) ==0);

    list_destroy(&my_list);
    assert(my_list == NULL);

    printf("Step 1 passed: List created and destroyed cleanly!\n");
    return 0;
}
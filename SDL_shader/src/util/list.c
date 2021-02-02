#include "list.h"

#include <stdlib.h>

list* list_create(size_t stride, unsigned int count)
{
    list* list_obj = malloc(sizeof(list));

    if (list_obj)
    {
        list_obj->size = stride * count;
        list_obj->stride = stride;
        list_obj->begin = malloc(list_obj->size);
    }
    else
        return NULL;

    return list_obj;
}

void list_free(list* list_obj)
{
    free(list_obj->begin);
    free(list_obj);
}

void list_append(list* list_obj, void* data)
{
    // if
    //  list_insert(list[end])
    // else
    //  realloc()
}

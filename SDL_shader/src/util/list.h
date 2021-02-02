#pragma once

// TODO: Melhorar algumas descrições de funções e implementar elas

// Python style list object
typedef struct
{
    size_t size;
    size_t stride;
    void* begin;
} list;

// Allocate a new zero-initialized list* on heap
list* list_create(size_t stride, unsigned int count);

// Free list* memory
void list_free(list* list_obj);

// Add an item to the end of the list
void list_append(list* list_obj, void* data);

// Extend the list by appending all the items from the iterable
void list_extend(list* list_obj, unsigned int count, void* data);

// Insert an item at a given index
void list_insert(list* list_obj, unsigned int index, void* data);

// Remove an item at a given index
void list_remove(list* list_obj, unsigned int index);

// Remove the item at the given index in the list, and return it
// void list_pop(list* list_obj, unsigned int index, void* buffer);

// Remove all items from the list
void list_clear(list* list_obj);

// Return the index in the list of the first item that is equal to data
// Return -1 if not found
int list_index(list* list_obj, void* data);

// Return a void* shifted at given index in the list
void* list_at(list* list_obj, unsigned int index);

// Return the number of times data appears in the list
unsigned int list_count(list* list_obj, void* data);

// Sort the items of the list in place
// void list_sort(list* list_obj);

// Reverse the elements of the list in place
void list_reverse(list* list_obj);

// Return a copy of the list
list* list_copy(list* list_obj);

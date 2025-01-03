/*
* filename      myallocater.c
* author        Jatin Jain
* desc          this has the implementation for the following functions
                    - mymalloc_init(): Initializes the memory allocator by setting up the memory pool and free list.
                    - mymalloc(size_t size): Allocates a block of memory of the requested size from the memory pool using a first-fit allocation strategy.
                    - myfree(void* ptr): Frees a previously allocated memory block and coalesces adjacent free blocks to minimize fragmentation.
*/

#include <stdio.h>
#include "myallocator.h"


#define MEMORY_SIZE 1024 * 1024 // 1 MB
static char memory_pool[MEMORY_SIZE];

//defiining Data structures
typedef struct Block {
    size_t size;
    int free; // 1 if the block is free, 0 otherwise
    struct Block* next;
} Block;

#define BLOCK_SIZE sizeof(Block)

static Block* free_list = (Block*)memory_pool;



//initializing the allocater 
void mymalloc_init() {
    free_list->size = MEMORY_SIZE - BLOCK_SIZE;
    free_list->free = 1;
    free_list->next = NULL;
}
//allocating memory using first-fit stratergy
void* mymalloc(size_t size) {
    Block* current = free_list;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            size_t remaining_size = current->size - size - BLOCK_SIZE;

            if (remaining_size > 0) { // Split block
                Block* new_block = (Block*)((char*)current + BLOCK_SIZE + size);
                new_block->size = remaining_size;
                new_block->free = 1;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }

            current->free = 0;
            return (void*)((char*)current + BLOCK_SIZE);
        }
        current = current->next;
    }

    return NULL; // No suitable block found
}
//freeing the allocated memory
void myfree(void* ptr) {
    if (ptr == NULL) return;

    Block* block_to_free = (Block*)((char*)ptr - BLOCK_SIZE);
    block_to_free->free = 1;

    // Coalesce adjacent free blocks
    Block* current = free_list;

    while (current != NULL) {
        if (current->free && current->next && current->next->free) {
            current->size += BLOCK_SIZE + current->next->size;
            current->next = current->next->next;
        }
        current = current->next;
    }
}




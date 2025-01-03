#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H

#include <stddef.h> // For size_t

// Initializes the memory allocator
void mymalloc_init(void);

// Allocates a block of memory
void* mymalloc(size_t size);

// Frees a previously allocated block of memory
void myfree(void* ptr);

#endif // MYALLOCATOR_H


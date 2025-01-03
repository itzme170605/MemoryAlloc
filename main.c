/*
* filename      main.c
* author        Jatin Jain
* desc          this has the main test function to test mymalloc() and myfree() functions 
*/

#include <stdio.h>
#include "myallocator.h"


//main function to test this
#include <stdio.h>

int main() {
    mymalloc_init();

    void* ptr1 = mymalloc(256);
    void* ptr2 = mymalloc(512);
    void* ptr3 = mymalloc(128);

    printf("Allocated 256 bytes at %p\n", ptr1);
    printf("Allocated 512 bytes at %p\n", ptr2);
    printf("Allocated 128 bytes at %p\n", ptr3);

    myfree(ptr2);
    printf("Freed 512 bytes at %p\n", ptr2);

    void* ptr4 = mymalloc(300);
    printf("Allocated 300 bytes at %p\n", ptr4);

    return 0;
}


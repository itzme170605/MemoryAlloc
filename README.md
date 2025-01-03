# Memory Allocator Project
A simple implementation of a memory allocator in C. This project demonstrates basic concepts of memory management, including block allocation, freeing, and coalescing adjacent free blocks to reduce fragmentation.

# Features
  - Custom Memory Management: Simulates a simple memory allocator with a fixed-size memory pool.
  - First-Fit Allocation Strategy: Allocates memory using the first available block large enough to fit the requested size.
  - Block Coalescing: Merges adjacent free blocks to minimize fragmentation.

# Project Structure

├── main.c               // Test program for the memory allocator
├── myallocator.c        // Implementation of the memory allocator
├── myallocator.h        // Header file containing function declarations
├── README.md            // Project documentation

# Compilation
To compile the project, use the following command:

## bash
gcc -o myallocator_test main.c myallocator.c
## Run the Program
Execute the compiled program:

## bash
./myallocator_test

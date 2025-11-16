#pragma once

#include <common.h>

#include <stddef.h>

void grow_ptr(char** ptr, size_t* capacity_ptr, size_t elem_size);

void* aligned_alloc(size_t alignment, size_t size);
void aligned_free(void* memblock);

u32 get_elapsed_ms();
int getpagesize();

// Virtual memory functions for heap management
char* vmem_reserve(size_t size);
void vmem_commit(char* addr, size_t size);
void vmem_release(char* addr, size_t size);
#include <utils.h>

void grow_ptr(char** ptr, size_t* capacity_ptr, size_t elem_size)
{
	char* data = *ptr;
	size_t capacity = *capacity_ptr;
	size_t old_data_size = capacity*elem_size;
	
	char* new_data = malloc(old_data_size << 1);
	
	for (size_t i = 0; i < old_data_size; ++i)
	{
		new_data[i] = data[i];
	}
	
	free(data);
	
	*ptr = new_data;
	*capacity_ptr = capacity << 1;
}

#if defined(_MSC_VER)
//  Microsoft

#include <malloc.h>
#include <windows.h>
#include <Winbase.h>

void* aligned_alloc(size_t alignment, size_t size)
{
	return _aligned_malloc(size, alignment);
}

void aligned_free(void* memblock)
{
	_aligned_free(memblock);
}

u32 get_elapsed_ms()
{
	return (u32) GetTickCount();
}

int getpagesize()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	return (int)si.dwPageSize;
}

// Virtual memory functions for Windows
char* vmem_reserve(size_t size)
{
	return (char*)VirtualAlloc(NULL, size, MEM_RESERVE, PAGE_READWRITE);
}

void vmem_commit(char* addr, size_t size)
{
	VirtualAlloc(addr, size, MEM_COMMIT, PAGE_READWRITE);
}

void vmem_release(char* addr, size_t size)
{
	(void)size;  // size parameter unused on Windows
	VirtualFree(addr, 0, MEM_RELEASE);
}

#elif defined(__GNUC__)
// GCC

#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>

void aligned_free(void* memblock)
{
	free(memblock);
}

u32 get_elapsed_ms()
{
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC_RAW, &now);
	return (now.tv_sec)*1000 + (now.tv_nsec)/1000000;
}

// Virtual memory functions for Linux
char* vmem_reserve(size_t size)
{
	void* addr = mmap(NULL, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr == MAP_FAILED)
	{
		return NULL;
	}
	return (char*)addr;
}

void vmem_commit(char* addr, size_t size)
{
	mprotect(addr, size, PROT_READ | PROT_WRITE);
}

void vmem_release(char* addr, size_t size)
{
	munmap(addr, size);
}

#endif
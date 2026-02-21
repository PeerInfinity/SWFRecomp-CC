#include <string.h>

#include <heap.h>
#include <utils.h>

void grow_ptr(SWFAppContext* app_context, char** ptr, size_t* capacity_ptr, size_t elem_size)
{
	char* data = *ptr;
	size_t capacity = *capacity_ptr;
	size_t old_data_size = capacity*elem_size;

	char* new_data = HALLOC(old_data_size << 1);

	memcpy(new_data, data, old_data_size);

	FREE(data);

	*ptr = new_data;
	*capacity_ptr = capacity << 1;
}

#if defined(_MSC_VER)
// Microsoft

#include <windows.h>
#include <Winbase.h>

u32 get_elapsed_ms()
{
	return (u32) GetTickCount();
}

int getpagesize()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	return si.dwPageSize;
}

char* vmem_reserve(size_t size)
{
	return VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

void vmem_release(char* addr, size_t size)
{
	VirtualFree(addr, 0, MEM_RELEASE);
}

#elif defined(__wasi__)
// WASI (no mmap, use malloc/free; no POSIX clocks)

#include <stdlib.h>

u32 get_elapsed_ms()
{
	return 0;  // Timing not needed for trace-only WASI builds
}

char* vmem_reserve(size_t size)
{
	return (char*)malloc(size);
}

void vmem_release(char* addr, size_t size)
{
	(void)size;
	free(addr);
}

#elif defined(__GNUC__)
// GCC

#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>

u32 get_elapsed_ms()
{
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &now);
	return (now.tv_sec)*1000 + (now.tv_nsec)/1000000;
}

char* vmem_reserve(size_t size)
{
	return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
}

void vmem_release(char* addr, size_t size)
{
	munmap(addr, size);
}

#endif

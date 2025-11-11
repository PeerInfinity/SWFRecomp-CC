#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "o1heap.h"
#include "memory/heap.h"

/**
 * Multi-Heap Manager Implementation
 *
 * Strategy:
 * - Maintain a chain of o1heap instances
 * - When current heap is full (OOM), create a new larger heap
 * - Each new heap is 2x the size of the previous
 * - On free(), check which heap owns the pointer
 *
 * This eliminates stuttering from memory migration while allowing
 * the heap to grow as needed.
 */

#define DEFAULT_INITIAL_HEAP_SIZE (32 * 1024 * 1024)  // 32 MB
#define MAX_HEAPS 8  // Max 8 heaps: 32, 64, 128, 256, 512, 1024, 2048, 4096 MB

typedef struct HeapEntry {
	O1HeapInstance* instance;
	void* arena;
	size_t arena_size;
	void* arena_start;  // Start of usable memory (for pointer ownership check)
	void* arena_end;    // End of usable memory
} HeapEntry;

static HeapEntry g_heaps[MAX_HEAPS];
static int g_heap_count = 0;
static size_t g_next_heap_size = 0;
static bool g_initialized = false;

/**
 * Create a new heap of the specified size
 */
static bool create_heap(size_t size)
{
	if (g_heap_count >= MAX_HEAPS)
	{
		fprintf(stderr, "ERROR: Maximum number of heaps (%d) reached\n", MAX_HEAPS);
		return false;
	}

	// Allocate arena (use system malloc for the arena itself)
	void* arena = malloc(size);
	if (arena == NULL)
	{
		fprintf(stderr, "ERROR: Failed to allocate heap arena of size %zu bytes\n", size);
		return false;
	}

	// Initialize o1heap instance
	O1HeapInstance* instance = o1heapInit(arena, size);
	if (instance == NULL)
	{
		fprintf(stderr, "ERROR: Failed to initialize o1heap (size=%zu, arena=%p)\n", size, arena);
		free(arena);
		return false;
	}

	// Store heap entry
	g_heaps[g_heap_count].instance = instance;
	g_heaps[g_heap_count].arena = arena;
	g_heaps[g_heap_count].arena_size = size;
	g_heaps[g_heap_count].arena_start = arena;
	g_heaps[g_heap_count].arena_end = (char*)arena + size;

	printf("[HEAP] Created heap %d: size=%zu MB (%zu bytes)\n",
		g_heap_count, size / (1024 * 1024), size);

	g_heap_count++;
	g_next_heap_size = size * 2;  // Next heap will be 2x larger

	return true;
}

bool heap_init(size_t initial_size)
{
	if (g_initialized)
	{
		fprintf(stderr, "WARNING: heap_init() called when already initialized\n");
		return true;
	}

	if (initial_size == 0)
	{
		initial_size = DEFAULT_INITIAL_HEAP_SIZE;
	}

	g_heap_count = 0;
	g_next_heap_size = initial_size;

	if (!create_heap(initial_size))
	{
		return false;
	}

	g_initialized = true;
	printf("[HEAP] Initialized with %zu MB initial heap\n", initial_size / (1024 * 1024));

	return true;
}

void* heap_alloc(size_t size)
{
	if (!g_initialized)
	{
		fprintf(stderr, "ERROR: heap_alloc() called before heap_init()\n");
		return NULL;
	}

	if (size == 0)
	{
		return NULL;  // Standard malloc behavior
	}

	// Try to allocate from existing heaps (most recent first, as it's most likely to have space)
	for (int i = g_heap_count - 1; i >= 0; i--)
	{
		void* ptr = o1heapAllocate(g_heaps[i].instance, size);
		if (ptr != NULL)
		{
			return ptr;
		}
	}

	// All heaps are full - try to create a new heap
	if (create_heap(g_next_heap_size))
	{
		// Try allocation from the new heap
		void* ptr = o1heapAllocate(g_heaps[g_heap_count - 1].instance, size);
		if (ptr != NULL)
		{
			return ptr;
		}
	}

	// Failed to allocate even after creating new heap
	fprintf(stderr, "ERROR: heap_alloc(%zu) failed - out of memory\n", size);
	return NULL;
}

void* heap_calloc(size_t num, size_t size)
{
	// Check for overflow
	if (num != 0 && size > SIZE_MAX / num)
	{
		return NULL;
	}

	size_t total = num * size;
	void* ptr = heap_alloc(total);

	if (ptr != NULL)
	{
		memset(ptr, 0, total);
	}

	return ptr;
}

void heap_free(void* ptr)
{
	if (ptr == NULL)
	{
		return;  // Standard free behavior
	}

	if (!g_initialized)
	{
		fprintf(stderr, "ERROR: heap_free() called before heap_init()\n");
		return;
	}

	// Find which heap owns this pointer
	for (int i = 0; i < g_heap_count; i++)
	{
		if (ptr >= g_heaps[i].arena_start && ptr < g_heaps[i].arena_end)
		{
			o1heapFree(g_heaps[i].instance, ptr);
			return;
		}
	}

	// Pointer not found in any heap - this is a bug
	fprintf(stderr, "ERROR: heap_free() called with invalid pointer %p\n", ptr);
	fprintf(stderr, "       This pointer was not allocated by heap_alloc()\n");
	assert(0);  // Crash in debug builds
}

void heap_stats(void)
{
	if (!g_initialized)
	{
		printf("[HEAP] Not initialized\n");
		return;
	}

	printf("\n========== Heap Statistics ==========\n");
	printf("Number of heaps: %d\n", g_heap_count);
	printf("Next heap size:  %zu MB\n\n", g_next_heap_size / (1024 * 1024));

	size_t total_capacity = 0;
	size_t total_allocated = 0;
	size_t total_peak = 0;
	uint64_t total_oom = 0;

	for (int i = 0; i < g_heap_count; i++)
	{
		O1HeapDiagnostics diag = o1heapGetDiagnostics(g_heaps[i].instance);

		printf("Heap %d:\n", i);
		printf("  Arena size:      %zu MB (%zu bytes)\n",
			g_heaps[i].arena_size / (1024 * 1024), g_heaps[i].arena_size);
		printf("  Capacity:        %zu MB (%zu bytes)\n",
			diag.capacity / (1024 * 1024), diag.capacity);
		printf("  Allocated:       %zu MB (%zu bytes, %.1f%%)\n",
			diag.allocated / (1024 * 1024), diag.allocated,
			100.0 * diag.allocated / diag.capacity);
		printf("  Peak allocated:  %zu MB (%zu bytes, %.1f%%)\n",
			diag.peak_allocated / (1024 * 1024), diag.peak_allocated,
			100.0 * diag.peak_allocated / diag.capacity);
		printf("  Peak request:    %zu bytes\n", diag.peak_request_size);
		printf("  OOM count:       %llu\n", (unsigned long long)diag.oom_count);
		printf("\n");

		total_capacity += diag.capacity;
		total_allocated += diag.allocated;
		total_peak += diag.peak_allocated;
		total_oom += diag.oom_count;
	}

	printf("Total:\n");
	printf("  Capacity:        %zu MB\n", total_capacity / (1024 * 1024));
	printf("  Allocated:       %zu MB (%.1f%%)\n",
		total_allocated / (1024 * 1024),
		100.0 * total_allocated / total_capacity);
	printf("  Peak allocated:  %zu MB (%.1f%%)\n",
		total_peak / (1024 * 1024),
		100.0 * total_peak / total_capacity);
	printf("  Total OOM:       %llu\n", (unsigned long long)total_oom);
	printf("=====================================\n\n");
}

void heap_shutdown(void)
{
	if (!g_initialized)
	{
		return;
	}

	printf("[HEAP] Shutting down - freeing %d heap(s)\n", g_heap_count);

	for (int i = 0; i < g_heap_count; i++)
	{
		free(g_heaps[i].arena);
		g_heaps[i].instance = NULL;
		g_heaps[i].arena = NULL;
	}

	g_heap_count = 0;
	g_initialized = false;
}

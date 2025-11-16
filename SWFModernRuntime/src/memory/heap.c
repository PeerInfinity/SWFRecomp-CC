#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "o1heap.h"
#include "memory/heap.h"
#include "libswf/swf.h"
#include "utils.h"

/**
 * Virtual Memory-based Heap Implementation
 *
 * Strategy:
 * - Reserve large virtual address space (DEFAULT_FULL_HEAP_SIZE) upfront
 * - Commit physical pages on demand starting with DEFAULT_INITIAL_HEAP_SIZE
 * - When heap is full, commit more pages by doubling the committed size
 * - All allocations remain at same addresses (no migration needed)
 * - Heap state stored in app_context for proper lifecycle management
 */

#define DEFAULT_INITIAL_HEAP_SIZE (64 * 1024 * 1024)  // 64 MB
#define DEFAULT_FULL_HEAP_SIZE (4ULL * 1024 * 1024 * 1024)  // 4 GB virtual space

static SWFAppContext* g_app_context = NULL;

bool heap_init(SWFAppContext* app_context, size_t initial_size)
{
	if (app_context == NULL)
	{
		fprintf(stderr, "ERROR: heap_init() called with NULL app_context\n");
		return false;
	}

	if (app_context->heap_inited)
	{
		fprintf(stderr, "WARNING: heap_init() called when already initialized\n");
		return true;
	}

	if (initial_size == 0)
	{
		initial_size = DEFAULT_INITIAL_HEAP_SIZE;
	}

	// Store reference to app_context for later use
	g_app_context = app_context;

	// Reserve large virtual address space
	app_context->heap_full_size = DEFAULT_FULL_HEAP_SIZE;
	app_context->heap = vmem_reserve(app_context->heap_full_size);

	if (app_context->heap == NULL)
	{
		fprintf(stderr, "ERROR: Failed to reserve %llu bytes of virtual address space\n",
			(unsigned long long)app_context->heap_full_size);
		return false;
	}

	// Commit initial physical pages
	app_context->heap_current_size = initial_size;
	vmem_commit(app_context->heap, app_context->heap_current_size);

	// Initialize o1heap instance
	app_context->heap_instance = o1heapInit(app_context->heap, app_context->heap_current_size);

	if (app_context->heap_instance == NULL)
	{
		fprintf(stderr, "ERROR: Failed to initialize o1heap (size=%zu, arena=%p)\n",
			app_context->heap_current_size, (void*)app_context->heap);
		vmem_release(app_context->heap, app_context->heap_full_size);
		app_context->heap = NULL;
		return false;
	}

	app_context->heap_inited = 1;

	printf("[HEAP] Initialized with %zu MB committed (%.1f GB reserved)\n",
		app_context->heap_current_size / (1024 * 1024),
		app_context->heap_full_size / (1024.0 * 1024.0 * 1024.0));

	return true;
}

void* heap_alloc(size_t size)
{
	if (g_app_context == NULL || !g_app_context->heap_inited)
	{
		fprintf(stderr, "ERROR: heap_alloc() called before heap_init()\n");
		return NULL;
	}

	if (size == 0)
	{
		return NULL;  // Standard malloc behavior
	}

	// Try to allocate from current heap
	void* ptr = o1heapAllocate(g_app_context->heap_instance, size);

	if (ptr != NULL)
	{
		return ptr;
	}

	// Heap is full - try to expand by committing more pages
	size_t new_size = g_app_context->heap_current_size * 2;

	if (new_size > g_app_context->heap_full_size)
	{
		fprintf(stderr, "ERROR: Cannot expand heap beyond reserved virtual space (%llu bytes)\n",
			(unsigned long long)g_app_context->heap_full_size);
		return NULL;
	}

	// Commit additional pages
	size_t additional_size = new_size - g_app_context->heap_current_size;
	char* commit_addr = g_app_context->heap + g_app_context->heap_current_size;
	vmem_commit(commit_addr, additional_size);

	printf("[HEAP] Expanding: %zu MB -> %zu MB\n",
		g_app_context->heap_current_size / (1024 * 1024),
		new_size / (1024 * 1024));

	// Reinitialize o1heap with the expanded arena
	g_app_context->heap_instance = o1heapInit(g_app_context->heap, new_size);
	g_app_context->heap_current_size = new_size;

	if (g_app_context->heap_instance == NULL)
	{
		fprintf(stderr, "ERROR: Failed to reinitialize o1heap after expansion\n");
		return NULL;
	}

	// Try allocation again
	ptr = o1heapAllocate(g_app_context->heap_instance, size);

	if (ptr == NULL)
	{
		fprintf(stderr, "ERROR: heap_alloc(%zu) failed even after expansion\n", size);
	}

	return ptr;
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

	if (g_app_context == NULL || !g_app_context->heap_inited)
	{
		fprintf(stderr, "ERROR: heap_free() called before heap_init()\n");
		return;
	}

	// Check if pointer is within our heap bounds
	if (ptr < (void*)g_app_context->heap ||
		ptr >= (void*)(g_app_context->heap + g_app_context->heap_current_size))
	{
		fprintf(stderr, "ERROR: heap_free() called with invalid pointer %p\n", ptr);
		fprintf(stderr, "       This pointer was not allocated by heap_alloc()\n");
		assert(0);  // Crash in debug builds
		return;
	}

	o1heapFree(g_app_context->heap_instance, ptr);
}

void heap_stats(void)
{
	if (g_app_context == NULL || !g_app_context->heap_inited)
	{
		printf("[HEAP] Not initialized\n");
		return;
	}

	O1HeapDiagnostics diag = o1heapGetDiagnostics(g_app_context->heap_instance);

	printf("\n========== Heap Statistics ==========\n");
	printf("Reserved space:  %.1f GB (%llu bytes)\n",
		g_app_context->heap_full_size / (1024.0 * 1024.0 * 1024.0),
		(unsigned long long)g_app_context->heap_full_size);
	printf("Committed space: %zu MB (%zu bytes)\n",
		g_app_context->heap_current_size / (1024 * 1024),
		g_app_context->heap_current_size);
	printf("Capacity:        %zu MB (%zu bytes)\n",
		diag.capacity / (1024 * 1024), diag.capacity);
	printf("Allocated:       %zu MB (%zu bytes, %.1f%%)\n",
		diag.allocated / (1024 * 1024), diag.allocated,
		100.0 * diag.allocated / diag.capacity);
	printf("Peak allocated:  %zu MB (%zu bytes, %.1f%%)\n",
		diag.peak_allocated / (1024 * 1024), diag.peak_allocated,
		100.0 * diag.peak_allocated / diag.capacity);
	printf("Peak request:    %zu bytes\n", diag.peak_request_size);
	printf("OOM count:       %llu\n", (unsigned long long)diag.oom_count);
	printf("=====================================\n\n");
}

void heap_shutdown(void)
{
	if (g_app_context == NULL || !g_app_context->heap_inited)
	{
		return;
	}

	printf("[HEAP] Shutting down - releasing virtual memory\n");

	// Release all virtual memory
	vmem_release(g_app_context->heap, g_app_context->heap_full_size);

	g_app_context->heap_instance = NULL;
	g_app_context->heap = NULL;
	g_app_context->heap_inited = 0;
	g_app_context->heap_current_size = 0;
	g_app_context->heap_full_size = 0;

	g_app_context = NULL;
}

#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>
#include <stdbool.h>

// Forward declaration
typedef struct SWFAppContext SWFAppContext;

/**
 * Memory Heap Manager
 *
 * Wrapper around o1heap allocator using virtual memory for efficient expansion.
 *
 * Design:
 * - Reserves large virtual address space (e.g., 4 GB) upfront (cheap, no physical RAM)
 * - Initializes o1heap with the FULL reserved address space (manages entire range)
 * - Commits physical pages on demand (starts with 64 MB committed)
 * - When heap needs more space, commits additional pages (no reinitialization)
 * - Physical RAM only allocated on first access (lazy allocation by OS)
 * - No copying or migration needed - all allocations stay at same addresses
 * - Heap state stored in app_context for proper lifecycle management
 *
 * Key benefit: Lazy physical allocation spreads memory overhead across frames,
 * reducing stutter compared to traditional malloc/realloc approaches.
 */

/**
 * Initialize the heap system
 *
 * @param app_context The SWF application context to store heap state
 * @param initial_size Initial heap size in bytes (default: 64 MB if 0)
 * @return true on success, false on failure
 */
bool heap_init(SWFAppContext* app_context, size_t initial_size);

/**
 * Allocate memory from the heap
 *
 * Semantics similar to malloc():
 * - Returns pointer aligned to O1HEAP_ALIGNMENT
 * - Returns NULL on allocation failure
 * - Size of 0 returns NULL (standard behavior)
 *
 * @param size Number of bytes to allocate
 * @return Pointer to allocated memory, or NULL on failure
 */
void* heap_alloc(size_t size);

/**
 * Allocate zero-initialized memory from the heap
 *
 * Semantics similar to calloc():
 * - Allocates num * size bytes
 * - Zeroes the memory before returning
 * - Returns NULL on allocation failure or overflow
 *
 * @param num Number of elements
 * @param size Size of each element
 * @return Pointer to allocated zero-initialized memory, or NULL on failure
 */
void* heap_calloc(size_t num, size_t size);

/**
 * Free memory allocated by heap_alloc() or heap_calloc()
 *
 * Semantics similar to free():
 * - Passing NULL is a no-op
 * - Pointer must have been returned by heap_alloc() or heap_calloc()
 *
 * @param ptr Pointer to memory to free
 */
void heap_free(void* ptr);

/**
 * Get heap statistics
 *
 * Prints detailed statistics about heap usage including:
 * - Number of heaps
 * - Size of each heap
 * - Allocated memory
 * - Peak allocation
 * - OOM count
 */
void heap_stats(void);

/**
 * Shutdown the heap system
 *
 * Frees all heap arenas. Should be called at program exit.
 * After calling this, heap_alloc() will fail until heap_init() is called again.
 */
void heap_shutdown(void);

#endif // HEAP_H

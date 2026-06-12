// alloc_guard.c — link-time interposition of free/realloc that flags any
// system-allocator free of a pointer inside the o1heap arena. In production
// (browser-WASM) such a call silently corrupts dlmalloc chunk metadata —
// dlmalloc reads the o1heap fragment bytes preceding the pointer as a chunk
// header and links a fake chunk into its bins; a later malloc spins forever.
// That failure mode is invisible to ASAN under -DHEAP_PASSTHROUGH (both
// allocators become one), so this guard runs against the REAL o1heap.
//
// Build with: -Wl,--wrap=free -Wl,--wrap=realloc  (and WITHOUT HEAP_PASSTHROUGH)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <execinfo.h>

#include <libswf/swf.h>

extern SWFAppContext app_context;  // defined in main.c

void __real_free(void* ptr);
void* __real_realloc(void* ptr, size_t size);

static void report(const char* fn, void* ptr)
{
	fprintf(stderr, "\n=== ALLOC GUARD: system %s() of o1heap arena pointer %p ===\n", fn, ptr);
	fprintf(stderr, "arena = [%p, %p)\n", (void*)app_context.heap,
	        (void*)(app_context.heap + app_context.heap_current_size));
	void* bt[32];
	int n = backtrace(bt, 32);
	backtrace_symbols_fd(bt, n, 2);
	fflush(stderr);
	abort();
}

static int in_arena(void* ptr)
{
	return app_context.heap_inited && ptr != NULL &&
	       (char*)ptr >= app_context.heap &&
	       (char*)ptr < app_context.heap + app_context.heap_current_size;
}

void __wrap_free(void* ptr)
{
	if (in_arena(ptr)) report("free", ptr);
	__real_free(ptr);
}

void* __wrap_realloc(void* ptr, size_t size)
{
	if (in_arena(ptr)) report("realloc", ptr);
	return __real_realloc(ptr, size);
}

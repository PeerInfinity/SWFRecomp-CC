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
 * - Reserve full virtual address space (1 GB) upfront - no physical RAM used
 * - Commit all pages immediately - still no physical RAM used!
 * - Initialize o1heap with the full 1 GB committed space
 * - Physical memory is lazily allocated by OS on first access (spreads overhead across frames)
 * - No expansion logic needed - heap has full space from start
 * - Heap state stored in app_context for proper lifecycle management
 *
 * Key Insights (NATIVE — Linux anonymous mmap + demand paging):
 * 1. Reserving virtual address space is cheap (no physical RAM)
 * 2. Committing pages is also cheap (<1 ms for 1 GB) - still no physical RAM!
 * 3. Physical RAM only allocated when memory is first touched (lazy allocation)
 * 4. This spreads allocation overhead across many frames, preventing stutter
 * 5. Pre-touching pages to force allocation is too slow (150 ms for 512 MB)
 * 6. Trusting OS lazy allocation is fastest and smoothest
 *
 * Performance: Committing 1 GB upfront is faster than trying to be "smart" about
 * incremental expansion. The OS handles lazy physical allocation better than we can.
 *
 * ****************************************************************************
 * WARNING — the "lazy allocation" insight above is NATIVE-ONLY. It does NOT
 * hold under emscripten. Emscripten implements anonymous mmap (see
 * system/lib/libc/emscripten_mmap.c) as `emscripten_builtin_memalign(len)`
 * followed by `memset(ptr, 0, len)`. So vmem_reserve(N) in the browser:
 *   (1) grows WebAssembly.Memory from INITIAL_MEMORY to ~N at heap_init
 *       (before the first frame), and
 *   (2) memsets the whole region, so the browser physically backs all ~N
 *       bytes of the linear-memory ArrayBuffer at LOAD.
 * i.e. the tab pays the full arena size eagerly, not on touch. heap_init runs
 * at the top of runSWF_avm2() (the first frame, right after the user hits
 * Start), so page-load costs only INITIAL_MEMORY and the ~2 GB lands on Start.
 * MEASURED 2026-07-21 (real-GPU Windows Chrome): rwk 512 MiB before Start ->
 * 2117 MiB the first frame after, resident RSS ~2121 MiB (not just reserved).
 * This is why the browser arena must be sized to real demand, not to
 * comfortable headroom. See SWFRecompDocs/plans/avm2-browser-footprint.md.
 * ****************************************************************************
 */

#ifdef __wasi__
#define DEFAULT_FULL_HEAP_SIZE (64ULL * 1024 * 1024)  // 64 MB for WASI (no virtual memory)
#elif defined(__EMSCRIPTEN__) && defined(SWF_AVM2)
// Browser AVM2: 512 MB. The arena is committed AND zero-filled resident at
// heap_init under emscripten (see the WARNING block above), so its SIZE — not
// its usage — is what a player's tab pays at Start. It was 1984 MB only to
// hold a single tick's `FlxTilemap.arrayToCSV` O(n^2) concat transient
// (measured ~1397 MB for RWK, up to ~1788 MB for RWIC). The native arrayToCSV
// intrinsic (avm2_flixel.c id 4) removes that transient: with it, RWK's whole
// run peaks at a MEASURED 246 MB (worst gameplay tick 118 MB, was 1397 MB) —
// no title's post-intrinsic demand approaches 512 MB. 512 gives ~2x margin
// under o1heap's 7/8 eager-sweep valve (448 MB) and the watermark self-clamps
// to ~(512-live)/4, keeping the GC sawtooth well below the valve.
//   FINAL GATE (per SWFRecompDocs/plans/avm2-browser-footprint.md §6.3): a
//   browser soak (zero OOM, HEAPU8 flat at 512+base) and a real-GPU rig FPS
//   check (all-frames mean + >250ms stall count, NOT p50; every title >=30fps)
//   on the Windows Playwright rig. If GC cadence bites, raise via SWF_HEAP_MB
//   or bump this to 768-1024 (still ~2x under the old 1984). See §3 Lever 1A.
// Override at runtime for A/B sizing: SWF_HEAP_MB=<n> (native + wasm-with-env).
#define DEFAULT_FULL_HEAP_SIZE (512ULL * 1024 * 1024)
#elif defined(__EMSCRIPTEN__)
// Browser AVM1: 256 MB. Same commit-at-load mechanism as AVM2 above; AVM1 live
// sets are single-digit MB (Tetris/N/Bloons) with no Flixel transient, so the
// old wasm32-default 1 GB was ~30x headroom paid resident at every demo's
// Start. 256 MB is still ~30x the live set. (Native AVM1 is 64-bit -> the 4 GB
// branch below; only the browser demos take this path.)
#define DEFAULT_FULL_HEAP_SIZE (256ULL * 1024 * 1024)
#elif !defined(__LP64__)
#define DEFAULT_FULL_HEAP_SIZE (1ULL * 1024 * 1024 * 1024)  // 1 GB (32-bit native address space)
#else
// 64-bit native: 4 GB virtual space, physical RAM lazy (native Linux anonymous
// mmap + demand paging — genuinely lazy here, unlike wasm), so the reservation
// costs no resident RAM until touched. Kept roomy as a native-only convenience;
// the FlxTilemap.arrayToCSV intrinsic (avm2_flixel.c id 4) already removed the
// old multi-GB single-tick transient that motivated this (RWK measured
// 1397 -> 118 MB worst tick), so real games now peak in the low hundreds of MB.
#define DEFAULT_FULL_HEAP_SIZE (4ULL * 1024 * 1024 * 1024)  // 4 GB virtual space
#endif

#ifdef HEAP_PASSTHROUGH
// Sanitizer mode: route HALLOC/HCALLOC/FREE straight to the system allocator
// so ASAN/valgrind can see every runtime allocation individually. The o1heap
// arena is one opaque block to sanitizers — UAF/double-free/OOB inside it are
// invisible without this. Debug-only; never enable in production builds
// (o1heap exists for per-frame latency, not correctness).
bool heap_init(SWFAppContext* app_context, size_t initial_size)
{
	(void)initial_size;
	if (app_context == NULL) return false;
	app_context->heap_inited = 1;
	fprintf(stderr, "[HEAP] PASSTHROUGH mode: HALLOC/FREE = system malloc/free (sanitizer hunt build)\n");
	return true;
}

void* heap_alloc(SWFAppContext* app_context, size_t size)
{
	(void)app_context;
	if (size == 0) return NULL;
	void* ptr = malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr, "ERROR: heap_alloc(%zu) failed - out of memory\n", size);
		exit(1);
	}
	return ptr;
}

void* heap_calloc(SWFAppContext* app_context, size_t num, size_t size)
{
	(void)app_context;
	if (num == 0 || size == 0) return NULL;
	return calloc(num, size);
}

void heap_free(SWFAppContext* app_context, void* ptr)
{
	(void)app_context;
	free(ptr);
}

void heap_stats(SWFAppContext* app_context)
{
	(void)app_context;
	printf("[HEAP] PASSTHROUGH mode: no o1heap statistics\n");
}

size_t heap_allocated_bytes(SWFAppContext* app_context)
{
	(void)app_context;
	return 0;  // unknown — passthrough has no allocation accounting
}

size_t heap_capacity_bytes(SWFAppContext* app_context)
{
	(void)app_context;
	return 0;
}

void* heap_arena_base(SWFAppContext* app_context)
{
	(void)app_context;
	return NULL;  // system malloc: no arena — callers fall back
}

size_t heap_arena_span(SWFAppContext* app_context)
{
	(void)app_context;
	return 0;
}

void heap_tick_mark(SWFAppContext* app_context)
{
	(void)app_context;  // passthrough: no per-fragment accounting
}

size_t heap_peak_since_mark_bytes(SWFAppContext* app_context)
{
	(void)app_context;
	return 0;  // unknown — passthrough has no allocation accounting
}

void heap_shutdown(SWFAppContext* app_context)
{
	// MC registry memory is going away — disable the mem-report atexit fallback.
	extern void swfMemMarkUnsafeToWalk(void);
	swfMemMarkUnsafeToWalk();
	if (app_context != NULL)
		app_context->heap_inited = 0;
}

#else  // !HEAP_PASSTHROUGH

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

	// Use caller-specified heap size, or default
	if (app_context->heap_full_size == 0)
		app_context->heap_full_size = DEFAULT_FULL_HEAP_SIZE;
	// SWF_HEAP_MB=<n> overrides the arena size (A/B arena sizing for the
	// footprint work — native always, and wasm builds that expose the env).
	{
		const char* mb = getenv("SWF_HEAP_MB");
		if (mb != NULL && mb[0] != '\0')
		{
			long long v = atoll(mb);
			if (v > 0)
				app_context->heap_full_size = (size_t) v * 1024ULL * 1024ULL;
		}
	}
	app_context->heap = vmem_reserve(app_context->heap_full_size);

	if (app_context->heap == NULL)
	{
		fprintf(stderr, "ERROR: Failed to reserve %llu bytes of virtual address space\n",
			(unsigned long long)app_context->heap_full_size);
		return false;
	}

	// vmem_reserve now does both reserve and commit in one step
	// Physical memory is still allocated lazily by OS on first access
	app_context->heap_current_size = app_context->heap_full_size;

	// Initialize o1heap with the full committed size
	app_context->heap_instance = o1heapInit(app_context->heap, app_context->heap_full_size);

	if (app_context->heap_instance == NULL)
	{
		fprintf(stderr, "ERROR: Failed to initialize o1heap (size=%zu, arena=%p)\n",
			app_context->heap_full_size, (void*)app_context->heap);
		vmem_release(app_context->heap, app_context->heap_full_size);
		app_context->heap = NULL;
		return false;
	}

	app_context->heap_inited = 1;

	printf("[HEAP] Initialized: %.1f GB reserved and committed (physical RAM allocated on access)\n",
		app_context->heap_full_size / (1024.0 * 1024.0 * 1024.0));

	return true;
}

void* heap_alloc(SWFAppContext* app_context, size_t size)
{
	if (app_context == NULL || !app_context->heap_inited)
	{
		fprintf(stderr, "ERROR: heap_alloc() called before heap_init()\n");
		return NULL;
	}

	if (size == 0)
	{
		return NULL;  // Standard malloc behavior
	}

	// Allocate from the heap
	// All pages are already committed, so no expansion logic needed
	// Physical RAM is allocated lazily by the OS when memory is first accessed
	void* ptr = o1heapAllocate(app_context->heap_instance, size);

	if (ptr == NULL)
	{
		fprintf(stderr, "ERROR: heap_alloc(%zu) failed - out of memory\n", size);
		exit(1);
	}

	return ptr;
}

void* heap_calloc(SWFAppContext* app_context, size_t num, size_t size)
{
	// Check for overflow
	if (num != 0 && size > SIZE_MAX / num)
	{
		return NULL;
	}

	size_t total = num * size;
	void* ptr = heap_alloc(app_context, total);

	if (ptr != NULL)
	{
		memset(ptr, 0, total);
	}

	return ptr;
}

void heap_free(SWFAppContext* app_context, void* ptr)
{
	if (ptr == NULL)
	{
		return;  // Standard free behavior
	}

	if (app_context == NULL || !app_context->heap_inited)
	{
		fprintf(stderr, "ERROR: heap_free() called before heap_init()\n");
		return;
	}

	// Check if pointer is within our heap bounds
	if (ptr < (void*)app_context->heap ||
		ptr >= (void*)(app_context->heap + app_context->heap_current_size))
	{
		fprintf(stderr, "ERROR: heap_free() called with invalid pointer %p\n", ptr);
		fprintf(stderr, "       This pointer was not allocated by heap_alloc()\n");
		assert(0);  // Crash in debug builds
		return;
	}

	o1heapFree(app_context->heap_instance, ptr);
}

size_t heap_allocated_bytes(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return 0;
	return o1heapGetDiagnostics(app_context->heap_instance).allocated;
}

size_t heap_capacity_bytes(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return 0;
	return o1heapGetDiagnostics(app_context->heap_instance).capacity;
}

void* heap_arena_base(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return NULL;
	return (void*) app_context->heap;
}

size_t heap_arena_span(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return 0;
	return app_context->heap_current_size;
}

void heap_tick_mark(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return;
	o1heapMarkPeak(app_context->heap_instance);
}

size_t heap_peak_since_mark_bytes(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited) return 0;
	return o1heapGetPeakSinceMark(app_context->heap_instance);
}

void heap_stats(SWFAppContext* app_context)
{
	if (app_context == NULL || !app_context->heap_inited)
	{
		printf("[HEAP] Not initialized\n");
		return;
	}

	O1HeapDiagnostics diag = o1heapGetDiagnostics(app_context->heap_instance);

	printf("\n========== Heap Statistics ==========\n");
	printf("Reserved space:  %.1f GB (%llu bytes)\n",
		app_context->heap_full_size / (1024.0 * 1024.0 * 1024.0),
		(unsigned long long)app_context->heap_full_size);
	printf("Committed space: %zu MB (%zu bytes)\n",
		app_context->heap_current_size / (1024 * 1024),
		app_context->heap_current_size);
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

void heap_shutdown(SWFAppContext* app_context)
{
	// MC registry memory is going away — disable the mem-report atexit fallback.
	extern void swfMemMarkUnsafeToWalk(void);
	swfMemMarkUnsafeToWalk();

	if (app_context == NULL || !app_context->heap_inited)
	{
		return;
	}

	printf("[HEAP] Shutting down - releasing virtual memory\n");

	// Release all virtual memory
	vmem_release(app_context->heap, app_context->heap_full_size);

	app_context->heap_instance = NULL;
	app_context->heap = NULL;
	app_context->heap_inited = 0;
	app_context->heap_current_size = 0;
	app_context->heap_full_size = 0;
}

#endif  // !HEAP_PASSTHROUGH

// Allocation alignment, both backends (system malloc guarantees at least
// max_align_t, which is <= O1HEAP_ALIGNMENT on every target here — but the
// passthrough backend reports no arena, so this value is only ever used with
// the o1heap one).
size_t heap_arena_alignment(void)
{
	return O1HEAP_ALIGNMENT;
}

# O1Heap Virtual Memory Implementation Analysis

**Date:** November 16, 2025

**Status:** Critical Bug Identified - Requires Fix

**Context:** Follow-up to o1heap integration investigation

**Related Commits:**
- SWFModernRuntime: [34d143a](https://github.com/SWFRecomp/SWFModernRuntime/commit/34d143a78660b16edf13ecc2039a7c94ac189df1)
- SWFRecomp-CC: [686e58c](https://github.com/SWFRecomp/SWFRecomp-CC/commit/686e58c89665173710c712c16b53da1bdfa72382)

---

## Executive Summary

This document analyzes the virtual memory-based heap implementation integrated from SWFModernRuntime commit 34d143a. While the integration was successful, **a critical bug was discovered**: reinitializing o1heap after expansion corrupts existing allocations.

**Status:** ⚠️ **CRITICAL BUG FOUND - Needs architectural decision**

---

## Background

### Commit Comparison

On November 16, 2025, LittleCube implemented a virtual memory-based heap approach in SWFModernRuntime (commit 34d143a). This was subsequently integrated into SWFRecomp-CC (commit 686e58c) with the following improvements:

**Changes from Upstream (34d143a):**
- Implemented o1heap foundation with virtual memory
- Reserved 4 GB virtual address space upfront
- Committed 64 MB physical pages initially
- Doubled committed size on heap expansion (64→128→256 MB)
- Stored heap state in `SWFAppContext`

**Additional Changes in SWFRecomp-CC (686e58c):**
- Fixed `getpagesize()` Linux compatibility issue
- Added comprehensive commit documentation
- Verified build process works

**Follow-up Fix (this session):**
- Changed `getpagesize()` to return `int` instead of platform-specific `u32`
- Removed `#ifdef _MSC_VER` guard to match POSIX signature

### Virtual Memory Strategy

The implementation uses a two-level memory approach:

1. **Virtual Memory Layer:**
   - Reserve large virtual address space (4 GB) without physical allocation
   - Commit physical pages on demand using `vmem_commit()`
   - Platform-specific: VirtualAlloc (Windows) or mmap/mprotect (Linux)

2. **O1heap Layer:**
   - Manage allocations within the committed physical pages
   - O(1) constant-time allocation/deallocation
   - Deterministic performance

---

## Critical Bug Discovery

### The Problem: Heap Reinitialization Corrupts Allocations

**Location:** `SWFModernRuntime/src/memory/heap.c:125-127`

```c
// Reinitialize o1heap with the expanded arena
g_app_context->heap_instance = o1heapInit(g_app_context->heap, new_size);
g_app_context->heap_current_size = new_size;
```

### Why This Is Dangerous

Based on investigation of the o1heap source code (`lib/o1heap/o1heap.c:263-312`), calling `o1heapInit()` performs the following operations:

1. **Line 270:** `out = (O1HeapInstance*) base;` - Places heap metadata at arena start
2. **Lines 271-275:** Zeros all bin pointers and metadata structures
3. **Lines 292-300:** Creates a new root fragment spanning the entire capacity
4. **Lines 304-308:** Resets all diagnostics (allocated count, peak usage, etc.)

**Critical Impact:**

When `o1heapInit()` is called again on the same arena after expansion:

- ✅ Virtual memory addresses remain valid (allocations don't move)
- ❌ **All fragment metadata is overwritten** (allocation headers destroyed)
- ❌ **Bin pointers reset to NULL** (heap loses track of allocations)
- ❌ **Fragment chain is rebuilt** (existing allocations orphaned)
- ❌ **Diagnostics reset** (allocated count goes to 0 despite memory in use)

**Result:** Calling `heap_free()` on a pointer allocated before the reinit will:
- Read corrupted fragment metadata (at `pointer - O1HEAP_ALIGNMENT`)
- Trigger assertions in debug builds
- Cause heap corruption in release builds
- Potentially double-free or access invalid memory

### O1Heap Internal Structure

```c
struct O1HeapInstance {
    Fragment* bins[NUM_BINS_MAX];      // 64 pointers on 64-bit systems
    size_t nonempty_bin_mask;          // Bitmap of non-empty bins
    O1HeapDiagnostics diagnostics;     // Capacity, allocated, peak, OOM count
};
```

Each allocation has an associated fragment header:
- Located at `allocation_address - O1HEAP_ALIGNMENT`
- Contains size, next/prev pointers, usage flags
- Used by `o1heapFree()` to return memory to the correct bin

When `o1heapInit()` runs again, it creates a **new** fragment spanning the expanded space, destroying the existing fragment chain.

---

## Technical Investigation Results

### O1Heap API Analysis

**Available Functions:**
```c
O1HeapInstance* o1heapInit(void* base, size_t size);
void* o1heapAllocate(O1HeapInstance* handle, size_t size);
void o1heapFree(O1HeapInstance* handle, void* pointer);
O1HeapDiagnostics o1heapGetDiagnostics(const O1HeapInstance* handle);
size_t o1heapGetMaxAllocationSize(const O1HeapInstance* handle);
bool o1heapDoInvariantsHold(const O1HeapInstance* handle);
```

**Critical Finding:** ❌ **No API exists for extending the heap arena after initialization**

O1heap assumes:
- Arena size is fixed at initialization
- All memory is provided upfront
- No dynamic expansion is needed

### Does O1heap Support Arena Expansion?

**Answer:** ❌ **NO - Not officially supported**

The library design assumes:
1. You know your memory requirements upfront
2. Arena size is fixed for the lifetime of the heap
3. External expansion must be handled by the caller

**Key Quote from Investigation:**
> "Most allocators don't support expanding the arena after initialization. When you call o1heapInit() again, you're likely corrupting the heap state."

---

## Current Implementation Analysis

### Files Modified (Commit 686e58c)

**1. `SWFModernRuntime/include/libswf/swf.h`**
```c
typedef struct O1HeapInstance O1HeapInstance;  // Forward declaration

typedef struct SWFAppContext {
    // ... existing fields ...

    // Heap management fields
    O1HeapInstance* heap_instance;
    char* heap;
    int heap_inited;
    size_t heap_current_size;
    size_t heap_full_size;
} SWFAppContext;
```

**2. `SWFModernRuntime/include/memory/heap.h`**
```c
bool heap_init(SWFAppContext* app_context, size_t initial_size);
void* heap_alloc(size_t size);
void* heap_calloc(size_t num, size_t size);
void heap_free(void* ptr);
void heap_stats(void);
void heap_shutdown(void);
```

**3. `SWFModernRuntime/include/utils.h`**
```c
// Virtual memory functions
char* vmem_reserve(size_t size);
void vmem_commit(char* addr, size_t size);
void vmem_release(char* addr, size_t size);
```

**4. `SWFModernRuntime/src/utils.c`**

Windows implementation:
```c
char* vmem_reserve(size_t size) {
    return (char*)VirtualAlloc(NULL, size, MEM_RESERVE, PAGE_READWRITE);
}

void vmem_commit(char* addr, size_t size) {
    VirtualAlloc(addr, size, MEM_COMMIT, PAGE_READWRITE);
}

void vmem_release(char* addr, size_t size) {
    (void)size;
    VirtualFree(addr, 0, MEM_RELEASE);
}
```

Linux implementation:
```c
char* vmem_reserve(size_t size) {
    void* addr = mmap(NULL, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        return NULL;
    }
    return (char*)addr;
}

void vmem_commit(char* addr, size_t size) {
    mprotect(addr, size, PROT_READ | PROT_WRITE);
}

void vmem_release(char* addr, size_t size) {
    munmap(addr, size);
}
```

**5. `SWFModernRuntime/src/memory/heap.c`**

The problematic expansion code:
```c
void* heap_alloc(size_t size) {
    // ... initialization checks ...

    // Try to allocate from current heap
    void* ptr = o1heapAllocate(g_app_context->heap_instance, size);

    if (ptr != NULL) {
        return ptr;
    }

    // Heap is full - try to expand by committing more pages
    size_t new_size = g_app_context->heap_current_size * 2;

    if (new_size > g_app_context->heap_full_size) {
        fprintf(stderr, "ERROR: Cannot expand heap beyond reserved virtual space\n");
        return NULL;
    }

    // Commit additional pages
    size_t additional_size = new_size - g_app_context->heap_current_size;
    char* commit_addr = g_app_context->heap + g_app_context->heap_current_size;
    vmem_commit(commit_addr, additional_size);

    printf("[HEAP] Expanding: %zu MB -> %zu MB\n",
        g_app_context->heap_current_size / (1024 * 1024),
        new_size / (1024 * 1024));

    // ⚠️ BUG: This destroys existing allocations!
    g_app_context->heap_instance = o1heapInit(g_app_context->heap, new_size);
    g_app_context->heap_current_size = new_size;

    // ... retry allocation ...
}
```

---

## Additional Issues Found

### 1. Missing Error Checking on `vmem_commit()`

**Location:** `heap.c:62, 119`

```c
// No error checking!
vmem_commit(app_context->heap, app_context->heap_current_size);
```

On Linux, `mprotect()` can fail and returns -1 on error. This should be checked.

**Fix Required:**
```c
bool vmem_commit(char* addr, size_t size) {
    #ifdef _MSC_VER
    void* result = VirtualAlloc(addr, size, MEM_COMMIT, PAGE_READWRITE);
    return result != NULL;
    #else
    return mprotect(addr, size, PROT_READ | PROT_WRITE) == 0;
    #endif
}
```

### 2. Redundant Global Variable

**Location:** `heap.c:25`

```c
static SWFAppContext* g_app_context = NULL;
```

The global variable is used to avoid passing `app_context` to every `heap_alloc()` / `heap_free()` call. While this simplifies the API, it:
- Creates hidden coupling
- Makes the code less testable
- Duplicates state (heap info is in both `g_app_context` and the passed `app_context`)

**Trade-off:** API convenience vs. code clarity. Current design is acceptable for a singleton heap manager.

### 3. Platform Consistency: `getpagesize()`

**Fixed in this session:**

Changed from:
```c
// utils.h
#ifdef _MSC_VER
u32 getpagesize();
#endif

// utils.c
u32 getpagesize() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return si.dwPageSize;
}
```

To:
```c
// utils.h
int getpagesize();  // Always declared, matches POSIX signature

// utils.c
int getpagesize() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return (int)si.dwPageSize;
}
```

**Rationale:** Consistent return type across platforms, matches standard POSIX signature, eliminates Linux declaration conflicts.

---

## Why Current Implementation *Might* Work

### Under Specific Conditions

The reinitialization approach could work if:

1. **No old allocations are freed after heap expansion**
   - Application never calls `heap_free()` on pre-expansion pointers
   - Memory is leaked or kept until shutdown

2. **Short allocation lifetimes**
   - Allocations are freed before the next expansion
   - Heap expansion happens during loading screens

3. **Luck**
   - The specific allocation patterns don't trigger the bug
   - Fragment headers happen to be in uncommitted memory regions

### Evidence from Test Files

Found at: `SWFRecomp/tests/prev_frame_swf_4/build/native/heap.c`

The same implementation pattern exists in test builds, suggesting it's been deployed and possibly working in practice. However, this doesn't make it safe—it just means the bug hasn't been triggered yet.

**Hypothesis:** Test content may not be:
- Large enough to trigger expansion
- Complex enough to have long-lived allocations across expansion
- Exercising `heap_free()` on old allocations after expansion

---

## Recommended Solutions

### Option 1: Multiple Independent Heaps (Safest)

**Approach:**
- Keep old heap instances alive when creating new ones
- Track which heap owns each allocation
- On `heap_free()`, identify the owning heap before freeing

**Advantages:**
- ✅ No allocation corruption
- ✅ No memory copying needed
- ✅ Simple to implement
- ✅ Predictable behavior

**Disadvantages:**
- ❌ Small overhead on `free()` (check multiple heaps)
- ❌ Slightly more complex memory management

**Implementation:**
```c
#define MAX_HEAPS 8

typedef struct HeapEntry {
    O1HeapInstance* instance;
    char* base;
    size_t size;
} HeapEntry;

static HeapEntry heaps[MAX_HEAPS];
static int heap_count = 0;

void* heap_alloc(size_t size) {
    // Try to allocate from most recent heap first
    for (int i = heap_count - 1; i >= 0; i--) {
        void* ptr = o1heapAllocate(heaps[i].instance, size);
        if (ptr != NULL) return ptr;
    }

    // All heaps full - create new heap
    if (heap_count < MAX_HEAPS) {
        create_new_heap(heaps[heap_count - 1].size * 2);
        return o1heapAllocate(heaps[heap_count - 1].instance, size);
    }

    return NULL;  // Out of heaps
}

void heap_free(void* ptr) {
    // Find which heap owns this pointer
    for (int i = 0; i < heap_count; i++) {
        if (ptr >= (void*)heaps[i].base &&
            ptr < (void*)(heaps[i].base + heaps[i].size)) {
            o1heapFree(heaps[i].instance, ptr);
            return;
        }
    }

    // Not found - bug!
    assert(0 && "Freeing pointer not allocated by heap");
}
```

**Recommendation:** This approach was suggested in the original investigation document (lines 246-257) and is the safest solution.

---

### Option 2: Over-Allocate Initially (Simplest)

**Approach:**
- Start with a large enough heap that expansion is unlikely
- Accept one-time memory cost

**Advantages:**
- ✅ Simplest implementation
- ✅ No expansion complexity
- ✅ No corruption risk
- ✅ Predictable performance

**Disadvantages:**
- ❌ Uses more memory upfront
- ❌ Doesn't scale to unknown workloads

**Configuration:**
```c
#define DEFAULT_INITIAL_HEAP_SIZE (256 * 1024 * 1024)  // 256 MB instead of 64 MB
```

**Use Case:** Embedded systems with known memory limits, or applications where memory is cheap.

---

### Option 3: Never Free Old Allocations (Document Current Behavior)

**Approach:**
- Accept that allocations from before expansion cannot be freed
- Document this limitation
- Track which allocations are "pre-expansion" and leak them intentionally

**Advantages:**
- ✅ No code changes needed
- ✅ Works with current implementation

**Disadvantages:**
- ❌ Memory leaks grow over time
- ❌ Unpredictable memory usage
- ❌ Not acceptable for long-running applications

**Recommendation:** ❌ **DO NOT USE** - This is a workaround, not a solution.

---

### Option 4: Virtual Memory with Custom Allocator (Advanced)

**Approach:**
- Don't use o1heap for expansion
- Build custom fragment-based allocator that understands virtual memory
- Manage fragment chain across expansions manually

**Advantages:**
- ✅ Full control over expansion
- ✅ No reinitialization needed
- ✅ Can optimize for specific patterns

**Disadvantages:**
- ❌ Significant implementation effort
- ❌ Loses o1heap's determinism guarantees
- ❌ Must maintain custom allocator code

**Recommendation:** Only consider if o1heap proves insufficient.

---

### Option 5: Use Different Allocator (Radical)

**Approach:**
- Switch to an allocator that supports arena expansion
- Examples: dlmalloc, nedmalloc (with custom arena)

**Advantages:**
- ✅ Designed for dynamic arena management
- ✅ Battle-tested implementations

**Disadvantages:**
- ❌ Loses o1heap's O(1) determinism
- ❌ More complex code (thousands of LoC)
- ❌ Doesn't match LittleCube's vision

**Recommendation:** ❌ **NOT RECOMMENDED** - Diverges from project goals.

---

## Comparison Matrix

| Solution | Safety | Performance | Memory Efficiency | Complexity | Recommendation |
|----------|--------|-------------|-------------------|------------|----------------|
| **Multiple Heaps** | ✅ Perfect | ✅ Excellent | ✅ Good | ⚠️ Medium | ✅ **RECOMMENDED** |
| **Over-Allocate** | ✅ Perfect | ✅ Excellent | ⚠️ Fair | ✅ Low | ✅ **ACCEPTABLE** |
| **Never Free** | ❌ Broken | ✅ Excellent | ❌ Poor | ✅ Low | ❌ **AVOID** |
| **Custom Allocator** | ⚠️ Depends | ⚠️ Depends | ✅ Good | ❌ High | ⚠️ **FUTURE** |
| **Different Allocator** | ✅ Good | ⚠️ Fair | ✅ Good | ❌ High | ❌ **AVOID** |

---

## Implementation Plan

### Immediate Action Required

**Decision Point:** Choose between Option 1 (Multiple Heaps) or Option 2 (Over-Allocate)

Both are safe and effective. The choice depends on:
- **Memory constraints:** Option 2 uses more memory upfront
- **Workload predictability:** Option 2 better for known sizes
- **Scalability:** Option 1 handles arbitrary sizes
- **Complexity tolerance:** Option 2 is simpler

**Recommendation:** Implement **Option 1 (Multiple Heaps)** because:
1. Scales to unknown workloads
2. More efficient memory usage
3. Matches the original investigation recommendation
4. Only slightly more complex than current implementation

### Phase 1: Fix the Bug (Option 1 Implementation)

**Estimated Time:** 1-2 days

**Changes Required:**

1. **Update heap.c data structures:**
```c
#define MAX_HEAPS 8

typedef struct HeapEntry {
    O1HeapInstance* instance;
    char* base;
    size_t size;
} HeapEntry;

static HeapEntry heaps[MAX_HEAPS];
static int heap_count = 0;
```

2. **Rewrite heap_init():**
```c
bool heap_init(SWFAppContext* app_context, size_t initial_size) {
    // Reserve virtual memory once
    app_context->heap_full_size = DEFAULT_FULL_HEAP_SIZE;
    app_context->heap = vmem_reserve(app_context->heap_full_size);

    // Create first heap
    return create_heap(initial_size);
}
```

3. **Implement create_heap() helper:**
```c
static bool create_heap(size_t size) {
    if (heap_count >= MAX_HEAPS) {
        fprintf(stderr, "ERROR: Maximum heaps reached\n");
        return false;
    }

    // Calculate offset in virtual memory
    size_t offset = 0;
    for (int i = 0; i < heap_count; i++) {
        offset += heaps[i].size;
    }

    char* base = g_app_context->heap + offset;

    // Commit physical pages
    if (!vmem_commit(base, size)) {
        fprintf(stderr, "ERROR: Failed to commit memory\n");
        return false;
    }

    // Initialize o1heap
    O1HeapInstance* instance = o1heapInit(base, size);
    if (instance == NULL) {
        fprintf(stderr, "ERROR: Failed to initialize heap\n");
        return false;
    }

    // Store heap entry
    heaps[heap_count].instance = instance;
    heaps[heap_count].base = base;
    heaps[heap_count].size = size;
    heap_count++;

    return true;
}
```

4. **Update heap_alloc():**
```c
void* heap_alloc(size_t size) {
    // Try most recent heap first (likely to have free space)
    for (int i = heap_count - 1; i >= 0; i--) {
        void* ptr = o1heapAllocate(heaps[i].instance, size);
        if (ptr != NULL) return ptr;
    }

    // All heaps full - create new one
    size_t new_size = heaps[heap_count - 1].size * 2;
    if (create_heap(new_size)) {
        return o1heapAllocate(heaps[heap_count - 1].instance, size);
    }

    return NULL;
}
```

5. **Update heap_free():**
```c
void heap_free(void* ptr) {
    if (ptr == NULL) return;

    // Find owning heap
    for (int i = 0; i < heap_count; i++) {
        if (ptr >= (void*)heaps[i].base &&
            ptr < (void*)(heaps[i].base + heaps[i].size)) {
            o1heapFree(heaps[i].instance, ptr);
            return;
        }
    }

    // Invalid pointer
    fprintf(stderr, "ERROR: heap_free() called with invalid pointer\n");
    assert(0);
}
```

6. **Update vmem_commit() to return bool:**
```c
bool vmem_commit(char* addr, size_t size);  // Return success/failure
```

**Testing:**
- Run all existing tests
- Add specific test for heap expansion
- Verify with Valgrind (no leaks, no corruption)
- Test freeing allocations across heap boundaries

---

### Phase 2: Documentation and Hardening

**Estimated Time:** 1 day

1. Update `heap.h` documentation
2. Add heap expansion logging
3. Document memory usage patterns
4. Add invariant checking with `o1heapDoInvariantsHold()`
5. Update status documentation

---

### Phase 3: Performance Validation

**Estimated Time:** 1-2 days

1. Benchmark allocation/free performance
2. Compare with system malloc
3. Measure heap expansion overhead
4. Profile real Flash content
5. Optimize heap selection strategy if needed

---

## Questions for LittleCube

1. **Are you aware of the reinitialization issue?**
   - Has it caused problems in practice?
   - Is there something we're missing that makes it safe?

2. **Preferred solution:**
   - Option 1 (Multiple Heaps) - safer, scalable
   - Option 2 (Over-Allocate) - simpler, uses more memory

3. **Target memory budget:**
   - What's acceptable initial heap size?
   - What's the maximum total memory budget?

4. **Heap expansion scenarios:**
   - Have you observed expansions in real content?
   - Are expansions typically during loading or during gameplay?

---

## References

**Related Documents:**
- [O1Heap Integration Investigation](o1heap-integration-investigation.md) - Original analysis
- [O1Heap GitHub](https://github.com/pavel-kirienko/o1heap) - Upstream project
- [O1Heap Source](../SWFModernRuntime/lib/o1heap/o1heap.c) - Local implementation

**Relevant Source Files:**
- `SWFModernRuntime/src/memory/heap.c` - Current implementation
- `SWFModernRuntime/src/utils.c` - Virtual memory functions
- `SWFModernRuntime/include/libswf/swf.h` - Heap state in SWFAppContext
- `SWFModernRuntime/lib/o1heap/o1heap.c` - O1heap implementation (lines 263-312)

**Investigation Evidence:**
- `SWFRecomp/tests/prev_frame_swf_4/build/native/heap.c` - Test implementation with same pattern

---

## Conclusion

While the virtual memory integration from commit 34d143a/686e58c was architecturally sound, **the heap expansion implementation has a critical bug** that corrupts allocations when `o1heapInit()` is called again.

**Immediate Action Required:**
1. ✅ `getpagesize()` return type fixed (completed in this session)
2. ⚠️ **Heap reinitialization bug requires architectural decision**
3. ⚠️ Missing error checking on `vmem_commit()` should be added

**Recommended Path Forward:**
- Implement **Option 1: Multiple Independent Heaps**
- Estimated effort: 2-4 days (implementation + testing)
- Provides safe, scalable solution
- Matches original investigation recommendations

The multiple heap approach was already recommended in the original investigation document (November 11, 2025, lines 246-265) but was not implemented in the initial integration. This analysis confirms that recommendation and provides the implementation details needed to fix the bug.

---

**Document Status:** Complete
**Next Steps:** Await architectural decision from LittleCube
**Last Updated:** November 16, 2025

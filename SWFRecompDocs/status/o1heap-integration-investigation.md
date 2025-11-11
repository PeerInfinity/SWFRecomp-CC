# O1Heap Integration Investigation

**Date:** November 11, 2025
**Status:** Investigation Complete - Ready for Implementation
**Requested By:** LittleCube

## Executive Summary

This document investigates the feasibility of integrating the o1heap memory allocator into SWFRecomp-CC to improve performance by reducing malloc overhead through pre-allocated memory pools.

**Verdict:** ✅ **HIGHLY FEASIBLE AND RECOMMENDED**

O1heap is an excellent fit for this project's needs. The integration would be straightforward, and the benefits align well with the performance goals for Flash recompilation.

---

## Background

### The Problem

Current memory allocation patterns in SWFRecomp-CC involve many small, frequent malloc/free operations:

- Property name strings (10-50 bytes each)
- Function register arrays (allocated per function call)
- Temporary argument arrays (allocated per function/constructor call)
- Enumeration linked list nodes
- Individual variable structures

This creates significant malloc overhead, especially for Flash content with heavy ActionScript execution.

### Proposed Solution

LittleCube proposed integrating the o1heap allocator with the following approach:

1. Pre-allocate a large memory arena (e.g., 32 MB)
2. Use o1heap to manage allocations from this arena
3. Double the arena size if more memory is needed
4. Eliminate per-allocation malloc overhead

This differs from n64recomp's virtual memory approach (which allocates on-demand) in favor of pre-allocation.

---

## Current Memory Allocation Analysis

### Allocation Sites

I identified **23 distinct malloc/calloc/realloc sites** in the core runtime:

#### High-Frequency Allocations (Prime Candidates for o1heap)

**Property Names** (`object.c:303`)
- Size: Variable (10-50 bytes typical)
- Frequency: Every property creation
- Lifetime: Until object is released
- Benefit: **HIGH** - Many small allocations, improved locality

**Function Registers** (`action.c` - 5 sites)
- Size: `register_count × sizeof(ActionVar)` (~32 bytes each)
- Frequency: Every function call
- Lifetime: Duration of function execution
- Benefit: **HIGH** - Predictable size, very short-lived

**Argument Arrays** (`action.c:5967, 6488`)
- Size: Up to 16 arguments × `sizeof(ActionVar)`
- Frequency: Every function/constructor call
- Lifetime: Very short (duration of call)
- Benefit: **HIGH** - Fixed max size, extremely high frequency

**Enumeration Nodes** (`action.c:1102, 1240`)
- Size: `sizeof(EnumeratedName)` or `sizeof(PropList)`
- Frequency: During for-in loops and property enumeration
- Lifetime: Duration of enumeration
- Benefit: **MEDIUM** - Temporary linked lists

**Individual Variables** (`variables.c`)
- Size: `sizeof(ActionVar)` (~32 bytes)
- Frequency: Variable creation
- Lifetime: Variable lifetime
- Benefit: **MEDIUM** - Fixed size, good for slab allocator

#### Lower Priority Allocations

**Object/Array Main Structures**
- Size: Variable (with capacity-based arrays)
- Frequency: Object/array creation
- Lifetime: Reference-counted
- Benefit: **LOW** - Already well-managed by reference counting

**String Concatenation Results**
- Size: Unpredictable
- Lifetime: Variable
- Benefit: **LOW** - Unpredictable size makes pooling less effective

### Memory Management Infrastructure

The codebase has a mature reference-counting system:

- Zero memory leaks (Valgrind verified in Experiment #4)
- Clear ownership semantics
- Recursive release for nested structures
- ~400 lines of well-tested code

**Key insight:** Reference counting works at a different level than heap allocation. O1heap would replace malloc/free at the allocation layer while reference counting continues to manage object lifetimes.

---

## O1Heap Characteristics

### What is O1Heap?

O1heap is a constant-complexity deterministic memory allocator designed for hard real-time embedded systems.

**GitHub:** https://github.com/pavel-kirienko/o1heap
**License:** MIT
**Size:** <500 lines of C99/C11 code
**Files:** Just 2 files (`o1heap.c` and `o1heap.h`)

### Key Features

#### Performance
- **O(1) allocation and deallocation** - constant worst-case execution time
- ~165 cycles per allocation on Cortex M4
- Deterministic behavior (no worst-case surprises)

#### Memory Management
- Requires a pre-allocated memory arena (provided by caller)
- Rounds allocations to power-of-two sizes
- Modified half-fit algorithm
- Per-allocation overhead = 4× pointer width (16 bytes on 64-bit systems)

#### Quality
- MISRA C:2012 compliant (with documented necessary deviations)
- Thoroughly tested
- Used in production embedded systems
- Simple codebase (<500 LoC) - easy to validate

#### API
```c
O1HeapInstance* o1heapInit(void* base, size_t size);
void* o1heapAllocate(O1HeapInstance* handle, size_t size);
void o1heapFree(O1HeapInstance* handle, void* pointer);
bool o1heapDoInvariantsHold(const O1HeapInstance* handle);
```

### Limitations

1. **Power-of-Two Sizing**: Allocations rounded up to next power of two
   - This can waste memory but provides predictability
   - For SWF runtime, this is acceptable given the benefits

2. **Thread Safety**: Not thread-safe (needs external locking)
   - Not a concern: SWF runtime is single-threaded

3. **Pre-allocation Required**: Must provide memory arena upfront
   - This aligns perfectly with LittleCube's vision

---

## Feasibility Assessment

### Technical Compatibility: ✅ EXCELLENT

| Aspect | Compatibility | Notes |
|--------|--------------|-------|
| **Language** | ✅ Perfect | Both o1heap and runtime are pure C |
| **Licensing** | ✅ Perfect | MIT license compatible with project |
| **Platform** | ✅ Perfect | Portable across all architectures |
| **Size** | ✅ Perfect | <500 LoC, minimal binary size impact |
| **Dependencies** | ✅ Perfect | Zero dependencies |
| **Thread Safety** | ✅ N/A | Runtime is single-threaded |

### Integration Approach: ✅ STRAIGHTFORWARD

The project already has a `lib/` directory pattern:
- `SWFModernRuntime/lib/SDL3/`
- `SWFModernRuntime/lib/c-hashmap/`
- `SWFModernRuntime/lib/zlib/`
- `SWFModernRuntime/lib/lzma/`

**Recommended Integration:**
1. Add `SWFModernRuntime/lib/o1heap/` directory
2. Copy `o1heap.c` and `o1heap.h` (just 2 files!)
3. Update `CMakeLists.txt` to include o1heap source
4. Create wrapper layer in `SWFModernRuntime/src/memory/` (optional)

**No git submodule needed** - o1heap is small enough to vendor directly (standard pattern for this project).

### Performance Benefits: ✅ SIGNIFICANT EXPECTED

#### Predicted Performance Improvements

1. **Reduced Malloc Overhead**
   - Current: System malloc for every small allocation
   - With o1heap: ~165 cycles for allocation
   - Expected: 2-10× speedup on allocation-heavy workloads

2. **Improved Cache Locality**
   - Objects allocated from contiguous arena
   - Better CPU cache utilization
   - Expected: 10-30% speedup on object-heavy operations

3. **Deterministic Performance**
   - No worst-case malloc behavior
   - Consistent frame times
   - Reduced stuttering

#### Flash vs N64 Memory Comparison

LittleCube noted: "Flash recomps will unfortunately need more memory than n64 recomps"

**Why Flash needs more memory:**
- Dynamic objects/arrays vs static N64 game structures
- ActionScript variables and functions
- Property names stored as strings
- Prototype chains
- Event handlers

**Estimated memory needs:**
- **Light Flash content:** 8-16 MB
- **Medium Flash games:** 32-64 MB
- **Heavy Flash games with mods:** 128-256 MB

**Doubling strategy is appropriate:**
- Start: 32 MB (LittleCube's suggestion)
- First expansion: 64 MB
- Second expansion: 128 MB
- Third expansion: 256 MB

### Risk of Stuttering on Expansion: ⚠️ MODERATE

LittleCube noted: "It's possible that if we go with that approach, then flash recomps with a lot of mods installed will stutter when expanding the space"

**Analysis:**

1. **When does expansion happen?**
   - When o1heap runs out of space in current arena
   - This is **predictable** - happens at arena exhaustion

2. **Cost of expansion:**
   - Allocate new larger arena: ~1ms for 256MB (depends on system)
   - Migrate existing allocations: **THIS IS THE PROBLEM**
   - O1heap cannot move existing allocations

3. **Solutions:**

   **Option A: Over-allocate initially** (Recommended)
   - Start with 64 MB instead of 32 MB
   - Memory is cheap on modern systems
   - Reduces probability of expansion

   **Option B: Multiple heaps**
   - Keep old heap alive, create new heap
   - No migration needed
   - Small cost: need to check multiple heaps on free
   - Recommended approach for production

   **Option C: Virtual memory mapping** (Advanced)
   - Reserve large address space (e.g., 1 GB)
   - Only commit pages as needed
   - Eliminates expansion problem entirely
   - Platform-specific (mmap on Linux, VirtualAlloc on Windows)
   - This is similar to n64recomp's approach

**Recommendation:** Start with Option B (multiple heaps) - simplest and most reliable.

---

## Implementation Plan

### Phase 1: Basic Integration (1-2 days)

**Goal:** Get o1heap integrated and working with simple allocations

1. **Add o1heap to project**
   ```bash
   mkdir -p SWFModernRuntime/lib/o1heap
   cd SWFModernRuntime/lib/o1heap
   # Download o1heap.c and o1heap.h from GitHub
   ```

2. **Update CMakeLists.txt**
   ```cmake
   set(CORE_SOURCES
       # ... existing sources ...
       ${PROJECT_SOURCE_DIR}/lib/o1heap/o1heap.c
   )
   ```

3. **Create memory manager wrapper** (`SWFModernRuntime/src/memory/heap.c`)
   ```c
   // Wrapper API:
   void heap_init(void);
   void* heap_alloc(size_t size);
   void heap_free(void* ptr);
   void heap_stats(void);
   ```

4. **Initial configuration**
   - Start with 32 MB arena (LittleCube's suggestion)
   - Single heap initially
   - Add instrumentation to track allocation patterns

### Phase 2: Integration with Object System (2-3 days)

**Goal:** Replace high-frequency allocations

**Priority 1: Property Names** (`object.c:303`)
- Replace `malloc()` with `heap_alloc()`
- Replace `free()` with `heap_free()`
- Test with existing object tests

**Priority 2: Function Registers** (`action.c` - 5 sites)
- Replace `calloc()` calls
- Consider adding a register pool for common sizes

**Priority 3: Argument Arrays** (`action.c:5967, 6488`)
- Replace `malloc()` calls
- Consider pre-allocated argument buffers (max 16 args)

**Testing:**
- Run all existing tests
- Valgrind to verify no memory leaks
- Add heap statistics logging

### Phase 3: Multi-Heap Support (1-2 days)

**Goal:** Eliminate expansion stuttering

1. **Implement heap chain**
   - Keep list of heaps
   - When current heap exhausted, create new one
   - On free, check which heap owns the pointer

2. **Size strategy**
   - Heap 0: 32 MB (initial)
   - Heap 1: 64 MB (first expansion)
   - Heap 2: 128 MB (second expansion)
   - etc.

3. **Add heap statistics**
   - Track which heap owns what
   - Log heap usage patterns
   - Identify optimal starting size

### Phase 4: Optimization (2-3 days)

**Goal:** Fine-tune for maximum performance

1. **Analyze allocation patterns**
   - Add logging to track allocation sizes
   - Identify most common sizes
   - Optimize for hot paths

2. **Consider specialized pools**
   - Small string pool (8-64 bytes)
   - Register pool (common register counts)
   - Variable pool (sizeof(ActionVar))

3. **Benchmark comparison**
   - Compare malloc vs o1heap performance
   - Measure memory usage
   - Profile real Flash content

### Phase 5: Production Hardening (1-2 days)

**Goal:** Make it production-ready

1. **Error handling**
   - Handle OOM gracefully
   - Provide diagnostics
   - Fallback to system malloc if needed

2. **Configuration options**
   - Compile-time option to use system malloc
   - Runtime option for initial heap size
   - Environment variable overrides

3. **Documentation**
   - Document heap architecture
   - Add usage guidelines
   - Performance tuning guide

---

## Memory Usage Estimates

### Current System (System Malloc)

**Per-allocation overhead:** ~16-32 bytes (depends on malloc implementation)

**Example object with 10 properties:**
- ASObject struct: 32 bytes
- Property array: 10 × 40 bytes = 400 bytes
- Property names: 10 × (20 bytes average + 32 malloc overhead) = 520 bytes
- **Total: ~1000 bytes** (48% overhead from malloc)

### With O1Heap

**Per-allocation overhead:** 16 bytes (64-bit systems)

**Same object:**
- ASObject struct: 32 bytes (rounded to 32)
- Property array: 400 bytes (rounded to 512)
- Property names: 10 × (20 bytes rounded to 32 + 16 overhead) = 480 bytes
- **Total: ~1040 bytes** (29% overhead, but better locality)

**Trade-off:** Slightly more memory (power-of-two rounding) but much faster allocations and better cache behavior.

### Overall Memory Savings

For typical Flash content:
- **Small content:** 32 MB heap sufficient (current estimate)
- **Medium content:** 64 MB heap sufficient
- **Large content with mods:** 128-256 MB heap

These are reasonable for modern systems (even embedded devices have gigabytes of RAM).

---

## Comparison with N64Recomp Approach

| Aspect | N64Recomp (Virtual Memory) | Proposed (O1Heap Pre-allocation) |
|--------|---------------------------|----------------------------------|
| **Strategy** | Allocate on demand | Pre-allocate large arena |
| **Performance** | Page fault overhead on first access | No page faults |
| **Memory efficiency** | Only allocates what's needed | Allocates upfront |
| **Predictability** | Page faults unpredictable | Deterministic |
| **Complexity** | Platform-specific virtual memory | Simple portable allocator |
| **Expansion cost** | Free (just map more pages) | Need new heap (or remap) |

**LittleCube's preference:** Pre-allocation (o1heap approach)

**Reasoning:** "I don't trust that method being more performant lol"

**My assessment:** LittleCube is correct for this use case:
- Flash workloads are allocation-heavy
- Deterministic performance is valuable
- Memory is plentiful on target platforms
- Simpler implementation

**Hybrid approach (future consideration):**
- Use virtual memory to reserve address space
- Use o1heap to manage allocations within that space
- Get best of both worlds

---

## Risks and Mitigations

### Risk 1: Power-of-Two Waste

**Risk:** Rounding to power-of-two wastes memory

**Mitigation:**
- Most allocations are small (waste is minimal)
- Cache benefits offset memory cost
- Can track actual waste with instrumentation
- If problematic, can implement size classes

### Risk 2: Expansion Stuttering

**Risk:** Creating new heap causes frame drops

**Mitigation:**
- Multi-heap approach (keep old heaps alive)
- Over-allocate initial heap
- Virtual memory approach (future)
- Pre-expand during loading screens

### Risk 3: Integration Bugs

**Risk:** Memory management bugs during integration

**Mitigation:**
- Extensive testing with Valgrind
- Incremental integration (one allocation site at a time)
- Keep system malloc as compile-time fallback
- Comprehensive test suite already exists

### Risk 4: Platform Compatibility

**Risk:** O1heap behavior varies on different platforms

**Mitigation:**
- O1heap is designed for portability
- Test on Linux, Windows, macOS
- Simple codebase (<500 LoC) easy to debug

---

## Recommendations

### Primary Recommendation: ✅ PROCEED WITH INTEGRATION

O1heap is an excellent fit for SWFRecomp-CC:

1. **Technical fit:** Pure C, MIT license, zero dependencies
2. **Performance:** Addresses the malloc overhead problem
3. **Integration:** Straightforward (~1 week of work)
4. **Risk:** Low, with clear mitigation strategies
5. **Alignment:** Matches LittleCube's vision perfectly

### Recommended Configuration

**Initial Setup:**
- Start with 32 MB heap (as LittleCube suggested)
- Multi-heap expansion strategy
- Double size on expansion (32 → 64 → 128 → 256 MB)

**Integration Strategy:**
- Phase 1-2: Basic integration (3-5 days)
- Phase 3: Multi-heap support (1-2 days)
- Phase 4-5: Optimization and hardening (3-5 days)
- **Total effort: ~2 weeks**

**Testing:**
- All existing tests must pass
- Valgrind verification
- Performance benchmarking
- Real Flash content testing

### Alternative Approaches (for comparison)

**Alternative 1: Object Pools**
- Create specialized pools for common objects
- More code than o1heap
- Less general-purpose
- **Verdict:** O1heap is simpler and more general

**Alternative 2: Arena Allocator (custom)**
- Write custom arena allocator
- More control, less code
- No deterministic guarantees
- **Verdict:** O1heap is battle-tested and deterministic

**Alternative 3: jemalloc / mimalloc**
- Use modern malloc replacement
- Heavier weight (thousands of LoC)
- Not deterministic
- **Verdict:** Overkill for this use case

**Alternative 4: Virtual Memory (n64recomp approach)**
- Reserve large address space
- Commit pages on demand
- Platform-specific
- **Verdict:** More complex, LittleCube prefers pre-allocation

---

## Next Steps

### Immediate Actions

1. **Get approval from LittleCube**
   - Confirm 32 MB initial size
   - Confirm multi-heap expansion strategy
   - Confirm priority of allocation sites

2. **Set up integration branch**
   - Create feature branch
   - Add o1heap to lib/
   - Update CMakeLists.txt

3. **Create tracking issue**
   - Document implementation plan
   - Track progress
   - Share updates

### Success Criteria

**Phase 1 (Integration):**
- [ ] O1heap integrated into build
- [ ] All existing tests pass
- [ ] Valgrind shows zero leaks

**Phase 2 (Performance):**
- [ ] Measurable performance improvement on allocation-heavy workloads
- [ ] No regression on existing content
- [ ] Memory usage within expected bounds

**Phase 3 (Production):**
- [ ] Multi-heap expansion working
- [ ] No stuttering on expansion
- [ ] Comprehensive documentation

---

## Conclusion

Integrating o1heap into SWFRecomp-CC is **highly feasible and recommended**. The allocator is a perfect match for the project's needs:

- **Addresses the problem:** Reduces malloc overhead for frequent small allocations
- **Aligns with vision:** Pre-allocated arena with expansion matches LittleCube's design
- **Low risk:** Battle-tested allocator, incremental integration, comprehensive testing
- **High value:** Significant performance improvements expected
- **Simple:** <500 LoC, 2 files, ~2 weeks of work

The integration can be done incrementally with clear success criteria at each phase. The multi-heap expansion strategy eliminates the stuttering risk while maintaining simplicity.

**Recommendation: Proceed with implementation.**

---

## References

- O1heap GitHub: https://github.com/pavel-kirienko/o1heap
- O1heap Documentation: https://github.com/pavel-kirienko/o1heap/blob/master/README.md
- SWFRecomp Memory Analysis: See "Current Memory Allocation Analysis" section above
- Reference Counting System: `SWFRecompDocs/status/experiment-04-refcount-poc-results.md`

---

**Document Status:** Complete
**Last Updated:** November 11, 2025
**Next Review:** After LittleCube approval

# SWFRecomp-CC Upstream/Downstream Merge Plan

**Date:** December 4, 2025
**Last Updated:** March 9, 2026

**Author:** Claude (via PeerInfinity/SWFRecomp-CC)

**Target Repositories:**

- Upstream: [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp)
- Upstream: [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime)
- This repo: [PeerInfinity/SWFRecomp-CC](https://github.com/PeerInfinity/SWFRecomp-CC)

---

## UPDATE: March 17, 2026

### Upstream Objects & Functions PRs — GC Implementation Added

LittleCube has added **garbage collection** to the runtime PR (commit `f02311c`, March 26, 2026). This was the hardest remaining task before the PR could merge.

#### GC Architecture (SWFModernRuntime `f02311c`)
- **Concurrent collector**: Separate free thread checks objects with decremented refcounts
- **Cycle detection**: If refcount > 0 after decrement, walks references to detect unreachable cycles; frees entire cycle if all members are unreachable
- **Read-write locks**: New locking API (`LOCK_READ`/`LOCK_WRITE` macros) — both threads can read simultaneously, only one can write. Every ASObject has its own lock (`OBJ_LOCK_READ`/`OBJ_LOCK_WRITE`)
- **ASObject struct expanded**: `reached`/`used`/`blocked`/`freed` flags, `SwapVector` for `neighbors`/`blocked_list`, temporary refcount, mutex lock
- **Stack integration**: `PUSH_OBJ()` now calls `retainObject()`, `POP()` now calls `releaseObject()` for objects — refcounting woven into stack operations
- **`object_free_queue`**: rbtree with u64 keys (object pointers) for pending-free set
- **SwapVector**: New data structure (`src/apis/swap-vector/swap_vector.c`) for GC tracking
- **ActionVar restructured**: Union now separates function data (func, args) from string data (str_size, string_id, owns_memory)

#### SWFRecomp `c7348af` (March 26, 2026)
- Removes `arg1`-`arg6` from initial strings (no longer needed)
- Adds `ACTION_STACK_VALUE_NULL = 2` and `ACTION_STACK_VALUE_UNDEFINED = 3` to enum
- Recompiler emits `PUSH_NULL()` and `PUSH_UNDEFINED()`

#### Updated PR Status

**SWFRecomp PR #4** — now 6 commits (was 5):
- Previous 5 commits (objects and functions infrastructure)
- `c7348af` - remove arg initial strings, add null/undefined push values

**SWFModernRuntime PR #3** — now 21 commits (was 14):
- Previous 14 commits (objects and functions infrastructure)
- `f02311c` - **first attempt at garbage collection** (concurrent GC with cycle detection)
- `f1d2da9` - move free thread functions to separate file (`free_thread.c`/`free_thread.h`)
- `e2db29b` - cleanup
- `6f256b2` - **fix free mechanism bug** — edge case with aliased objects in dense cycles
- `aa3fa7f` - cleanup
- `18589c8` - cleanup, manage scope objects, fix Math.abs
- `21439f1` - **implement prototype support** — `STR_ID_PROTOTYPE`/`STR_ID_PROTO` string IDs, `getPropertyWithPrototype()` returns `ASProperty*` with string_id lookup, `RuntimeFunc.constructor` flag distinguishes constructors from methods
- `c8aec0d` - **lazy prototype instantiation** — prototypes created on first access (not at function definition), new `getOrCreateProperty()` with `bool* created` flag, `rbtree_get_or_insert()` tracks creation state

#### LittleCube's Pre-Merge TODO (Updated)

| Task | Status |
|------|--------|
| Remaining primitive types (Array, String, Number) | In progress |
| Arena optimization for rbtree | Not started |
| Refcount/free mechanism | **In progress** (`f02311c`, `f1d2da9`) |

---

## UPDATE: March 9, 2026

### Upstream Objects & Functions PRs (In Progress)

LittleCube and PeerInfinity have opened PRs implementing **objects and functions** in the upstream repositories. These are currently **Open** (not yet merged to master):

#### SWFRecomp PR #4: `feature/objects-and-functions`
- **Status:** Open
- **Branch:** `PeerInfinity/SWFRecomp:feature/objects-and-functions` → `master`
- **5 commits** (as of March 9):
  - `98977fd` - Add minimal object and function opcode support
  - `37192d3` - Mark unsupported opcodes in minimal build
  - `4e93e6c` - Add back arithmetic, comparison, string, and variable opcodes
  - `8da99f2` - major prune/rework (LittleCube)
  - `8742c6a` - implement bulk of objects and functions (LittleCube)

**Key changes:**
- ~25 new opcodes: DefineFunction/DefineFunction2, CallFunction/CallMethod, GetMember/SetMember, NewObject/NewMethod, InstanceOf, Extends, etc.
- String deduplication via `string_to_id` map — every string gets a unique ID
- Per-function output streams (`func_id_to_stream`) for isolated recompilation of nested scopes
- Parameter naming uses `arg1`–`arg6` with string IDs tracked per function
- `initial_strings.hpp`: pre-defines `"_global"`, `"Object"`, `"Math"`, `"this"`, `"length"`, etc.
- `Constant` struct for constant pool indexing

#### SWFModernRuntime PR #3: `feature/objects-and-functions`
- **Status:** Open
- **Branch:** `PeerInfinity/SWFModernRuntime:feature/objects-and-functions` → `master`
- **14 commits** (as of March 9, iterative refinements), key ones:
  - `bfdbf3c` - Add object/function opcode support and heap refactoring
  - `f409c12` - major prune/rework (LittleCube)
  - `96f3ac8` - implement the bulk of objects and functions (LittleCube)

**Key changes:**
- Stack expansion: variables = 24 bytes, functions = 40 bytes. `PUSH_FUNC` macro
- **Red-black tree** (`lib/rbtree`) for property storage on objects
- `Function2Ptr` typedef: `(SWFAppContext*, ActionVar*, u32, ActionVar*, void*)` — matches our signature
- Scope chain: `getPropertyInThisScope()`, `actionDefineLocal`/`actionDefineLocal2`
- Runtime API modules: `Math.c`/`Object.c` with native C functions registered via `RuntimeFunc` table
- **String interning**: enum-based string IDs replace raw string comparisons
- `_global` object as root scope — similar concept to ours
- Constructor support: `actionNewObject`, `actionNewMethod`, `new_Object()` built-in
- `initial_strings_decls.h` / `initial_strings_defs.h` for pre-defined string IDs

#### Architectural Comparison: Upstream vs Our Fork

| Aspect | Upstream (Objects/Functions PR) | Our Fork |
|--------|--------------------------------|----------|
| Property storage | Red-black tree (`lib/rbtree`) | Linear `properties` array on ASObject |
| String handling | Enum-based string IDs (compile-time interning) | Raw strings with strcmp |
| Function struct | Stack-embedded (40 bytes via PUSH_FUNC) | Separate `ASFunction` struct with prototype_obj, captured_scope, base_clip |
| Scope chain | `getPropertyInThisScope()` | WITH scope stack + function scope + global |
| Object/Function relation | Unified ("functions are objects") | Separate structs (ASObject vs ASFunction) — **different structs, never cast** |
| Memory management | Red-black tree + refcount (in progress) | Reference counting on ASObject/ASArray, manual lifecycle |
| Prototype chains | `getPropertyWithPrototype()` with string_id lookup (`21439f1`) | Full __proto__ chain traversal, __constructor__, super depth tracking |
| Closure semantics | Not yet visible in PR | Full base_clip capture, SWF5 vs SWF6+ differentiation |
| Test coverage | Basic (included in PR) | 616 Ruffle tests + 115 hand-written tests |

#### Impact on Upstream Contribution Strategy (Phases 5-8)

The upstream objects/functions PR significantly changes our upstream contribution plans:

1. **Object system (Phase 5):** Upstream is building their own object system with fundamentally different architecture (rbtree vs linear array, string IDs vs raw strings). **Direct merge of our `object.h`/`object.c` is no longer viable.** Instead, we should:
   - Wait for upstream's objects/functions PR to merge
   - Identify gaps in their implementation vs ours (prototype chains, closures, super, etc.)
   - Contribute incremental additions using their architecture

2. **Action implementations (Phase 7):** Our opcode implementations assume our object system's API. They would need to be **rewritten against upstream's API** (rbtree properties, string IDs, etc.) rather than cherry-picked.

3. **Tests (Phase 8):** Test SWFs are architecture-independent and can still be contributed directly.

4. **New recommended approach:** Instead of porting our code upstream, we should:
   - Help review/test the objects-and-functions PRs
   - Contribute AVM1 semantics knowledge (prototype chains, scope rules, closure behavior, super keyword, etc.)
   - Port specific behavioral fixes and edge case handling as incremental PRs against their new architecture

### New Master Commits Since December 20, 2025

#### SWFRecomp/SWFRecomp

| Date | SHA | Description | Priority |
|------|-----|-------------|----------|
| Jan 11, 2026 | `297c920` | fix false hole issue | MEDIUM |
| Jan 12, 2026 | `2400abd` | update README | LOW |
| Feb 6, 2026 | `7f53538` | update README | LOW |
| Feb 6, 2026 | `293fe5f` | update README | LOW |

#### SWFRecomp/SWFModernRuntime

| Date | SHA | Description | Priority |
|------|-----|-------------|----------|
| Feb 6, 2026 | `9b6f2c0` | comment update | LOW |

No critical architectural changes since December 20, 2025 on master. The `297c920` ("fix false hole issue") may be worth investigating for the recompiler.

---

## UPDATE: December 20, 2025

### Critical Upstream Changes Since Original Document

Since this document was created on December 4, 2025, **significant architectural changes** have been made upstream that affect the merge strategy:

#### New Commits - SWFRecomp/SWFRecomp

| Date | SHA | Description | Priority |
|------|-----|-------------|----------|
| **Dec 20** | `06506c3` | **refactor stack and sp into app_context** | **CRITICAL** |
| Dec 12 | `44324d8` | update README | LOW |
| Dec 12 | `620c30f` | fix passing app_context to tagInit | HIGH |

#### New Commits - SWFRecomp/SWFModernRuntime

| Date | SHA | Description | Priority |
|------|-----|-------------|----------|
| **Dec 20** | `39ec6ad` | **refactor stack and sp into app_context** | **CRITICAL** |
| Dec 12 | `b682cd2` | pass app_context to tagInit | HIGH |
| Dec 5 | `669e40c` | if guard bitmap_transfer | LOW |

### Impact on This Repository

1. **app-context-migration-plan.md is now OBSOLETE** - The migration plan created in this repo on Dec 4 anticipated adopting the `app_context` convention. Upstream has now completed this refactoring AND gone further by moving `stack` and `sp` into the `SWFAppContext` structure.

2. **Function signatures have fundamentally changed** - All action functions upstream now use:
   ```c
   // OLD (what we planned):
   void actionAdd(SWFAppContext* app_context, char* stack, u32* sp);

   // NEW (upstream Dec 20):
   void actionAdd(SWFAppContext* app_context);
   // stack and sp are now accessed via app_context->stack, app_context->sp
   ```

3. **Merge strategy must be revised** - The downstream merge of these architectural changes should now be **Phase 0** (immediate priority) before any upstream contributions.

### Revised Priority Order

1. **Phase 0 (NEW - CRITICAL):** Pull Dec 5-20 upstream commits, adopting new app_context architecture
2. **Phase 1:** Memory/Linux fixes (already in Dec 2-3 commits, now part of Phase 0)
3. **Phase 2:** Font/Text system (already documented)
4. **Phase 3:** Heap reconciliation (may need revision based on new architecture)
5. **Phases 4-8:** Upstream contributions — **strategy revised, see March 2026 update above**

---

## Executive Summary

This document outlines a merge strategy for synchronizing code between the SWFRecomp-CC fork and the main SWFRecomp repositories. The fork contains significant AS2 runtime enhancements (object/function system, 100+ opcode implementations) that should flow upstream, while recent upstream fixes (memory leaks, Linux support) should flow downstream.

---

## Part 1: Upstream Merges (This Repo → SWFRecomp Org)

### 1.1 Object System (HIGH PRIORITY)

**Files to merge:**
```
SWFModernRuntime/include/actionmodern/object.h  (178 lines - NEW FILE)
SWFModernRuntime/src/actionmodern/object.c      (845 lines - NEW FILE)
```

**What it provides:**
- `ASObject` struct with reference counting
- `ASArray` struct for array types
- `ASProperty` struct with ECMA-262 compliant flags
- Property management: `getProperty()`, `setProperty()`, `deleteProperty()`
- Prototype chain traversal: `getPropertyWithPrototype()`
- Interface support: `setInterfaceList()`, `implementsInterface()`, `getConstructor()`
- Memory management: `allocObject()`, `retainObject()`, `releaseObject()`
- Array operations: `allocArray()`, `retainArray()`, `releaseArray()`, `getArrayElement()`, `setArrayElement()`

**Dependencies:**
- Requires `ActionVar` type from `variables.h`
- Used by many opcodes in `action.c`

**Merge strategy:**
1. Create PR adding `object.h` and `object.c` as new files
2. Update `CMakeLists.txt` to include `object.c` in build
3. No conflicts expected (files don't exist upstream)

---

### 1.2 Extended Action Header (HIGH PRIORITY)

**File:** `SWFModernRuntime/include/actionmodern/action.h`

**Key additions vs upstream:**

| Addition | Lines | Description |
|----------|-------|-------------|
| `MovieClip` struct | 11-33 | Full Flash MovieClip with 30+ properties |
| `root_movieclip` extern | 36 | Global root MovieClip |
| New action declarations | 107-232 | ~80 new function declarations |

**New function declarations include:**
- Frame control: `actionGoToLabel`, `actionGotoFrame2`, `actionPrevFrame`, `actionNextFrame`
- Object/member: `actionGetMember`, `actionSetMember`, `actionNewObject`, `actionNewMethod`
- Functions: `actionCallFunction`, `actionDefineFunction`, `actionDefineFunction2`, `actionReturn`
- Arrays: `actionInitArray`, `actionInitObject`
- Control flow: `actionEnumerate`, `actionEnumerate2`, `evaluateCondition`
- Exception handling: `actionThrow`, `actionTryBegin`, `actionTryExecute`, `actionTryEnd`, `actionCatchToVariable`, `actionCatchToRegister`
- Type operations: `actionTypeof`, `actionCastOp`, `actionInstanceOf`, `actionExtends`, `actionImplementsOp`
- Bitwise: `actionBitAnd`, `actionBitOr`, `actionBitXor`, `actionBitLShift`, `actionBitRShift`, `actionBitURShift`
- String: `actionStringExtract`, `actionMbStringLength`, `actionMbStringExtract`, `actionStringLess`, `actionStringGreater`
- Misc: `actionStoreRegister`, `actionPushRegister`, `actionDelete`, `actionDelete2`, `actionDuplicate`, `actionStackSwap`

**Merge strategy:**
1. Diff local vs upstream `action.h`
2. Create PR adding new declarations while preserving upstream changes
3. May need coordination if upstream has diverged

---

### 1.3 Extended Action Implementation (HIGH PRIORITY)

**File:** `SWFModernRuntime/src/actionmodern/action.c`

**Size comparison:**
| Version | Lines | Size |
|---------|-------|------|
| This repo | 6,795 | 187 KB |
| Upstream | ~825 | ~17 KB |

**This represents ~6,000 lines of new opcode implementations.**

**Major implementations to merge:**

| Opcode | Function | Line (approx) | Description |
|--------|----------|---------------|-------------|
| 0x40 | `actionNewObject` | 4634-4830 | Constructor handling for Array, Object, Date, String |
| 0x53 | `actionNewMethod` | 4972+ | Method invocation with `this` binding |
| 0x3D | `actionCallFunction` | 5948-6465 | Function calls + built-in functions (parseInt, parseFloat) |
| 0x9B | `actionDefineFunction` | 5866 | Simple function storage |
| 0x8E | `actionDefineFunction2` | 5907 | Advanced function with registers |
| 0x46 | `actionEnumerate` | - | Object property enumeration |
| 0x55 | `actionEnumerate2` | - | Enhanced enumeration |
| 0x49 | `actionEquals2` | - | Type-coercing equality |
| 0x48 | `actionLess2` | - | Type-coercing less-than |
| 0x67 | `actionGreater` | - | Greater-than comparison |
| 0x69 | `actionExtends` | - | Prototype inheritance |
| 0x2B | `actionCastOp` | - | Type casting |
| 0x54 | `actionInstanceOf` | - | Instance checking |
| 0x2C | `actionImplementsOp` | - | Interface implementation |
| 0x8A | `actionWaitForFrame` | - | Frame synchronization |
| 0x8D | `actionWaitForFrame2` | - | Enhanced frame wait |
| 0x8C | `actionGoToLabel` | - | Label-based navigation |
| 0x9F | `actionGotoFrame2` | - | Frame navigation |
| 0x9E | `actionCall` | - | Frame/scene calls |
| 0x9A | `actionGetURL2` | - | Dynamic URL loading |
| 0x8F | `actionTry` | - | Exception try block |
| 0x2A | `actionThrow` | - | Exception throwing |
| 0x87 | `actionStoreRegister` | - | Register storage |
| many | Bitwise ops | - | AND, OR, XOR, shifts |

**Merge strategy:**
1. This is the most complex merge - significant code addition
2. Consider breaking into multiple PRs by feature area:
   - PR 1: Object/Array primitives (depends on object.c)
   - PR 2: Function definition/calling
   - PR 3: Control flow (frames, labels, exceptions)
   - PR 4: Type operations and comparisons
3. Each PR should include corresponding tests

---

### 1.4 Extended Variables (MEDIUM PRIORITY)

**File:** `SWFModernRuntime/src/actionmodern/variables.c`

**Size comparison:**
| Version | Lines |
|---------|-------|
| This repo | 249 |
| Upstream | ~100 |

**Merge strategy:**
1. Diff and merge additions
2. Lower priority - may have fewer conflicts

---

### 1.5 Test Suite (MEDIUM PRIORITY)

**Location:** `SWFRecomp/tests/`

**Comparison:**
| Version | Test directories |
|---------|-----------------|
| This repo | 159 |
| Upstream | ~52 |

**New test categories include:**
- Object tests: `new_object_swf_4`, `init_object_swf_4`, `get_member_swf_4`, `set_member_swf_4`
- Function tests: `call_function_swf_5`, `call_method_swf_5`, `define_function_swf_5`, `define_function2_swf_7`
- Control flow: `throw_swf_7`, `try_swf_7`, `extends_swf_7`, `implements_op_swf_7`
- Type tests: `typeof_swf_5`, `instanceof_swf_6`, `cast_op_swf_7`
- Enumeration: `enumerate_swf_4`, `enumerate2_swf_6`
- Many more arithmetic, string, and comparison tests

**Merge strategy:**
1. Tests are mostly additive - low conflict risk
2. Can be merged in batches corresponding to feature PRs
3. Ensure test infrastructure (`all_tests.sh`, `test_utils.py`) is compatible

---

### 1.6 Stackvalue Type Enum (LOW PRIORITY)

**File:** `SWFModernRuntime/include/actionmodern/stackvalue.h`

**Local version includes:**
```c
ACTION_STACK_VALUE_STRING
ACTION_STACK_VALUE_F32
ACTION_STACK_VALUE_F64
ACTION_STACK_VALUE_NULL
ACTION_STACK_VALUE_UNDEFINED
ACTION_STACK_VALUE_BOOLEAN
ACTION_STACK_VALUE_OBJECT      // For ASObject*
ACTION_STACK_VALUE_ARRAY       // For ASArray*
ACTION_STACK_VALUE_FUNCTION    // For function references
ACTION_STACK_VALUE_MOVIECLIP   // For MovieClip references
// ... potentially more
```

**Merge strategy:**
1. Compare with upstream
2. Add any missing type values

---

## Part 2: Downstream Merges (SWFRecomp Org → This Repo)

### Fork Divergence Points

This repository forked from the upstream repos on **October 31, 2025**:
- **SWFRecomp:** Forked at commit `bc761f4` ("remove unnecessary check", Oct 10, 2025)
- **SWFModernRuntime:** Forked at commit `267553d` ("select bitmap at style index", Oct 7, 2025)

All commits after these points need to be evaluated for downstream merge.

---

### 2.1 SWFRecomp Upstream Commits (Since Fork)

| Date | SHA | Author | Description | Priority |
|------|-----|--------|-------------|----------|
| **Feb 6, 2026** | `293fe5f` | LittleCube | update README | LOW |
| Feb 6, 2026 | `7f53538` | LittleCube | update README | LOW |
| Jan 12, 2026 | `2400abd` | LittleCube | update README | LOW |
| **Jan 11, 2026** | `297c920` | LittleCube | **fix false hole issue** | **MEDIUM** |
| **Dec 20** | `06506c3` | LittleCube | **refactor stack and sp into app_context** | **CRITICAL** |
| Dec 12 | `44324d8` | LittleCube | update README | LOW |
| Dec 12 | `620c30f` | LittleCube | fix passing app_context to tagInit | HIGH |
| Dec 2 | `3690992` | LittleCube | update CMakeLists.txt and main.c for wild_shadow test | LOW |
| Nov 28 | `989a0b4` | PeerInfinity | wasm support (#3) - **Already in this repo** | SKIP |
| Nov 17 | `e26d958` | LittleCube | use GETVAR, use app_context | MEDIUM |
| Nov 10 | `8e270e2` | LittleCube | add font test | **HIGH** |
| Nov 10 | `45b15f6` | LittleCube | implement color transforms and text color, fix text position | **HIGH** |
| Nov 8 | `17f07ee` | LittleCube | **implement glyph and text recompilation** | **HIGH** |
| Oct 10 | `bc761f4` | LittleCube | remove unnecessary check | FORK POINT |

**Open PR:** PR #4 (`feature/objects-and-functions`) — 5 commits implementing object/function opcodes in the recompiler. See March 2026 update above for details.

**App Context Architecture (CRITICAL - Dec 2025):**
The Dec 12-20 commits complete the `app_context` refactoring, moving `stack` and `sp` into the `SWFAppContext` structure. This is a major architectural change that must be merged before any upstream contributions.

**Font/Text System (HIGH PRIORITY):**
The Nov 8-10 commits add significant font and text rendering capabilities that are missing from this fork.

**False Hole Fix (Jan 2026):**
`297c920` fixes a "false hole issue" in the recompiler — worth investigating for potential relevance to our recompilation pipeline.

---

### 2.2 SWFModernRuntime Upstream Commits (Since Fork)

| Date | SHA | Author | Description | Priority |
|------|-----|--------|-------------|----------|
| **Feb 6, 2026** | `9b6f2c0` | LittleCube | comment update | LOW |
| **Dec 20** | `39ec6ad` | LittleCube | **refactor stack and sp into app_context** | **CRITICAL** |
| Dec 12 | `b682cd2` | LittleCube | pass app_context to tagInit | HIGH |
| Dec 5 | `669e40c` | LittleCube | if guard bitmap_transfer | LOW |
| Dec 3 | `101b95b` | LittleCube | remove memory leaks from flashbang | **HIGH** |
| Dec 2 | `3210b9a` | LittleCube | fix Linux support, fix freeMap signature, remove aligned | **HIGH** |
| Dec 2 | `767b6a3` | LittleCube | clean up freeMap | MEDIUM |
| Dec 2 | `566bc8a` | LittleCube | remove define guard in tag.c | LOW |
| Nov 28 | `6c33c2a` | LittleCube | whoops LOL | LOW |
| Nov 28 | `0823214` | PeerInfinity | wasm support (#2) - **Already in this repo** | SKIP |
| Nov 17 | `93e3c6e` | LittleCube | add GETVAR, use heap | MEDIUM |
| Nov 17 | `3e751da` | LittleCube | don't use heap_inited | MEDIUM |
| Nov 17 | `0df3915` | LittleCube | clean up heap implementation | MEDIUM |
| Nov 16 | `34d143a` | LittleCube | implement o1heap foundation | **HIGH** |
| Nov 12 | `375c702` | LittleCube | add grow_ptr_aligned and ENSURE_SIZE_ALIGN, use memcpy | MEDIUM |
| Nov 11 | `4f82243` | LittleCube | implement cxforms, text position and color | **HIGH** |
| Nov 9 | `f389d26` | LittleCube | optimize extra transforms | MEDIUM |
| Nov 9 | `9041de4` | LittleCube | implement text position | **HIGH** |
| Nov 9 | `7558e43` | LittleCube | add flashbang_upload_extra_transform functions | **HIGH** |
| Nov 8 | `00166cc` | LittleCube | **implement glyph and text recompilation** | **HIGH** |
| Oct 7 | `267553d` | LittleCube | select bitmap at style index | FORK POINT |

**Open PR:** PR #3 (`feature/objects-and-functions`) — 14 commits implementing runtime object/function support. See March 2026 update above for details.

**App Context Architecture (CRITICAL - Dec 2025):**
- Dec 5: `669e40c` - bitmap_transfer guard
- Dec 12: `b682cd2` - Pass app_context to tagInit
- Dec 20: `39ec6ad` - **Refactor stack and sp into app_context** (major architectural change)

**Font/Text System (HIGH PRIORITY):**
- Nov 8: `00166cc` - Core glyph and text recompilation
- Nov 9: `9041de4` - Text position implementation
- Nov 9: `7558e43` - Extra transform functions for text
- Nov 11: `4f82243` - Color transforms, text position and color

**Memory/Heap System (HIGH PRIORITY):**
- Nov 16: `34d143a` - o1heap foundation (note: this repo has o1heap too, may conflict)
- Dec 2-3: Memory leak fixes and Linux support

---

### 2.3 Categorized Downstream Merges

#### Category 0: App Context Architecture (CRITICAL - NEW)

**Why critical:** This is a fundamental architectural change that affects ALL function signatures. Must be merged first to establish compatibility with upstream.

**What changed:**
- `stack` and `sp` (stack pointer) are now members of `SWFAppContext`
- All action functions now take only `SWFAppContext* app_context` parameter
- Tag functions now receive `app_context`
- Frame functions pass `app_context` throughout

**SWFRecomp commits:**
- `620c30f` - fix passing app_context to tagInit
- `06506c3` - refactor stack and sp into app_context

**SWFModernRuntime commits:**
- `669e40c` - if guard bitmap_transfer
- `b682cd2` - pass app_context to tagInit
- `39ec6ad` - refactor stack and sp into app_context

**Merge strategy:**
1. This is a **breaking change** - the fork's action implementations must be refactored
2. The `app-context-migration-plan.md` in this repo is now obsolete - upstream's approach is more aggressive
3. All ~100 action function signatures must change from:
   ```c
   void actionXxx(char* stack, u32* sp)
   // or
   void actionXxx(SWFAppContext* app_context, char* stack, u32* sp)
   ```
   to:
   ```c
   void actionXxx(SWFAppContext* app_context)
   // accessing via app_context->stack, app_context->sp
   ```
4. The compiler (SWFRecomp) must also be updated to generate the new calling convention
5. **Recommended approach:**
   - Fetch upstream as a remote
   - Create a merge branch
   - Carefully merge upstream changes, adapting our action implementations
   - This will be the largest single merge effort

**Dependencies:**
- Must complete before any upstream contributions (our code won't compile against their headers otherwise)
- Must complete before font/text merge (those commits use the new convention)

---

#### Category A: Font/Text System (HIGH PRIORITY)

**Why important:** This repo has no font/text rendering support. These commits add:
- Glyph recompilation
- Text positioning
- Color transforms for text
- Extra transform uploads

**SWFRecomp commits:**
- `17f07ee` - implement glyph and text recompilation
- `45b15f6` - implement color transforms and text color, fix text position
- `8e270e2` - add font test

**SWFModernRuntime commits:**
- `00166cc` - implement glyph and text recompilation
- `7558e43` - add flashbang_upload_extra_transform functions
- `9041de4` - implement text position
- `4f82243` - implement cxforms, text position and color

**Merge strategy:**
1. Cherry-pick all font/text commits together as a coherent feature
2. Test with existing font test files
3. May require updates to graphics pipeline

#### Category B: Memory Management (HIGH PRIORITY)

**Why important:** Memory leaks and Linux compatibility issues.

**Commits:**
- `101b95b` - remove memory leaks from flashbang
- `3210b9a` - fix Linux support, fix freeMap signature
- `767b6a3` - clean up freeMap

**Merge strategy:**
1. Review for conflicts with local memory management
2. Cherry-pick carefully - may affect object.c reference counting

#### Category C: Heap Implementation (MEDIUM - POTENTIAL CONFLICT)

**Note:** This repo already integrated o1heap in commit `686e58c` ("Integrate o1heap virtual memory improvements"). Need to compare implementations.

**Upstream commits:**
- `34d143a` - implement o1heap foundation
- `0df3915` - clean up heap implementation
- `3e751da` - don't use heap_inited
- `93e3c6e` - add GETVAR, use heap

**Merge strategy:**
1. Compare local o1heap integration with upstream
2. Determine which implementation is more complete
3. Reconcile differences carefully

#### Category D: Build/Config Updates (LOW PRIORITY)

**Commits:**
- `3690992` - update CMakeLists.txt for wild_shadow test
- `e26d958` - use GETVAR, use app_context
- `566bc8a` - remove define guard in tag.c

**Merge strategy:**
1. Review and apply as needed
2. Low conflict risk

---

### 2.4 Commits to Skip

These commits are already in this repo via the wasm-support merge:
- `989a0b4` (SWFRecomp) - wasm support (#3)
- `0823214` (SWFModernRuntime) - wasm support (#2)

---

## Part 3: Recommended Merge Order

> **NOTE (Dec 20, 2025):** The merge order has been revised due to the critical app_context architecture changes upstream. Phase 0 is now the immediate priority.

### Phase 0: Downstream - App Context Architecture (CRITICAL - NEW)
**Priority:** Must complete first - architectural foundation
**Estimated effort:** HIGH (touches all action functions)

1. Add upstream repos as remotes:
   ```bash
   git remote add upstream-recomp https://github.com/SWFRecomp/SWFRecomp.git
   git remote add upstream-runtime https://github.com/SWFRecomp/SWFModernRuntime.git
   git fetch upstream-recomp
   git fetch upstream-runtime
   ```

2. Create architecture migration branch:
   ```bash
   git checkout -b feature/upstream-app-context-sync
   ```

3. Analyze upstream changes in detail:
   - Review `39ec6ad` (SWFModernRuntime) - how stack/sp are now in app_context
   - Review `06506c3` (SWFRecomp) - how compiler generates new calling convention
   - Document all signature changes

4. Update SWFAppContext structure to include stack and sp:
   ```c
   typedef struct SWFAppContext {
       // ... existing fields ...
       char* stack;      // NEW - was passed as parameter
       u32 sp;           // NEW - was passed as parameter (or u32*)
   } SWFAppContext;
   ```

5. Refactor all action function signatures (~100 functions):
   - Update declarations in `action.h`
   - Update implementations in `action.c`
   - Change all `stack` and `*sp` references to `app_context->stack` and `app_context->sp`

6. Update compiler code generation:
   - Frame functions pass only `app_context`
   - Script functions pass only `app_context`
   - Action calls pass only `app_context`

7. Update tag functions to receive `app_context`

8. Build and test:
   ```bash
   cd SWFRecomp && mkdir build && cd build && cmake .. && make
   cd ../../tests && ./all_tests.sh
   ```

9. Mark `app-context-migration-plan.md` as obsolete (superseded by upstream implementation)

**Note:** This phase subsumes the original Phase 1 (memory/Linux fixes) since those commits will be included when syncing to the Dec 20 upstream state.

---

### Phase 1: Downstream - Memory/Linux Fixes (NOW INCLUDED IN PHASE 0)
**Status:** Merged into Phase 0

~~**Priority:** Critical bugfixes~~
~~1. Cherry-pick memory leak fixes (`101b95b`, `767b6a3`)~~
~~2. Cherry-pick Linux support fixes (`3210b9a`)~~
~~3. Cherry-pick minor cleanups (`566bc8a`)~~
~~4. Verify local builds still work~~
~~5. Run test suite~~

These commits are now part of the upstream state that Phase 0 will sync to.

---

### Phase 2: Downstream - Font/Text System (HIGH PRIORITY)
**Priority:** Major missing feature
1. Cherry-pick SWFRecomp font commits:
   - `17f07ee` - implement glyph and text recompilation
   - `45b15f6` - implement color transforms and text color
   - `8e270e2` - add font test
2. Cherry-pick SWFModernRuntime font commits:
   - `00166cc` - implement glyph and text recompilation
   - `7558e43` - add flashbang_upload_extra_transform functions
   - `9041de4` - implement text position
   - `4f82243` - implement cxforms, text position and color
3. Resolve any conflicts with local changes
4. Test font rendering

### Phase 3: Downstream - Heap Reconciliation (MEDIUM)
**Priority:** Ensure compatibility
1. Compare local o1heap integration with upstream (`34d143a`)
2. Cherry-pick additional heap improvements (`0df3915`, `3e751da`, `93e3c6e`)
3. Reconcile any differences
4. Verify memory management still works

### Phase 4: Downstream - Build Updates (LOW)
1. Review `e26d958` (use GETVAR, use app_context)
2. Review `3690992` (wild_shadow test updates)
3. Apply as needed

---

### Phase 5: Upstream - Object System (REVISED March 2026)

> **NOTE:** Upstream is now building their own object/function system via PR #4 (SWFRecomp) and PR #3 (SWFModernRuntime). Direct porting of our `object.h`/`object.c` is **no longer viable** due to fundamental architectural differences (rbtree vs linear array, string IDs vs raw strings, unified vs separate function structs).

**New approach:**
1. Wait for upstream's `feature/objects-and-functions` PRs to merge to master
2. Review their implementation for correctness and completeness
3. Identify gaps vs our implementation (prototype chains, closures, super, etc.)
4. Contribute incremental additions using their architecture and conventions

### Phase 6: Upstream - AVM1 Semantics Knowledge (REVISED March 2026)

Rather than porting code, contribute **behavioral knowledge** as incremental PRs against upstream's new architecture:
1. Prototype chain traversal and `__proto__` semantics
2. Closure scope capture (WITH scope, base_clip for SWF6+)
3. Super keyword depth-based dispatch
4. Constructor return value handling
5. `__resolve` hook
6. SetTarget/target_clip semantics
7. MovieClip timeline control and execution ordering

### Phase 7: Upstream - Tests (REVISED March 2026)

Test SWFs are architecture-independent and can be contributed directly:
1. **PR 7a:** Basic opcode tests (arithmetic, comparison, bitwise, string)
2. **PR 7b:** Object/function/scope tests
3. **PR 7c:** Control flow tests (goto, frame navigation, exceptions)
4. **PR 7d:** Advanced semantics tests (super, closures, prototype chains)
5. Consider contributing our Ruffle test infrastructure

### Phase 8: Upstream - Remaining Contributions (ongoing)
1. Bug fixes and edge case handling as incremental PRs
2. Help validate upstream's implementation against Flash behavior
3. Share investigation docs (ACCEPTED_DIFFS, RUFFLE_VS_FLASH_DIFFERENCES)

---

## Part 4: Risk Assessment

### Critical Risk Areas (NEW - Dec 2025)
| Area | Risk | Mitigation |
|------|------|------------|
| **App context architecture** | All function signatures changed | Must sync with upstream before any contributions; largest single merge effort |
| **Stack/SP in app_context** | All 100+ action implementations must change | Systematic refactoring with find/replace; thorough testing |
| **Compiler code generation** | Generated code incompatible with old runtime | Update compiler and runtime together in same branch |

### High Risk Areas
| Area | Risk | Mitigation |
|------|------|------------|
| `action.c` merge | Large diff, potential conflicts | Break into smaller PRs, coordinate with maintainers |
| Function storage system | Architectural differences possible | Review upstream patterns first |
| Memory management | Reference counting assumptions | Thorough testing, leak detection |

### Low Risk Areas
| Area | Reason |
|------|--------|
| `object.h`/`object.c` | New files, no conflicts |
| Test additions | Mostly additive |
| `stackvalue.h` | Small enum additions |

---

## Part 5: Pre-Merge Checklist

### Before Phase 0 (App Context Sync) - NEW
- [ ] Archive or mark `app-context-migration-plan.md` as obsolete
- [ ] Document current function signatures for reference
- [ ] Create backup branch: `git checkout -b backup/pre-app-context-sync`
- [ ] Verify all 159 tests pass on current codebase
- [ ] Review upstream `SWFAppContext` structure in detail

### Before Each Upstream PR
- [ ] Fetch latest upstream master
- [ ] Rebase local changes
- [ ] Run full test suite locally
- [ ] Check for memory leaks with valgrind/ASAN
- [ ] Verify WASM build still works
- [ ] Update relevant documentation
- [ ] **NEW:** Ensure code uses new `app_context->stack` / `app_context->sp` convention

### Before Downstream Merge
- [ ] Backup current state (tag or branch)
- [ ] Review upstream changes for conflicts
- [ ] Test in isolation first
- [ ] Run full test suite after merge

---

## Part 6: Communication Plan

1. **Initial contact:** Share this document with LittleCube and SWFRecomp maintainers
2. **PR descriptions:** Reference this document in each PR
3. **Progress tracking:** Update this document as merges complete
4. **Issue tracking:** Create GitHub issues for each major merge phase

---

## Appendix A: File Inventory

### Files Unique to This Repo (to merge upstream)
```
SWFModernRuntime/include/actionmodern/object.h
SWFModernRuntime/src/actionmodern/object.c
SWFRecomp/tests/ (107+ additional test directories)
```

### Files Modified in This Repo (to diff and merge)
```
SWFModernRuntime/include/actionmodern/action.h   (+120 lines approx)
SWFModernRuntime/include/actionmodern/stackvalue.h (+types)
SWFModernRuntime/src/actionmodern/action.c       (+5970 lines approx)
SWFModernRuntime/src/actionmodern/variables.c    (+149 lines approx)
```

### Files to Pull from Upstream
```
SWFModernRuntime/src/* (Dec 2-3 fixes)
SWFRecomp/CMakeLists.txt (Dec 2 updates)
SWFRecomp/tests/wild_shadow/* (if applicable)
```

---

## Appendix B: Key Code Locations Reference

For contributors working on the merge:

| Feature | Header | Implementation |
|---------|--------|----------------|
| Object system | `object.h` | `object.c` |
| Stack operations | `action.h:38-97` | `action.c` |
| MovieClip | `action.h:11-33` | `action.c` |
| Function storage | `action.h:209-212` | `action.c:5866-5950` |
| Built-in functions | - | `action.c:5982-6465` |
| Constructor dispatch | - | `action.c:4634-4830` |
| Property access | `object.h:95-107` | `object.c:157-340` |

---

## Appendix C: Technical Implementation Details for Phase 0

*Added December 20, 2025 after detailed analysis of upstream changes.*

Reference files from upstream are available in `upstream-reference/` (gitignored).

### C.1 SWFAppContext Structure Comparison

#### Upstream (New)
```c
typedef struct SWFAppContext
{
    char* stack;          // NEW - moved from global
    u32 sp;               // NEW - moved from global
    u32 oldSP;            // NEW - moved from global

    frame_func* frame_funcs;

    int width;
    int height;
    const float* stage_to_ndc;

    O1HeapInstance* heap_instance;
    char* heap;
    size_t heap_size;     // Simplified from heap_current_size/heap_full_size

    size_t max_string_id; // NEW - for string ID lookups

    size_t bitmap_count;
    size_t bitmap_highest_w;
    size_t bitmap_highest_h;

    // Graphics data buffers...

    // NEW - Font/Text support
    u32* glyph_data;
    size_t glyph_data_size;
    u32* text_data;
    size_t text_data_size;
    char* cxform_data;
    size_t cxform_data_size;
} SWFAppContext;
```

#### Local (Current)
```c
typedef struct SWFAppContext
{
    frame_func* frame_funcs;
    size_t frame_count;   // LOCAL ADDITION - keep this

    // Graphics fields...

    // Heap management
    O1HeapInstance* heap_instance;
    char* heap;
    int heap_inited;           // Different from upstream
    size_t heap_current_size;  // Different from upstream
    size_t heap_full_size;     // Different from upstream
} SWFAppContext;

// These are currently GLOBALS - must move to struct:
extern char* stack;
extern u32 sp;
extern u32 oldSP;
```

#### Migration Actions
| Field | Action |
|-------|--------|
| `stack`, `sp`, `oldSP` | Move from globals into struct |
| `frame_count` | Keep (local addition) |
| `heap_inited`, `heap_current_size`, `heap_full_size` | Replace with `heap_size` |
| `max_string_id` | Add |
| `glyph_data`, `text_data`, `cxform_data` | Add (for font support) |

---

### C.2 Character Structure Changes

#### Upstream (New) - Union for Shape + Text
```c
typedef enum {
    CHAR_TYPE_SHAPE,
    CHAR_TYPE_TEXT,
} CharacterType;

typedef struct Character {
    CharacterType type;
    union {
        // DefineShape
        struct {
            size_t shape_offset;
            size_t size;
        };
        // DefineText
        struct {
            size_t text_start;
            size_t text_size;
            u32 transform_start;
            u32 cxform_id;
        };
    };
} Character;
```

#### Local (Current) - Shape Only
```c
typedef struct Character {
    size_t shape_offset;
    size_t size;
} Character;
```

**Migration:** Replace with upstream union version to support text.

---

### C.3 Frame Function Typedef

#### Upstream (New)
```c
typedef void (*frame_func)(SWFAppContext* app_context);
```

#### Local (Current)
```c
typedef void (*frame_func)();
```

**Migration:** Update typedef and all frame function signatures.

---

### C.4 Stack Access Macros

#### Upstream (New) - Uses app_context members
```c
#define STACK (app_context->stack)
#define SP (app_context->sp)
#define OLDSP (app_context->oldSP)

#define PUSH(t, v) \
    OLDSP = SP; \
    SP -= 4 + 4 + 8 + 8; \
    SP &= ~7; \
    STACK[SP] = t; \
    VAL(u32, &STACK[SP + 4]) = OLDSP; \
    VAL(u64, &STACK[SP + 16]) = v;

#define POP() \
    SP = VAL(u32, &STACK[SP + 4]);

#define PUSH_VAR(p) pushVar(app_context, p);
```

#### Local (Current) - Uses stack/sp parameters
```c
#define PUSH(t, v) \
    do { \
        u32 oldSP = *sp; \
        *sp -= 4 + 4 + 8 + 8; \
        *sp &= ~7; \
        stack[*sp] = t; \
        VAL(u32, &stack[*sp + 4]) = oldSP; \
        VAL(u64, &stack[*sp + 16]) = v; \
    } while(0)

#define POP() \
    *sp = VAL(u32, &stack[*sp + 4]);

#define PUSH_VAR(p) pushVar(stack, sp, p);
```

**Migration:** Replace all macros with upstream versions that use `STACK`, `SP`, `OLDSP`.

---

### C.5 Action Function Signatures

#### Upstream Pattern
```c
void actionAdd(SWFAppContext* app_context);
void actionTrace(SWFAppContext* app_context);
void actionStringEquals(SWFAppContext* app_context, char* a_str, char* b_str);
void pushVar(SWFAppContext* app_context, ActionVar* p);
int evaluateCondition(SWFAppContext* app_context);
```

#### Local Pattern
```c
void actionAdd(char* stack, u32* sp);
void actionTrace(char* stack, u32* sp);
void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str);
void pushVar(char* stack, u32* sp, ActionVar* p);
int evaluateCondition(char* stack, u32* sp);
```

#### Sed Commands for Bulk Refactoring
```bash
# In action.h - update declarations
sed -i 's/void action\([A-Za-z0-9]*\)(char\* stack, u32\* sp)/void action\1(SWFAppContext* app_context)/g' action.h

# In action.c - update definitions
sed -i 's/void action\([A-Za-z0-9]*\)(char\* stack, u32\* sp)/void action\1(SWFAppContext* app_context)/g' action.c

# In action.c - update stack/sp references to use macros
# (This requires more careful manual review)
```

---

### C.6 Compiler Code Generation Changes

#### Upstream Pattern (action.cpp)
```cpp
out_script << "\t" << "actionAdd(app_context);" << endl;
out_script << "\t" << "actionTrace(app_context);" << endl;
out_script << "\t" << "if (evaluateCondition(app_context))" << endl;
```

#### Local Pattern (action.cpp)
```cpp
out_script << "\t" << "actionAdd(stack, sp);" << endl;
out_script << "\t" << "actionTrace(stack, sp);" << endl;
out_script << "\t" << "if (evaluateCondition(stack, sp))" << endl;
```

#### Sed Command for Compiler
```bash
# Replace (stack, sp) with (app_context) for action calls
sed -i 's/action\([A-Za-z0-9]*\)(stack, sp)/action\1(app_context)/g' action.cpp
sed -i 's/action\([A-Za-z0-9]*\)(stack, \&sp)/action\1(app_context)/g' action.cpp
```

---

### C.7 Local Features to Preserve

These features exist in local code but not upstream - must be preserved during merge:

| Feature | Location | Notes |
|---------|----------|-------|
| MovieClip struct | `action.h:11-33` | Flash MovieClip properties |
| Exception handling | `action.h:216-227` | actionThrow, actionTry*, etc. |
| Function2Ptr typedef | `action.h:210` | For DefineFunction2 |
| Object system | `object.h`, `object.c` | Full AS2 object model |
| ~80 additional actions | `action.c` | Beyond upstream's ~20 |
| 107 additional tests | `tests/` | Comprehensive test suite |

---

### C.8 Globals to Keep vs. Move

#### Move to SWFAppContext
- `stack` → `app_context->stack`
- `sp` → `app_context->sp`
- `oldSP` → `app_context->oldSP`

#### Keep as Globals (runtime state)
- `quit_swf` - exit flag
- `is_playing` - playback state
- `current_frame`, `next_frame` - frame navigation
- `manual_next_frame` - frame control
- `is_dragging`, `dragged_target` - drag state
- `dictionary`, `display_list`, `max_depth` - display structures

---

### C.9 Implementation Order (Option A: Incremental)

1. **Update swf.h**
   - Add `stack`, `sp`, `oldSP` to SWFAppContext
   - Add `STACK`, `SP`, `OLDSP` macros
   - Update `frame_func` typedef
   - Add missing fields (`max_string_id`, font data)

2. **Update action.h macros**
   - Replace `PUSH`, `POP`, etc. with upstream versions
   - Update `PUSH_VAR` macro

3. **Update action.h declarations**
   - Change all function signatures to `(SWFAppContext* app_context, ...)`

4. **Update action.c implementations**
   - Change function signatures
   - Replace `stack[*sp]` with `STACK[SP]`
   - Replace `*sp` with `SP`

5. **Update variables.c**
   - Change function signatures
   - Update stack access patterns

6. **Update compiler (action.cpp)**
   - Change generated action calls to use `app_context`

7. **Update compiler (swf.cpp)**
   - Change frame/script function signatures
   - Update tag function calls

8. **Update tag.c, swf.c**
   - Update function signatures
   - Pass `app_context` through call chain

9. **Build and test incrementally**
   - Test after each major file change
   - Fix issues as they arise

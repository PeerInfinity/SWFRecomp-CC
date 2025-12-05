# SWFRecomp-CC Upstream/Downstream Merge Plan

**Date:** December 4, 2025

**Author:** Claude (via PeerInfinity/SWFRecomp-CC)

**Target Repositories:**

- Upstream: [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp)
- Upstream: [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime)
- This repo: [PeerInfinity/SWFRecomp-CC](https://github.com/PeerInfinity/SWFRecomp-CC)

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
| Dec 2 | `3690992` | LittleCube | update CMakeLists.txt and main.c for wild_shadow test | LOW |
| Nov 28 | `989a0b4` | PeerInfinity | wasm support (#3) - **Already in this repo** | SKIP |
| Nov 17 | `e26d958` | LittleCube | use GETVAR, use app_context | MEDIUM |
| Nov 10 | `8e270e2` | LittleCube | add font test | **HIGH** |
| Nov 10 | `45b15f6` | LittleCube | implement color transforms and text color, fix text position | **HIGH** |
| Nov 8 | `17f07ee` | LittleCube | **implement glyph and text recompilation** | **HIGH** |
| Oct 10 | `bc761f4` | LittleCube | remove unnecessary check | FORK POINT |

**Font/Text System (HIGH PRIORITY):**
The Nov 8-10 commits add significant font and text rendering capabilities that are missing from this fork.

---

### 2.2 SWFModernRuntime Upstream Commits (Since Fork)

| Date | SHA | Author | Description | Priority |
|------|-----|--------|-------------|----------|
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

### Phase 1: Downstream - Memory/Linux Fixes (IMMEDIATE)
**Priority:** Critical bugfixes
1. Cherry-pick memory leak fixes (`101b95b`, `767b6a3`)
2. Cherry-pick Linux support fixes (`3210b9a`)
3. Cherry-pick minor cleanups (`566bc8a`)
4. Verify local builds still work
5. Run test suite

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

### Phase 5: Upstream - Object System
1. Create PR for `object.h` + `object.c`
2. Update upstream `CMakeLists.txt`
3. Include basic object tests

### Phase 6: Upstream - Action Header
1. Create PR for `action.h` additions
2. Coordinate with maintainers on MovieClip struct placement

### Phase 7: Upstream - Action Implementation
1. **PR 7a:** Object/Array opcode implementations
   - `actionNewObject`, `actionInitObject`, `actionInitArray`
   - `actionGetMember`, `actionSetMember`
   - Tests: `new_object_*`, `init_object_*`, `get_member_*`, `set_member_*`

2. **PR 7b:** Function opcode implementations
   - `actionDefineFunction`, `actionDefineFunction2`
   - `actionCallFunction`, `actionCallMethod`, `actionReturn`
   - Tests: `call_function_*`, `define_function*`, `call_method_*`

3. **PR 7c:** Control flow opcodes
   - `actionGotoFrame`, `actionGotoFrame2`, `actionGoToLabel`
   - `actionWaitForFrame`, `actionWaitForFrame2`
   - `actionTry*`, `actionThrow`, `actionCatch*`
   - Tests: `goto_*`, `wait_for_frame*`, `try_*`, `throw_*`

4. **PR 7d:** Type and comparison opcodes
   - `actionEquals2`, `actionLess2`, `actionGreater`, `actionStrictEquals`
   - `actionTypeof`, `actionCastOp`, `actionInstanceOf`, `actionExtends`
   - Tests: `equals2_*`, `less2_*`, `typeof_*`, `instanceof_*`, `extends_*`

5. **PR 7e:** Remaining opcodes
   - Bitwise operations
   - String operations
   - Enumeration
   - Miscellaneous

### Phase 8: Upstream - Remaining Tests (ongoing)
1. Merge remaining test cases as features stabilize

---

## Part 4: Risk Assessment

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

### Before Each Upstream PR
- [ ] Fetch latest upstream master
- [ ] Rebase local changes
- [ ] Run full test suite locally
- [ ] Check for memory leaks with valgrind/ASAN
- [ ] Verify WASM build still works
- [ ] Update relevant documentation

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

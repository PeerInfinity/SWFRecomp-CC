# String Features Implementation Plan

Last updated: 2026-02-14

## Overview

String-related tests account for 13 failing Ruffle tests, split into two distinct sub-features:

1. **String methods** (4 tests, ~895 expected lines): Methods on String primitives (charAt, indexOf, slice, split, etc.) and the String constructor (fromCharCode). Many methods exist but have critical bugs (16-byte buffer truncation, byte-level indexing instead of UTF-16, missing methods).

2. **String paths** (9 tests, ~167 expected lines): Flash's path-based variable resolution using slash/dot/colon syntax (e.g., `_root/clip:variable`), `eval()` for dynamic path resolution, and variable aliasing. These are **not String code** -- they depend on MovieClip infrastructure (attachMovie, duplicateMovieClip, eval, setInterval, unloadMovie) that doesn't exist yet.

**Recommendation**: Focus on string methods (Phases 1-3). The string_paths tests are blocked by MovieClip infrastructure and should be addressed as part of a MovieClip methods effort.

## Current Pass Rates

| Test | Lines | Pass Rate | Category | Status |
|------|-------|-----------|----------|--------|
| string_methods_negative_args | 240/240 | 100% | String methods | PASS |
| string_methods_swfv5 | 274/275 | 99.6% | String methods | 1 line off (objToString) |
| string_methods | ~250/285 | ~88% | String methods | UTF-16/surrogate/toString remaining |
| string_ops_swf6 | 0/95 | 0% | SWF4/6 string ops | Not yet started |
| string_paths_* | various | various | String paths | Blocked by MovieClip infra |

## Implementation Phases

```
Phase 1 (ASCII fixes) ──DONE──→ Phase 2 (UTF-16 storage) ──→ Phase 3 (SWF4/6 ops)
```

---

## Phase 1: Fix Buffer Limits + Argument Coercion + Missing Methods ✅ DONE

**Committed:** `3fb6a61` — "Implement String methods: UTF-16 awareness, missing methods, SWF5 fixes"

Phase 1 implemented:
- Removed 16-byte buffer limit — all string methods use HALLOC for dynamic allocation
- Fixed argument coercion — all types handled (f32, f64, string, boolean, null, undefined)
- Added missing methods: concat, slice, fromCharCode, charCodeAt, lastIndexOf, split
- Fixed substr negative-length semantics (negative length = "stop N chars before end")
- SWF5-specific fixes: charCodeAt negative→NaN, concat undefined→"", indexOf/lastIndexOf undefined→"", split(undefined)→split on ","
- Added UTF-8↔UTF-16 conversion helpers (to be replaced by Phase 2)

**Remaining issues not addressed by Phase 1:**
- Object toString() coercion in concat: `[object Object]` vs calling AS2 toString() method
- toLowerCase/toUpperCase: ASCII-only, needs Unicode case mapping tables
- Surrogate pair boundary bugs in substr/substring (extracting at surrogate pair boundaries produces wrong output)

---

## Phase 2: Switch to UTF-16 Internal String Storage

**Goal**: Replace UTF-8 (`char*`) string storage with UTF-16 (`uint16_t*`). This eliminates all UTF-8↔UTF-16 conversion overhead in string methods and fixes surrogate pair boundary bugs.

### Motivation

Flash strings are natively UTF-16. The current UTF-8 storage requires O(n) conversion on every string method call (charAt, substr, indexOf, etc.) and has unresolved surrogate pair boundary bugs where extracting a substring that starts/ends in the middle of a surrogate pair produces wrong output.

With UTF-16 storage:
- All string indexing is O(1) array access
- No surrogate boundary issues (surrogates are individual code units)
- `.length` is just `str_size` (no conversion)
- ~130 lines of UTF-8↔UTF-16 helper code gets deleted
- String methods become trivial array operations

### Key Design Decision: Minimize Blast Radius

There are ~140 `strcmp`/`strncmp` sites in action.c for property name dispatch (e.g., `strncmp(prop_name, "length", 6)`). Rather than change all of them, we convert UTF-16 → char* at the ~15 **extraction points** where a string comes off the stack for property/variable dispatch. Everything downstream stays unchanged.

**What stays unchanged:**
- ASProperty names in object.h/object.c stay `char*`
- `getProperty`/`setProperty`/`deleteProperty` in object.c unchanged
- Variable hashmap keys stay `char*`
- All ~140 strcmp/strncmp dispatch sites unchanged
- Recompiler (action.cpp) unchanged — still emits `char* str_N = "..."` and `PUSH_STR_ID(str_N, strlen(str_N), id)`
- Generated script code unchanged (str_buffer parameter becomes unused but kept for compatibility)

### Changes by File

#### variables.h — ActionVar struct

Change `heap_ptr` type from `char*` to `uint16_t*`. `str_size` semantics change from byte count to UTF-16 code unit count.

```c
struct {
    uint16_t* heap_ptr;    // was char*
    bool owns_memory;
} string_data;
```

#### action.h — Stack macros

Change `PUSH_STR_ID` from a macro to an inline function that accepts `char*` (from generated code), converts to UTF-16 with caching by string_id, and pushes `uint16_t*` + code unit count onto the stack.

Add `PUSH_U16(u16_ptr, u16_len)` macro for pushing pre-existing UTF-16 strings from runtime code (constant strings like "true", "false", etc.).

The generated code's `PUSH_STR_ID(str_0, strlen(str_0), 0)` calls work unchanged — the inline function handles conversion internally.

#### swf.h — SWFAppContext

Add string cache fields:
```c
uint16_t** str_cache;     // Cached UTF-16 versions, indexed by string_id
u32* str_cache_len;       // Code unit counts for cached strings
```

#### action.c — Core runtime (~16K lines)

**Add conversion infrastructure** (~100 lines):
```c
static uint16_t* utf8_to_u16(SWFAppContext*, const char* utf8, u32 byte_len, u32* out_u16_len);
static int u16_to_utf8(const uint16_t* u16, u32 u16_len, char* out, int out_size);
static int u16_cmp(const uint16_t* a, u32 a_len, const uint16_t* b, u32 b_len);
```

**Add pre-defined UTF-16 constants** (~25 strings):
```c
static const uint16_t u16_true[] = {'t','r','u','e'};
static const uint16_t u16_false[] = {'f','a','l','s','e'};
static const uint16_t u16_null[] = {'n','u','l','l'};
static const uint16_t u16_undefined[] = {'u','n','d','e','f','i','n','e','d'};
static const uint16_t u16_NaN[] = {'N','a','N'};
// ... etc for all runtime-produced string literals
```

**Add UTF-16→char* extraction at ~15 property dispatch points** (~60 lines):
- actionGetVariable, actionSetVariable, actionGetMember, actionSetMember
- actionCallFunction, actionCallMethod, actionNewMethod, actionNewObject
- actionDefineLocal, actionDeclareLocal, actionEnumerate, actionEnumerate2
- actionDelete, actionDelete2, actionSetTarget2, actionInitObject

Pattern at each extraction point:
```c
const uint16_t* _u16 = (const uint16_t*) VAL(u64, &STACK[SP + 16]);
u32 _u16_len = VAL(u32, &STACK[SP + 8]);
char _prop_buf[512];
int prop_name_len = u16_to_utf8(_u16, _u16_len, _prop_buf, sizeof(_prop_buf));
const char* prop_name = _prop_buf;
// ... all existing strcmp dispatch below here stays UNCHANGED
```

**Rewrite convertString** to produce UTF-16 on the stack:
- Numbers: snprintf to temp char[], then utf8_to_u16
- Boolean/null/undefined: push pre-defined u16 constants
- Objects: toString() returns UTF-16 (already on stack)
- The `str_buffer` parameter from generated code becomes unused

**Simplify string methods** (net ~200 line reduction):
- charAt(n): `str_value[n]` → encode single code unit → push
- charCodeAt(n): `(double)str_value[n]` → push as number
- substr/substring/slice: direct uint16_t sub-array copy
- indexOf/lastIndexOf: uint16_t array search
- split: uint16_t array scanning
- concat: concatenate uint16_t arrays
- .length: `str_size` directly (already code unit count)

**Delete old UTF-8↔UTF-16 helpers** (~130 lines removed):
- utf8_utf16_length, utf8_decode_one, utf8_build_utf16_tables
- byte_offset_to_utf16_index, utf16_unit_to_utf8

**Update string concatenation** (actionAdd2): work with uint16_t arrays
**Update string comparison operators**: use u16_cmp
**Update trace output**: convert UTF-16 → UTF-8 for printf
**Update STR_LIST handling**: store uint16_t* pointers

#### variables.c

- Empty string initialization: `(u64) u16_empty` (static const uint16_t)
- `materializeStringList`: concatenate uint16_t arrays
- `setVariableWithValue`: `str_size` = code unit count
- `free()` calls on `heap_ptr` unchanged (free doesn't care about pointer type)

### Implementation Order

1. Add conversion helpers and UTF-16 constants
2. Change ActionVar union in variables.h
3. Change PUSH_STR/PUSH_STR_ID in action.h, add str_cache to swf.h
4. Rewrite convertString to produce UTF-16
5. Add extraction boilerplate at ~15 property name extraction points
6. Update pushVar/popVar for UTF-16 pointer handling
7. Simplify string methods in callStringPrimitiveMethod
8. Update string production (actionAdd2, fromCharCode, etc.)
9. Update string comparison operators
10. Update actionTrace and printStringValue
11. Update STR_LIST handling
12. Update variables.c
13. Run all tests

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_methods --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_methods_swfv5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_methods_negative_args --diff --verbose
cd SWFRecomp && bash tests/all_tests.sh
```

---

## Phase 3: SWF4/6 String Operations (string_ops_swf6)

**Goal**: Fix the legacy SWF4 string functions (ord, chr, length, substring as functions) to use UTF-16 semantics in SWF6+ mode. With UTF-16 storage from Phase 2, these become straightforward.

### What the test expects

`string_ops_swf6` (95 expected lines, currently 0% pass):

1. **length("str") / mblength("str")**: Both return UTF-16 code unit count → just `str_size` with UTF-16 storage
2. **ord("str") / mbord("str")**: Return first code unit value → just `str[0]`. Supplementary chars (>U+FFFF) → U+FFFD
3. **chr(n) / mbchr(n)**: Convert uint16 code to character → create 1-element uint16_t array. Surrogates → U+FFFD
4. **substring(str, start, count) / mbsubstring(str, start, count)**: 1-based extraction → array slice with offset adjustment

### Implementation

With UTF-16 storage:
- `actionStringLength()`: return `str_size` (already code units)
- `actionMbStringLength()`: same
- `actionCharToAscii()`: return `(int)str[0]` (first code unit). If supplementary (>0xD800), return 0xFFFD
- `actionAsciiToChar()`: create 1-element uint16_t array with the code value (mod 65536)
- `actionStringExtract()` / `actionMbStringExtract()`: direct array slice (convert 1-based to 0-based)

### Tests fixed

- **string_ops_swf6**: From 0% → ~90%+

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_ops_swf6 --diff --verbose
```

---

## Phase 4: Unicode Case Mapping (toUpperCase/toLowerCase)

**Goal**: Add full Unicode case mapping tables for toUpperCase/toLowerCase.

The tests expect full Unicode case mapping including Latin Extended, Cyrillic, Greek, Armenian, Georgian, and more. Flash Player uses Unicode 5.1.0 case mapping (vintage 2008).

With UTF-16 storage, case mapping iterates the uint16_t array and maps each code unit through a lookup table. Only BMP matters (U+0000-U+FFFF).

Implementation: static lookup table, ~1500 entries covering the tested ranges.

### Tests fixed

- **string_methods**: remaining toLowerCase/toUpperCase diffs

---

## Phase 5: String Paths (Deferred)

The 9 `string_paths_*` tests are blocked by MovieClip infrastructure, not String code:

| Test | Blocking Feature |
|------|-----------------|
| string_paths_basic | attachMovie() |
| string_paths_eval | eval() function |
| string_paths_eval2 | eval() + loadMovie() |
| string_paths_hidden | Nested child MC lookup by dot/slash/colon paths |
| string_paths_other | attachMovie, duplicateMovieClip, removeMovieClip, _parent |
| string_paths_reference_launder | attachMovie + MC reference tracking |
| string_paths_unload | unloadMovie + onUnload event |
| string_paths_variable_alias | attachMovie |
| string_paths_variable_scopes | setInterval callbacks |

---

## Design Decisions

1. **UTF-16 internal storage** (changed from previous plan): All string values stored as `uint16_t*` with code unit count. This matches Flash's native model. Conversion to/from UTF-8 happens only at narrow boundaries (string literal push, trace output, property name dispatch).

2. **Minimal blast radius for property dispatch**: Rather than changing ~140 strcmp sites, convert UTF-16→char* at ~15 extraction points. Property names, object.c, and hashmap keys stay as char*.

3. **String constant caching**: Constant pool strings (str_0, str_1, ...) are converted from UTF-8 to UTF-16 on first push and cached by string_id. No repeated conversion for frequently-pushed constants.

4. **No recompiler changes**: The recompiler still emits `char* str_N = "..."` and `PUSH_STR_ID(str_N, strlen(str_N), id)`. The runtime's `PUSH_STR_ID` inline function handles conversion internally.

5. **SWF version awareness**: Several behaviors differ between SWF5 and SWF6+:
   - `indexOf(undefined)`: SWF5 searches for `""`, SWF6+ searches for `"undefined"`
   - `charCodeAt()` out of range: SWF5 returns 0, SWF6+ returns NaN
   - `split("")`: SWF5 returns 1-element array with whole string, SWF6+ splits by code unit
   - `split(undefined)`: SWF5 splits on `,`, SWF6+ returns 1-element array

---

## Files Modified (All Phases)

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Phase 2: conversion helpers, UTF-16 constants, extraction points, string method simplification, concat/trace/comparison updates. Phase 3: SWF4/6 ops. Phase 4: case mapping table. |
| `SWFModernRuntime/include/actionmodern/action.h` | Phase 2: PUSH_STR macros → inline functions, PUSH_U16 macro |
| `SWFModernRuntime/include/actionmodern/variables.h` | Phase 2: ActionVar heap_ptr type change |
| `SWFModernRuntime/include/libswf/swf.h` | Phase 2: str_cache fields in SWFAppContext |
| `SWFModernRuntime/src/actionmodern/variables.c` | Phase 2: materializeStringList, empty string init |
| `SWFModernRuntime/src/actionmodern/object.c` | UNCHANGED |
| `SWFRecomp/src/action/action.cpp` | UNCHANGED |

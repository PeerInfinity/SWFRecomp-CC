# String Features Implementation Plan

Last updated: 2026-02-15

## Overview

String-related tests account for 13 failing Ruffle tests, split into two distinct sub-features:

1. **String methods** (4 tests, ~895 expected lines): Methods on String primitives (charAt, indexOf, slice, split, etc.) and the String constructor (fromCharCode). Phases 1-2 are complete (UTF-16 internal storage, all methods working). Remaining: Phase 3 (SWF4/6 string ops have bugs), Phase 4 (Unicode case mapping not implemented).

2. **String paths** (9 tests, ~167 expected lines): Flash's path-based variable resolution using slash/dot/colon syntax (e.g., `_root/clip:variable`), `eval()` for dynamic path resolution, and variable aliasing. These are **not String code** -- they depend on MovieClip infrastructure (attachMovie, duplicateMovieClip, eval, setInterval, unloadMovie) that doesn't exist yet.

**Status**: Phases 1-2 complete. Phase 3 partially done (functions exist but have bugs). Phase 4 not started. String paths remain blocked by MovieClip infrastructure.

## Current Pass Rates

| Test | Lines | Pass Rate | Category | Status |
|------|-------|-----------|----------|--------|
| string_methods_negative_args | 240/240 | 100% | String methods | PASS |
| string_methods_swfv5 | 275/275 | 100% | String methods | PASS |
| string_methods | 283/286 | 99% | String methods | 2 lines off (Unicode case mapping on lines 279, 285) |
| string_ops_swf6 | 0/95 | 0% | SWF4/6 string ops | Functions exist but have bugs (see Phase 3) |
| string_paths_* | various | various | String paths | Blocked by MovieClip infra |

## Implementation Phases

```
Phase 1 (ASCII fixes) ──DONE──→ Phase 2 (UTF-16 storage) ──DONE──→ Phase 3 (SWF4/6 ops) ──BUGS──→ Phase 4 (Unicode case mapping) ──TODO
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

## Phase 2: Switch to UTF-16 Internal String Storage ✅ DONE

**Goal**: Replace UTF-8 (`char*`) string storage with UTF-16 (`uint16_t*`). This eliminates all UTF-8↔UTF-16 conversion overhead in string methods and fixes surrogate pair boundary bugs.

All planned changes were implemented:

- `variables.h`: `heap_ptr` changed to `uint16_t*`, `str_size` is UTF-16 code unit count
- `action.h`: `push_str_id_fn()` inline function with lazy str_cache init, `PUSH_U16` and `PUSH_U16_ID` macros
- `swf.h`: `str_cache` (`uint16_t**`) and `str_cache_len` (`u32*`) fields in SWFAppContext
- `action.c`: `utf8_to_u16()`, `u16_to_utf8()`, `u16_cmp()` conversion helpers; UTF-16 constants (`u16_true`, `u16_false`, `u16_null`, `u16_undefined`, `u16_NaN`, etc.); UTF-16→char* extraction at 30+ property dispatch points; all string methods operate on `uint16_t*` arrays directly
- `variables.c`: `setVariableWithValue()` copies UTF-16 data; empty string via NULL/0

**Result**: `string_methods_negative_args` 240/240 PASS, `string_methods_swfv5` 275/275 PASS, `string_methods` 283/286 (99%, only Unicode case mapping lines 279+285 remain)

---

## Phase 3: SWF4/6 String Operations (string_ops_swf6) — PARTIALLY DONE (bugs remain)

**Goal**: Fix the legacy SWF4 string functions (ord, chr, length, substring as functions) to use UTF-16 semantics in SWF6+ mode.

### Current Status

All 8 functions exist in action.c but have bugs. `string_ops_swf6` is 0% pass (line-shifted + content mismatches).

### Bugs Found

1. **Spurious warning**: `Warning: DECLARE_LOCAL outside function for variable 's'` printed at line 1, shifting all output by one line. This alone causes 0% match rate.

2. **length("")** returns 9 instead of 0 — suggests the empty string literal `""` is being interpreted as a 9-char string (possibly `"undefined"` contamination)

3. **ord/mbord of supplementary characters**: `ord("😋")` returns 55357 (raw high surrogate) instead of 65533 (U+FFFD). `mbord("😋")` returns 128523 (full codepoint decoded from surrogate pair) instead of 65533. Both should return U+FFFD for chars > U+FFFF.

4. **chr() range handling**: `chr(12345)` masks to `& 0xFF` → returns `9` (ASCII 57) instead of the CJK character at U+3039. SWF6+ chr() should handle full 0-65535 range (same as mbchr). Also `chr(0xd801)` should produce U+FFFD, not empty string.

5. **mbchr() overflow**: `mbchr(65616)` returns a surrogate pair (`U+10010`) instead of wrapping to BMP (`chr(65616 % 65536)` = `P`).

6. **substring 1-based indexing**: `substring(s, 1, 2)` returns wrong characters — treating index as 0-based but Flash substring() is 1-based.

7. **substring negative args**: `substring(s, -5, -100)` returns empty instead of the full string. Flash clamps negative values to 1.

8. **substring overflow**: `substring(s, 4294967303, -4294967294)` returns `es` instead of `te` — needs 32-bit signed clamping.

### Remaining Implementation

With UTF-16 storage, the fixes are straightforward:
- `actionCharToAscii()` (SWF6+ ord): return `(int)str[0]`, but if `str[0]` is a high surrogate (0xD800-0xDBFF), return 0xFFFD
- `actionMbCharToAscii()` (SWF6+ mbord): same as above (both return code unit, not codepoint)
- `actionAsciiToChar()` (SWF6+ chr): create 1-element uint16_t array with `code_value & 0xFFFF`. If result is surrogate range, use 0xFFFD. Remove the `& 0xFF` mask.
- `actionMbAsciiToChar()` (SWF6+ mbchr): same as chr for SWF6+ (`& 0xFFFF`, surrogates → U+FFFD)
- `actionStringExtract()` / `actionMbStringExtract()`: convert 1-based to 0-based (subtract 1 from start). Clamp negative start/count to 0. Apply 32-bit signed interpretation for large values.
- Fix the spurious DECLARE_LOCAL warning
- Fix length("") returning 9

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_ops_swf6 --diff --verbose
```

---

## Phase 4: Unicode Case Mapping (toUpperCase/toLowerCase) — NOT STARTED

**Goal**: Add full Unicode case mapping tables for toUpperCase/toLowerCase.

**Current state**: toLowerCase/toUpperCase in `callStringPrimitiveMethod` are ASCII-only (`a-z` ↔ `A-Z`). Non-ASCII characters pass through unchanged.

The tests expect full Unicode case mapping including Latin Extended, Cyrillic, Greek, Armenian, Georgian, and more. Flash Player uses Unicode 5.1.0 case mapping (vintage 2008).

With UTF-16 storage, case mapping iterates the uint16_t array and maps each code unit through a lookup table. Only BMP matters (U+0000-U+FFFF).

Implementation: static lookup table, ~1500 entries covering the tested ranges.

### Tests fixed

- **string_methods**: lines 279 and 285 (the only 2 failing lines out of 286)

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

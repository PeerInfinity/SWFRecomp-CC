# String Features Implementation Plan

Last updated: 2026-02-14

## Overview

String-related tests account for 13 failing Ruffle tests, split into two distinct sub-features:

1. **String methods** (4 tests, ~895 expected lines): Methods on String primitives (charAt, indexOf, slice, split, etc.) and the String constructor (fromCharCode). Many methods exist but have critical bugs (16-byte buffer truncation, byte-level indexing instead of UTF-16, missing methods).

2. **String paths** (9 tests, ~167 expected lines): Flash's path-based variable resolution using slash/dot/colon syntax (e.g., `_root/clip:variable`), `eval()` for dynamic path resolution, and variable aliasing. These are **not String code** -- they depend on MovieClip infrastructure (attachMovie, duplicateMovieClip, eval, setInterval, unloadMovie) that doesn't exist yet.

**Recommendation**: Focus on string methods (Phases 1-3). The string_paths tests are blocked by MovieClip infrastructure and should be addressed as part of a MovieClip methods effort.

## Current Pass Rates

| Test | Lines | Pass Rate | Category |
|------|-------|-----------|----------|
| string_methods | 172/285 | 60% | String methods |
| string_methods_negative_args | 127/240 | 53% | String methods |
| string_methods_swfv5 | 171/275 | 62% | String methods |
| string_ops_swf6 | 0/95 | 0% | SWF4/6 string ops |
| string_paths_basic | 1/4 | 25% | String paths |
| string_paths_eval | 0/4 | 0% | String paths |
| string_paths_eval2 | 1/7 | 14% | String paths |
| string_paths_hidden | 35/54 | 65% | String paths |
| string_paths_other | 6/36 | 17% | String paths |
| string_paths_reference_launder | 0/2 | 0% | String paths |
| string_paths_unload | 0/1 | 0% | String paths |
| string_paths_variable_alias | 1/4 | 25% | String paths |
| string_paths_variable_scopes | 0/5 | 0% | String paths |

## Current Implementation State

### What exists in the runtime (`action.c`)

`callStringPrimitiveMethod()` (line ~14352) handles methods called on string primitives via `actionCallMethod`. Currently implements:

| Method | Status | Issues |
|--------|--------|--------|
| toUpperCase() | Broken | ASCII-only (a-z), 16-byte buffer limit |
| toLowerCase() | Broken | ASCII-only (A-Z), 16-byte buffer limit |
| charAt(index) | Broken | Byte-level indexing, not UTF-16; 16-byte buffer limit |
| substr(start, length) | Broken | Negative-length handling wrong, 16-byte buffer limit |
| substring(start, end) | Broken | Arg coercion limited to f32 type only, 16-byte buffer limit |
| indexOf(searchStr, start) | Partial | Works on bytes; arg coercion limited to string/f32 only |

SWF4 legacy string ops:
| Function | Status | Issues |
|----------|--------|--------|
| actionStringLength() | Broken | Returns `str_size` (byte count), should return UTF-16 code units in SWF6+ |
| actionStringExtract() | Broken | Byte-level, 16-byte buffer limit |
| actionMbStringLength() | Partial | Uses `utf8_strlen()` (Unicode char count), should return UTF-16 code units |
| actionMbStringExtract() | Partial | UTF-8 aware, but should use UTF-16 code unit indexing |
| actionCharToAscii() | Broken | Returns first byte value, should return first UTF-16 code unit |
| actionAsciiToChar() | Broken | Wraps to 0-255 with `& 0xFF`, should emit UTF-16 code unit as UTF-8 |
| actionMbCharToAscii() | Partial | Decodes UTF-8 to codepoint, but should return UTF-16 for surrogates |
| actionMbAsciiToChar() | Unknown | Not checked |

String constructor:
- `String` is registered as a global constructor (line ~7172)
- `new String(value)` creates a boxed string object (line ~11292)
- **No `String.prototype` methods** -- calling `"str".method()` routes through `callStringPrimitiveMethod`, but `new String("str").method()` would not (it goes through object method dispatch)
- **No `String.fromCharCode()`** -- this is a static method on the String constructor, not on instances

String `.length` property:
- Handled in `actionGetMember` (line ~10757): `utf8_strlen(str)` -- counts UTF-8 characters, not UTF-16 code units

### Root causes of failures

1. **16-byte buffer limit**: Every string method writes to `str_buffer[17]` with `i < 16` guards. Any string longer than 16 bytes gets truncated. The tests use strings like `"aatestbbtest1234null"` (21 chars). This is the #1 issue.

2. **Byte-level operations instead of UTF-16**: Flash strings are UTF-16. The runtime operates on raw UTF-8 bytes. `charAt(3)` returns the 4th byte, not the 4th UTF-16 code unit. For ASCII-only strings this works; for Unicode (emoji, CJK) everything is wrong.

3. **Missing methods**: `lastIndexOf`, `concat`, `slice`, `split`, `charCodeAt`, `String.fromCharCode` are completely unimplemented.

4. **Argument coercion**: Methods only accept `ACTION_STACK_VALUE_F32` arguments, ignoring f64, string-as-number, null, undefined, boolean. Flash coerces all argument types through `toNumber()` or `toString()`.

5. **Wrong negative-argument semantics for substr**: `str.substr(0, -1)` should return `str.length + (-1)` characters, not empty string.

6. **toUpperCase/toLowerCase ASCII-only**: Tests expect full Unicode case mapping (Cyrillic, Greek, Armenian, Georgian, Latin Extended, etc. -- ~1000 characters).

---

## Phase 1: Fix Buffer Limits + Argument Coercion + Missing ASCII Methods

**Goal**: Remove the 16-byte buffer truncation, fix argument coercion to handle all types, implement missing methods for ASCII strings. This fixes the majority of `string_methods_swfv5` (SWF5 = ASCII only).

### 1a. Dynamic string buffers

Replace the fixed `str_buffer[17]` pattern with dynamically allocated buffers. The `str_buffer` parameter passed into `callStringPrimitiveMethod` is only 17 bytes. Options:

**Option A (recommended)**: Allocate result strings on the heap using `HALLOC`. The runtime already does this extensively (see `actionStringAdd`). Use `PUSH_STR_HEAP(ptr, len)` or equivalent to push heap-allocated strings.

**Option B**: Use a large static buffer (e.g., 4096 bytes). Simpler but risks overflow on very long strings.

Going with Option A: each method that produces a string result will `HALLOC` the result buffer sized to the actual output length.

### 1b. Fix argument coercion

All methods need to accept any ActionVar type for numeric arguments, not just `ACTION_STACK_VALUE_F32`. Replace patterns like:
```c
if (num_args > 0 && args[0].type == ACTION_STACK_VALUE_F32)
    index = (int)VAL(float, &args[0].data.numeric_value);
```
with a proper `varToNumber()`/`varToInt32()` call that handles f32, f64, string, boolean, null, undefined:
```c
if (num_args > 0)
    index = varToInt32(&args[0]);  // handles all types
```

Similarly, string arguments should use `varToStringBuf()` to coerce non-string types.

Special cases per the test expectations:
- `indexOf()` with **no arguments**: returns the literal string `"undefined"` (not -1)
- `indexOf(null)`: coerces null to the string `"null"` and searches for it
- `indexOf(undefined)`: in SWF6+, coerces to `"undefined"`; in SWF5, coerces to `""`
- `charAt(undefined)` / `charAt(NaN)`: index 0 (toNumber → NaN → 0)
- `substr()` with no args: returns `"undefined"` (the string)
- `substring()` with no args: returns `"undefined"`

### 1c. Implement missing methods

**lastIndexOf(searchStr, endIndex)**:
- Search backwards from endIndex (default: string length) for the last occurrence
- `endIndex` is the starting position for backward search (inclusive)
- Edge cases: empty search string returns endIndex (clamped to length), no args returns `"undefined"`, null/undefined arg coercion same as indexOf

**concat(str1, str2, ...)**:
- Concatenate `this` string with all arguments, each coerced to string
- Returns new string; `"foo".concat()` returns `"foo"`

**slice(start, end)**:
- Like substring but negative indices count from end (like Python slicing)
- `slice(3, 1)` returns empty (no swap, unlike substring)
- `slice(-3, -1)` → last 3 chars minus last 1 char
- `slice()` with no args returns `"undefined"` (the string)
- `slice(null, null)` → empty (both coerce to 0)
- `slice(undefined, undefined)` → full string (start=0, end=length since undefined→NaN→0→special case: undefined end means length)

Actually, the test shows:
- `s.slice()` → `"undefined"` (no-args means the method wasn't recognized, returns the literal... wait, that means something different)

Looking at the expected output more carefully:
- `s.slice()` → `undefined` — this is the method returning undefined when called with no args
- `s.slice(null, null)` → empty string
- `s.slice(undefined, undefined)` → full string `"Hello1234"`

The SWF5 test (no multi-byte) has `s = "Hello1234"` (9 chars). The behavior:
- `slice(start, end)`: start default=0 if undefined, end default=length if undefined
- Wait no — `s.slice()` outputs `undefined` meaning the method returns undefined. That's the behavior when no args are passed.

**split(delimiter, limit)**:
- Split string by delimiter into an Array
- Returns the array's length on first trace, then elements joined by `,`
- `split("")` splits into individual characters (UTF-16 code units)
- `split(undefined)` / `split()` → array with single element (whole string) in SWF5; in SWF6+ `split(undefined)` splits on the literal `"undefined"`
- `split(",", 0)` → empty array
- `split(",", -100)` → empty array (negative limit = 0)
- `split(",", null)` → empty array (null coerces to 0)

**charCodeAt(index)**:
- Returns UTF-16 code unit at index as a number
- Out-of-range index: NaN in SWF6+, 0 in SWF5
- `charCodeAt()` / `charCodeAt(undefined)` / `charCodeAt(NaN)` → code of first char (index 0)

**String.fromCharCode(code1, code2, ...)**:
- Static method on String constructor (not on instances)
- Each argument coerced to uint16, then converted to the corresponding UTF-16 code unit
- `fromCharCode()` with no args → empty string
- `fromCharCode(80, 0, 82)` → `"P"` (NUL terminates the string — actually this means the result contains a NUL byte so output appears as just "P")
- `fromCharCode(65616)` → wraps to `80` → `"P"` (toUint16 = value & 0xFFFF)

### 1d. Fix substr negative-length semantics

The `string_methods_negative_args` test is entirely about `substr()` with negative lengths. The Flash behavior (derived from the test):

```
str = "hello world" (length 11)
str.substr(start, negative_length):
  effective_length = str.length + negative_length
  if effective_length <= 0: return ""
  then extract substr(start, effective_length) with the normal start/clamping rules
  BUT: if start + effective_length > str.length, clamp
```

Wait, let me re-examine. Looking at the test output for `text = "abcd"` (length 4):

```
text.substr(-5, -3) → "a"    // start=max(0,4+(-5))=0, len=4+(-3)=1 → "a"
text.substr(-5, -2) → "ab"   // start=0, len=4+(-2)=2 → "ab"
text.substr(-5, -1) → "abc"  // start=0, len=4+(-1)=3 → "abc"
text.substr(-3, -3) → "b"    // start=4+(-3)=1, len=4+(-3)=1 → "b"
text.substr(-3, -2) → "bc"   // start=1, len=4+(-2)=2 → "bc"
text.substr(-3, -1) → ""     // start=1, len=4+(-1)=3, but start+len=4=length... hmm
```

Actually wait: `text.substr(-3, -1)` → empty string. But `text.substr(-3, -2)` → `"bc"`. Let me reconsider.

The pattern for `text = "abcd"` (length 4), `text.substr(start, neg_len)`:
- negative length semantics: `effective_len = str.length + neg_len - start` (if start is resolved positive)

No wait, let me look more systematically. For `text.substr(0, neg)`:
```
substr(0, -5) → ""    // len = 4+(-5) = -1 → ""
substr(0, -4) → ""    // len = 4+(-4) = 0 → ""
substr(0, -3) → "a"   // len = 4+(-3) = 1 → "a"
substr(0, -2) → "ab"  // len = 4+(-2) = 2 → "ab"
substr(0, -1) → "abc" // len = 4+(-1) = 3 → "abc"
```

For `text.substr(1, neg)`:
```
substr(1, -5) → ""    // ??
substr(1, -4) → ""    // ??
substr(1, -3) → "b"   // ??
substr(1, -2) → "bc"  // ??
substr(1, -1) → ""    // ??
```

Hmm, `substr(1, -1)` → empty but `substr(1, -2)` → "bc"? That's `effective_len = length - start + neg_len`?

For start=1: `effective_len = 4 - 1 + neg_len = 3 + neg_len`
- neg=-5: 3+(-5)=-2 → ""
- neg=-4: 3+(-4)=-1 → ""
- neg=-3: 3+(-3)=0 → "" — but test says "b"!

OK, different formula. Let me try: `effective_len = length + neg_len`:
- start=1, neg=-3: len=4+(-3)=1 → substr(1,1) = "b" ✓
- start=1, neg=-2: len=4+(-2)=2 → substr(1,2) = "bc" ✓
- start=1, neg=-1: len=4+(-1)=3 → substr(1,3) = "bcd" — but test says ""!

So `effective_len = length + neg_len` works for some but not `substr(1, -1)`. Let me check `substr(2, neg)`:
```
substr(2, -3) → "c"   // len=4+(-3)=1 → substr(2,1)="c" ✓
substr(2, -2) → ""    // len=4+(-2)=2 → substr(2,2)="cd" — but test says ""!
substr(2, -1) → ""
```

So `substr(2, -2)` should give `"cd"` with `len=length+neg` but test says "". And `substr(2, -3)` gives `"c"`.

Looking for the pattern: when does it return empty?
- `substr(start, neg)` → empty when `start + (length + neg) >= length`
- i.e., when `start >= -neg`
- i.e., when `start + neg >= 0`... no, `start >= -neg` → `start + neg >= 0`

Check: `substr(1, -1)`: `1 >= 1` → true → empty ✓
Check: `substr(2, -2)`: `2 >= 2` → true → empty ✓
Check: `substr(2, -3)`: `2 >= 3` → false → not empty, len=4+(-3)=1 → "c" ✓
Check: `substr(1, -3)`: `1 >= 3` → false → len=4+(-3)=1 → "b" ✓
Check: `substr(-3, -1)`: start resolves to 1, `1 >= 1` → true → empty ✓
Check: `substr(-3, -2)`: start=1, `1 >= 2` → false → len=4+(-2)=2 → "bc" ✓

So the rule is:
1. Resolve start (negative start → `max(0, length + start)`)
2. If `neg_len < 0`: `effective_len = length + neg_len`; if `start >= -neg_len` OR `effective_len <= 0`: return ""
3. Otherwise: extract `substr(start, effective_len)`

Actually simplifying: if neg_len < 0:
- `effective_len = length + neg_len`
- if `effective_len <= 0` → empty
- if `start + effective_len > length` → empty (equivalent to `start >= -neg_len`)
- otherwise: `substr(start, effective_len)`

Wait: `start + effective_len > length` → `start + length + neg_len > length` → `start + neg_len > 0` → `start > -neg_len`. But we said `start >= -neg_len`. Let me recheck `substr(1, -1)`: `start + eff_len = 1 + 3 = 4 = length`. So `>= length` is the condition for empty, not `> length`.

Actually wait. `substr(1, -1)`: effective_len = 4+(-1) = 3. We'd extract from index 1, length 3 → "bcd". But test says empty. So the condition must be `start + effective_len >= length`... no, that's `1 + 3 = 4 ≥ 4` → true → empty ✓.

But `substr(0, -1)`: effective_len = 3. `0 + 3 = 3 < 4` → not empty → "abc" ✓.
And `substr(-3, -2)` (start=1): effective_len = 2. `1 + 2 = 3 < 4` → not empty → "bc" ✓.

Hmm but then what about: `"hello world".substr(0, -1)` → "hello worl" (10 chars). length=11, eff_len=11+(-1)=10. `0+10=10 < 11` → not empty → extract 10 chars from index 0 → "hello worl" ✓.

And `"hello world".substr(3, -4)` → "lo worl". length=11, eff_len=11+(-4)=7. `3+7=10 < 11` → extract → "lo worl" ✓.

And `"hello world".substr(8, -4)` → "". length=11, eff_len=7. `8+7=15 >= 11` → empty ✓.

And `"hello world".substr(3, -3)` → "". eff_len=11+(-3)=8. `3+8=11 >= 11` → empty ✓.

So the rule: if `start + effective_len >= length` → empty. Otherwise extract. This is equivalent to: the negative length clips from the END of the string; if the clip reaches past the start position, result is empty.

Better stated: **negative length means "stop N characters before the end of the string"**. So `substr(start, -N)` extracts from `start` up to `length - N` (exclusive). If `start >= length - N`, result is empty.

That maps to: `end = length + neg_len`. If `end <= start` → empty. Otherwise extract `str[start..end]`.

Check: `text.substr(0, -1)`: end=4+(-1)=3. 3>0 → "abc" ✓.
Check: `text.substr(1, -1)`: end=3. 3>1 → "bc"... but test says ""!

That doesn't work either. Let me re-examine.

```
text = "abcd", length = 4
text.substr(0, -1) → "abc"   // end = 3
text.substr(1, -1) → ""      // end = ???
text.substr(1, -2) → "bc"    //
text.substr(1, -3) → "b"     //
```

If end = length + neg_len:
- (0, -1): end=3, start=0, 3>0 → "abc" ✓
- (1, -1): end=3, start=1, 3>1 → should be "bc" but test says "" ✗

So that formula is wrong. Let me try yet another approach. Maybe it's: `effective_length = max(0, length + neg_len - start)`:
- (0, -1): max(0, 4-1-0) = 3 → "abc" ✓
- (1, -1): max(0, 4-1-1) = 2 → "bc" — but test says "" ✗

Hmm. Let me study more cases from the "hello world" (length 11) test:

```
substr(0, -1) → "hello worl"  // 10 chars
substr(0, -4) → "hello w"     // 7 chars
substr(3, -3) → ""            // empty
substr(3, -4) → "lo worl"    // 7 chars from index 3
substr(3, -5) → "lo wor"     // 6 chars from index 3
substr(4, -4) → ""           // empty
substr(4, -5) → "o worl"    // 6 chars from index 4
```

For (3, -4): 7 chars from index 3. That's "lo worl" = str[3..10]. end would be 10. length+neg=11+(-4)=7. start+len=3+7=10. Hmm that equals 10 which is < 11.

For (3, -3): length+neg=11+(-3)=8. start+len=3+8=11 which is ≥ 11 → empty.

For (4, -4): length+neg=7. start+len=4+7=11 ≥ 11 → empty.
For (4, -5): length+neg=6. start+len=4+6=10 < 11 → extract 6 chars from index 4 → "o worl" ✓.

OK so: `effective_len = length + neg_len`. Then: if `start + effective_len >= length` → empty. Otherwise → extract `effective_len` chars from `start`.

Back to "abcd" (length 4):
- (1, -1): eff=3. 1+3=4 >= 4 → empty ✓
- (1, -2): eff=2. 1+2=3 < 4 → extract 2 chars from 1 → "bc" ✓
- (1, -3): eff=1. 1+1=2 < 4 → extract 1 char from 1 → "b" ✓

It works! The condition is `start + effective_len >= length`, which is equivalent to `start >= -neg_len`. Or equivalently: the extracted range `[start, start+eff_len)` must not reach the end of the string. If it does (or exceeds), result is empty.

### Tests fixed by Phase 1

With buffer limits removed, argument coercion fixed, and missing methods implemented (all operating on raw bytes/ASCII):

- **string_methods_swfv5**: Should jump from 62% → ~90%+. SWF5 tests use ASCII-only strings (no emoji/CJK). The only SWF5 quirks are: `charCodeAt` returns 0 (not NaN) for out-of-range, `split("")` returns 1-element array with whole string, `indexOf(undefined)` searches for `""` not `"undefined"`.
- **string_methods**: Should jump from 60% → ~75%. The multi-byte sections will still fail (toUpperCase/toLowerCase Unicode, charAt/charCodeAt/substr on multi-byte strings), but all ASCII sections will pass.
- **string_methods_negative_args**: Should jump from 53% → ~95%+. This test is entirely ASCII with `text = "abcd"` and `str = "hello world"`.

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_methods_swfv5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_methods_negative_args --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_methods --diff --verbose
```

---

## Phase 2: UTF-16 Awareness

**Goal**: Make all string operations work on UTF-16 code units instead of raw bytes. Flash strings are internally UTF-16; our runtime stores UTF-8. We need conversion functions.

### 2a. UTF-16 code unit indexing

Create helper functions to map between UTF-16 indices and UTF-8 byte offsets:

```c
// Count UTF-16 code units in a UTF-8 string
// (codepoints U+0000-U+FFFF = 1 unit, U+10000-U+10FFFF = 2 units / surrogate pair)
static size_t utf16_length(const char* utf8_str, size_t byte_len);

// Convert UTF-16 index to byte offset in UTF-8 string
// Returns byte offset, or -1 if index is out of range
static int utf16_index_to_byte_offset(const char* utf8_str, size_t byte_len, int utf16_index);

// Get UTF-16 code unit at a given UTF-16 index
// Returns the code unit (0x0000-0xFFFF), or -1 if out of range
static int utf16_code_unit_at(const char* utf8_str, size_t byte_len, int utf16_index);

// Encode a single UTF-16 code unit as UTF-8
// Returns number of bytes written (1-3)
static int utf16_unit_to_utf8(uint16_t code_unit, char* out);
```

### 2b. Fix `.length` property

Replace `utf8_strlen()` with `utf16_length()` in the `actionGetMember` handler for string `.length` (line ~10757).

Expected results:
- `"foo".length` → 3 (unchanged, ASCII)
- `"😋".length` → 2 (currently returns 1 with utf8_strlen; U+1F60B is a surrogate pair)
- `"😋Спасибо𝌆𝌆hello".length` → 18

### 2c. Update all string methods to use UTF-16 indexing

Every method that takes or returns an index needs to convert between UTF-16 code unit indices and UTF-8 byte offsets:

- **charAt(n)**: Return the n-th UTF-16 code unit as a string (possibly a lone surrogate → U+FFFD)
- **charCodeAt(n)**: Return the n-th UTF-16 code unit as a number
- **indexOf/lastIndexOf**: Search using UTF-16 semantics (but since both operands are the same encoding, byte-level search still works for indexOf — the issue is the return value must be a UTF-16 index, and the startIndex argument is UTF-16)
- **substr(start, length)**: start and length are in UTF-16 code units
- **substring(start, end)**: start and end are in UTF-16 code units
- **slice(start, end)**: same
- **split("")**: Split into individual UTF-16 code units

### 2d. Fix SWF4 legacy string ops

- **actionStringLength()** / **actionMbStringLength()**: Both should return UTF-16 code unit count in SWF6+ (the test `string_ops_swf6` confirms this). In SWF4-5, `length()` returns byte count and `mblength()` returns character count.
- **actionCharToAscii()** (ord): Should return the UTF-16 code unit of the first character. For `"😋"` (U+1F60B), this is 0xD83D (high surrogate) → 55357... wait, the test expects `65533` which is U+FFFD (replacement character). So surrogates above U+FFFF get U+FFFD.

Actually looking more carefully at the test:
```
// ord("😋")
65533
// mbord("😋")
65533
```
65533 = 0xFFFD = replacement character. So `ord`/`mbord` returns the first UTF-16 code unit, and since 😋 (U+1F60B) encodes as surrogate pair D83D+DE0B, the first unit is D83D — but the test expects FFFD. That means Flash treats surrogates as replacement characters in SWF6+ `ord()`.

Wait, or does it mean Flash's ord() returns the Unicode codepoint but clamped to BMP (0-65535), and anything above FFFF returns FFFD? Let me check:
- `ord("愛")` → 24859 → that's 0x611B = 愛, correct BMP codepoint
- `ord("😋")` → 65533 → 0xFFFD, since 😋 = U+1F60B > 0xFFFF

So: `ord()`/`mbord()` returns the BMP codepoint, or FFFD for supplementary characters.

- **actionAsciiToChar()** (chr) / **actionMbAsciiToChar()** (mbchr): Should convert a code point (mod 65536) to the corresponding UTF-8 character.
  - `chr(12345)` → `〹` (U+3039)
  - `chr(65616)` → 65616 mod 65536 = 80 → `P`
  - `chr(-65456)` → -65456 mod 65536 = 80 → `P` (toUint16 wrapping)
  - `chr(0xd801)` → `�` (surrogate → replacement character)
  - `chr(0xabababab)` → `0xabababab & 0xFFFF = 0xABAB` → `ꮫ` (U+ABAB)

### 2e. Unicode case mapping for toUpperCase/toLowerCase

The tests expect **full Unicode case mapping** including Latin Extended, Cyrillic, Greek, Armenian, Georgian, and more (see lines 279-285 of `string_methods/output.txt`).

Implementation options:
1. **Lookup table**: Generate a ~2KB table mapping each codepoint to its upper/lower case equivalent. Only the BMP matters (U+0000-U+FFFF).
2. **ICU**: Too heavyweight for this project.
3. **Simplified table**: Cover the specific ranges tested: Basic Latin, Latin Extended, Cyrillic, Greek, Armenian, Georgian, Coptic, Latin Extended Additional, Greek Extended, Circled Latin, Fullwidth Latin.

Recommended: Generate a mapping table at build time or embed a static table. The Flash Player uses Unicode 5.1.0 case mapping (vintage 2008), which covers:
- Basic Latin: A-Z ↔ a-z
- Latin-1 Supplement: À-Ö (U+00C0-00D6) ↔ à-ö (U+00E0-00F6), Ø-Þ ↔ ø-þ
- Latin Extended-A/B, Cyrillic, Greek, Armenian, Georgian, etc.

The table can be a sorted array of `{codepoint, upper, lower}` tuples for sparse ranges, or a flat array for dense ranges.

### Tests fixed by Phase 2

- **string_methods**: Jump from ~75% → ~95%+ (the remaining failures would be very edge-case)
- **string_methods_swfv5**: Unchanged (already ASCII-only, 90%+ after Phase 1)
- **string_methods_negative_args**: Unchanged (already ASCII-only, 95%+ after Phase 1)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_methods --diff --verbose
```

---

## Phase 3: SWF4/6 String Operations (string_ops_swf6)

**Goal**: Fix the legacy SWF4 string functions (ord, chr, length, substring as functions, not methods) to use UTF-16 semantics in SWF6+ mode.

### What the test expects

`string_ops_swf6` (95 expected lines, currently 0% pass) tests the SWF4 string *functions* (not dot-syntax methods) when run under SWF6:

1. **length("str") / mblength("str")**: Both should return UTF-16 code unit count
   - `length("😋")` → 2 (surrogate pair)
   - `length("😋Спасибо𝌆𝌆hello")` → 18

2. **ord("str") / mbord("str")**: Return first character's code
   - `ord("f")` → 102
   - `ord("愛")` → 24859 (BMP codepoint)
   - `ord("😋")` → 65533 (FFFD, supplementary → replacement)
   - `ord(null)` → 110 (first char of "null" = 'n')

3. **chr(n) / mbchr(n)**: Convert number to character
   - `chr(80)` → `P`
   - `chr(12345)` → `〹`
   - `chr(65616)` → `P` (wraps mod 65536)
   - `chr(0xd801)` → `�` (surrogate → replacement)
   - `chr(null)` → empty (null → 0 → NUL char → appears empty)
   - `chr(true)` → empty (true → 1 → SOH → appears empty)

4. **substring(str, start, count) / mbsubstring(str, start, count)**: 1-based extraction
   - Indices are 1-based (Flash SWF4 convention)
   - `substring(s, 1, 2)` → first 2 characters
   - Negative/zero indices treated as 1
   - Very large/negative values wrap via int32 overflow

### Implementation

Most of this is already partially implemented. The fixes needed:

1. **actionStringLength**: Use `utf16_length()` instead of `str_size`
2. **actionMbStringLength**: Use `utf16_length()` instead of `utf8_strlen()`
3. **actionCharToAscii**: Decode first UTF-8 character to BMP codepoint (FFFD for supplementary)
4. **actionAsciiToChar**: Convert uint16 code to UTF-8 character
5. **actionStringExtract / actionMbStringExtract**: Use UTF-16 indexing, 1-based to 0-based conversion, dynamic buffer

Also fix the first-line issue: the test currently outputs 0 lines, suggesting the recompiler or runtime crashes/outputs nothing. Check if `string_ops_swf6` compiles and runs at all.

### Tests fixed by Phase 3

- **string_ops_swf6**: From 0% → ~90%+

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_ops_swf6 --diff --verbose
```

---

## Phase 4: String Paths (Deferred)

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

These should be addressed as part of:
- **MovieClip Methods** plan (attachMovie, duplicateMovieClip, eval)
- **Timer** plan (setInterval/setTimeout)
- **Unload** plan (unloadMovie events)

`string_paths_hidden` (65% passing) is the closest to passing and depends mainly on fixing nested child clip lookup by name. It may improve alongside other MovieClip scope/path resolution work.

---

## Implementation Priority and Dependencies

```
Phase 1 (ASCII fixes) ──→ Phase 2 (UTF-16) ──→ Phase 3 (SWF4/6 ops)
```

Phase 2 depends on Phase 1 (buffer management infrastructure). Phase 3 depends on Phase 2 (UTF-16 helper functions).

**Estimated test impact:**

| Phase | Tests Improved | Lines Fixed (est.) | Cumulative New Passes |
|-------|---------------|-------------------|----------------------|
| 1 | string_methods_swfv5, string_methods_negative_args, string_methods | ~300 lines | ~0 new test passes (partial improvements) |
| 2 | string_methods | ~80 lines | ~0-1 new test passes |
| 3 | string_ops_swf6 | ~85 lines | ~0-1 new test passes |

Note: Even with 90%+ line match rates, tests only "pass" at 100%. The remaining edge cases in each test may require further work. But the line match improvements benefit the overall statistics and demonstrate progress.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Rewrite `callStringPrimitiveMethod()`: remove buffer limits, fix arg coercion, add lastIndexOf/concat/slice/split/charCodeAt. Fix `actionStringLength`/`actionMbStringLength`/`actionCharToAscii`/`actionAsciiToChar`/`actionStringExtract`/`actionMbStringExtract` for UTF-16. Add `String.fromCharCode` as static method on String constructor. Add UTF-16 helper functions. Add Unicode case mapping table. |
| `include/actionmodern/action.h` | No new declarations needed (all changes are internal to action.c) |

### Recompiler (SWFRecomp/)

No recompiler changes needed for string methods. The bytecodes (`ActionCallMethod`, `ActionStringLength`, `ActionCharToAscii`, etc.) are already correctly emitted.

### New files (possibly)

| File | Purpose |
|------|---------|
| `src/actionmodern/unicode_case.h` | Unicode case mapping table (auto-generated or hand-crafted) |

---

## Design Decisions

1. **UTF-8 internal storage, UTF-16 external semantics**: The runtime stores all strings as UTF-8 (this is deeply embedded and would be very expensive to change). All methods that take or return indices will convert between UTF-16 code unit indices and byte offsets on the fly. This has O(n) cost per index conversion but the strings in typical Flash content are short.

2. **Dynamic allocation for results**: Use `HALLOC` for string method results instead of fixed buffers. The `PUSH_STR` macro already supports heap-allocated strings via `PUSH_STR_HEAP`. If not, we can allocate and let the string be copied by PUSH_STR — check how PUSH_STR works.

3. **Unicode case table scope**: Only cover codepoints actually tested by `string_methods/output.txt`. The test has ~700 characters for toLowerCase and ~700 for toUpperCase. We need a mapping table that covers Basic Latin through Fullwidth Latin (roughly U+0000-U+FF60), plus Cyrillic, Greek Extended, Armenian, Georgian, Coptic, Latin Extended Additional. Approximately 1500 entries.

4. **SWF version awareness**: Several behaviors differ between SWF5 and SWF6+:
   - `indexOf(undefined)`: SWF5 searches for `""`, SWF6+ searches for `"undefined"`
   - `charCodeAt()` out of range: SWF5 returns 0, SWF6+ returns NaN
   - `split("")`: SWF5 returns 1-element array with whole string, SWF6+ splits by code unit
   - `split(undefined)`: SWF5 returns 1-element array, SWF6+ splits on literal `"undefined"`

   We need to check the SWF version at runtime. The `app_context->swf_version` field should be available.

---

## Quick Win Estimate

**Phase 1 alone** would improve line match rates significantly:
- string_methods_negative_args: 53% → ~95% (+~100 lines)
- string_methods_swfv5: 62% → ~90% (+~75 lines)
- string_methods: 60% → ~75% (+~40 lines)

Total: ~215 additional matching lines from Phase 1. This is purely runtime changes (no recompiler work) and is self-contained.

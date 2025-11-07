# STRING_GREATER Opcode Test (0x68)

## Opcode Information

- **Opcode**: `STRING_GREATER` (0x68)
- **Name**: ActionStringGreater
- **Category**: String Comparison
- **Flash Version**: 4+

## Description

The `STRING_GREATER` opcode performs lexicographic (dictionary-style) string comparison. It pops two strings from the stack and pushes a boolean result indicating whether the second string is greater than the first.

This opcode was added (along with `GREATER` for numeric comparison) to avoid argument evaluation order issues when emulating greater-than with less-than + NOT operations.

## Operation

1. Pop `arg1` from stack (first operand)
2. Pop `arg2` from stack (second operand)
3. Compare: `arg2 > arg1` using byte-by-byte lexicographic comparison
4. Push boolean result: `1.0` for true, `0.0` for false

**Stack Effect**: `[..., arg2, arg1] → [..., result]`

## Implementation

### Files Modified

1. **SWFRecomp/include/action/action.hpp**
   - Added `SWF_ACTION_STRING_GREATER = 0x68` enum

2. **SWFRecomp/src/action/action.cpp**
   - Added translation case for STRING_GREATER opcode

3. **SWFModernRuntime/include/actionmodern/action.h**
   - Declared `void actionStringGreater(char* stack, u32* sp);`

4. **SWFModernRuntime/src/actionmodern/action.c**
   - Implemented runtime function using `strcmp()` for lexicographic comparison

### Implementation Details

The implementation uses C's standard `strcmp()` function which performs byte-by-byte comparison:
- Returns positive value if first string > second string
- Returns negative value if first string < second string
- Returns 0 if strings are equal

Comparison is:
- **Case-sensitive**: 'Z' (90) < 'a' (97)
- **Lexicographic**: Character-by-character comparison
- **Length-aware**: Longer string is greater when prefix matches

## Test Cases

### Test 1: Basic comparison (false)
**Stack**: `[apple, zebra]` → pop arg1=zebra, pop arg2=apple → compare `apple > zebra`
```actionscript
// Equivalent to: trace("apple" > "zebra");
```
Expected: `0` (false, 'a' < 'z')

### Test 2: Basic comparison (true)
**Stack**: `[zebra, apple]` → pop arg1=apple, pop arg2=zebra → compare `zebra > apple`
```actionscript
// Equivalent to: trace("zebra" > "apple");
```
Expected: `1` (true, 'z' > 'a')

### Test 3: Equal strings
**Stack**: `[hello, hello]` → pop arg1=hello, pop arg2=hello → compare `hello > hello`
```actionscript
// Equivalent to: trace("hello" > "hello");
```
Expected: `0` (false, equal strings are not greater)

### Test 4: Case sensitivity
**Stack**: `[a, Z]` → pop arg1=Z, pop arg2=a → compare `a > Z`
```actionscript
// Equivalent to: trace("a" > "Z");
```
Expected: `1` (true, lowercase 'a'=97 > uppercase 'Z'=90)

### Test 5: Prefix comparison
**Stack**: `[hello, hello world]` → pop arg1="hello world", pop arg2=hello → compare `hello > hello world`
```actionscript
// Equivalent to: trace("hello" > "hello world");
```
Expected: `0` (false, shorter string when prefix matches)

## Expected Output

```
0
1
0
1
0
```

## Building and Running

```bash
# From SWFRecomp directory
./scripts/build_test.sh string_greater_swf_4 native

# Run test
./tests/string_greater_swf_4/build/native/string_greater_swf_4
```

## Known Issues

~~There is currently a runtime issue with pushing multiple strings in sequence that causes segmentation faults.~~

**RESOLVED** (commit 3c3ea22): The segmentation fault issue was caused by `oldSP` variable reuse in PUSH macros. This has been fixed by declaring `oldSP` as a local variable within each macro scope. The test now runs successfully without segfaults.

## Implementation Status

- [x] Enum defined in action.hpp
- [x] Translation case added to action.cpp
- [x] API declared in action.h
- [x] Runtime implemented in action.c
- [x] Test SWF created with comprehensive test cases
- [x] Test directory setup complete
- [x] Builds without errors
- [x] Test execution working correctly
- [x] Runtime string handling issue resolved (commit 3c3ea22)

## References

- SWF File Format Specification v19
- ActionScript 2.0 Language Reference
- Similar opcode: `STRING_EQUALS` (0x13)
- Numeric equivalent: `GREATER` (0x48)

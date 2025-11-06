# STRING_LESS Opcode Test (0x29)

This test verifies the implementation of the STRING_LESS opcode for ActionScript 2.

## Opcode Details

- **Opcode**: 0x29 (STRING_LESS)
- **Category**: String Comparison
- **Operation**: Lexicographic string comparison (less than)
- **SWF Version**: 4+

## Test Cases

### Test Case 1: Basic comparison (true)
```actionscript
trace("apple" < "banana");
```
**Expected**: `1` (true - "apple" comes before "banana" lexicographically)

### Test Case 2: Basic comparison (false)
```actionscript
trace("zebra" < "apple");
```
**Expected**: `0` (false - "zebra" comes after "apple")

### Test Case 3: Case sensitivity
```actionscript
trace("Apple" < "apple");
```
**Expected**: `1` (true - uppercase 'A' (65) < lowercase 'a' (97) in ASCII)

### Test Case 4: Equal strings
```actionscript
trace("hello" < "hello");
```
**Expected**: `0` (false - equal strings are not less than each other)

### Test Case 5: Prefix comparison
```actionscript
trace("cat" < "catch");
```
**Expected**: `1` (true - shorter string is less when it's a prefix of the longer string)

### Test Case 6: Empty string
```actionscript
trace("" < "a");
```
**Expected**: `1` (true - empty string is less than any non-empty string)

## Expected Output

```
1
0
1
0
1
1
```

## Implementation Notes

- Uses standard C `strcmp()` for lexicographic comparison
- Comparison is case-sensitive
- Based on Unicode/ASCII code point ordering
- Stack order: first value pushed is left operand, second value pushed is right operand
- Result: 1.0 for true, 0.0 for false

## Running the Test

```bash
cd SWFRecomp
./scripts/build_test.sh string_less_swf_4 native
./tests/string_less_swf_4/build/native/string_less_swf_4
```

## Files

- `create_test_swf.py` - Python script to generate test.swf
- `config.toml` - SWFRecomp configuration
- `test.swf` - Generated SWF file (created by build script)
- `README.md` - This file

## Implementation Location

- **Enum**: `SWFRecomp/include/action/action.hpp` (SWF_ACTION_STRING_LESS = 0x29)
- **Translation**: `SWFRecomp/src/action/action.cpp` (case SWF_ACTION_STRING_LESS)
- **API**: `SWFModernRuntime/include/actionmodern/action.h` (actionStringLess)
- **Runtime**: `SWFModernRuntime/src/actionmodern/action.c` (actionStringLess implementation)

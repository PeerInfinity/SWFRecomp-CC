# MB ASCII to Char Test (SWF 4)

## Overview

This test validates the `ActionMBAsciiToChar` (0x37) opcode implementation.

## Opcode Description

**ActionMBAsciiToChar (0x37)**: Converts a numeric Unicode code point to its corresponding multibyte character string (UTF-8 encoded).

**Stack Operation**:
```
Before: [... codepoint_number]
After:  [... character_string]
```

## Test Cases

The test exercises the following scenarios:

1. **Basic ASCII (1-byte UTF-8)**:
   - `mbchr(65)` → `"A"`
   - `mbchr(97)` → `"a"`

2. **Latin Extended (2-byte UTF-8)**:
   - `mbchr(233)` → `"é"` (U+00E9)
   - `mbchr(241)` → `"ñ"` (U+00F1)

3. **CJK Characters (3-byte UTF-8)**:
   - `mbchr(20013)` → `"中"` (U+4E2D - Chinese character)
   - `mbchr(26085)` → `"日"` (U+65E5 - Japanese character)

4. **Symbols (3-byte UTF-8)**:
   - `mbchr(8364)` → `"€"` (U+20AC - Euro symbol)

5. **Edge Cases**:
   - `mbchr(0)` → `""` (null character)
   - `mbchr(9999999)` → `""` (out of valid Unicode range)

## Expected Output

```
A
a
é
ñ
中
日
€


```

Note: The last two lines are empty strings for the edge cases (null and out-of-range).

## Implementation Details

The implementation properly encodes Unicode code points as UTF-8:

- **1-byte sequence** (U+0000 to U+007F): ASCII range
- **2-byte sequence** (U+0080 to U+07FF): Latin extended and other scripts
- **3-byte sequence** (U+0800 to U+FFFF): Most common scripts including CJK
- **4-byte sequence** (U+10000 to U+10FFFF): Supplementary characters

Invalid code points (> 0x10FFFF) are handled by returning an empty string.

## Files

- `test.swf` - Generated SWF file with test bytecode
- `create_test_swf.py` - Python script to generate test.swf
- `config.toml` - SWFRecomp configuration
- `test_info.json` - Test metadata for validation system
- `validate.py` - Validation script that checks output correctness

## Building and Running

```bash
# Build test
cd SWFRecomp
./scripts/build_test.sh mb_ascii_to_char_swf_4 native

# Run test manually
./tests/mb_ascii_to_char_swf_4/build/native/mb_ascii_to_char_swf_4

# Run validation
cd tests
./all_tests.sh mb_ascii_to_char_swf_4
```

## Related Opcodes

- **ActionAsciiToChar (0x33)**: Single-byte ASCII version
- **ActionMBCharToAscii (0x36)**: Inverse operation (char → code point)
- **ActionMBStringLength (0x31)**: Get character count (not byte count)

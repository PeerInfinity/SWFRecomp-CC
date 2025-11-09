# MB_ASCII_TO_CHAR Edge Cases Test

## Purpose

This test validates edge case handling for the ActionMBAsciiToChar (0x37) opcode by testing boundary conditions, invalid code points, and special UTF-8 encoding scenarios.

## Test Cases

### UTF-8 Encoding Boundaries

1. **Maximum 1-byte UTF-8** (127): Last code point in ASCII range
2. **Minimum 2-byte UTF-8** (128): First code point requiring 2 bytes
3. **Maximum 2-byte UTF-8** (2047): Last 2-byte UTF-8 code point
4. **Minimum 3-byte UTF-8** (2048): First code point requiring 3 bytes
5. **Maximum 3-byte UTF-8** (65535): Last 3-byte UTF-8 code point
6. **Minimum 4-byte UTF-8** (65536): First code point requiring 4 bytes

### Surrogate Pair Range

7. **Before surrogate range** (0xD7FF): Valid code point just before surrogates
8. **Surrogate start** (0xD800): First surrogate pair code point (invalid in UTF-8)
9. **Surrogate end** (0xDFFF): Last surrogate pair code point (invalid in UTF-8)
10. **After surrogate range** (0xE000): Valid code point just after surrogates

### Special Values

11. **Negative number** (-1): Tests negative value handling
12. **Zero** (0): Null character handling
13. **Maximum Unicode** (0x10FFFF): Highest valid Unicode code point
14. **Beyond Unicode** (0x110000): Just beyond valid Unicode range

## Expected Behavior

- **Negative numbers**: Convert to large unsigned values, caught by range check → empty string
- **Zero**: Produces null character (may appear as empty in output)
- **Valid code points**: Properly encoded as UTF-8
- **Surrogate pairs**: Encoded as-is (matches Flash Player behavior - not strictly valid Unicode but Flash doesn't validate)
- **Out of range** (> 0x10FFFF): Empty string

## Implementation Notes

The implementation follows Flash Player behavior:
- Does not strictly validate Unicode (allows surrogate pairs)
- Converts negative floats to unsigned integers before range check
- Returns empty string for code points beyond valid Unicode range
- Properly encodes all 4 UTF-8 byte lengths

## Running the Test

```bash
cd SWFRecomp
./scripts/build_test.sh mb_ascii_to_char_edge_cases_swf_4 native
./tests/mb_ascii_to_char_edge_cases_swf_4/build/native/mb_ascii_to_char_edge_cases_swf_4
```

The test outputs each character followed by a label for identification.

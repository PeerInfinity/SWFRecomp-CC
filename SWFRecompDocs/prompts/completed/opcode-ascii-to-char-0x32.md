# AS2 Opcode Implementation Task: ASCII_TO_CHAR

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ASCII_TO_CHAR**

## Opcode Specification

**Opcode Name**: ASCII_TO_CHAR
**Hex Value**: 0x32
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts an ASCII code value to its corresponding character string.

**Operation**: Pop number from stack, convert to ASCII character, push result as string.

**Expected Behavior**:
- Pop value from stack and convert to number
- Convert number to integer (truncate/round)
- Get the character corresponding to that ASCII/Unicode code point
- Push the single-character string onto the stack
- Handle out-of-range values gracefully (negative, > 255 or > 65535)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/ascii_to_char_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII
```actionscript
trace(chr(65));
```
Expected output: `A`

### Test Case 2: Lowercase letter
```actionscript
trace(chr(97));
```
Expected output: `a`

### Test Case 3: Special character
```actionscript
trace(chr(33));
```
Expected output: `!`

### Test Case 4: Space
```actionscript
trace(chr(32));
```
Expected output: ` ` (space character)

### Test Case 5: Extended ASCII
```actionscript
trace(chr(233));
```
Expected output: `é`

### Test Case 6: Out of range (edge case)
```actionscript
trace(chr(999));
```
Expected output: Depends on modulo behavior (999 % 256 = 231) or empty string

## Implementation Hints

**Pattern**: This is a number-to-string conversion operation.

**Reference these similar opcodes**:
- `actionStringAdd` in `SWFModernRuntime/src/actionmodern/action.c` (string result handling)
- `convertFloat` utility (for type conversion to number)
- `PUSH_STR` macro for pushing string results

**Implementation outline**:
```c
void actionAsciiToChar(char* stack, u32* sp, char* str_buffer)
{
    // Convert top of stack to number
    convertFloat(stack, sp);

    // Pop the numeric value
    ActionVar a;
    popVar(stack, sp, &a);

    // Get integer code (truncate decimal)
    int code = (int)a.value.f32;

    // Handle out-of-range values (wrap to 0-255 or 0-65535)
    code = code & 0xFF;  // For single-byte encoding
    // OR: code = code & 0xFFFF;  // For Unicode

    // Handle negative values
    if (code < 0) {
        code = 0;  // or some other behavior
    }

    // Create single-character string
    str_buffer[0] = (char)code;
    str_buffer[1] = '\0';

    // Push result string
    PUSH_STR(str_buffer, 1);
}
```

**Note**:
- Check Flash specification for exact behavior with out-of-range values
- May need to handle UTF-8 encoding for codes > 127
- String buffer management is critical - ensure str_buffer has sufficient lifetime

**Important Considerations**:
- Return value is a string, not a character
- Need to use str_buffer parameter (passed to function)
- Ensure null termination of result string
- Handle edge cases: negative numbers, very large numbers, NaN

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/ascii_to_char_swf_4/README.md` - Test description and expected output
- Document Flash-specific encoding behavior (Latin-1 vs UTF-8)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (out of range, negative)
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `chr(code)` or accessed via `String.fromCharCode(code)`.

**Flash Version**: Available in SWF 4+

**Character Encoding**: Flash AS2 typically uses UTF-8 encoding, but may treat codes 0-255 as Latin-1 for compatibility.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

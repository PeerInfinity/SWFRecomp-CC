# AS2 Opcode Implementation Task: STRING_EXTRACT

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STRING_EXTRACT**

## Opcode Specification

**Opcode Name**: STRING_EXTRACT (Substring)
**Hex Value**: 0x15
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Extracts a substring from a string given a starting index and length.

**Operation**: Pop length, pop index, pop string; extract substring; push result.

**Expected Behavior**:
- Pop `length` (number of characters to extract)
- Pop `index` (starting position, 0-based)
- Pop `string` (source string)
- Extract substring starting at `index` with `length` characters
- Push the resulting substring onto the stack
- Handle out-of-bounds gracefully (clamp to string length)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/string_extract_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic substring
```actionscript
trace(substring("Hello World", 0, 5));
```
Expected output: `Hello`

### Test Case 2: Middle of string
```actionscript
trace(substring("Hello World", 6, 5));
```
Expected output: `World`

### Test Case 3: Length extends beyond string
```actionscript
trace(substring("Hello", 2, 100));
```
Expected output: `llo` (clamp to actual string length)

### Test Case 4: Index beyond string length
```actionscript
trace(substring("Hello", 10, 5));
```
Expected output: `` (empty string)

### Test Case 5: Zero length
```actionscript
trace(substring("Hello", 2, 0));
```
Expected output: `` (empty string)

## Implementation Hints

**Pattern**: This is a string manipulation operation with three parameters.

**Reference these similar opcodes**:
- `actionStringLength` (0x14) - String handling reference
- `actionStringAdd` (0x21) - String result handling

**Implementation outline**:
```c
void actionStringExtract(char* stack, u32* sp, char* str_buffer)
{
    // Pop length
    convertFloat(stack, sp);
    ActionVar length_var;
    popVar(stack, sp, &length_var);
    int length = (int)length_var.value.f32;

    // Pop index
    convertFloat(stack, sp);
    ActionVar index_var;
    popVar(stack, sp, &index_var);
    int index = (int)index_var.value.f32;

    // Pop string
    char src_buffer[17];
    convertString(stack, sp, src_buffer);
    const char* src = src_buffer;  // Adjust based on actual string location
    POP();

    // Get source string length
    int src_len = strlen(src);

    // Handle out-of-bounds index
    if (index < 0) index = 0;
    if (index >= src_len) {
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
        return;
    }

    // Handle out-of-bounds length
    if (length < 0) length = 0;
    if (index + length > src_len) {
        length = src_len - index;
    }

    // Extract substring
    int i;
    for (i = 0; i < length && i < 16; i++) {  // Limit to buffer size
        str_buffer[i] = src[index + i];
    }
    str_buffer[i] = '\0';

    // Push result
    PUSH_STR(str_buffer, i);
}
```

**Note**:
- AS2 `substring()` function uses (string, index, length) parameter order
- Index is 0-based
- Need to clamp index and length to valid ranges
- Result must fit in str_buffer (typically 17 bytes max)

**Important Considerations**:
- Parameter order: length is popped first, then index, then string
- Bounds checking is critical
- Edge cases: negative index/length, out-of-bounds, empty string
- Buffer overflow protection

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/string_extract_swf_4/README.md` - Test description and expected output
- Document bounds handling behavior

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (out of bounds, negative values)
- [ ] No buffer overflows
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is `substring(str, index, length)`.

**Flash Version**: Available in SWF 4+

**Note on AS3 difference**: AS3's `substr()` and `substring()` have different semantics. This opcode implements AS2 behavior.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

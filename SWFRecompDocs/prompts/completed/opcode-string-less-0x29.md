# AS2 Opcode Implementation Task: STRING_LESS

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STRING_LESS**

## Opcode Specification

**Opcode Name**: STRING_LESS (String Less Than)
**Hex Value**: 0x29
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Compares two strings lexicographically and returns true if the first is less than the second.

**Operation**: Pop two strings from stack, compare lexicographically, push boolean result.

**Expected Behavior**:
- Pop string `a` from stack
- Pop string `b` from stack
- Compare `b < a` lexicographically (dictionary order)
- Push 1.0 if true, 0.0 if false
- Comparison is case-sensitive
- Use Unicode/ASCII code point ordering

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/string_less_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic comparison (true)
```actionscript
trace("apple" < "banana");
```
Expected output: `1`

### Test Case 2: Basic comparison (false)
```actionscript
trace("zebra" < "apple");
```
Expected output: `0`

### Test Case 3: Case sensitivity
```actionscript
trace("Apple" < "apple");
```
Expected output: `1` (uppercase 'A' = 65 < lowercase 'a' = 97)

### Test Case 4: Equal strings
```actionscript
trace("hello" < "hello");
```
Expected output: `0`

### Test Case 5: Prefix comparison
```actionscript
trace("cat" < "catch");
```
Expected output: `1` (shorter string is less when it's a prefix)

### Test Case 6: Empty string
```actionscript
trace("" < "a");
```
Expected output: `1`

## Implementation Hints

**Pattern**: This is a binary comparison operation for strings.

**Reference these similar opcodes**:
- `actionStringEquals` (0x13) - String comparison reference
- `actionLess` (0x0F) - Boolean result pattern

**Implementation outline**:
```c
void actionStringLess(char* stack, u32* sp)
{
    // Pop second operand (a)
    char str_a[17];
    convertString(stack, sp, str_a);
    const char* a = str_a;  // Adjust based on actual string location
    POP();

    // Pop first operand (b)
    char str_b[17];
    convertString(stack, sp, str_b);
    const char* b = str_b;  // Adjust based on actual string location
    POP();

    // Lexicographic comparison using strcmp
    // strcmp returns: < 0 if b < a, 0 if equal, > 0 if b > a
    int cmp_result = strcmp(b, a);

    // Push boolean result
    float result = (cmp_result < 0) ? 1.0f : 0.0f;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Note**:
- Use `strcmp()` from `<string.h>` for lexicographic comparison
- Result is boolean: 1.0 for true, 0.0 for false
- Comparison is case-sensitive by default
- Stack order: second pop is first operand (b), first pop is second operand (a)

**Important Considerations**:
- String pointers must remain valid during comparison
- Ensure proper stack order (b < a, not a < b)
- Edge cases: empty strings, equal strings, null
- Case sensitivity (unlike some other comparison opcodes)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/string_less_swf_4/README.md` - Test description and expected output
- Document lexicographic ordering behavior

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (empty, equal, prefix)
- [ ] Stack order correct (b < a)
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is the `<` operator when used on strings.

**Flash Version**: Available in SWF 4+

**Comparison Details**:
- Lexicographic (dictionary) order
- Case-sensitive
- Based on character code values
- Shorter string is less if it's a prefix of longer string

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

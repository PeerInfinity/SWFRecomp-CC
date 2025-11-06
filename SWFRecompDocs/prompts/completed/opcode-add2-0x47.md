# AS2 Opcode Implementation Task: ADD2

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ADD2**

## Opcode Specification

**Opcode Name**: ADD2 (Type-Aware Addition)
**Hex Value**: 0x47
**Category**: Utility Operations / Arithmetic
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Performs addition with ECMA-262 type coercion rules. Unlike the basic ADD (0x0A) opcode, ADD2 follows strict type conversion semantics.

**Operation**: Pop two values, perform type-aware addition, push result.

**Expected Behavior**:
- Pop value `a` from stack
- Pop value `b` from stack
- If either operand is a string, perform string concatenation
- Otherwise, convert both to numbers and perform numeric addition
- Push result onto stack
- Follows ECMA-262 specification for the `+` operator

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/add2_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Number + Number
```actionscript
trace(5 + 3);
```
Expected output: `8`

### Test Case 2: String + String
```actionscript
trace("Hello" + " " + "World");
```
Expected output: `Hello World`

### Test Case 3: Number + String (string concatenation)
```actionscript
trace(5 + " items");
```
Expected output: `5 items`

### Test Case 4: String + Number (string concatenation)
```actionscript
trace("Total: " + 42);
```
Expected output: `Total: 42`

### Test Case 5: Boolean + Number
```actionscript
trace(true + 5);
```
Expected output: `6` (true converts to 1)

### Test Case 6: Null + Number
```actionscript
trace(null + 5);
```
Expected output: `5` (null converts to 0)

## Implementation Hints

**Pattern**: This is a type-aware binary operation with special handling.

**Reference these similar opcodes**:
- `actionAdd` (0x0A) - Basic addition (may not have type awareness)
- `actionStringAdd` (0x21) - String concatenation

**Implementation outline**:
```c
void actionAdd2(char* stack, u32* sp, char* str_buffer)
{
    // Peek at types without popping
    u32 sp_top = *sp;
    u8 type_a = STACK_TOP_TYPE;

    // Move to second value
    u32 sp_second = VAL(u32, &(stack[*sp + 4]));  // Get previous_sp
    u8 type_b = stack[sp_second];  // Type of second value

    // Check if either operand is a string
    if (type_a == ACTION_STACK_VALUE_STRING || type_b == ACTION_STACK_VALUE_STRING) {
        // String concatenation path

        // Convert first operand to string
        char str_a[17];
        convertString(stack, sp, str_a);
        POP();

        // Convert second operand to string
        char str_b[17];
        convertString(stack, sp, str_b);
        POP();

        // Concatenate (b + a, due to stack order)
        snprintf(str_buffer, 17, "%s%s", str_b, str_a);

        // Push result
        PUSH_STR(str_buffer, strlen(str_buffer));
    } else {
        // Numeric addition path

        // Convert and pop first operand
        convertFloat(stack, sp);
        ActionVar a;
        popVar(stack, sp, &a);

        // Convert and pop second operand
        convertFloat(stack, sp);
        ActionVar b;
        popVar(stack, sp, &b);

        // Perform addition
        float result = b.value.f32 + a.value.f32;

        // Push result
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
    }
}
```

**Note**:
- Type checking determines operation (string concatenation vs numeric addition)
- If either operand is string, result is string
- Otherwise, both convert to numbers and add
- Follows ECMA-262 rules for type coercion

**Important Considerations**:
- Type detection before popping (to avoid losing type information)
- String concatenation may require str_buffer parameter
- Buffer overflow protection for string results
- Proper type conversion for booleans, null, undefined

**Difference from ADD (0x0A)**:
- ADD (0x0A): Simple numeric addition, may always treat as numbers
- ADD2 (0x47): Type-aware, performs string concatenation when appropriate

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/add2_swf_5/README.md` - Test description and expected output
- Document type coercion rules
- Explain difference from ADD (0x0A)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all type combinations
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] String concatenation works correctly
- [ ] Numeric addition works correctly
- [ ] Type coercion follows ECMA-262 rules
- [ ] Documentation created

## Additional Notes

**ActionScript Operator**: In AS2, this implements the `+` operator behavior in SWF 5+.

**Flash Version**: Available in SWF 5+ (replaces ADD 0x0A for better type awareness)

**ECMA-262 Type Coercion**:
1. If either operand is string → convert both to string and concatenate
2. Otherwise → convert both to number and add

**Type Conversion Rules**:
- String → String (no conversion)
- Number → String (format as decimal)
- Boolean → String ("true"/"false") or Number (1/0)
- null → String ("null") or Number (0)
- undefined → String ("undefined") or Number (NaN)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

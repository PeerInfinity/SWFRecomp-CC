# AS2 Opcode Implementation Task: TYPEOF

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TYPEOF**

## Opcode Specification

**Opcode Name**: TYPEOF
**Hex Value**: 0x3C
**Category**: Utility Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Returns a string indicating the type of a value.

**Operation**: Pop value, determine type, push type name as string.

**Expected Behavior**:
- Pop value from stack
- Determine the value's type
- Push a string onto the stack indicating the type
- Type strings: "number", "string", "boolean", "object", "undefined", "null", "movieclip", "function"

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/typeof_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Number type
```actionscript
trace(typeof(42));
```
Expected output: `number`

### Test Case 2: String type
```actionscript
trace(typeof("hello"));
```
Expected output: `string`

### Test Case 3: Boolean type
```actionscript
trace(typeof(true));
```
Expected output: `boolean`

### Test Case 4: Undefined type
```actionscript
var x;
trace(typeof(x));
```
Expected output: `undefined`

### Test Case 5: Object type
```actionscript
var obj = {};
trace(typeof(obj));
```
Expected output: `object`

## Implementation Hints

**Pattern**: This is a type introspection operation.

**Reference these similar opcodes**:
- Stack type system in `action.h` (ACTION_STACK_VALUE_* constants)
- String result handling like `actionStringAdd`

**Implementation outline**:
```c
void actionTypeof(char* stack, u32* sp, char* str_buffer)
{
    // Peek at the type without modifying value
    u8 type = STACK_TOP_TYPE;

    // Pop the value
    POP();

    // Determine type string based on stack type
    const char* type_str;
    switch (type) {
        case ACTION_STACK_VALUE_F32:
        case ACTION_STACK_VALUE_U32:
            type_str = "number";
            break;

        case ACTION_STACK_VALUE_STRING:
            type_str = "string";
            break;

        case ACTION_STACK_VALUE_BOOLEAN:
            type_str = "boolean";
            break;

        case ACTION_STACK_VALUE_OBJECT:
            type_str = "object";
            break;

        case ACTION_STACK_VALUE_UNDEFINED:
            type_str = "undefined";
            break;

        case ACTION_STACK_VALUE_NULL:
            type_str = "null";
            break;

        case ACTION_STACK_VALUE_FUNCTION:
            type_str = "function";
            break;

        case ACTION_STACK_VALUE_MOVIECLIP:
            type_str = "movieclip";
            break;

        default:
            type_str = "undefined";
            break;
    }

    // Copy to str_buffer and push
    int len = strlen(type_str);
    strncpy(str_buffer, type_str, 16);
    str_buffer[len] = '\0';
    PUSH_STR(str_buffer, len);
}
```

**Note**:
- Type strings must match Flash AS2 specification exactly
- Common types: "number", "string", "boolean", "object", "undefined"
- Special types: "movieclip", "function", "null"
- Result is always a string

**Important Considerations**:
- Type detection must be accurate
- String result must be null-terminated
- Match Flash AS2 type string conventions
- Handle all possible stack value types

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/typeof_swf_5/README.md` - Test description and expected output
- Document type string mappings

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct type strings for all types
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] All stack value types handled
- [ ] Type strings match Flash AS2 specification
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is the `typeof` operator.

**Flash Version**: Available in SWF 5+

**Type String Reference**:
| Value Type | typeof Result |
|------------|---------------|
| Number | "number" |
| String | "string" |
| Boolean | "boolean" |
| Object | "object" |
| Array | "object" |
| Function | "function" |
| MovieClip | "movieclip" |
| undefined | "undefined" |
| null | "null" |

**Note**: In AS2, `typeof null` returns "null" (not "object" like JavaScript).

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

# AS2 Opcode Implementation Task: ActionTypeOf

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionTypeOf**

## Opcode Specification

**Opcode Name**: ActionTypeOf
**Hex Value**: 0x44
**Category**: Type Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Returns the type of a value as a string, equivalent to the ActionScript typeof operator.

**Operation**: Pop value from stack, determine its type, push type name as string.

**Expected Behavior** (from SWF Spec 19):
- Pops the value to determine the type of off the stack
- Determines the type according to ActionScript rules
- Pushes a string with the type of the object onto the stack

**Possible type strings**:
- `"number"` - for numeric values (including NaN and Infinity)
- `"boolean"` - for true/false values
- `"string"` - for string values
- `"object"` - for objects, arrays, and null (special case)
- `"movieclip"` - for MovieClip instances
- `"null"` - for null value
- `"undefined"` - for undefined value
- `"function"` - for function objects

**Stack Operations**:
```
Before: [... value]
After:  [... type_string]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TYPEOF = 0x44` to `SWFRecomp/include/action/action.hpp`
   - **Note**: There may already be a `SWF_ACTION_TYPEOF` defined at 0x3C - verify and consolidate if needed
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with various type checks
6. **Setup Test Directory** - Create `SWFRecomp/tests/typeof_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Primitive types
```actionscript
trace(typeof 42);
trace(typeof 3.14);
trace(typeof "hello");
trace(typeof true);
```
Expected output:
```
number
number
string
boolean
```

### Test Case 2: Special number values
```actionscript
trace(typeof NaN);
trace(typeof Infinity);
```
Expected output:
```
number
number
```

### Test Case 3: Null and undefined
```actionscript
trace(typeof null);
trace(typeof undefined);
var x;
trace(typeof x);
```
Expected output:
```
object
undefined
undefined
```

### Test Case 4: Objects and arrays
```actionscript
var obj = {a: 1};
trace(typeof obj);
var arr = [1, 2, 3];
trace(typeof arr);
```
Expected output:
```
object
object
```

### Test Case 5: Functions
```actionscript
function myFunc() {}
trace(typeof myFunc);
trace(typeof trace);  // Built-in function
```
Expected output:
```
function
function
```

### Test Case 6: MovieClip (if supported)
```actionscript
trace(typeof _root);
```
Expected output:
```
movieclip
```

## Implementation Hints

**Pattern**: This is a type introspection operation that examines stack value types.

**Reference these similar opcodes**:
- Stack value type checking in other opcodes
- String operations for returning type names

**Implementation outline**:
```c
void actionTypeOf(char* stack, u32* sp, char* str_buffer)
{
    // Peek at the top of stack to determine type
    // (don't convert, we want the raw type)
    u8 type = STACK_TOP_TYPE;

    // Pop the value
    ActionVar a;
    popVar(stack, sp, &a);

    // Determine type string
    const char* type_str;
    switch (type) {
        case ACTION_STACK_VALUE_F32:
            type_str = "number";
            break;
        case ACTION_STACK_VALUE_STRING:
            type_str = "string";
            break;
        case ACTION_STACK_VALUE_BOOL:
            type_str = "boolean";
            break;
        case ACTION_STACK_VALUE_NULL:
            // Note: typeof null returns "object" in JavaScript/ActionScript
            type_str = "object";
            break;
        case ACTION_STACK_VALUE_UNDEFINED:
            type_str = "undefined";
            break;
        case ACTION_STACK_VALUE_OBJECT:
            // Check if it's a function
            // For now, return "object" (may need function detection)
            type_str = "object";
            break;
        case ACTION_STACK_VALUE_MOVIECLIP:
            type_str = "movieclip";
            break;
        case ACTION_STACK_VALUE_FUNCTION:
            type_str = "function";
            break;
        default:
            type_str = "undefined";
            break;
    }

    // Copy type string to buffer and push
    strcpy(str_buffer, type_str);
    PUSH_STR(str_buffer, strlen(type_str));
}
```

**Translation (action.cpp)**:
```cpp
case SWF_ACTION_TYPEOF:
{
    out_script << "\t" << "// TypeOf - get type of value" << endl
               << "\t" << "actionTypeOf(stack, sp, str_buffer);" << endl;
    break;
}
```

**Important Notes**:
- **typeof null**: Returns `"object"` (JavaScript quirk, ActionScript follows this)
- **Type detection**: Must examine raw stack type, not convert values
- **Function detection**: May need to distinguish function objects from regular objects
- **MovieClip**: Special type for Flash movie clips (may be stub in NO_GRAPHICS mode)
- **SWF 5+ support**: This opcode is available in SWF version 5 and later

## Edge Cases

1. **typeof null returns "object"**: This is a well-known JavaScript quirk that ActionScript inherits
2. **Uninitialized variables**: Should return `"undefined"`
3. **NaN and Infinity**: Both return `"number"`
4. **Empty string**: Still returns `"string"`
5. **Array**: Returns `"object"` (arrays are objects in ActionScript)
6. **Function objects**: Must distinguish from regular objects

## Type System Notes

**ActionScript Type Hierarchy**:
```
Primitive Types:
- number (includes NaN, Infinity)
- string
- boolean
- null (typeof returns "object")
- undefined

Reference Types:
- object (plain objects, arrays)
- function
- movieclip (Flash-specific)
```

**Stack Value Types** (check action.h):
```c
#define ACTION_STACK_VALUE_F32       0
#define ACTION_STACK_VALUE_STRING    1
#define ACTION_STACK_VALUE_BOOL      2
#define ACTION_STACK_VALUE_NULL      3
#define ACTION_STACK_VALUE_UNDEFINED 4
#define ACTION_STACK_VALUE_OBJECT    5
// ... check for additional types
```

## Testing Strategy

**Unit tests**:
- Test each primitive type (number, string, boolean)
- Test special values (null, undefined, NaN, Infinity)
- Test reference types (object, array, function)
- Test uninitialized variables

**Integration tests**:
- Use with conditional logic (if (typeof x == "number"))
- Chain with other type operations
- Test with variables of different types

**Validation**:
```bash
# Build and run test
cd SWFRecomp
./scripts/build_test.sh typeof_swf_5 native
./tests/typeof_swf_5/build/native/typeof_swf_5

# Expected: Type strings matching test cases
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to action.hpp (or verified if already exists)
- [ ] Translation case added to action.cpp
- [ ] Function declared in action.h
- [ ] Runtime implemented in action.c with proper type detection
- [ ] Test produces correct type strings for all test cases
- [ ] Handles special cases (null → "object", undefined, NaN) correctly
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Documentation created

## Documentation

Create or update:
- `SWFRecomp/tests/typeof_swf_5/README.md` - Test description and expected output
- Document any discrepancies between ActionScript and JavaScript typeof behavior
- Note any limitations in NO_GRAPHICS mode (e.g., MovieClip detection)

## Related Opcodes

- **ActionToNumber (0x4A)**: Convert value to number
- **ActionToString (0x4B)**: Convert value to string
- **ActionInstanceOf (0x54)**: Check if object is instance of class
- **ActionEquals2 (0x49)**: Type-aware equality comparison

## Special Considerations

**Enum Conflict**: The codebase shows `SWF_ACTION_TYPEOF` at both 0x3C and 0x44. According to the SWF spec:
- **0x3C = ActionDefineLocal** (not typeof)
- **0x44 = ActionTypeOf** (correct)

You may need to:
1. Verify existing enum definitions
2. Fix any incorrect mappings
3. Update any existing tests that use the wrong opcode

**ActionScript Quirks**:
- `typeof null` returns `"object"` (not `"null"`)
- `typeof NaN` returns `"number"` (not `"NaN"`)
- `typeof []` returns `"object"` (not `"array"`)
- `typeof function(){}` returns `"function"`

---

**Estimated Time**: 2-4 hours
**Category**: Type Operations
**Complexity**: MEDIUM
**SWF Version**: 5+

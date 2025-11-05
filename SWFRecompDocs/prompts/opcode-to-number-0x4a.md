# Opcode Implementation Task: TO_NUMBER (0x4A)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TO_NUMBER**

## Opcode Specification

**Opcode Name**: TO_NUMBER
**Spec Name**: ActionToNumber
**Hex Value**: 0x4A
**Category**: Type Conversion
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: Converts the object on the top of the stack into a number, and pushes the number back to the stack. For the Object type, the ActionScript valueOf() method is invoked to convert the object to a Number type for ActionToNumber. Conversions between primitive types, such as from String to Number, are built-in.

**Operation**: Pops value, converts to number, pushes result.

**Expected Behavior**:
- Pop a value from stack
- Convert to number based on type:
  - Number: return as-is
  - String: parse as number (empty→0, invalid→NaN)
  - Boolean: true→1, false→0
  - Null/undefined: 0 or NaN
  - Object: call valueOf() (not needed for basic implementation)
- Push the resulting number to the stack
- Available in SWF 5 and later

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TO_NUMBER = 0x4A` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionToNumber(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/to_number_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh to_number_swf_4 native` and verify output

## Test Cases

### Test Case 1: Number input (no change)
```actionscript
trace(Number(42.5));
```
Expected output: `42.5`

### Test Case 2: String to number
```actionscript
trace(Number("123.45"));
```
Expected output: `123.45`

### Test Case 3: Empty string
```actionscript
trace(Number(""));
```
Expected output: `0`

### Test Case 4: Integer string
```actionscript
trace(Number("42"));
```
Expected output: `42`

### Test Case 5: Invalid string (implementation-dependent)
```actionscript
trace(Number("hello"));
```
Expected output: `NaN` or `0` (depending on parser)

## Implementation Hints

**Category**: This is a type conversion operation (unary).

**Pattern**: Unary type conversion
```
peek type → convert based on type → pop → push result
```

**Reference these similar opcodes**:
- `convertFloat` utility function - does this conversion already!
- `actionToInteger` - similar conversion pattern
- `actionToString` - opposite conversion

**Implementation outline**:
```c
void actionToNumber(char* stack, u32* sp)
{
    // The convertFloat() utility already does this conversion!
    // It handles: numbers (passthrough), strings (parse), etc.

    // Convert to float (this is the main work)
    convertFloat(stack, sp);

    // Value is already converted on stack, nothing more needed
    // (convertFloat modifies stack in-place)

    // Note: For a more explicit implementation, you could:
    // ActionVar a;
    // peekVar(stack, sp, &a);
    // If already float, do nothing
    // If string, parse and replace
    // But convertFloat() already handles this
}
```

**Simplified implementation** (since convertFloat does the work):
```c
void actionToNumber(char* stack, u32* sp)
{
    // Convert top of stack to number
    // convertFloat() handles all type conversions
    convertFloat(stack, sp);
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_TO_NUMBER:
{
    out_script << "\t" << "// ToNumber" << endl
               << "\t" << "actionToNumber(stack, sp);" << endl;
    break;
}
```

**Note**:
- This is essentially what `convertFloat()` already does
- For basic types (number, string), `convertFloat()` handles conversion
- Result is a floating-point number on the stack
- Empty string converts to 0
- Invalid strings may convert to NaN or 0 (check convertFloat behavior)

## Documentation

Create these files as you work:
- `SWFRecomp/tests/to_number_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x4A)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] String to number conversion works
- [ ] Number input passes through unchanged
- [ ] Empty string converts to 0
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Very simple implementation: just call `convertFloat()`
- The `convertFloat()` utility already handles all type conversions
- For SWF 5+, but works in our SWF 4 runtime
- Result is floating-point number stored on stack
- Check what `convertFloat()` does with invalid strings (may need adjustment)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

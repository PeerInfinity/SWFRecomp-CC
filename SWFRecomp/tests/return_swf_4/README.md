# RETURN Opcode Test (0x3E)

## Description

This test demonstrates the RETURN opcode (0x3E) for ActionScript 2. The RETURN opcode is used to return a value from a function and transfer control back to the caller.

## Opcode Details

- **Opcode**: 0x3E
- **Name**: RETURN
- **Category**: Control Flow
- **Description**: Returns a value from a function

## Test Implementation

### Simplified Test Approach

Since this test is created before the DefineFunction (0x9B) and CallFunction (0x3D) opcodes are implemented, this is a simplified demonstration of the RETURN opcode's basic behavior:

1. Push a value to the stack (simulating a return value)
2. Execute the RETURN opcode
3. Trace the value to verify it remains on the stack

### Test Cases

**Test 1: Return numeric value**
- Push number 42
- Execute RETURN (0x3E)
- Trace the value
- Expected output: `42`

**Test 2: Return string value**
- Push string "returned"
- Execute RETURN (0x3E)
- Trace the value
- Expected output: `returned`

## Expected Output

```
42
returned
```

## Implementation Notes

### Current Behavior

In this simplified test:
- The RETURN opcode is recognized and processed
- The value remains on the stack (as it would for a caller)
- No actual function exit occurs (since we're not in a function context)

### Future Enhancement

When DefineFunction and CallFunction are implemented, this test should be enhanced to:
- Define actual functions that return values
- Call those functions
- Verify the return value is properly passed back to the caller
- Test nested function calls with multiple returns
- Test early returns and conditional returns

### Full Function Test Example

Once DefineFunction is available, a complete test would look like:

```actionscript
function add(a, b) {
    return a + b;
}

trace(add(5, 3));  // Should output: 8
```

## Build and Run

```bash
# From SWFRecomp directory
./scripts/build_test.sh return_swf_4 native

# Run the test
./tests/return_swf_4/build/native/return_swf_4
```

## Technical Details

### Stack Behavior

**Before RETURN**:
```
[... return_value]
```

**After RETURN**:
```
[... ]  (in callee context - not applicable in this test)
[... return_value]  (in caller context)
```

### Translation

The SWFRecomp translator generates:
```c
// Return
actionReturn(stack, sp);
return;  // C return statement exits the function
```

### Runtime Implementation

The `actionReturn` function is minimal in this implementation:
- The return value is already on the stack
- The C `return;` statement handles the actual function exit
- The caller accesses the return value from the stack

## Limitations

This test has the following limitations due to missing opcodes:
- No actual function definition (requires DefineFunction 0x9B)
- No function calls (requires CallFunction 0x3D)
- Cannot test proper function entry/exit semantics
- Cannot test call stack management
- Cannot test nested returns

These limitations will be addressed when the function-related opcodes are implemented.

## Success Criteria

- ✅ Test compiles without errors
- ✅ RETURN opcode is recognized
- ✅ No crashes or segfaults
- ✅ Values remain on stack after RETURN
- ✅ Output matches expected values
- ⏳ Full function context testing (pending DefineFunction implementation)

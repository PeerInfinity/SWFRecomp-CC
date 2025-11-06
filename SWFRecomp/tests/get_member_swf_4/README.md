# GET_MEMBER Opcode Test

This test validates the implementation of the `GET_MEMBER` opcode (0x4E) in ActionScript 2.

## Opcode Details

- **Opcode**: GET_MEMBER (0x4E)
- **Category**: Object Operations
- **Complexity**: COMPLEX (4-6 hours)

## Description

The GET_MEMBER opcode retrieves a property value from an object or primitive type.

**Stack Operations**:
```
Before: [... object, property_name]
After:  [... property_value]
```

## Implementation

### Files Modified

1. **SWFRecomp/include/action/action.hpp**
   - Added `SWF_ACTION_GET_MEMBER = 0x4E` enum

2. **SWFRecomp/src/action/action.cpp**
   - Added translation case that generates `actionGetMember(stack, sp)` call

3. **SWFModernRuntime/include/actionmodern/action.h**
   - Added `void actionGetMember(char* stack, u32* sp)` declaration

4. **SWFModernRuntime/src/actionmodern/action.c**
   - Implemented `actionGetMember()` function
   - Added `pushUndefined()` helper function
   - Updated `actionTrace()` to handle UNDEFINED type
   - Updated `pushVar()` to handle OBJECT and UNDEFINED types

5. **SWFModernRuntime/include/actionmodern/stackvalue.h**
   - Added `ACTION_STACK_VALUE_UNDEFINED = 5` type

6. **SWFRecomp/scripts/build_test.sh**
   - Added object.c to build process

## Test Cases

### Test Case 1: String length property
```actionscript
// Equivalent ActionScript:
// var x = "Hello";
// trace(x.length);
```

**Bytecode**:
- PUSH "Hello"
- PUSH "length"
- GET_MEMBER (0x4E)
- TRACE

**Expected Output**: `5`

### Test Case 2: Undefined property
```actionscript
// Equivalent ActionScript:
// var y = "World";
// trace(y.xyz);  // xyz doesn't exist
```

**Bytecode**:
- PUSH "World"
- PUSH "xyz"
- GET_MEMBER (0x4E)
- TRACE

**Expected Output**: `undefined`

## Test Results

✅ **All tests passing**

```
$ ./tests/get_member_swf_4/build/native/get_member_swf_4
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
5
undefined
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Supported Features

- ✅ String.length property access
- ✅ ASObject property lookup (via existing object infrastructure)
- ✅ Returns `undefined` for missing properties
- ✅ Returns `undefined` for properties on primitive types (except strings)
- ⚠️ Array support pending (INIT_ARRAY opcode not yet implemented)
- ⚠️ Object literal support pending (INIT_OBJECT opcode not yet implemented)

## Build and Run

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh get_member_swf_4 native

# Run the test
./tests/get_member_swf_4/build/native/get_member_swf_4
```

## Implementation Notes

### Object Model Integration

This opcode leverages the existing object infrastructure:
- `ASObject` structure with reference counting
- `getProperty()` function for property lookup
- `ActionVar` for type-safe value storage

### Type Handling

The implementation handles the following types:
- **ACTION_STACK_VALUE_OBJECT**: Looks up property in object's property array
- **ACTION_STACK_VALUE_STRING**: Special handling for `.length` property
- **Other types**: Returns undefined

### Edge Cases

- NULL object → undefined
- Missing property → undefined
- Empty string length → 0
- Property name conversion to string (automatic via `convertString()`)

## Future Enhancements

When INIT_OBJECT (0x43) and INIT_ARRAY (0x42) are implemented, this test can be expanded to include:
- Object literal property access
- Array element access via numeric indices
- Array.length property
- Nested property access

## Dependencies

- ✅ Object infrastructure (object.h, object.c)
- ✅ Variable system (variables.h, variables.c)
- ✅ Stack value types (stackvalue.h)
- ⚠️ INIT_OBJECT (0x43) - for comprehensive object testing
- ⚠️ INIT_ARRAY (0x42) - for array testing

# InitArray Test (Opcode 0x42)

## Overview

This test validates the INIT_ARRAY opcode (0x42) which creates array objects in ActionScript 2.

## Test Cases

### Test Case 1: Empty Array
Creates an empty array with 0 elements: `[]`

### Test Case 2: Simple Array
Creates an array with 3 elements: `[1.0, 2.0, 3.0]`

## Expected Output

```
Array creation test passed
```

## Current Limitations

This initial test verifies that arrays can be created without crashing. However, full array functionality testing requires additional opcodes:

- **GET_MEMBER (0x4E)**: Required to access `array.length` property and `array[index]` elements
- **SET_MEMBER (0x4F)**: Required to modify array elements

Once these opcodes are implemented, this test should be expanded to include:
- Verifying array length property
- Accessing individual array elements
- Testing nested arrays
- Testing mixed-type arrays

## Implementation Details

### Array Structure (ASArray)
```c
typedef struct {
    u32 refcount;      // Reference count for memory management
    u32 length;        // Number of elements
    u32 capacity;      // Allocated capacity
    ActionVar elements[];  // Flexible array member
} ASArray;
```

### Memory Management
- Uses reference counting (not garbage collection)
- Initial refcount = 1 when array is created
- Increment refcount when storing in variables or containers
- Decrement refcount when popping or overwriting
- Free array when refcount reaches 0

### Stack Operations
```
Before InitArray: [..., elem_N, elem_N-1, ..., elem_1, count]
After InitArray:  [..., array_reference]
```

## Build and Run

```bash
cd SWFRecomp
./scripts/build_test.sh init_array_swf_4 native
./tests/init_array_swf_4/build/native/init_array_swf_4
```

## Design Decisions

1. **Fixed-size arrays**: Initial implementation uses fixed-size arrays (no dynamic resizing)
2. **Dense arrays**: No support for sparse arrays in this version
3. **Reference counting**: Arrays are memory-managed using reference counting
4. **Nested arrays**: Properly handles nested arrays with reference counting

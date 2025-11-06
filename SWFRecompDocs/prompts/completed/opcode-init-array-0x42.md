# Opcode Implementation Task: INIT_ARRAY

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **INIT_ARRAY**

## Opcode Specification

**Opcode Name**: INIT_ARRAY
**Hex Value**: 0x42
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Initializes a new array object with specified elements.

**Operation**: Pop array element count, pop elements, create array, push array reference.

**Expected Behavior** (from SWF Spec 19):
- Pop `elems` (number of elements) from stack
- Pop `[arg1, arg2, ..., argN]` from stack (in reverse order)
- Create a new array as a ScriptObject
- Set object type to Array
- Populate array with initial elements
- Push the newly created array object to the stack
- Arguments are pushed in reverse order (rightmost first, leftmost last)

**Stack Operations**:
```
Before: [... elem_N, elem_N-1, ..., elem_1, count]
After:  [... array_reference]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_INIT_ARRAY = 0x42` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that creates arrays
6. **Setup Test Directory** - Create `SWFRecomp/tests/init_array_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Empty array
```actionscript
var arr = [];
trace(arr.length);
```
Expected output: `0`

### Test Case 2: Simple array
```actionscript
var arr = [1, 2, 3];
trace(arr[0]);
trace(arr[1]);
trace(arr[2]);
trace(arr.length);
```
Expected output:
```
1
2
3
3
```

### Test Case 3: Mixed type array
```actionscript
var arr = ["hello", 42, true];
trace(arr[0]);
trace(arr[1]);
trace(arr[2]);
```
Expected output:
```
hello
42
true
```

### Test Case 4: Nested arrays
```actionscript
var arr = [[1, 2], [3, 4]];
trace(arr[0][0]);
trace(arr[0][1]);
trace(arr[1][0]);
```
Expected output:
```
1
2
3
```

## Implementation Hints

**Pattern**: This is an object creation operation with memory management.

### Object Model Design

This opcode requires implementing a basic array object model. The implementation guide discusses using **compile-time inlined reference counting** instead of runtime GC.

**Key Design Decisions**:

1. **Array Structure**: Define an `ASArray` structure with:
   - `refcount` (u32) - for reference counting
   - `length` (u32) - number of elements
   - `capacity` (u32) - allocated capacity
   - `elements[]` - array of ActionVar structures

2. **Memory Management**: Use reference counting:
   ```c
   typedef struct {
       u32 refcount;
       u32 length;
       u32 capacity;
       ActionVar elements[];
   } ASArray;
   ```

3. **Allocation Pattern**:
   ```c
   ASArray* allocArray(u32 initial_capacity) {
       ASArray* arr = malloc(sizeof(ASArray) + initial_capacity * sizeof(ActionVar));
       arr->refcount = 1;  // Initial reference
       arr->length = 0;
       arr->capacity = initial_capacity;
       return arr;
   }
   ```

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_INIT_ARRAY:
{
    out_script << "\t" << "// InitArray" << endl
               << "\t" << "actionInitArray(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionInitArray(char* stack, u32* sp)
{
    // 1. Pop array element count
    ActionVar count_var;
    convertFloat(stack, sp);
    popVar(stack, sp, &count_var);
    u32 num_elements = (u32) count_var.value.f32;

    // 2. Allocate array
    ASArray* arr = allocArray(num_elements);
    arr->length = num_elements;

    // 3. Pop elements in reverse order and populate array
    for (int i = num_elements - 1; i >= 0; i--) {
        ActionVar elem;
        popVar(stack, sp, &elem);
        arr->elements[i] = elem;

        // If element is object/array, increment refcount
        if (elem.type == ACTION_STACK_VALUE_OBJECT ||
            elem.type == ACTION_STACK_VALUE_ARRAY) {
            retainObject((void*) elem.value.u64);
        }
    }

    // 4. Push array reference to stack
    PUSH(ACTION_STACK_VALUE_ARRAY, VAL(u64, arr));
}
```

**Array Access** (for testing):
```c
// You'll need to implement array indexing for GET_MEMBER/SET_MEMBER
// This can be done as part of this opcode or deferred to those opcodes
```

### Reference Counting Notes

When implementing arrays:
- **Increment refcount** when: storing in variable, adding to another container
- **Decrement refcount** when: popping without storing, overwriting variable
- **Release array** when refcount reaches 0:
  ```c
  void releaseArray(ASArray* arr) {
      if (--arr->refcount == 0) {
          // Release all element objects
          for (u32 i = 0; i < arr->length; i++) {
              if (arr->elements[i].type == ACTION_STACK_VALUE_OBJECT ||
                  arr->elements[i].type == ACTION_STACK_VALUE_ARRAY) {
                  releaseObject((void*) arr->elements[i].value.u64);
              }
          }
          free(arr);
      }
  }
  ```

### Integration with Existing Code

- **Stack Types**: Add `ACTION_STACK_VALUE_ARRAY` to the type enum in `action.h`
- **Variable Storage**: Arrays can be stored in variables using existing `actionSetVariable`
- **Property Access**: Array indexing will be implemented in GET_MEMBER/SET_MEMBER opcodes

Similar implemented opcodes to reference:
- `actionPush` for stack manipulation
- `actionSetVariable` / `actionGetVariable` for storage patterns

### Testing Strategy

1. **Unit tests**: Test array creation with various sizes
2. **Property tests**: Verify length property works
3. **Element access**: Test reading elements (requires GET_MEMBER or array[index] syntax)
4. **Memory tests**: Verify no memory leaks with valgrind
5. **Integration tests**: Combine with variables and other opcodes

### Edge Cases to Handle

- Empty arrays (length = 0)
- Single-element arrays
- Large arrays (>100 elements)
- Arrays containing other arrays (nested)
- Arrays containing objects
- Undefined elements (sparse arrays - may defer to later)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/init_array_swf_4/README.md` - Test description and expected output
- Document your array structure design decisions
- Note any deferred features (like sparse arrays)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] No memory leaks (test with valgrind if available)
- [ ] Edge cases handled correctly
- [ ] Documentation created
- [ ] Array length property accessible
- [ ] Elements properly reference-counted

## Important Notes

**Object Model Coordination**: This is a foundational opcode that establishes the array object model. Consider coordinating with implementations of:
- `INIT_OBJECT` (0x43) - similar pattern for objects
- `GET_MEMBER` (0x4E) - for array element access
- `SET_MEMBER` (0x4F) - for array element modification

**Simplified Initial Implementation**: For the first pass, you may:
- Implement fixed-size arrays (no resize)
- Defer sparse array support
- Implement basic array indexing inline
- Use simple linear property lookup

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-6 hours for core functionality
**Priority**: HIGH - foundational for many other opcodes

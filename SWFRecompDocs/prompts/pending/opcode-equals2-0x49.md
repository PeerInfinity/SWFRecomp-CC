# AS2 Opcode Implementation Task: ActionEquals2

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionEquals2**

## Opcode Specification

**Opcode Name**: ActionEquals2
**Hex Value**: 0x49
**Category**: Comparison
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Type-aware equality comparison following ECMA-262 specification.

**Operation**: Pop two values from stack, compare using ECMA-262 equality algorithm, push boolean result.

**Expected Behavior** (from SWF Spec 19):
- Similar to ActionEquals (0x0E), but type-aware
- Uses equality comparison algorithm from ECMA-262 Section 11.9.3
- Pops arg1 from stack
- Pops arg2 from stack
- Compares arg2 == arg1 with proper type coercion
- Pushes 1.0 (true) or 0.0 (false) onto stack
- Handles different types (numbers, strings, booleans, objects, null, undefined)

**Stack Operations**:
```
Before: [... arg2, arg1]
After:  [... result]  // 1.0 for true, 0.0 for false
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_EQUALS2 = 0x49` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with equality comparisons
6. **Setup Test Directory** - Create `SWFRecomp/tests/equals2_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Number equality
```actionscript
trace(5 == 5);
trace(5 == 3);
```
Expected output:
```
true
false
```

### Test Case 2: String equality
```actionscript
trace("hello" == "hello");
trace("hello" == "world");
```
Expected output:
```
true
false
```

### Test Case 3: Type coercion (number and string)
```actionscript
trace(5 == "5");     // String "5" converts to number 5
trace(10 == "10");
```
Expected output:
```
true
true
```

### Test Case 4: Boolean comparison
```actionscript
trace(true == true);
trace(true == false);
trace(true == 1);    // Boolean converts to number
trace(false == 0);   // Boolean converts to number
```
Expected output:
```
true
false
true
true
```

### Test Case 5: Null and undefined
```actionscript
trace(null == null);
trace(undefined == undefined);
trace(null == undefined);  // Special case: equal
trace(null == 0);          // Not equal
```
Expected output:
```
true
true
true
false
```

## Implementation Hints

**Pattern**: This is a type-aware comparison operation following ECMA-262 rules.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_EQUALS2:
{
    out_script << "\t" << "// Equals2" << endl
               << "\t" << "actionEquals2(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionEquals2(char* stack, u32* sp)
{
    // Pop arg1
    ActionVar arg1;
    popVar(stack, sp, &arg1);

    // Pop arg2
    ActionVar arg2;
    popVar(stack, sp, &arg2);

    // Perform ECMA-262 equality comparison
    bool result = ecmaEquals(arg2, arg1);

    // Push result as float (1.0 = true, 0.0 = false)
    float result_val = result ? 1.0f : 0.0f;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_val));
}
```

### ECMA-262 Equality Algorithm

```c
bool ecmaEquals(ActionVar x, ActionVar y)
{
    // 1. If types are the same, use strict equality
    if (x.type == y.type) {
        return strictEquals(x, y);
    }

    // 2. null == undefined (special case)
    if ((x.type == ACTION_STACK_VALUE_NULL && y.type == ACTION_STACK_VALUE_UNDEFINED) ||
        (x.type == ACTION_STACK_VALUE_UNDEFINED && y.type == ACTION_STACK_VALUE_NULL)) {
        return true;
    }

    // 3. Number and String: convert string to number
    if (x.type == ACTION_STACK_VALUE_F32 && y.type == ACTION_STACK_VALUE_STRING) {
        float y_num = parseFloat((const char*)y.value.u64);
        return x.value.f32 == y_num;
    }
    if (x.type == ACTION_STACK_VALUE_STRING && y.type == ACTION_STACK_VALUE_F32) {
        float x_num = parseFloat((const char*)x.value.u64);
        return x_num == y.value.f32;
    }

    // 4. Boolean: convert to number and compare
    if (x.type == ACTION_STACK_VALUE_BOOLEAN) {
        float x_num = x.value.u32 ? 1.0f : 0.0f;
        ActionVar x_as_num = {ACTION_STACK_VALUE_F32, {.f32 = x_num}};
        return ecmaEquals(x_as_num, y);
    }
    if (y.type == ACTION_STACK_VALUE_BOOLEAN) {
        float y_num = y.value.u32 ? 1.0f : 0.0f;
        ActionVar y_as_num = {ACTION_STACK_VALUE_F32, {.f32 = y_num}};
        return ecmaEquals(x, y_as_num);
    }

    // 5. null or undefined compared with anything else (except each other) is false
    if (x.type == ACTION_STACK_VALUE_NULL || x.type == ACTION_STACK_VALUE_UNDEFINED ||
        y.type == ACTION_STACK_VALUE_NULL || y.type == ACTION_STACK_VALUE_UNDEFINED) {
        return false;
    }

    // 6. Otherwise, not equal
    return false;
}

bool strictEquals(ActionVar x, ActionVar y)
{
    switch (x.type) {
        case ACTION_STACK_VALUE_F32:
            // Handle NaN: NaN != NaN
            if (isnan(x.value.f32) || isnan(y.value.f32)) {
                return false;
            }
            return x.value.f32 == y.value.f32;

        case ACTION_STACK_VALUE_STRING:
            return strcmp((const char*)x.value.u64,
                         (const char*)y.value.u64) == 0;

        case ACTION_STACK_VALUE_BOOLEAN:
            return x.value.u32 == y.value.u32;

        case ACTION_STACK_VALUE_NULL:
        case ACTION_STACK_VALUE_UNDEFINED:
            return true;  // Same type already checked

        case ACTION_STACK_VALUE_OBJECT:
            return x.value.u64 == y.value.u64;  // Reference equality

        default:
            return false;
    }
}
```

### Similar Opcodes

Reference these opcodes:
- `actionEquals` (0x0E) - Basic equality (may not have type awareness)
- `actionStrictEquals` (0x66) - Strict equality (no type coercion)
- `actionLess2` (0x48) - Type-aware less-than comparison

### Edge Cases to Handle

- NaN comparisons (NaN == anything is false, even NaN == NaN)
- Infinity values
- Empty string and zero
- null vs undefined vs 0 vs false vs ""
- Object reference equality
- String-to-number conversion failures

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/equals2_swf_5/README.md` - Test description and expected output
- Document ECMA-262 equality rules
- Explain difference from ActionEquals (0x0E)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Type coercion works correctly
- [ ] null == undefined returns true
- [ ] NaN comparisons handled correctly
- [ ] String-to-number conversion works
- [ ] Boolean conversion works
- [ ] Documentation created

## Important Notes

**Difference from ActionEquals (0x0E)**:
- ActionEquals (0x0E): Basic equality, may treat everything as strings
- ActionEquals2 (0x49): Type-aware, follows ECMA-262 rules

**ECMA-262 Equality vs Strict Equality**:
- Equals2 (0x49): `==` operator, allows type coercion
- StrictEquals (0x66): `===` operator, no type coercion

**Flash Version**: Available in SWF 5+

**Type Coercion Priority**:
1. Same type → direct comparison
2. null == undefined → true
3. Number vs String → convert string to number
4. Boolean → convert to number (true=1, false=0)
5. null/undefined vs other → false

**Common Pitfalls**:
- `0 == false` is true (false converts to 0)
- `"" == false` is true (both convert to 0)
- `null == 0` is false (special case)
- `undefined == 0` is false (special case)
- `null == undefined` is true (special case)

**Testing Strategy**:
- Test numeric equality
- Test string equality
- Test cross-type comparisons
- Test special values (null, undefined, NaN)
- Test boolean conversions
- Verify ECMA-262 compliance

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

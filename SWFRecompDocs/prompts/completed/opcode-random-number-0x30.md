# AS2 Opcode Implementation Task: RANDOM_NUMBER

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **RANDOM_NUMBER**

## Opcode Specification

**Opcode Name**: RANDOM_NUMBER
**Hex Value**: 0x30
**Category**: Utility Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Generates a random integer in a specified range.

**Operation**: Pop maximum value, generate random number [0, max), push result.

**Expected Behavior**:
- Pop `max` value from stack (converted to integer)
- Generate random integer in range [0, max)
- Push the random number onto the stack as a float
- If max ≤ 0, return 0
- Uses pseudo-random number generator

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/random_number_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Random in range [0, 10)
```actionscript
var r = random(10);
trace(r >= 0 && r < 10 ? "PASS" : "FAIL");
```
Expected output: `PASS` (verify range)

### Test Case 2: Random in range [0, 100)
```actionscript
var r = random(100);
trace(r >= 0 && r < 100 ? "PASS" : "FAIL");
```
Expected output: `PASS`

### Test Case 3: Edge case - max = 0
```actionscript
trace(random(0));
```
Expected output: `0`

### Test Case 4: Edge case - max = 1
```actionscript
trace(random(1));
```
Expected output: `0` (only value in range [0, 1))

### Test Case 5: Large range
```actionscript
var r = random(1000);
trace(r >= 0 && r < 1000 ? "PASS" : "FAIL");
```
Expected output: `PASS`

## Implementation Hints

**Pattern**: This is a utility operation that generates values.

**Reference these similar opcodes**:
- `actionGetTime` (0x34) - Similar pattern (push value without popping)
- Standard C `rand()` function

**Implementation outline**:
```c
void actionRandomNumber(char* stack, u32* sp)
{
    // Pop maximum value
    convertFloat(stack, sp);
    ActionVar max_var;
    popVar(stack, sp, &max_var);
    int max = (int)max_var.value.f32;

    // Handle edge cases
    if (max <= 0) {
        float result = 0.0f;
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
        return;
    }

    // Generate random number in range [0, max)
    int random_val = rand() % max;

    // Push result as float
    float result = (float)random_val;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Note**:
- Use `rand()` from `<stdlib.h>`
- Modulo operation to get range: `rand() % max`
- Flash AS2 random() returns integer, not float (but stored as float on stack)
- May need to call `srand()` for initialization (typically done at runtime startup)

**Important Considerations**:
- Random seed initialization (should be done once at program start)
- Edge cases: max ≤ 0, max = 1
- Result is integer but stored as float
- Modulo bias for very large ranges (acceptable for Flash compatibility)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/random_number_swf_4/README.md` - Test description and expected output
- Document random number generator initialization if needed

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces values in correct range
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (max ≤ 0)
- [ ] Random seed initialized appropriately
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is `random(max)`.

**Flash Version**: Available in SWF 4+

**Random Number Quality**: The `rand()` function provides adequate pseudo-random numbers for Flash games and animations. For cryptographic purposes, a better PRNG would be needed, but that's not required for Flash compatibility.

**Initialization**: Consider initializing the random seed with `srand(time(NULL))` in the runtime initialization code (not in this opcode).

**Range**: Returns integer in range [0, max), i.e., 0 ≤ result < max.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

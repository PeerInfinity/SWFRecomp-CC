# Stack Swap Test (SWF 4)

## Opcode
**STACK_SWAP** (0x4C) - Swaps the top two values on the stack

## Test Description
This test verifies that the STACK_SWAP opcode correctly exchanges the positions of the top two stack values.

## Test Case
```
Push 2.0
Push 10.0
Stack Swap (0x4C)
Divide (0x0D)
Trace (0x26)
```

## Stack State During Execution
1. After `push 2.0`: Stack = [2.0]
2. After `push 10.0`: Stack = [2.0, 10.0] (10.0 on top)
3. After `swap`: Stack = [10.0, 2.0] (2.0 on top)
4. After `divide`: Pops 2.0, pops 10.0, computes 10.0 / 2.0 = 5.0, pushes 5.0
5. After `trace`: Outputs "5"

## Expected Output
```
5
```

## Verification
Without the swap operation, the computation would be `2 / 10 = 0.2`. With the swap, the operands are reversed, resulting in `10 / 2 = 5`.

This test confirms that:
- Stack Swap exchanges the top two values
- Type and value preservation works correctly
- The swapped values can be used by subsequent operations
- Non-commutative operations (like division) produce the correct reversed result

## Building and Running
```bash
cd SWFRecomp
./scripts/build_test.sh stack_swap_swf_4 native
./tests/stack_swap_swf_4/build/native/stack_swap_swf_4
```

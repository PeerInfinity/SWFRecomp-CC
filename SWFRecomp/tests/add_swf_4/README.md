# ADD Opcode Test (0x0A)

## Overview
Comprehensive test suite for the ActionAdd opcode (0x0A) in SWF version 4.

## Test Cases

1. **Basic Integer Addition**: `5 + 3 = 8`
   - Tests simple integer arithmetic

2. **Floating Point Addition**: `2.5 + 1.5 = 4`
   - Tests decimal number addition

3. **String to Number Conversion**: `"10" + 5 = 15`
   - Tests automatic string-to-number conversion

4. **Zero Addition**: `0 + 42 = 42`
   - Tests identity property of zero

5. **Negative Numbers**: `-5 + 10 = 5`
   - Tests addition with negative values

6. **Mixed Float/Int**: `7.5 + 2 = 9.5`
   - Tests mixed precision arithmetic

7. **Large Numbers**: `1000000 + 500000 = 1500000`
   - Tests large number handling

8. **Small Decimals**: `0.001 + 0.002 = 0.003`
   - Tests precision with small decimals

9. **Negative Result**: `-10 + 3 = -7`
   - Tests result that is negative

10. **Double Negative**: `-5 + -5 = -10`
    - Tests addition of two negative numbers

## Implementation Details

The ADD opcode:
- Pops two values from the stack
- Converts both to floating point numbers
- Performs addition (value2 + value1)
- Pushes result back onto stack

Stack order is important: the second value pushed is the first operand.

## Files

- `test.swf`: Generated SWF file containing test cases
- `test_info.json`: Test metadata
- `validate.py`: Validation script for test output
- `create_test_swf.py`: Script to generate test SWF
- `config.toml`: SWFRecomp configuration
- `main.c`: Entry point for compiled test
- `CMakeLists.txt`: Build configuration
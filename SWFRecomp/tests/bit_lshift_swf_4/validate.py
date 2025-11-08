#!/usr/bin/env python3
"""
Validation script for bit_lshift_swf_4

Tests the BIT_LSHIFT opcode (0x63) - bitwise left shift operation.
Expected behavior:
- Pops shift_count, then value from stack
- Converts value to 32-bit signed integer
- Masks shift_count to 5 bits (0-31 range)
- Performs value << shift_count
- Pushes result as signed 32-bit integer
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output for BIT_LSHIFT opcode.

    Tests:
    1. Basic left shift: 1 << 3 = 8
    2. Multiply by power of 2: 5 << 2 = 20
    3. Shift count wrapping (5-bit mask): 1 << 33 = 2 (33 & 0x1F = 1)
    4. Zero shift: 42 << 0 = 42
    5. Shift into sign bit: 1 << 31 = -2147483648
    """
    lines = parse_output(output)

    # We expect 5 output lines
    if len(lines) < 5:
        lines.extend([''] * (5 - len(lines)))  # Pad with empty strings
    
    results = []
    
    # Test 1: Basic left shift (1 << 3 = 8)
    results.append(make_result(
        "basic_shift_1_lshift_3",
        lines[0] == "8",
        "8",
        lines[0]
    ))
    
    # Test 2: Multiply by power of 2 (5 << 2 = 20)
    results.append(make_result(
        "multiply_by_power_5_lshift_2",
        lines[1] == "20",
        "20",
        lines[1]
    ))
    
    # Test 3: Shift count wrapping (1 << 33 = 2, because 33 & 0x1F = 1)
    results.append(make_result(
        "shift_count_wrap_1_lshift_33",
        lines[2] == "2",
        "2",
        lines[2]
    ))
    
    # Test 4: Zero shift (42 << 0 = 42)
    results.append(make_result(
        "zero_shift_42_lshift_0",
        lines[3] == "42",
        "42",
        lines[3]
    ))
    
    # Test 5: Shift into sign bit (1 << 31 = -2147483648)
    results.append(make_result(
        "sign_bit_shift_1_lshift_31",
        lines[4] == "-2147483648",
        "-2147483648",
        lines[4]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

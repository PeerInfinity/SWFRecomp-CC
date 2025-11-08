#!/usr/bin/env python3
"""
Validation script for bit_rshift_swf_4

Tests the BIT_RSHIFT opcode (0x64) - Arithmetic right shift operation.

Expected output (5 test cases):
1. 8 >> 2 = 2
2. 20 >> 2 = 5
3. -8 >> 2 = -2 (sign extension)
4. 42 >> 0 = 42
5. 16 >> 33 = 8 (33 & 0x1F = 1, so 16 >> 1 = 8)
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
    Validate BIT_RSHIFT test output.

    Expected: 5 lines with values 2, 5, -2, 42, 8
    """
    lines = parse_output(output)

    # Define expected outputs for each test case
    expected_values = ["2", "5", "-2", "42", "8"]
    test_names = [
        "basic_rshift_8_2",       # 8 >> 2 = 2
        "divide_by_4",            # 20 >> 2 = 5
        "sign_extension_neg8",    # -8 >> 2 = -2
        "zero_shift",             # 42 >> 0 = 42
        "shift_count_wrapping"    # 16 >> 33 = 8
    ]

    results = []

    # Validate each expected output
    for i, (expected, test_name) in enumerate(zip(expected_values, test_names)):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
        else:
            actual = "<missing>"
            passed = False

        results.append(make_result(test_name, passed, expected, actual))

    # Check if we have extra unexpected lines
    if len(lines) > len(expected_values):
        results.append(make_result(
            "no_extra_output",
            False,
            f"{len(expected_values)} lines",
            f"{len(lines)} lines",
            f"Got {len(lines) - len(expected_values)} extra output lines"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

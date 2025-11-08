#!/usr/bin/env python3
"""
Validation script for bit_urshift_swf_4

Tests the BIT_URSHIFT opcode (0x65) - unsigned/logical right shift.
Expected outputs for 5 test cases:
  1. 8 >>> 2 = 2
  2. -8 >>> 2 = 1073741824 (float precision)
  3. 42 >>> 0 = 42
  4. 255 >>> 8 = 0
  5. 16 >>> 33 = 8 (33 & 0x1F = 1, so 16 >>> 1 = 8)
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
    Validate test output.

    Expected outputs (5 test cases):
      1. 8 >>> 2 = 2
      2. -8 >>> 2 = 1073741824 (float precision)
      3. 42 >>> 0 = 42
      4. 255 >>> 8 = 0
      5. 16 >>> 33 = 8
    """
    lines = parse_output(output)

    # Expected outputs for each test case
    expected_values = ["2", "1073741824", "42", "0", "8"]
    test_names = [
        "basic_urshift_8_2",
        "negative_urshift_neg8_2",
        "zero_shift_42_0",
        "shift_all_bits_255_8",
        "shift_wrap_16_33"
    ]

    results = []

    # Validate each test case
    for i, (expected, test_name) in enumerate(zip(expected_values, test_names)):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            results.append(make_result(test_name, passed, expected, actual))
        else:
            # Missing output line
            results.append(make_result(
                test_name,
                False,
                expected,
                "<missing>",
                f"Missing output line {i+1}"
            ))

    # Check for extra output lines
    if len(lines) > len(expected_values):
        results.append(make_result(
            "no_extra_output",
            False,
            f"{len(expected_values)} lines",
            f"{len(lines)} lines",
            f"Unexpected extra output: {lines[len(expected_values):]}"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for subtract_swf_4

Comprehensive tests for SUBTRACT opcode including:
- Basic subtraction
- Floating point subtraction
- String to number conversion
- Edge cases (negative results, zero, non-numeric strings)
"""
import sys
import json
import os
import math

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output for comprehensive SUBTRACT opcode tests.

    Tests:
    1. Basic subtraction: 10 - 3 = 7
    2. Floating point: 5.5 - 2.5 = 3
    3. String conversion: "20" - 5 = 15
    4. Subtracting zero: 42 - 0 = 42
    5. Negative result: 5 - 10 = -5
    6. Negative numbers: -5 - 3 = -8
    7. Double negative: -5 - (-3) = -2
    8. Large numbers: 1000000 - 250000 = 750000
    9. Small decimals: 0.005 - 0.002 = 0.003
    10. Zero minus number: 0 - 10 = -10
    11. Non-numeric string: "hello" - 5 = -5 (atof converts to 0)
    """
    lines = parse_output(output)

    # We expect 11 output lines
    if len(lines) < 11:
        lines.extend([''] * (11 - len(lines)))  # Pad with empty strings

    results = []

    # Test 1: Basic subtraction
    results.append(make_result(
        "basic_subtraction_10_minus_3",
        lines[0] == "7",
        "7",
        lines[0]
    ))

    # Test 2: Floating point
    results.append(make_result(
        "floating_point_5.5_minus_2.5",
        lines[1] == "3",
        "3",
        lines[1]
    ))

    # Test 3: String conversion (string "20" - number 5)
    results.append(make_result(
        "string_conversion_20_minus_5",
        lines[2] == "15",
        "15",
        lines[2]
    ))

    # Test 4: Subtracting zero
    results.append(make_result(
        "subtracting_zero_42_minus_0",
        lines[3] == "42",
        "42",
        lines[3]
    ))

    # Test 5: Negative result
    results.append(make_result(
        "negative_result_5_minus_10",
        lines[4] == "-5",
        "-5",
        lines[4]
    ))

    # Test 6: Negative numbers
    results.append(make_result(
        "negative_numbers_-5_minus_3",
        lines[5] == "-8",
        "-8",
        lines[5]
    ))

    # Test 7: Double negative
    results.append(make_result(
        "double_negative_-5_minus_-3",
        lines[6] == "-2",
        "-2",
        lines[6]
    ))

    # Test 8: Large numbers
    results.append(make_result(
        "large_numbers_1000000_minus_250000",
        lines[7] == "750000",
        "750000",
        lines[7]
    ))

    # Test 9: Small decimals
    # Handle potential floating point imprecision
    try:
        actual_val = float(lines[8])
        expected_val = 0.003
        is_close = abs(actual_val - expected_val) < 0.0001
        results.append(make_result(
            "small_decimals_0.005_minus_0.002",
            is_close,
            "0.003",
            lines[8]
        ))
    except:
        results.append(make_result(
            "small_decimals_0.005_minus_0.002",
            False,
            "0.003",
            lines[8]
        ))

    # Test 10: Zero minus number
    results.append(make_result(
        "zero_minus_number_0_minus_10",
        lines[9] == "-10",
        "-10",
        lines[9]
    ))

    # Test 11: Non-numeric string case
    # atof("hello") returns 0, so "hello" - 5 = 0 - 5 = -5
    results.append(make_result(
        "non_numeric_string_hello_minus_5",
        lines[10] == "-5",
        "-5",
        lines[10]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

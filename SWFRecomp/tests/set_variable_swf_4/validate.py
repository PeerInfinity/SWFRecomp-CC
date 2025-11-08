#!/usr/bin/env python3
"""
Validation script for set_variable_swf_4

Tests the SET_VARIABLE opcode (0x1D).

Expected output:
  Line 1: 42 (number variable)
  Line 2: Alice (string variable)
  Line 3: 20 (updated variable)
  Line 4: 8 (expression result)
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

    Test cases:
    1. x = 42; trace(x) -> 42
    2. name = "Alice"; trace(name) -> Alice
    3. y = 10; y = 20; trace(y) -> 20
    4. z = 5 + 3; trace(z) -> 8
    """
    lines = parse_output(output)

    results = []

    # Test Case 1: Number variable
    expected_1 = "42"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "set_number_variable",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test Case 2: String variable
    expected_2 = "Alice"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "set_string_variable",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test Case 3: Update variable
    expected_3 = "20"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "update_variable",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Test Case 4: Set from expression
    expected_4 = "8"
    actual_4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "set_from_expression",
        actual_4 == expected_4,
        expected_4,
        actual_4
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

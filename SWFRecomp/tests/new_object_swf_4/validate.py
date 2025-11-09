#!/usr/bin/env python3
"""
Validation script for new_object_swf_4

Tests the NEW_OBJECT opcode (0x40) which creates objects via constructor calls.

Test cases:
  1. new Array(5) - verify length is 5
  2. new Array(10, 20, 30) - verify length is 3
  3. new Array(10, 20, 30) - verify first element is 10
  4. new Object() - set and get property x=42
  5. new Array() - verify empty array has length 0
  6. new Array(0) - verify array with length 0

Expected output:
  5
  3
  10
  42
  0
  0
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

    Expected: Six trace outputs verifying that NEW_OBJECT correctly creates
    arrays and objects with the expected properties.
    """
    lines = parse_output(output)

    results = []

    # Test 1: new Array(5) - length should be 5
    expected = "5"
    actual = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "array_with_length_5",
        actual == expected,
        expected,
        actual
    ))

    # Test 2: new Array(10, 20, 30) - length should be 3
    expected = "3"
    actual = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "array_with_3_elements_length",
        actual == expected,
        expected,
        actual
    ))

    # Test 3: new Array(10, 20, 30) - first element should be 10
    expected = "10"
    actual = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "array_first_element",
        actual == expected,
        expected,
        actual
    ))

    # Test 4: new Object() with property x=42
    expected = "42"
    actual = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "object_property_x",
        actual == expected,
        expected,
        actual
    ))

    # Test 5: new Array() - empty array length should be 0
    expected = "0"
    actual = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "empty_array_no_args",
        actual == expected,
        expected,
        actual
    ))

    # Test 6: new Array(0) - array with length 0
    expected = "0"
    actual = lines[5] if len(lines) > 5 else ""
    results.append(make_result(
        "array_with_length_0",
        actual == expected,
        expected,
        actual
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

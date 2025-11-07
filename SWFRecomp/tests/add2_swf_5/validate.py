#!/usr/bin/env python3
"""
Validation script for add2_swf_5

Tests the ADD2 (Type-Aware Addition) opcode.
Expected outputs:
  1. Number + Number: trace(5 + 3) = 8
  2. String + Number: trace("Total: " + 42) = Total: 42
  3. Number + String: trace(5 + " items") = 5 items
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

    Expected outputs:
      1. 8 (number + number)
      2. Total: 42 (string + number)
      3. 5 items (number + string)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Number + Number (5 + 3 = 8)
    if len(lines) > 0:
        expected = "8"
        actual = lines[0]
        results.append(make_result(
            "number_plus_number",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "number_plus_number",
            False,
            "8",
            "(no output)",
            "Missing output for test 1"
        ))

    # Test 2: String + Number ("Total: " + 42 = "Total: 42")
    if len(lines) > 1:
        expected = "Total: 42"
        actual = lines[1]
        results.append(make_result(
            "string_plus_number",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "string_plus_number",
            False,
            "Total: 42",
            "(no output)",
            "Missing output for test 2"
        ))

    # Test 3: Number + String (5 + " items" = "5 items")
    if len(lines) > 2:
        expected = "5 items"
        actual = lines[2]
        results.append(make_result(
            "number_plus_string",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "number_plus_string",
            False,
            "5 items",
            "(no output)",
            "Missing output for test 3"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

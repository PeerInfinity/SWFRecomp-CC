#!/usr/bin/env python3
"""
Validation script for push_swf_4

Tests the PUSH opcode (0x96) with different data types.
Expected output:
- Line 1: 42 (integer as float)
- Line 2: Hello (string)
- Line 3: 3.14 (float)
- Line 4: 1 (boolean as float)
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

    Expected: Four trace outputs testing different Push data types
    """
    lines = parse_output(output)

    results = []

    # Test 1: Push integer (42)
    if len(lines) > 0:
        expected = "42"
        actual = lines[0]
        results.append(make_result(
            "push_integer",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "push_integer",
            False,
            "42",
            "(no output)",
            "Missing output line 1"
        ))

    # Test 2: Push string ("Hello")
    if len(lines) > 1:
        expected = "Hello"
        actual = lines[1]
        results.append(make_result(
            "push_string",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "push_string",
            False,
            "Hello",
            "(no output)",
            "Missing output line 2"
        ))

    # Test 3: Push float (3.14)
    if len(lines) > 2:
        expected = "3.14"
        actual = lines[2]
        # Allow small floating point differences
        try:
            actual_float = float(actual)
            expected_float = float(expected)
            passed = abs(actual_float - expected_float) < 0.01
        except ValueError:
            passed = False

        results.append(make_result(
            "push_float",
            passed,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "push_float",
            False,
            "3.14",
            "(no output)",
            "Missing output line 3"
        ))

    # Test 4: Push boolean (1)
    if len(lines) > 3:
        expected = "1"
        actual = lines[3]
        results.append(make_result(
            "push_boolean",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "push_boolean",
            False,
            "1",
            "(no output)",
            "Missing output line 4"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

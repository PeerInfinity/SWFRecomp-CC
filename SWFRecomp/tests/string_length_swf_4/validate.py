#!/usr/bin/env python3
"""
Validation script for string_length_swf_4

Tests the STRING_LENGTH opcode (0x14).
Expected output:
- length("hello") = 5
- length("") = 0
- length("hello world") = 11
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

    Expected:
    - Line 1: 5 (length of "hello")
    - Line 2: 0 (length of "")
    - Line 3: 11 (length of "hello world")
    """
    lines = parse_output(output)

    results = []

    # Test 1: length("hello") = 5
    if len(lines) > 0:
        expected = "5"
        actual = lines[0]
        results.append(make_result(
            "length_hello",
            actual == expected,
            expected,
            actual
        ))

    # Test 2: length("") = 0
    if len(lines) > 1:
        expected = "0"
        actual = lines[1]
        results.append(make_result(
            "length_empty",
            actual == expected,
            expected,
            actual
        ))

    # Test 3: length("hello world") = 11
    if len(lines) > 2:
        expected = "11"
        actual = lines[2]
        results.append(make_result(
            "length_hello_world",
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

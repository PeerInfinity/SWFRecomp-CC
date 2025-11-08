#!/usr/bin/env python3
"""
Validation script for string_less_swf_4

Tests the STRING_LESS opcode (0x29) with various string comparisons.
Expected output: 6 lines showing results of lexicographic comparisons
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
    1. "apple" < "banana" = 1 (true)
    2. "zebra" < "apple" = 0 (false)
    3. "Apple" < "apple" = 1 (true, case-sensitive)
    4. "hello" < "hello" = 0 (false, equal)
    5. "cat" < "catch" = 1 (true, prefix)
    6. "" < "a" = 1 (true, empty string)
    """
    lines = parse_output(output)

    # Expected outputs for all 6 test cases
    expected_values = ["1", "0", "1", "0", "1", "1"]
    test_names = [
        "apple_less_banana",
        "zebra_less_apple",
        "Apple_less_apple_case_sensitive",
        "hello_equals_hello",
        "cat_less_catch_prefix",
        "empty_less_a"
    ]

    results = []

    # Check we have enough output lines
    if len(lines) < len(expected_values):
        for i in range(len(expected_values)):
            actual = lines[i] if i < len(lines) else ""
            results.append(make_result(
                test_names[i],
                False,
                expected_values[i],
                actual,
                f"Missing output line {i+1}" if i >= len(lines) else None
            ))
        return make_validation_result(results)

    # Validate each test case
    for i, (expected, test_name) in enumerate(zip(expected_values, test_names)):
        actual = lines[i]
        results.append(make_result(
            test_name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

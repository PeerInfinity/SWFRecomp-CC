#!/usr/bin/env python3
"""
Validation script for string_greater_swf_4

Tests the STRING_GREATER opcode (0x68) which performs lexicographic string comparison.
Expected output: 5 test results showing lexicographic comparison behavior.
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
    Validate STRING_GREATER opcode test output.

    Expected: 5 test cases for lexicographic string comparison
    Test 1: "apple" > "zebra" => 0 (false)
    Test 2: "zebra" > "apple" => 1 (true)
    Test 3: "hello" > "hello" => 0 (equal strings)
    Test 4: "a" > "Z" => 1 (case sensitivity, 97 > 90)
    Test 5: "hello" > "hello world" => 0 (prefix comparison)
    """
    lines = parse_output(output)

    # Expected outputs for each test case
    expected_values = ["0", "1", "0", "1", "0"]
    test_names = [
        "apple_vs_zebra",
        "zebra_vs_apple",
        "equal_strings",
        "case_sensitivity",
        "prefix_comparison"
    ]

    results = []

    # Validate each test case
    for i, (test_name, expected) in enumerate(zip(test_names, expected_values)):
        if i < len(lines):
            actual = lines[i]
            passed = (actual == expected)
            results.append(make_result(test_name, passed, expected, actual))
        else:
            # Missing output
            results.append(make_result(
                test_name,
                False,
                expected,
                "(missing)",
                f"Output line {i+1} not found"
            ))

    # Check for extra unexpected output
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

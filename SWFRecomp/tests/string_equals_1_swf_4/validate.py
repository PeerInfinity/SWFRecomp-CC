#!/usr/bin/env python3
"""
Validation script for string_equals_1_swf_4

Tests the STRING_EQUALS opcode (0x13) with equal strings.
Expected output: 1 (true - strings are equal)

Test case: "hello" eq "hello" = 1
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

    Expected: "1" (strings "hello" and "hello" are equal)
    """
    lines = parse_output(output)

    # Check that we have output
    if not lines:
        return make_validation_result([
            make_result(
                "string_equals_equal",
                False,
                "1",
                "",
                "No output received"
            )
        ])

    # Validate the output is "1"
    expected = "1"
    actual = lines[0]

    return make_validation_result([
        make_result(
            "string_equals_equal",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

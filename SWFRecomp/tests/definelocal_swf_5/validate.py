#!/usr/bin/env python3
"""
Validation script for definelocal_swf_5

Tests the DEFINE_LOCAL opcode (0x3C).
Expected output: 42
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

    Expected: Single line with value "42"
    Test: var x = 42; trace(x);
    """
    lines = parse_output(output)

    # Check we have at least one line of output
    if len(lines) < 1:
        return make_validation_result([
            make_result(
                "definelocal_basic",
                False,
                "42",
                "",
                "No output received"
            )
        ])

    # Verify the output is "42"
    expected = "42"
    actual = lines[0]

    return make_validation_result([
        make_result(
            "definelocal_basic",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

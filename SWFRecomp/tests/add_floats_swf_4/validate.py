#!/usr/bin/env python3
"""
Validation script for add_floats_swf_4

Tests the ADD opcode with floating point values.
Expected output: 1.5 + 1.25 = 2.75
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

    Expected: Single line with "2.75"
    """
    lines = parse_output(output)

    expected = "2.75"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "add_1.5_1.25",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

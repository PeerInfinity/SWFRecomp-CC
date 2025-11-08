#!/usr/bin/env python3
"""
Validation script for less_floats_false_swf_4

Tests the ActionLess (0x0F) opcode with the comparison 5 < 3.
Expected output: 0 (false)
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

    Expected: 0 (because 5 < 3 is false)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "0"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "less_than_false",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

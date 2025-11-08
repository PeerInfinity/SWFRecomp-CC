#!/usr/bin/env python3
"""
Validation script for less_floats_swf_4

Tests the ActionLess (0x0F) opcode with the comparison 3 < 5.
Expected output: 1 (true)
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

    Expected: 1 (because 3 < 5 is true)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "1"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "less_than_true",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

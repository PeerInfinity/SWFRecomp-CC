#!/usr/bin/env python3
"""
Validation script for increment_swf_4

Tests the INCREMENT opcode (0x50).
Expected output: 6 (increments 5.0 by 1)
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

    Expected: 6 (increment of 5.0)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "6"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "increment_5",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for not_floats_nonzero_swf_4

Tests the NOT opcode (0x12) with a nonzero float value.
Expected output: !5 = 0 (logical NOT of a truthy value)
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

    Expected: !5 = 0 (since 5 is truthy, NOT returns false which is 0.0)
    """
    lines = parse_output(output)

    # Expected output: 0 (logical NOT of 5.0 is 0.0)
    expected = "0"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "not_nonzero_float",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

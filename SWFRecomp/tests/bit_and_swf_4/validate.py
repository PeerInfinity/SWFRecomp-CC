#!/usr/bin/env python3
"""
Validation script for bit_and_swf_4

Tests the BIT_AND opcode (0x60).
Expected output: 8 (result of 12 & 10)
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

    Expected: 8 (12 & 10 = 8, binary: 1100 & 1010 = 1000)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "8"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "bit_and_12_10",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

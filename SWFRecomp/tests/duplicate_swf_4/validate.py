#!/usr/bin/env python3
"""
Validation script for duplicate_swf_4

Tests the DUPLICATE opcode (0x4C).
Expected output: 84 (result of 42 + 42 using duplicate)
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

    Expected: Push 42, duplicate it, add them -> trace(84)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "84"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "duplicate_add_test",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

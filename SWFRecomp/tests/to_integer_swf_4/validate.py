#!/usr/bin/env python3
"""
Validation script for to_integer_swf_4

Tests the TO_INTEGER opcode (0x18).
Expected output: 12 (from converting 12.7 to integer)

The TO_INTEGER opcode truncates floats toward zero, so:
- 12.7 → 12 (not 13)
- -12.7 → -12 (not -13)
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

    Expected: "12" (result of converting 12.7 to integer)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "12"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "to_integer_truncation",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

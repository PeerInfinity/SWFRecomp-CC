#!/usr/bin/env python3
"""
Validation script for to_number_swf_4

Tests the TO_NUMBER opcode (0x4A).
Expected output: String to number conversion: Number("123.45") → 123.45
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

    Expected: Number("123.45") converts to 123.45
    """
    lines = parse_output(output)

    # Validate string to number conversion
    expected = "123.45"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "string_to_number_conversion",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

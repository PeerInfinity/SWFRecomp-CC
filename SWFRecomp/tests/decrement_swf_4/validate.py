#!/usr/bin/env python3
"""
Validation script for decrement_swf_4

Tests the DECREMENT opcode (0x51).
Expected: Push 10.0, decrement (10.0 - 1), trace → output "9"
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

    Expected: 9 (from 10.0 - 1)
    """
    lines = parse_output(output)

    # Expected output: 9
    expected = "9"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "decrement_10",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

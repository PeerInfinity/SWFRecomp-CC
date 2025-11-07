#!/usr/bin/env python3
"""
Validation script for instanceof_swf_6

Tests the INSTANCEOF opcode (0x54) - ActionScript instanceof operator.

Current implementation is simplified and always returns false.
Expected output: 0 (false - primitives are not instances)

Test: trace(5 instanceof Number)
Expected: 0

Note: Full prototype chain traversal requires extending ASObject structure
with prototype field. This test validates the simplified implementation.
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
    Validate test output for INSTANCEOF opcode.

    Expected: 0 (false - primitives are not instances)
    """
    lines = parse_output(output)

    results = []

    # Test: 5 instanceof Number should return 0 (false)
    # Primitives are never instances in ActionScript
    expected = "0"
    actual = lines[0] if lines else ""

    results.append(make_result(
        "primitive_instanceof_false",
        actual == expected,
        expected,
        actual,
        "Primitive values should not be instances (instanceof should return false)"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

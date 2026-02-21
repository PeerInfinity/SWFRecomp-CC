#!/usr/bin/env python3
"""
Validation script for instanceof_swf_6

Tests the INSTANCEOF opcode (0x54) - ActionScript instanceof operator.

Current implementation is simplified and always returns false.
Expected output: "false" (primitives are not instances; SWF6+ traces booleans as "true"/"false")
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

    Expected: "false" (SWF6 boolean coercion)
    """
    lines = parse_output(output)

    results = []

    # Test: 5 instanceof Number should return false
    # Primitives are never instances in ActionScript
    expected = "false"
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

#!/usr/bin/env python3
"""
Validation script for call_function_swf_5

Tests the CALL_FUNCTION opcode (0x3D) by calling parseInt("42").
Expected output: 42
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

    Expected: "42" (result of parseInt("42"))
    """
    lines = parse_output(output)

    # Test should output "42" from parseInt("42")
    expected = "42"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "parseInt_call",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

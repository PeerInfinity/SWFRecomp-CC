#!/usr/bin/env python3
"""
Validation script for define_function_swf_5

Tests the DEFINE_FUNCTION opcode (0x9B).
Expected output: "Function defined"
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

    Expected: "Function defined"
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "Function defined"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "function_defined",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

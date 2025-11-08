#!/usr/bin/env python3
"""
Validation script for init_array_swf_4

Tests the INIT_ARRAY opcode (0x42) which creates array objects.
Expected output: "Array creation test passed"

This test creates:
1. Empty array []
2. Array with 3 elements [1.0, 2.0, 3.0]

Note: Full array testing requires GET_MEMBER opcode for element access.
This test verifies that arrays can be created without crashing.
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

    Expected: "Array creation test passed"
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "Array creation test passed"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "array_creation",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

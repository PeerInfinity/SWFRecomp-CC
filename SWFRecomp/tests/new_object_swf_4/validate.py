#!/usr/bin/env python3
"""
Validation script for new_object_swf_4

Tests the NEW_OBJECT opcode (0x40) which creates objects via constructor calls.

Test cases:
  1. new Array(3) - creates array with length 3
  2. new Object() - creates empty object
  3. new Array(1, 2, 3) - creates array with elements [1, 2, 3]

Expected output: 'NEW_OBJECT tests completed'
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

    Expected: The test creates three objects and outputs a success message
    if all constructors work without crashing.
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "NEW_OBJECT tests completed"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "new_object_success",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

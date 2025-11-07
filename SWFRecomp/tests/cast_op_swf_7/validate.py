#!/usr/bin/env python3
"""
Validation script for cast_op_swf_7

Tests the CAST_OP opcode (0x2B).
Expected output: cast_test_passed
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

    Expected: "cast_test_passed"
    This verifies that the CastOp opcode executed without crashing.
    """
    lines = parse_output(output)

    # Expected output
    expected = "cast_test_passed"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "cast_op_basic_test",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

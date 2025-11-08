#!/usr/bin/env python3
"""
Validation script for set_property_swf_4

Tests the SET_PROPERTY opcode (0x23).
Expected output: "SET_PROPERTY tests completed"
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

    Expected: "SET_PROPERTY tests completed"
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "SET_PROPERTY tests completed"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "set_property_completion",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

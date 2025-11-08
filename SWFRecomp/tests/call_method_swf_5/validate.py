#!/usr/bin/env python3
"""
Validation script for call_method_swf_5

Tests the CALL_METHOD opcode (0x52).
Expected output: HELLO (from "hello".toUpperCase())
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

    Expected: HELLO (result of calling toUpperCase on "hello")
    """
    lines = parse_output(output)

    # Test that string primitive methods work
    expected = "HELLO"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "toUpperCase_method_call",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

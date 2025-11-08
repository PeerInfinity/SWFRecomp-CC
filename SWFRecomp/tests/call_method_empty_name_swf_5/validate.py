#!/usr/bin/env python3
"""
Validation script for call_method_empty_name_swf_5

Tests the CALL_METHOD opcode (0x52) with empty method name.
Expected output: 42 (from invoking function object directly)
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

    Expected: 42 (result of calling function with empty method name)
    """
    lines = parse_output(output)

    expected = "42"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "empty_method_name_function_call",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

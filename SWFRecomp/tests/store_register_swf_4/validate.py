#!/usr/bin/env python3
"""
Validation script for store_register_swf_4

Tests the STORE_REGISTER opcode (0x87).
Expected output: 42 (store 42 in register 0, push from register, trace)
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

    Expected: Store value 42 in register 0, push it back, and trace it = 42
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "42"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "store_and_push_register",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

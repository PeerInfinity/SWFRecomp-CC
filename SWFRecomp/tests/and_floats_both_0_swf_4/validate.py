#!/usr/bin/env python3
"""
Validation script for and_floats_both_0_swf_4

Tests the ActionAnd opcode with both operands false (0 && 0).
Expected output: 0
"""
import sys
import json

def validate_output(output):
    """
    Validate test output.

    Expected: 0 (both operands are falsy)
    """
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]

    expected = "0"
    actual = lines[0] if lines else ""

    return {
        "passed": actual == expected,
        "sub_tests": [
            {
                "name": "both_false",
                "passed": actual == expected,
                "expected": expected,
                "actual": actual
            }
        ]
    }


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

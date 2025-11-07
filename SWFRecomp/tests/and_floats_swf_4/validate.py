#!/usr/bin/env python3
"""
Validation script for and_floats_swf_4

Tests the ActionAnd opcode with both operands true (1 && 1).
Expected output: 1
"""
import sys
import json

def validate_output(output):
    """
    Validate test output.

    Expected: 1 (both operands are truthy)
    """
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]

    expected = "1"
    actual = lines[0] if lines else ""

    return {
        "passed": actual == expected,
        "sub_tests": [
            {
                "name": "both_true",
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

#!/usr/bin/env python3
"""
Validation script for less2_swf_4

Tests the LESS2 opcode (0x48) - ActionLess2
Expected output: 1 (true, because 3 < 5)
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

    Expected: trace(3 < 5) outputs "1" (true)
    """
    lines = parse_output(output)

    # Test expects single output: 1 (true, because 3 < 5)
    expected = "1"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "less2_comparison",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

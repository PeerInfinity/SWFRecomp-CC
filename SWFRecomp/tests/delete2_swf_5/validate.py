#!/usr/bin/env python3
"""
Validation script for delete2_swf_5

Tests the DELETE2 opcode (0x3B).
Expected output: 1 (true - deleting non-existent property returns true in Flash)
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

    Expected: "1" (true - DELETE2 returns true for non-existent properties)
    """
    lines = parse_output(output)

    # Test Case 1: Delete non-existent property -> returns 1
    expected = "1"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "delete_nonexistent",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

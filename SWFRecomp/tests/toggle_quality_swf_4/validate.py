#!/usr/bin/env python3
"""
Validation script for toggle_quality_swf_4

Tests the TOGGLE_QUALITY opcode (0x08).
Expected output: Two trace statements before and after the quality toggle.
In NO_GRAPHICS mode, the toggle is a no-op, but the test verifies
the opcode executes without error.
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

    Expected:
    - Line 1: "Before toggleHighQuality"
    - Line 2: "After toggleHighQuality"
    """
    lines = parse_output(output)

    results = []

    # Check first output
    expected1 = "Before toggleHighQuality"
    actual1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "before_toggle",
        actual1 == expected1,
        expected1,
        actual1
    ))

    # Check second output
    expected2 = "After toggleHighQuality"
    actual2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "after_toggle",
        actual2 == expected2,
        expected2,
        actual2
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

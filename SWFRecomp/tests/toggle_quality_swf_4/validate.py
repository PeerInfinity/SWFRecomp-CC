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
    Test Case 1: Basic quality toggle
    - Line 1: "Before toggleHighQuality"
    - Line 2: "After toggleHighQuality"

    Test Case 2: Multiple quality toggles
    - Line 3: "Start"
    - Line 4: "Toggled once"
    - Line 5: "Toggled twice"
    """
    lines = parse_output(output)

    results = []

    # Test Case 1: Basic quality toggle
    expected1 = "Before toggleHighQuality"
    actual1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "before_toggle",
        actual1 == expected1,
        expected1,
        actual1
    ))

    expected2 = "After toggleHighQuality"
    actual2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "after_toggle",
        actual2 == expected2,
        expected2,
        actual2
    ))

    # Test Case 2: Multiple quality toggles
    expected3 = "Start"
    actual3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "multiple_toggles_start",
        actual3 == expected3,
        expected3,
        actual3
    ))

    expected4 = "Toggled once"
    actual4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "toggled_once",
        actual4 == expected4,
        expected4,
        actual4
    ))

    expected5 = "Toggled twice"
    actual5 = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "toggled_twice",
        actual5 == expected5,
        expected5,
        actual5
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

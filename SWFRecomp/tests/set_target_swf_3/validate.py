#!/usr/bin/env python3
"""
Validation script for set_target_swf_3

Tests the ActionSetTarget opcode (0x8B).
Expected output:
- SetTarget to "mySprite"
- SetTarget to "" (return to main)
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
    - Line 1: // SetTarget: mySprite
    - Line 2: // SetTarget: (main)
    """
    lines = parse_output(output)

    results = []

    # Check first SetTarget
    expected_1 = "// SetTarget: mySprite"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "settarget_mySprite",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Check second SetTarget (return to main)
    expected_2 = "// SetTarget: (main)"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "settarget_main",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

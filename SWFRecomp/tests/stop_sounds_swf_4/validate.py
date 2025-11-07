#!/usr/bin/env python3
"""
Validation script for stop_sounds_swf_4

Tests the STOP_SOUNDS opcode (0x09).
Expected output: Two trace statements before and after stopAllSounds call.
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
    Before stopAllSounds
    After stopAllSounds
    """
    lines = parse_output(output)

    results = []

    # Check first line
    expected_line1 = "Before stopAllSounds"
    actual_line1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "before_stop_sounds",
        actual_line1 == expected_line1,
        expected_line1,
        actual_line1
    ))

    # Check second line
    expected_line2 = "After stopAllSounds"
    actual_line2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "after_stop_sounds",
        actual_line2 == expected_line2,
        expected_line2,
        actual_line2
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

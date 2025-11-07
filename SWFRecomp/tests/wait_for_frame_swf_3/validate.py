#!/usr/bin/env python3
"""
Validation script for wait_for_frame_swf_3

Tests the WAIT_FOR_FRAME opcode (0x8A).
Expected output:
  1. "Frame 0 loaded" - WaitForFrame(0) succeeds, frame exists
  2. "Continued" - WaitForFrame(100) fails, skips trace, continues
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
      Line 1: "Frame 0 loaded" (frame 0 exists and is loaded)
      Line 2: "Continued" (after skipping frame 100 check)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Frame 0 loaded
    expected_1 = "Frame 0 loaded"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "wait_for_frame_exists",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test 2: Continued (after skip)
    expected_2 = "Continued"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "wait_for_frame_skip",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Ensure no extra output (should not print "Frame 100 loaded")
    if len(lines) > 2:
        results.append(make_result(
            "no_extra_output",
            False,
            "2 lines",
            f"{len(lines)} lines",
            "Extra output detected - skip logic may be broken"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

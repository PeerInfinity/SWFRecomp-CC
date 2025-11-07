#!/usr/bin/env python3
"""
Validation script for wait_for_frame2_swf_4

Tests the WAIT_FOR_FRAME2 opcode (0x8D).
Expected output:
  Frame 1 loaded
  Continued

This test pushes frame 1 to the stack, then uses WaitForFrame2 with skip count 1.
Since our implementation assumes all frames are loaded (non-streaming),
the frame check should pass and not skip the first trace.
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

    Expected: Two lines of output
    Line 1: "Frame 1 loaded"
    Line 2: "Continued"
    """
    lines = parse_output(output)

    results = []

    # Check first output
    expected_1 = "Frame 1 loaded"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "frame_loaded_trace",
        actual_1 == expected_1,
        expected_1,
        actual_1,
        "First trace should execute since frame is loaded"
    ))

    # Check second output
    expected_2 = "Continued"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "continuation_trace",
        actual_2 == expected_2,
        expected_2,
        actual_2,
        "Second trace should always execute"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

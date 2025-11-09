#!/usr/bin/env python3
"""
Validation script for stop_multiframe_swf_4

Tests that STOP opcode prevents further frames from executing.
Expected output: Only "Frame 1" (Frame 2 should not execute)
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

    Expected: Only "Frame 1"
    Frame 2 should NOT execute because STOP was called in Frame 1.
    """
    lines = parse_output(output)

    results = []

    # Check that we got exactly one line of output
    results.append(make_result(
        "output_line_count",
        len(lines) == 1,
        "1 line (Frame 2 should not execute)",
        f"{len(lines)} line(s)"
    ))

    # Check first line is "Frame 1"
    if len(lines) >= 1:
        expected = "Frame 1"
        actual = lines[0]
        results.append(make_result(
            "frame_1_output",
            actual == expected,
            expected,
            actual
        ))

    # Verify Frame 2 did NOT execute
    frame_2_executed = any("Frame 2" in line for line in lines)
    results.append(make_result(
        "frame_2_not_executed",
        not frame_2_executed,
        "Frame 2 should NOT execute",
        "Frame 2 executed" if frame_2_executed else "Frame 2 did not execute"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

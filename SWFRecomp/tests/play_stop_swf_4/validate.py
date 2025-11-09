#!/usr/bin/env python3
"""
Validation script for play_stop_swf_4

Tests PLAY and STOP opcodes interaction.
Expected:
- Frame 1 calls STOP then PLAY (allowing frame 2 to execute)
- Frame 2 executes and calls STOP (preventing frame 3)
- Frame 3 should NOT execute
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

    Expected: "Frame 1" and "Frame 2" only
    Frame 3 should NOT execute because Frame 2 called STOP.
    """
    lines = parse_output(output)

    results = []

    # Check that we got exactly two lines of output
    results.append(make_result(
        "output_line_count",
        len(lines) == 2,
        "2 lines (Frame 1 and Frame 2)",
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

    # Check second line is "Frame 2"
    if len(lines) >= 2:
        expected = "Frame 2"
        actual = lines[1]
        results.append(make_result(
            "frame_2_output",
            actual == expected,
            expected,
            actual
        ))

    # Verify Frame 3 did NOT execute
    frame_3_executed = any("Frame 3" in line for line in lines)
    results.append(make_result(
        "frame_3_not_executed",
        not frame_3_executed,
        "Frame 3 should NOT execute",
        "Frame 3 executed" if frame_3_executed else "Frame 3 did not execute"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

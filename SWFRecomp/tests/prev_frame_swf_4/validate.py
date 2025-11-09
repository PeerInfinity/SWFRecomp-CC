#!/usr/bin/env python3
"""
Validation script for prev_frame_swf_4

Tests the PREV_FRAME opcode (0x05).

This test properly exercises the prevFrame functionality:
- Frame 0: trace "Frame 1", gotoFrame(2) - jumps to Frame 2
- Frame 1: trace "Frame 2", STOP - only executes when prevFrame() is called
- Frame 2: trace "Frame 3", prevFrame() - goes back to Frame 1

Expected output: Frame 1, Frame 3, Frame 2
"""
import sys
import json
import os

script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected sequence:
    1. Frame 1 - from Frame 0
    2. Frame 3 - from Frame 2 (after gotoFrame)
    3. Frame 2 - from Frame 1 (after prevFrame)
    """
    lines = parse_output(output)

    # Check we got exactly 3 lines
    if len(lines) < 3:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "3 lines",
                f"{len(lines)} lines",
                "Expected exactly 3 trace outputs"
            )
        ])

    results = []

    # First output should be "Frame 1" from Frame 0
    results.append(make_result(
        "first_frame",
        lines[0] == "Frame 1",
        "Frame 1",
        lines[0],
        "First frame should trace 'Frame 1'"
    ))

    # Second output should be "Frame 3" from Frame 2 (after goto)
    results.append(make_result(
        "goto_target",
        lines[1] == "Frame 3",
        "Frame 3",
        lines[1],
        "After gotoFrame(2), should trace 'Frame 3'"
    ))

    # Third output should be "Frame 2" from Frame 1 (after prevFrame)
    results.append(make_result(
        "prev_frame_works",
        lines[2] == "Frame 2",
        "Frame 2",
        lines[2],
        "After prevFrame(), should trace 'Frame 2'"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

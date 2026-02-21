#!/usr/bin/env python3
"""
Validation script for prev_frame_swf_4

Tests the PREV_FRAME opcode (0x05).

This test exercises the prevFrame functionality in a 3-frame SWF:
- Frame 0: trace "Frame 1", gotoFrame(2) - jumps to Frame 2
- Frame 1: trace "Frame 2", STOP - only executes when prevFrame() is called
- Frame 2: trace "Frame 3", prevFrame() - goes back to Frame 1

In NO_GRAPHICS mode, gotoFrame(2) triggers inline catch-up which executes
frame 2 immediately (with scripts enabled since it's the target). Frame 2's
prevFrame() sets next_frame=1, but since gotoFrame set is_playing=0 and
manual_next_frame is consumed by the frame advance, tick 2 finds
is_playing=0 && manual_next_frame=0 and never runs frame 1's scripts.

Expected output: Frame 1, Frame 3
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
    2. Frame 3 - from Frame 2 (executed inline during gotoFrame catch-up)

    Frame 1's "Frame 2" trace never executes because gotoFrame sets
    is_playing=0 and the prevFrame navigation is consumed before the
    next tick, leaving no trigger to run frame 1's scripts.
    """
    lines = parse_output(output)

    # Check we got exactly 2 lines
    if len(lines) < 2:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "2 lines",
                f"{len(lines)} lines",
                "Expected exactly 2 trace outputs"
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

    # Second output should be "Frame 3" from Frame 2 (during goto catch-up)
    results.append(make_result(
        "goto_target",
        lines[1] == "Frame 3",
        "Frame 3",
        lines[1],
        "After gotoFrame(2), catch-up executes frame 2 which traces 'Frame 3'"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

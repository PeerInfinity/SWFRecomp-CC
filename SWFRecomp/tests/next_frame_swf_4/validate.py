#!/usr/bin/env python3
"""
Validation script for next_frame_swf_4

Tests the NEXT_FRAME opcode (0x04).
Expected output: Frame 1 followed by Frame 2
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
    Frame 1
    Frame 2
    Frame 3
    Frame 4

    Tests:
    - Basic nextFrame advancement
    - Multiple consecutive nextFrame calls
    - nextFrame behavior through multiple frames
    - Proper termination with stop()
    """
    lines = parse_output(output)

    # Check that we got exactly 4 lines of output
    if len(lines) < 4:
        return make_validation_result([
            make_result(
                "frame_count",
                False,
                "4 frames",
                f"{len(lines)} frames",
                "Expected 4 trace outputs"
            )
        ])

    results = []

    # Check Frame 1
    results.append(make_result(
        "frame_1_output",
        lines[0] == "Frame 1",
        "Frame 1",
        lines[0],
        "First frame with nextFrame() call"
    ))

    # Check Frame 2
    results.append(make_result(
        "frame_2_output",
        lines[1] == "Frame 2",
        "Frame 2",
        lines[1],
        "Second frame with nextFrame() call"
    ))

    # Check Frame 3
    results.append(make_result(
        "frame_3_output",
        lines[2] == "Frame 3",
        "Frame 3",
        lines[2],
        "Third frame with nextFrame() call"
    ))

    # Check Frame 4
    results.append(make_result(
        "frame_4_output",
        lines[3] == "Frame 4",
        "Frame 4",
        lines[3],
        "Fourth frame with stop() call"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

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
    """
    lines = parse_output(output)

    # Check that we got exactly 2 lines of output
    if len(lines) < 2:
        return make_validation_result([
            make_result(
                "frame_count",
                False,
                "2 frames",
                f"{len(lines)} frames",
                "Expected 2 trace outputs"
            )
        ])

    results = []

    # Check Frame 1
    results.append(make_result(
        "frame_1_output",
        lines[0] == "Frame 1",
        "Frame 1",
        lines[0]
    ))

    # Check Frame 2
    results.append(make_result(
        "frame_2_output",
        lines[1] == "Frame 2",
        "Frame 2",
        lines[1]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

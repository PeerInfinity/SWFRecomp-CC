#!/usr/bin/env python3
"""
Validation script for play_swf_4

Comprehensive test of PLAY opcode (0x06) with multiple edge cases:
- Basic play from stopped state
- Play when already playing (no-op)
- Multiple consecutive play calls
- Play/stop/play sequences

Expected output:
Frame 1
After stop
After play
Frame 2
Double play
Frame 3
Stop after play
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
    Validate comprehensive PLAY opcode test output.

    Expected: 7 lines of trace output demonstrating various play/stop scenarios
    """
    lines = parse_output(output)

    results = []

    # Check we have the expected number of lines
    expected_lines = 7
    if len(lines) < expected_lines:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                f"{expected_lines} lines",
                f"{len(lines)} lines",
                f"Expected {expected_lines} lines but got {len(lines)}"
            )
        ])

    # Frame 1: Basic play from stopped state
    results.append(make_result(
        "frame_1_start",
        lines[0] == "Frame 1",
        "Frame 1",
        lines[0]
    ))

    results.append(make_result(
        "after_stop",
        lines[1] == "After stop",
        "After stop",
        lines[1]
    ))

    results.append(make_result(
        "after_play",
        lines[2] == "After play",
        "After play",
        lines[2]
    ))

    # Frame 2: Play when already playing
    results.append(make_result(
        "frame_2_start",
        lines[3] == "Frame 2",
        "Frame 2",
        lines[3]
    ))

    results.append(make_result(
        "double_play",
        lines[4] == "Double play",
        "Double play",
        lines[4]
    ))

    # Frame 3: Play/stop/play sequence
    results.append(make_result(
        "frame_3_start",
        lines[5] == "Frame 3",
        "Frame 3",
        lines[5]
    ))

    results.append(make_result(
        "stop_after_play",
        lines[6] == "Stop after play",
        "Stop after play",
        lines[6]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

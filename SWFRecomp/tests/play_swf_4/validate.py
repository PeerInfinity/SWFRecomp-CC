#!/usr/bin/env python3
"""
Validation script for play_swf_4

Tests the PLAY opcode (0x06) along with STOP opcode.
Expected output:
- Frame 1: trace("Frame 1"), stop(), trace("Stopped"), play(), trace("Playing")
- Frame 2: trace("Frame 2"), stop()

Expected output:
Frame 1
Stopped
Playing
Frame 2
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

    Expected: Four lines of trace output demonstrating play/stop control
    """
    lines = parse_output(output)

    results = []

    # Check we have 4 lines
    if len(lines) < 4:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "4 lines",
                f"{len(lines)} lines",
                f"Expected 4 lines but got {len(lines)}"
            )
        ])

    # Validate each line
    results.append(make_result(
        "frame_1_trace",
        lines[0] == "Frame 1",
        "Frame 1",
        lines[0]
    ))

    results.append(make_result(
        "stopped_trace",
        lines[1] == "Stopped",
        "Stopped",
        lines[1]
    ))

    results.append(make_result(
        "playing_trace",
        lines[2] == "Playing",
        "Playing",
        lines[2]
    ))

    results.append(make_result(
        "frame_2_trace",
        lines[3] == "Frame 2",
        "Frame 2",
        lines[3]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

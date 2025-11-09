#!/usr/bin/env python3
"""
Validation script for goto_frame_swf_3

Tests the ActionGotoFrame opcode (0x81).
Note: The test has a single frame and attempts to goto frame 2, which doesn't exist.
With the improved implementation, gotoFrame now actually performs navigation instead of
just printing. Since frame 2 doesn't exist, execution continues in the same frame.

Expected output:
- "Start" (from trace before goto)
- "After goto" (from trace after goto - executes because goto to non-existent frame doesn't stop execution in same frame)
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

    Expected: Two lines of output - the trace before and after the goto.
    The goto itself now actually performs navigation instead of printing.
    """
    lines = parse_output(output)

    results = []

    # Expected output lines
    expected_lines = [
        "Start",
        "After goto"
    ]

    # Check we have the right number of lines
    if len(lines) < len(expected_lines):
        return make_validation_result([
            make_result(
                "output_count",
                False,
                f"{len(expected_lines)} lines",
                f"{len(lines)} lines",
                f"Expected {len(expected_lines)} lines of output but got {len(lines)}"
            )
        ])

    # Validate each line
    for i, expected in enumerate(expected_lines):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            f"line_{i+1}_{expected.replace(' ', '_').replace(':', '')}",
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

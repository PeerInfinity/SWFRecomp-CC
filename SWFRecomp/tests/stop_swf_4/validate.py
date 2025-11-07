#!/usr/bin/env python3
"""
Validation script for stop_swf_4

Tests the STOP opcode (0x07).
Expected output: Both "Before stop" and "After stop"
STOP sets quit_swf flag but doesn't halt current script execution.
The current action block runs to completion, then no more frames execute.
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

    Expected: Both "Before stop" and "After stop"
    STOP sets quit_swf flag but doesn't halt current script execution.
    """
    lines = parse_output(output)

    results = []

    # Check that we got exactly two lines of output
    results.append(make_result(
        "output_line_count",
        len(lines) == 2,
        "2 lines",
        f"{len(lines)} line(s)"
    ))

    # Check first line is "Before stop"
    if len(lines) >= 1:
        expected = "Before stop"
        actual = lines[0]
        results.append(make_result(
            "before_stop_output",
            actual == expected,
            expected,
            actual
        ))

    # Check second line is "After stop"
    if len(lines) >= 2:
        expected = "After stop"
        actual = lines[1]
        results.append(make_result(
            "after_stop_output",
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

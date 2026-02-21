#!/usr/bin/env python3
"""
Validation script for set_target2_swf_4

Tests the SET_TARGET2 opcode (0x20) - stack-based context switching.
Expected trace output (no debug lines):
  In mySprite
  Back to main
  In nested path
  Final main
"""
import sys
import json
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.
    Expects only the 4 trace lines (no debug log lines).
    """
    lines = parse_output(output)

    expected = [
        ("trace_in_mySprite", "In mySprite"),
        ("trace_back_to_main", "Back to main"),
        ("trace_in_nested", "In nested path"),
        ("trace_final_main", "Final main"),
    ]

    results = []
    for i, (name, exp) in enumerate(expected):
        actual = lines[i] if i < len(lines) else "<missing>"
        results.append(make_result(name, actual == exp, exp, actual))

    if len(lines) > len(expected):
        results.append(make_result(
            "no_extra_output",
            False,
            f"{len(expected)} lines",
            f"{len(lines)} lines",
            f"Unexpected extra output: {lines[len(expected):]}"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

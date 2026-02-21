#!/usr/bin/env python3
"""
Validation script for gotoframe2_swf_5

Tests the GOTO_FRAME2 opcode (stack-based frame navigation).
Expected trace output (no debug lines):
  After numeric frame
  After label
  After negative frame
  After target path numeric
  After target path label
"""
import sys
import json
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output for GotoFrame2 testing.
    Expects only the 5 trace lines (no debug log lines).
    """
    lines = parse_output(output)

    expected = [
        ("trace_after_numeric", "After numeric frame"),
        ("trace_after_label", "After label"),
        ("trace_after_negative", "After negative frame"),
        ("trace_after_target_numeric", "After target path numeric"),
        ("trace_after_target_label", "After target path label"),
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

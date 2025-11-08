#!/usr/bin/env python3
"""
Validation script for declare_local_swf_5

Tests the DECLARE_LOCAL opcode (0x41).

Expected behavior:
- DECLARE_LOCAL opcode is recognized and executed
- When called outside a function, it shows a warning
- Test completes successfully without crashing

Note: Full local variable functionality requires DEFINE_FUNCTION opcode.
This test validates basic opcode recognition and handling.
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

    Expected output:
    1. "Testing DECLARE_LOCAL opcode"
    2. "Warning: DECLARE_LOCAL outside function for variable 'x'"
    3. "DECLARE_LOCAL completed (warning expected)"
    """
    lines = parse_output(output)

    results = []

    # Check first line
    if len(lines) > 0:
        expected = "Testing DECLARE_LOCAL opcode"
        actual = lines[0]
        results.append(make_result(
            "first_trace",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "first_trace",
            False,
            "Testing DECLARE_LOCAL opcode",
            "(no output)",
            "Expected first trace output"
        ))

    # Check warning message (from printf)
    if len(lines) > 1:
        expected = "Warning: DECLARE_LOCAL outside function for variable 'x'"
        actual = lines[1]
        results.append(make_result(
            "warning_message",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "warning_message",
            False,
            "Warning: DECLARE_LOCAL outside function for variable 'x'",
            "(no output)",
            "Expected warning message"
        ))

    # Check third line
    if len(lines) > 2:
        expected = "DECLARE_LOCAL completed (warning expected)"
        actual = lines[2]
        results.append(make_result(
            "completion_trace",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "completion_trace",
            False,
            "DECLARE_LOCAL completed (warning expected)",
            "(no output)",
            "Expected completion trace output"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

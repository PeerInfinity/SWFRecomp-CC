#!/usr/bin/env python3
"""
Validation script for declare_local_swf_5

Tests the DECLARE_LOCAL opcode (0x41).

Expected behavior:
- DECLARE_LOCAL opcode is recognized and executed
- When called outside a function, Flash silently ignores it (no warning)
- Test completes successfully without crashing
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
    2. "DECLARE_LOCAL completed (warning expected)"

    Note: Flash silently ignores DECLARE_LOCAL outside functions (no warning).
    """
    lines = parse_output(output)

    results = []

    # Check first line
    expected_1 = "Testing DECLARE_LOCAL opcode"
    actual_1 = lines[0] if len(lines) > 0 else "(no output)"
    results.append(make_result(
        "first_trace",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Check completion line (no warning in between — Flash silently ignores)
    expected_2 = "DECLARE_LOCAL completed (warning expected)"
    actual_2 = lines[1] if len(lines) > 1 else "(no output)"
    results.append(make_result(
        "completion_trace",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

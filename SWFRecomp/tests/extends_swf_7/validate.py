#!/usr/bin/env python3
"""
Validation script for extends_swf_7

Tests the EXTENDS opcode (0x69) which sets up prototype-based inheritance
between constructor functions in ActionScript 2.0.

Expected output:
  EXTENDS test started
  EXTENDS completed successfully
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
      Line 1: "EXTENDS test started"
      Line 2: "EXTENDS completed successfully"
    """
    lines = parse_output(output)

    if len(lines) < 2:
        return make_validation_result([
            make_result(
                "extends_output_count",
                False,
                "2 lines",
                f"{len(lines)} lines",
                f"Expected 2 output lines, got {len(lines)}"
            )
        ])

    results = []

    # Check first line
    expected_start = "EXTENDS test started"
    actual_start = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "extends_test_started",
        actual_start == expected_start,
        expected_start,
        actual_start
    ))

    # Check second line
    expected_complete = "EXTENDS completed successfully"
    actual_complete = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "extends_test_completed",
        actual_complete == expected_complete,
        expected_complete,
        actual_complete
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

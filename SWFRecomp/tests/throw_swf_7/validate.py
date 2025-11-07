#!/usr/bin/env python3
"""
Validation script for throw_swf_7

Tests the THROW opcode (0x2A) for exception handling.
Expected output:
- "Before throw"
- "[Uncaught exception: Error message]"
- "After throw" should NOT appear (execution stops after throw)
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
    Line 1: "Before throw"
    Line 2: "[Uncaught exception: Error message]"

    NOT expected:
    "After throw" (execution should stop)
    """
    lines = parse_output(output)

    results = []

    # Check we have at least 2 lines
    if len(lines) < 2:
        results.append(make_result(
            "output_length",
            False,
            "at least 2 lines",
            f"{len(lines)} lines",
            "Not enough output lines"
        ))
        return make_validation_result(results)

    # Check line 1: "Before throw"
    expected_line1 = "Before throw"
    actual_line1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "before_throw",
        actual_line1 == expected_line1,
        expected_line1,
        actual_line1
    ))

    # Check line 2: "[Uncaught exception: Error message]"
    expected_line2 = "[Uncaught exception: Error message]"
    actual_line2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "exception_message",
        actual_line2 == expected_line2,
        expected_line2,
        actual_line2
    ))

    # Check that "After throw" does NOT appear
    has_after_throw = any("After throw" in line for line in lines)
    results.append(make_result(
        "no_after_throw",
        not has_after_throw,
        "Should not appear",
        "Appeared in output" if has_after_throw else "Not in output"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

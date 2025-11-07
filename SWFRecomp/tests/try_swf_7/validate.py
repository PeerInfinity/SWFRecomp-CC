#!/usr/bin/env python3
"""
Validation script for try_swf_7

Tests the ActionTry (0x8F) and ActionThrow (0x2A) opcodes.
Expected output:
In try
Caught: Error!
After try-catch
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
    In try
    Caught: Error!
    After try-catch
    """
    lines = parse_output(output)

    results = []

    # Check line 1: "In try"
    expected_1 = "In try"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "try_block_executes",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Check line 2: "Caught: Error!"
    expected_2 = "Caught: Error!"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "catch_block_executes",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Check line 3: "After try-catch"
    expected_3 = "After try-catch"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "after_try_catch_executes",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Verify that "This won't print" doesn't appear (execution stopped at throw)
    has_unreachable = any("This won't print" in line for line in lines)
    results.append(make_result(
        "throw_stops_execution",
        not has_unreachable,
        "No 'This won't print' in output",
        "Found 'This won't print'" if has_unreachable else "Not found"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

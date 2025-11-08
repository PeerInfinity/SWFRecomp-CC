#!/usr/bin/env python3
"""
Validation script for delete_swf_5

Tests the DELETE opcode (0x3A) with three test cases:
1. Delete existing property from object
2. Delete non-existent property from object
3. Delete property from non-existent object

Expected output:
  1
  1
  1
  DELETE tests complete
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
    Validate DELETE opcode test output.

    Expected: Four lines with three "1" results and completion message
    """
    lines = parse_output(output)

    results = []

    # Validate Test Case 1: Delete existing property
    if len(lines) > 0:
        expected = "1"
        actual = lines[0]
        results.append(make_result(
            "delete_existing_property",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "delete_existing_property",
            False,
            "1",
            "",
            "No output received"
        ))

    # Validate Test Case 2: Delete non-existent property
    if len(lines) > 1:
        expected = "1"
        actual = lines[1]
        results.append(make_result(
            "delete_nonexistent_property",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "delete_nonexistent_property",
            False,
            "1",
            "",
            "Missing second output"
        ))

    # Validate Test Case 3: Delete from non-existent object
    if len(lines) > 2:
        expected = "1"
        actual = lines[2]
        results.append(make_result(
            "delete_from_nonexistent_object",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "delete_from_nonexistent_object",
            False,
            "1",
            "",
            "Missing third output"
        ))

    # Validate completion message
    if len(lines) > 3:
        expected = "DELETE tests complete"
        actual = lines[3]
        results.append(make_result(
            "completion_message",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "completion_message",
            False,
            "DELETE tests complete",
            "",
            "Missing completion message"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

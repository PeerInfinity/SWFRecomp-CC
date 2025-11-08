#!/usr/bin/env python3
"""
Validation script for get_member_swf_4

Tests the GET_MEMBER opcode (0x4E).
Expected output:
  - Test 1: String.length property access -> "5"
  - Test 2: Undefined property access -> "undefined"
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
      Line 1: "5" (string.length)
      Line 2: "undefined" (undefined property)
    """
    lines = parse_output(output)

    results = []

    # Test 1: String.length property access
    if len(lines) > 0:
        expected = "5"
        actual = lines[0]
        results.append(make_result(
            "string_length_property",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "string_length_property",
            False,
            "5",
            "",
            "No output received"
        ))

    # Test 2: Undefined property access
    if len(lines) > 1:
        expected = "undefined"
        actual = lines[1]
        results.append(make_result(
            "undefined_property",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "undefined_property",
            False,
            "undefined",
            "",
            "Missing second output line"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

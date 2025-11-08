#!/usr/bin/env python3
"""
Validation script for strict_equals_swf_4

Tests the STRICT_EQUALS opcode (0x66).
Expected output:
  - Test 1: trace(5 === 5) = 1 (true - same type and value)
  - Test 2: trace(5 === 3) = 0 (false - different values)
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
    Validate test output for STRICT_EQUALS opcode.

    Expected output (2 lines):
      1  (5 === 5 is true)
      0  (5 === 3 is false)
    """
    lines = parse_output(output)

    results = []

    # Test 1: 5 === 5 should return 1 (true)
    if len(lines) > 0:
        expected = "1"
        actual = lines[0]
        results.append(make_result(
            "strict_equals_same_value",
            actual == expected,
            expected,
            actual,
            "Testing: 5 === 5 (should be true)"
        ))
    else:
        results.append(make_result(
            "strict_equals_same_value",
            False,
            "1",
            "(no output)",
            "Missing first test output"
        ))

    # Test 2: 5 === 3 should return 0 (false)
    if len(lines) > 1:
        expected = "0"
        actual = lines[1]
        results.append(make_result(
            "strict_equals_different_value",
            actual == expected,
            expected,
            actual,
            "Testing: 5 === 3 (should be false)"
        ))
    else:
        results.append(make_result(
            "strict_equals_different_value",
            False,
            "0",
            "(no output)",
            "Missing second test output"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

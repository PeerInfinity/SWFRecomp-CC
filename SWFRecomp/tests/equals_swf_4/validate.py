#!/usr/bin/env python3
"""
Validation script for equals_swf_4

Tests the EQUALS opcode (0x0E) - numeric equality comparison with type coercion.
Expected output:
  1. trace(5 == 5) = 1 (true)
  2. trace(5 == 3) = 0 (false)
  3. trace(0 == 0) = 1 (true)
  4. trace(10 == 20) = 0 (false)
  5. trace(-5 == -5) = 1 (true)
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

    Expected: 5 lines showing equality test results (1 or 0)
    """
    lines = parse_output(output)

    # Expected outputs for each test case
    test_cases = [
        ("equals_5_5", "1", "trace(5 == 5) should return 1"),
        ("equals_5_3", "0", "trace(5 == 3) should return 0"),
        ("equals_0_0", "1", "trace(0 == 0) should return 1"),
        ("equals_10_20", "0", "trace(10 == 20) should return 0"),
        ("equals_neg5_neg5", "1", "trace(-5 == -5) should return 1")
    ]

    results = []
    for i, (name, expected, description) in enumerate(test_cases):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            result = make_result(name, passed, expected, actual)
        else:
            # Missing output
            result = make_result(
                name,
                False,
                expected,
                "missing",
                f"Expected output line {i+1} but only got {len(lines)} lines"
            )
        results.append(result)

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

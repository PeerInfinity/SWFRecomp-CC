#!/usr/bin/env python3
"""
Validation script for multiply_floats_swf_4

Tests the MULTIPLY opcode (0x0C) with various numeric values.
Expected outputs:
  1. 5 * 3 = 15
  2. 2.5 * 4 = 10
  3. 42 * 0 = 0
  4. -3 * 7 = -21
  5. 1e38 * 1e38 = inf
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

    Expected: 5 lines with multiplication results
    """
    lines = parse_output(output)

    # We expect exactly 5 outputs
    if len(lines) < 5:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "5 lines",
                f"{len(lines)} lines",
                "Expected 5 multiplication results"
            )
        ])

    results = []

    # Test 1: 5 * 3 = 15
    results.append(make_result(
        "multiply_5_3",
        lines[0] == "15",
        "15",
        lines[0]
    ))

    # Test 2: 2.5 * 4 = 10
    results.append(make_result(
        "multiply_2.5_4",
        lines[1] == "10",
        "10",
        lines[1]
    ))

    # Test 3: 42 * 0 = 0
    results.append(make_result(
        "multiply_42_0",
        lines[2] == "0",
        "0",
        lines[2]
    ))

    # Test 4: -3 * 7 = -21
    results.append(make_result(
        "multiply_neg3_7",
        lines[3] == "-21",
        "-21",
        lines[3]
    ))

    # Test 5: 1e38 * 1e38 = inf
    results.append(make_result(
        "multiply_overflow",
        lines[4] == "inf",
        "inf",
        lines[4]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

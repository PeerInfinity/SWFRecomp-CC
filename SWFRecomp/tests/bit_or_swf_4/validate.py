#!/usr/bin/env python3
"""
Validation script for bit_or_swf_4

Tests the BIT_OR opcode (0x61) with multiple test cases.
Expected outputs:
  14 (12 | 10)
  42 (42 | 0)
  15 (10 | 15)
  7 (1 | 2 | 4)
  65535 (0xFF00 | 0x00FF)
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

    Expected outputs (in order):
      14 - Basic bitwise OR (12 | 10 = 1100 | 1010 = 1110)
      42 - OR with zero identity (42 | 0 = 42)
      15 - OR with all bits set (10 | 15 = 1010 | 1111 = 1111)
      7 - Chained OR operations (1 | 2 | 4 = 001 | 010 | 100 = 111)
      65535 - Large numbers (0xFF00 | 0x00FF = 0xFFFF)
    """
    lines = parse_output(output)

    # Expected outputs for 5 test cases
    expected_values = ["14", "42", "15", "7", "65535"]
    test_names = [
        "bit_or_12_10",
        "bit_or_42_0_identity",
        "bit_or_10_15",
        "bit_or_chained_1_2_4",
        "bit_or_large_numbers"
    ]

    results = []

    # Validate each test case
    for i, (expected, name) in enumerate(zip(expected_values, test_names)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for char_to_ascii_swf_4

Tests the CHAR_TO_ASCII opcode (0x32).
Expected behavior: Converts the first character of a string to its ASCII code value.
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

    Expected outputs:
    1. 65    (from 'A')
    2. 72    (from 'Hello' - first char 'H')
    3. 33    (from '!')
    4. nan   (from empty string)
    5. 233   (from 'é')
    """
    lines = parse_output(output)

    # Expected values
    expected_values = [
        ("65", "char_A"),
        ("72", "char_Hello"),
        ("33", "char_exclamation"),
        ("nan", "empty_string"),
        ("233", "char_e_acute")
    ]

    results = []

    # Validate each output
    for i, (expected, test_name) in enumerate(expected_values):
        if i < len(lines):
            actual = lines[i]
            # NaN comparison is case-insensitive and handles -nan
            if expected.lower() == "nan":
                passed = actual.lower() in ["nan", "-nan"]
            else:
                passed = actual == expected

            results.append(make_result(
                test_name,
                passed,
                expected,
                actual
            ))
        else:
            # Missing output
            results.append(make_result(
                expected[1],
                False,
                expected[0],
                "(missing)",
                f"Expected output line {i+1} but got only {len(lines)} lines"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

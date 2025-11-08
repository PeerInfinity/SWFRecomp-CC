#!/usr/bin/env python3
"""
Validation script for to_string_swf_4

Tests the TO_STRING opcode (0x4B).
Expected output: Four string conversions showing float-to-string with precision.
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

    Expected outputs (with 32-bit float precision):
    1. toString(42)      -> "42"
    2. toString(3.14)    -> "3.14000010490417" (32-bit float precision)
    3. toString(0)       -> "0"
    4. toString(-123.45) -> "-123.44999694824" (32-bit float precision)
    """
    # Filter out runtime messages before parsing
    filtered_lines = []
    for line in output.split('\n'):
        line = line.strip()
        # Skip runtime messages, frame markers, tag markers, and empty lines
        if (line and
            not line.startswith('SWF Runtime') and
            not line.startswith('===') and
            not line.startswith('[Frame') and
            not line.startswith('[Tag')):
            filtered_lines.append(line)

    lines = filtered_lines

    # We expect exactly 4 lines of output
    if len(lines) < 4:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "4 lines",
                f"{len(lines)} lines",
                "Expected 4 output lines"
            )
        ])

    results = []

    # Test Case 1: toString(42) -> "42"
    results.append(make_result(
        "toString_integer",
        lines[0] == "42",
        "42",
        lines[0]
    ))

    # Test Case 2: toString(3.14) -> "3.14000010490417"
    # This shows 32-bit float precision
    results.append(make_result(
        "toString_float_positive",
        lines[1] == "3.14000010490417",
        "3.14000010490417",
        lines[1]
    ))

    # Test Case 3: toString(0) -> "0"
    results.append(make_result(
        "toString_zero",
        lines[2] == "0",
        "0",
        lines[2]
    ))

    # Test Case 4: toString(-123.45) -> "-123.44999694824"
    # This shows 32-bit float precision for negative numbers
    results.append(make_result(
        "toString_float_negative",
        lines[3] == "-123.44999694824",
        "-123.44999694824",
        lines[3]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

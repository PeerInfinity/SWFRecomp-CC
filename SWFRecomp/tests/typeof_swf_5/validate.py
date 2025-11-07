#!/usr/bin/env python3
"""
Validation script for typeof_swf_5

Tests the ActionTypeOf opcode (0x44).
Expected output:
- typeof(42) -> "number"
- typeof("hello") -> "string"
- typeof(3.14) -> "number"
- typeof("") -> "string"
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
    1. typeof(42) -> "number"
    2. typeof("hello") -> "string"
    3. typeof(3.14) -> "number"
    4. typeof("") -> "string"
    """
    lines = parse_output(output)

    # Expected values for each test case
    expected = ["number", "string", "number", "string"]

    # Validate we have exactly 4 lines of output
    if len(lines) < 4:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "4 lines",
                f"{len(lines)} lines",
                f"Expected 4 outputs, got {len(lines)}"
            )
        ])

    # Validate each output
    results = []
    test_names = [
        "typeof_number_42",
        "typeof_string_hello",
        "typeof_number_3.14",
        "typeof_empty_string"
    ]

    for i in range(4):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            test_names[i],
            actual == expected[i],
            expected[i],
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

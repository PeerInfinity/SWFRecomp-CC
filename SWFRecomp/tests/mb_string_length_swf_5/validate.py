#!/usr/bin/env python3
"""
Validation script for mb_string_length_swf_5

Tests the MB_STRING_LENGTH opcode (0x31).
Expected output: Character counts for UTF-8 strings (not byte counts)
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
    Validate test output for MB_STRING_LENGTH.

    Expected outputs (in order):
    1. "Hello" -> 5 characters
    2. "café" -> 4 characters (é is 2 bytes but 1 character)
    3. "€100" -> 4 characters (€ is 3 bytes but 1 character)
    4. "中文" -> 2 characters (each is 3 bytes)
    5. "" -> 0 characters (empty string)
    6. "Hello世界" -> 7 characters (5 ASCII + 2 CJK)
    """
    lines = parse_output(output)

    # Expected values
    expected_values = ["5", "4", "4", "2", "0", "7"]
    test_names = [
        "basic_ascii_hello",
        "utf8_2byte_cafe",
        "utf8_3byte_euro",
        "cjk_characters",
        "empty_string",
        "mixed_ascii_cjk"
    ]

    results = []

    # Check we have exactly 6 outputs
    if len(lines) < 6:
        for i in range(6):
            actual = lines[i] if i < len(lines) else "(missing)"
            expected = expected_values[i]
            results.append(make_result(
                test_names[i],
                False,
                expected,
                actual,
                f"Missing output line {i+1}" if i >= len(lines) else None
            ))
        return make_validation_result(results)

    # Validate each output
    for i in range(6):
        expected = expected_values[i]
        actual = lines[i]
        passed = (actual == expected)
        results.append(make_result(test_names[i], passed, expected, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

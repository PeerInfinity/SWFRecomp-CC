#!/usr/bin/env python3
"""
Validation script for mb_ascii_to_char_swf_4

Tests the MB_ASCII_TO_CHAR opcode (0x37).
Expected output: UTF-8 characters corresponding to code points
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

    Expected outputs for each test case:
    1. mbchr(65) = 'A'
    2. mbchr(97) = 'a'
    3. mbchr(233) = 'é'
    4. mbchr(241) = 'ñ'
    5. mbchr(20013) = '中'
    6. mbchr(26085) = '日'
    7. mbchr(8364) = '€'

    Note: mbchr(0) and mbchr(9999999) produce empty strings which are
    filtered out by parse_output(), so we only validate the 7 non-empty outputs.
    """
    lines = parse_output(output)

    # Expected values for each non-empty test case
    # (Empty outputs for 0 and 9999999 are filtered by parse_output)
    expected_values = [
        "A",      # mbchr(65)
        "a",      # mbchr(97)
        "é",      # mbchr(233)
        "ñ",      # mbchr(241)
        "中",     # mbchr(20013)
        "日",     # mbchr(26085)
        "€"       # mbchr(8364)
    ]

    test_names = [
        "mbchr(65)_uppercase_A",
        "mbchr(97)_lowercase_a",
        "mbchr(233)_e_acute",
        "mbchr(241)_n_tilde",
        "mbchr(20013)_cjk_chinese",
        "mbchr(26085)_cjk_japanese",
        "mbchr(8364)_euro_symbol"
    ]

    results = []

    # Validate each test case
    for i, (expected, test_name) in enumerate(zip(expected_values, test_names)):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            results.append(make_result(test_name, passed, expected, actual))
        else:
            # Missing output line
            results.append(make_result(
                test_name,
                False,
                expected,
                "<missing>",
                f"Output line {i} is missing"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

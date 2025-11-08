#!/usr/bin/env python3
"""
Validation script for mb_char_to_ascii_swf_5

Tests the MB_CHAR_TO_ASCII opcode (0x36) which converts the first character
of a multibyte UTF-8 string to its Unicode code point value.

Expected outputs:
1. "A" → 65 (ASCII character)
2. "é" → 233 (2-byte UTF-8, U+00E9)
3. "€" → 8364 (3-byte UTF-8, U+20AC)
4. "中" → 20013 (3-byte UTF-8, U+4E2D)
5. "" → 0 (empty string)
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import validate_multiple_outputs


def validate_output(output):
    """
    Validate test output.

    Expected outputs (in order):
    1. 65 - ASCII "A"
    2. 233 - UTF-8 "é" (U+00E9)
    3. 8364 - UTF-8 "€" (U+20AC)
    4. 20013 - UTF-8 "中" (U+4E2D)
    5. 0 - empty string
    """
    expected_values = ["65", "233", "8364", "20013", "0"]
    test_names = [
        "ascii_A",
        "utf8_e_acute",
        "utf8_euro",
        "utf8_cjk_middle",
        "empty_string"
    ]

    return validate_multiple_outputs(output, expected_values, test_names)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

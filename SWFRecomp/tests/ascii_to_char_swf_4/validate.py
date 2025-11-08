#!/usr/bin/env python3
"""
Validation script for ascii_to_char_swf_4

Tests the ASCII_TO_CHAR opcode (0x33).
Expected outputs:
  - chr(65)  -> "A"
  - chr(97)  -> "a"
  - chr(33)  -> "!"
  - chr(32)  -> " " (space)
  - chr(233) -> "é" (Latin-1/ISO-8859-1 encoding)

Note: ASCII_TO_CHAR outputs raw bytes (Latin-1), not UTF-8.
      MB_ASCII_TO_CHAR (0x37) is for UTF-8 output.
"""
import sys
import json
import os
import io

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected: 5 lines with characters A, a, !, (space), and é
    """
    # Parse output carefully to preserve whitespace-only lines
    # Split by newline and remove only the final empty element (from trailing \n)
    lines = output.split('\n')

    # Remove trailing empty string if present (from final newline)
    if lines and lines[-1] == '':
        lines = lines[:-1]

    # We expect exactly 5 lines of output
    expected_outputs = [
        ("chr_65", "A"),
        ("chr_97", "a"),
        ("chr_33", "!"),
        ("chr_32", " "),
        ("chr_233", "é")
    ]

    results = []

    for i, (name, expected) in enumerate(expected_outputs):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
        else:
            actual = "<missing>"
            passed = False

        results.append(make_result(name, passed, expected, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    # Read stdin in binary mode and decode as Latin-1
    # This is necessary because ASCII_TO_CHAR outputs raw bytes (0-255)
    # which correspond to Latin-1/ISO-8859-1 encoding
    stdin_binary = sys.stdin.buffer.read()
    output = stdin_binary.decode('latin-1')

    result = validate_output(output)
    print(json.dumps(result, indent=2))

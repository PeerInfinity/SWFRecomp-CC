#!/usr/bin/env python3
"""
Validation script for mb_ascii_to_char_edge_cases_swf_4

Tests the MB_ASCII_TO_CHAR opcode (0x37) edge cases including:
- Negative numbers
- Zero (null character)
- UTF-8 byte boundaries (1, 2, 3, 4 bytes)
- Surrogate pair range (0xD800-0xDFFF)
- Maximum Unicode (0x10FFFF)
- Beyond Unicode range

Expected behavior:
- Negative numbers → empty string + label
- Zero → null character (appears as empty) + label
- Valid code points → UTF-8 encoded character + label
- Surrogate pairs → encoded as-is (Flash behavior, not strictly valid Unicode)
- Beyond Unicode range → empty string + label
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    The test outputs character followed by label for each test case.
    Some cases produce empty strings (negative, zero, beyond_unicode).
    """
    # Filter out runtime messages before parsing
    filtered_lines = []
    for line in output.split('\n'):
        line_stripped = line.strip()
        # Skip runtime messages, frame markers, tag markers, and empty lines
        if (line_stripped and
            not line_stripped.startswith('SWF Runtime') and
            not line_stripped.startswith('===') and
            not line_stripped.startswith('[Frame') and
            not line_stripped.startswith('[Tag')):
            filtered_lines.append(line)

    lines = filtered_lines

    # Expected test cases based on create_test_swf.py
    # Format: (expected_char, label, description)
    # Note: Surrogate pairs (0xD800-0xDFFF) are encoded as invalid UTF-8 sequences.
    # Python's text mode reads these using surrogate escape encoding (PEP 383).
    # Raw bytes: 0xD800 = ED A0 80, 0xDFFF = ED BF BF
    # When read by Python, these become: \udced\udca0\udc80 and \udced\udcbf\udcbf
    test_cases = [
        ("", "negative", "Negative number (-1) should produce empty string"),
        ("", "zero", "Zero (null character) should appear as empty"),
        ("\x7f", "max_1byte", "Maximum 1-byte UTF-8 (127)"),
        ("\u0080", "min_2byte", "Minimum 2-byte UTF-8 (128)"),
        ("\u07ff", "max_2byte", "Maximum 2-byte UTF-8 (2047)"),
        ("\u0800", "min_3byte", "Minimum 3-byte UTF-8 (2048)"),
        ("\ud7ff", "before_surrogate", "Just before surrogate range (0xD7FF)"),
        ("\udced\udca0\udc80", "surrogate_start", "Start of surrogate range (0xD800) - encoded as ED A0 80"),
        ("\udced\udcbf\udcbf", "surrogate_end", "End of surrogate range (0xDFFF) - encoded as ED BF BF"),
        ("\ue000", "after_surrogate", "Just after surrogate range (0xE000)"),
        ("\uffff", "max_3byte", "Maximum 3-byte UTF-8 (65535)"),
        ("\U00010000", "min_4byte", "Minimum 4-byte UTF-8 (65536)"),
        ("\U0010ffff", "max_unicode", "Maximum valid Unicode (0x10FFFF)"),
        ("", "beyond_unicode", "Beyond Unicode range (0x110000) should produce empty string"),
    ]

    results = []

    # Validate each test case
    for i, (expected_char, expected_label, description) in enumerate(test_cases):
        test_name = f"{expected_label}_{i+1}"

        if i < len(lines):
            actual_line = lines[i]
            expected_output = expected_char + expected_label

            # Check if the line matches expected output
            passed = actual_line == expected_output

            if not passed:
                # Provide detailed failure message
                message = f"{description}. Expected char+label but got: {repr(actual_line)}"
                results.append(make_result(
                    test_name,
                    passed,
                    repr(expected_output),
                    repr(actual_line),
                    message
                ))
            else:
                results.append(make_result(
                    test_name,
                    passed,
                    repr(expected_output),
                    repr(actual_line)
                ))
        else:
            # Missing output line
            results.append(make_result(
                test_name,
                False,
                f"{repr(expected_char + expected_label)}",
                "<missing>",
                f"Output line {i} is missing. {description}"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for goto_label_swf_3

Tests the GOTO_LABEL opcode (0x8C) with comprehensive label variations.
Tests label parsing for:
- Basic labels
- Labels with underscores and numbers
- Mixed case labels
- Empty labels (edge case)
- Single character labels
- Long labels
- Labels with special characters
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

    Expected: Alternating trace messages and GoToLabel calls for 7 test cases
    """
    lines = parse_output(output)

    results = []

    # Expected output pattern:
    # Test N: <description>
    # // GoToLabel: <label>
    # ... (repeated for each test)
    # All tests complete

    expected_tests = [
        ("test1_trace", "Test 1: Basic label"),
        ("test1_goto", "// GoToLabel: scene1"),
        ("test2_trace", "Test 2: Label with underscores"),
        ("test2_goto", "// GoToLabel: frame_2_start"),
        ("test3_trace", "Test 3: Mixed case label"),
        ("test3_goto", "// GoToLabel: MyScene"),
        ("test4_trace", "Test 4: Empty label"),
        ("test4_goto", "// GoToLabel:"),  # Empty label - no space after colon
        ("test5_trace", "Test 5: Single char label"),
        ("test5_goto", "// GoToLabel: A"),
        ("test6_trace", "Test 6: Long label"),
        ("test6_goto", "// GoToLabel: this_is_a_very_long_frame_label_name"),
        ("test7_trace", "Test 7: Special chars label"),
        ("test7_goto", "// GoToLabel: label-with-dash"),
        ("final_trace", "All tests complete"),
    ]

    # Check we have the expected number of lines
    expected_count = len(expected_tests)
    if len(lines) < expected_count:
        return make_validation_result([
            make_result(
                "output_line_count",
                False,
                str(expected_count),
                str(len(lines)),
                f"Expected {expected_count} lines of output, got {len(lines)}"
            )
        ])

    # Validate each line
    for i, (test_name, expected_line) in enumerate(expected_tests):
        if i < len(lines):
            results.append(make_result(
                test_name,
                lines[i] == expected_line,
                expected_line,
                lines[i]
            ))
        else:
            results.append(make_result(
                test_name,
                False,
                expected_line,
                "(missing)",
                f"Line {i} is missing from output"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

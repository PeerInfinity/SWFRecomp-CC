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

    Each GoToLabel call is preceded by a trace message describing the test.
    The GoToLabel opcode itself produces no output (it just sets the frame),
    so we only validate the trace messages.
    """
    lines = parse_output(output)

    results = []

    expected_traces = [
        ("test1_trace", "Test 1: Basic label"),
        ("test2_trace", "Test 2: Label with underscores"),
        ("test3_trace", "Test 3: Mixed case label"),
        ("test4_trace", "Test 4: Empty label"),
        ("test5_trace", "Test 5: Single char label"),
        ("test6_trace", "Test 6: Long label"),
        ("test7_trace", "Test 7: Special chars label"),
        ("final_trace", "All tests complete"),
    ]

    if len(lines) < len(expected_traces):
        return make_validation_result([
            make_result(
                "output_line_count",
                False,
                str(len(expected_traces)),
                str(len(lines)),
                f"Expected {len(expected_traces)} lines of output, got {len(lines)}"
            )
        ])

    for i, (test_name, expected_line) in enumerate(expected_traces):
        results.append(make_result(
            test_name,
            lines[i] == expected_line,
            expected_line,
            lines[i] if i < len(lines) else "(missing)"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

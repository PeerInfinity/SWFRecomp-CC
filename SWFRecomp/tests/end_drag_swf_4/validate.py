#!/usr/bin/env python3
"""
Validation script for end_drag_swf_4

Tests the END_DRAG opcode (0x28) comprehensively:
  1. END_DRAG when nothing is dragging (no-op)
  2. START_DRAG followed by END_DRAG (proper state management)
  3. Multiple END_DRAG calls (safe to call multiple times)

Expected output:
  Test 1: END_DRAG with no drag
  Test 2: Before START_DRAG
  Test 3: After START_DRAG
  Test 4: After END_DRAG
  Test 5: After second END_DRAG
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

    Expected: Five traces showing END_DRAG executes correctly in all scenarios
    """
    lines = parse_output(output)

    # Check we have exactly 5 lines of output
    if len(lines) < 5:
        return make_validation_result([
            make_result(
                "line_count",
                False,
                "5 lines",
                f"{len(lines)} lines",
                f"Expected 5 lines of output, got {len(lines)}"
            )
        ])

    # Define expected outputs
    expected_outputs = [
        ("test1_end_drag_no_drag", "Test 1: END_DRAG with no drag"),
        ("test2_before_start_drag", "Test 2: Before START_DRAG"),
        ("test3_after_start_drag", "Test 3: After START_DRAG"),
        ("test4_after_end_drag", "Test 4: After END_DRAG"),
        ("test5_second_end_drag", "Test 5: After second END_DRAG"),
    ]

    results = []
    for i, (name, expected) in enumerate(expected_outputs):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(name, actual == expected, expected, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

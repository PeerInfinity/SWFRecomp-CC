#!/usr/bin/env python3
"""
Validation script for end_drag_swf_4

Tests the END_DRAG opcode (0x28).
Expected output:
  Before stopDrag
  After stopDrag
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

    Expected: Two traces showing END_DRAG executes without error
    """
    lines = parse_output(output)

    # Check we have exactly 2 lines of output
    if len(lines) < 2:
        return make_validation_result([
            make_result(
                "end_drag_test",
                False,
                "2 lines",
                f"{len(lines)} lines",
                f"Expected 2 lines of output, got {len(lines)}"
            )
        ])

    # Check first line
    expected1 = "Before stopDrag"
    actual1 = lines[0] if len(lines) > 0 else ""
    result1 = make_result(
        "before_end_drag",
        actual1 == expected1,
        expected1,
        actual1
    )

    # Check second line
    expected2 = "After stopDrag"
    actual2 = lines[1] if len(lines) > 1 else ""
    result2 = make_result(
        "after_end_drag",
        actual2 == expected2,
        expected2,
        actual2
    )

    return make_validation_result([result1, result2])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

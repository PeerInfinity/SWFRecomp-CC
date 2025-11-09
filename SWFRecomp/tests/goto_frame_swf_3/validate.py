#!/usr/bin/env python3
"""
Validation script for goto_frame_swf_3

Tests the ActionGotoFrame opcode (0x81).
Expected output:
- "Before goto" (from trace before goto)
- "// GotoFrame: 2" (from the actionGotoFrame call)
- "After goto" (from trace after goto)

Note: This test verifies that the opcode is correctly parsed and the
frame parameter is extracted. Full frame navigation is not yet implemented.
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

    Expected: Three lines of output showing trace before goto, the goto action, and trace after.
    """
    lines = parse_output(output)

    results = []

    # Expected output lines
    expected_lines = [
        "Before goto",
        "// GotoFrame: 2",
        "After goto"
    ]

    # Check we have the right number of lines
    if len(lines) < len(expected_lines):
        return make_validation_result([
            make_result(
                "output_count",
                False,
                f"{len(expected_lines)} lines",
                f"{len(lines)} lines",
                f"Expected {len(expected_lines)} lines of output but got {len(lines)}"
            )
        ])

    # Validate each line
    for i, expected in enumerate(expected_lines):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            f"line_{i+1}_{expected.replace(' ', '_').replace(':', '')}",
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

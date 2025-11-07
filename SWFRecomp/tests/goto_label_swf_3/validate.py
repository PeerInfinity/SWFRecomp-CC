#!/usr/bin/env python3
"""
Validation script for goto_label_swf_3

Tests the GOTO_LABEL opcode (0x8C).
Expected output:
- Testing GoToLabel
- // GoToLabel: testlabel
- After GoToLabel
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

    Expected: Three lines showing trace before, GoToLabel call, and trace after
    """
    lines = parse_output(output)

    results = []

    # Check we have 3 lines
    if len(lines) < 3:
        return make_validation_result([
            make_result(
                "output_line_count",
                False,
                "3",
                str(len(lines)),
                f"Expected 3 lines of output, got {len(lines)}"
            )
        ])

    # Check first trace output
    results.append(make_result(
        "trace_before_goto",
        lines[0] == "Testing GoToLabel",
        "Testing GoToLabel",
        lines[0]
    ))

    # Check GoToLabel call output
    results.append(make_result(
        "goto_label_call",
        lines[1] == "// GoToLabel: testlabel",
        "// GoToLabel: testlabel",
        lines[1]
    ))

    # Check trace after goto
    results.append(make_result(
        "trace_after_goto",
        lines[2] == "After GoToLabel",
        "After GoToLabel",
        lines[2]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

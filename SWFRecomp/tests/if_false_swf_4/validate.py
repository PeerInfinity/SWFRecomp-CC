#!/usr/bin/env python3
"""
Validation script for if_false_swf_4

Tests the ActionIf opcode (0x9D) with a false condition.
Expected behavior: When condition is falsy (0.0), do NOT jump, continue normally.
Expected output:
  not skipped
  after
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

    Test: IF with false condition (0.0)
    - Pushes 0.0 (falsy)
    - IF does NOT jump, continues to next instruction
    - Executes PUSH "not skipped" + TRACE
    - Executes PUSH "after" + TRACE

    Expected output:
      not skipped
      after
    """
    lines = parse_output(output)

    # Pad with empty strings if needed
    if len(lines) < 2:
        lines.extend([''] * (2 - len(lines)))

    results = []

    # First output: "not skipped"
    results.append(make_result(
        "if_false_first_output",
        lines[0] == "not skipped",
        "not skipped",
        lines[0]
    ))

    # Second output: "after"
    results.append(make_result(
        "if_false_second_output",
        lines[1] == "after",
        "after",
        lines[1]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

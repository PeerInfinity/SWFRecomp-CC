#!/usr/bin/env python3
"""
Validation script for if_swf_4

Tests the ActionIf opcode (0x9D) with a true condition.
Expected behavior: When condition is truthy (1.0), jump forward and skip code.
Expected output: "after"
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

    Test: IF with true condition (1.0)
    - Pushes 1.0 (truthy)
    - IF jumps forward, skipping PUSH "skipped" + TRACE
    - Executes PUSH "after" + TRACE

    Expected output: "after"
    """
    lines = parse_output(output)

    expected = "after"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "if_true_condition",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

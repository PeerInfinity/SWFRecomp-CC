#!/usr/bin/env python3
"""
Validation script for string_add_swf_4

Tests the STRING_ADD opcode (0x21) which concatenates two strings.
This test pushes " World" then "Hello" and concatenates them.

Expected output: " WorldHello" (based on current implementation)

Note: The current implementation concatenates as: second + top
So with stack [" World", "Hello"] (Hello on top), result = " World" + "Hello"
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

    Expected: " WorldHello"

    This validates the current behavior of STRING_ADD which concatenates
    the second stack item with the top stack item.

    Note: We can't use parse_output here because it strips whitespace,
    and our test output contains a leading space.
    """
    # Split output into lines but don't strip to preserve leading/trailing spaces
    lines = [line for line in output.split('\n') if line and not line.isspace()]

    # Expected output based on current implementation
    expected = " WorldHello"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "string_concatenation",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

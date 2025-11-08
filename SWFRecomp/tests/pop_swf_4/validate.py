#!/usr/bin/env python3
"""
Validation script for pop_swf_4

Tests the POP opcode (0x17).

Test sequence:
1. PUSH "wrong" (value that should be removed)
2. POP (remove "wrong" from stack)
3. PUSH "correct" (value that should remain)
4. TRACE (should output "correct")

Expected output: "correct"
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

    Expected: "correct"
    The POP operation should remove "wrong" from the stack,
    leaving only "correct" to be traced.
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "correct"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "pop_removes_value",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

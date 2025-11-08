#!/usr/bin/env python3
"""
Validation script for stack_swap_swf_4

Tests the STACK_SWAP opcode (0x4D).
Expected output: 5 (result of 10 / 2 after swapping stack values)

Test sequence:
1. Push 2.0
2. Push 10.0
3. Stack Swap (now stack is [10.0, 2.0])
4. Divide (10.0 / 2.0 = 5.0)
5. Trace outputs "5"
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

    Expected: 5 (result of 10 / 2 after stack swap)
    Without swap, it would be 0.2 (result of 2 / 10)
    """
    lines = parse_output(output)

    # Expected output: 5
    expected = "5"
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "stack_swap_divide",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for implements_op_swf_7

Tests the IMPLEMENTS_OP opcode (0x2C) with comprehensive test coverage:
- Single interface implementation
- Multiple interfaces (2 and 3 interfaces)
- Zero interfaces (edge case)

Expected outputs:
  Test 1: Single interface - OK
  Test 2: Multiple interfaces - OK
  Test 3: Zero interfaces - OK
  Test 4: Two interfaces - OK
  All ImplementsOp tests passed
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

    Expects 5 trace outputs from the comprehensive ImplementsOp test.
    """
    lines = parse_output(output)
    results = []

    # Expected outputs
    expected = [
        "Test 1: Single interface - OK",
        "Test 2: Multiple interfaces - OK",
        "Test 3: Zero interfaces - OK",
        "Test 4: Two interfaces - OK",
        "All ImplementsOp tests passed"
    ]

    # Check each expected output
    for i, expected_line in enumerate(expected):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected_line
        else:
            actual = "(missing)"
            passed = False

        test_name = f"test_{i+1}_{expected_line.split(':')[0].replace(' ', '_').lower()}"
        results.append(make_result(test_name, passed, expected_line, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

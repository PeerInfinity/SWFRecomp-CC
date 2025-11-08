#!/usr/bin/env python3
"""
Validation script for get_variable_swf_4

Tests the GET_VARIABLE opcode (0x1C).
Expected outputs:
1. var x = 42; trace(x) -> 42
2. var name = "hello"; trace(name) -> hello
3. var x = 10; var y = x; trace(y) -> 10
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
    Validate test output for GET_VARIABLE opcode.

    Tests:
    1. Get existing numeric variable: var x = 42; trace(x) -> 42
    2. Get existing string variable: var name = "hello"; trace(name) -> hello
    3. Get after assignment: var x = 10; var y = x; trace(y) -> 10
    """
    lines = parse_output(output)

    # We expect 3 output lines
    if len(lines) < 3:
        lines.extend([''] * (3 - len(lines)))  # Pad with empty strings

    results = []

    # Test 1: Get existing numeric variable
    results.append(make_result(
        "get_numeric_variable_x_equals_42",
        lines[0] == "42",
        "42",
        lines[0]
    ))

    # Test 2: Get existing string variable
    results.append(make_result(
        "get_string_variable_name_equals_hello",
        lines[1] == "hello",
        "hello",
        lines[1]
    ))

    # Test 3: Get after assignment (y = x where x = 10)
    results.append(make_result(
        "get_after_assignment_y_equals_x_equals_10",
        lines[2] == "10",
        "10",
        lines[2]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

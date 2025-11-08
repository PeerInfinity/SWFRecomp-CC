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
from test_utils import make_result, make_validation_result

# Custom parse_output that preserves empty lines (needed for undefined variable test)
def parse_output_with_empty_lines(output):
    """Parse output preserving empty lines (for testing empty string results)"""
    return [line.strip() for line in output.strip().split('\n')]


def validate_output(output):
    """
    Validate test output for GET_VARIABLE opcode.

    Tests:
    1. Get existing numeric variable: var x = 42; trace(x) -> 42
    2. Get existing string variable: var name = "hello"; trace(name) -> hello
    3. Get after assignment: var x = 10; var y = x; trace(y) -> 10
    4. Get undefined variable: trace(undefinedVar) -> "" (empty string)
    5. Get zero value: var zero = 0; trace(zero) -> 0
    6. Get boolean true: var isTrue = 1; trace(isTrue) -> 1
    7. Get boolean false: var isFalse = 0; trace(isFalse) -> 0
    8. Get negative number: var neg = -99.5; trace(neg) -> -99.5
    """
    lines = parse_output_with_empty_lines(output)

    # We expect 8 output lines
    if len(lines) < 8:
        lines.extend([''] * (8 - len(lines)))  # Pad with empty strings

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

    # Test 4: Get undefined variable (should return empty string)
    results.append(make_result(
        "get_undefined_variable_returns_empty",
        lines[3] == "",
        "(empty string)",
        lines[3] if lines[3] else "(empty string)"
    ))

    # Test 5: Get zero value
    results.append(make_result(
        "get_zero_value",
        lines[4] == "0",
        "0",
        lines[4]
    ))

    # Test 6: Get boolean true (1)
    results.append(make_result(
        "get_boolean_true_as_1",
        lines[5] == "1",
        "1",
        lines[5]
    ))

    # Test 7: Get boolean false (0)
    results.append(make_result(
        "get_boolean_false_as_0",
        lines[6] == "0",
        "0",
        lines[6]
    ))

    # Test 8: Get negative number
    results.append(make_result(
        "get_negative_number",
        lines[7] == "-99.5",
        "-99.5",
        lines[7]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

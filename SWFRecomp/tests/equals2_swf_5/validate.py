#!/usr/bin/env python3
"""
Validation script for equals2_swf_5

Tests the ActionEquals2 opcode (0x49) - Type-aware equality comparison.
Expected behavior follows ECMA-262 equality rules:
- Same type: direct comparison
- Number vs String: convert string to number
- Different types: false
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

    Expected outputs:
    1. 5 == 5 -> 1 (true)
    2. 5 == 3 -> 0 (false)
    3. "hello" == "hello" -> 1 (true)
    4. "hello" == "world" -> 0 (false)
    5. 5 == "5" -> 1 (true, type coercion)
    6. 10 == "10" -> 1 (true, type coercion)
    """
    lines = parse_output(output)

    if len(lines) < 6:
        return make_validation_result([
            make_result("output_count", False, "6 lines", f"{len(lines)} lines",
                       f"Expected 6 output lines, got {len(lines)}")
        ])

    results = []

    # Test 1: 5 == 5 (number equality, true)
    results.append(make_result(
        "number_equal_true",
        lines[0] == "1",
        "1",
        lines[0],
        "5 == 5 should be true (1.0)"
    ))

    # Test 2: 5 == 3 (number equality, false)
    results.append(make_result(
        "number_equal_false",
        lines[1] == "0",
        "0",
        lines[1],
        "5 == 3 should be false (0.0)"
    ))

    # Test 3: "hello" == "hello" (string equality, true)
    results.append(make_result(
        "string_equal_true",
        lines[2] == "1",
        "1",
        lines[2],
        '"hello" == "hello" should be true (1.0)'
    ))

    # Test 4: "hello" == "world" (string equality, false)
    results.append(make_result(
        "string_equal_false",
        lines[3] == "0",
        "0",
        lines[3],
        '"hello" == "world" should be false (0.0)'
    ))

    # Test 5: 5 == "5" (type coercion, true)
    results.append(make_result(
        "type_coercion_5",
        lines[4] == "1",
        "1",
        lines[4],
        '5 == "5" should be true (1.0) with type coercion'
    ))

    # Test 6: 10 == "10" (type coercion, true)
    results.append(make_result(
        "type_coercion_10",
        lines[5] == "1",
        "1",
        lines[5],
        '10 == "10" should be true (1.0) with type coercion'
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

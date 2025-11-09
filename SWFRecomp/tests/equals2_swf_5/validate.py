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
    7. true == true -> 1 (true)
    8. true == false -> 0 (false)
    9. true == 1 -> 1 (true, boolean to number)
    10. false == 0 -> 1 (true, boolean to number)
    11. null == null -> 1 (true)
    12. undefined == undefined -> 1 (true)
    13. null == undefined -> 1 (true, ECMA-262 special case)
    14. null == 0 -> 0 (false)
    15. undefined == 0 -> 0 (false)
    """
    lines = parse_output(output)

    if len(lines) < 15:
        return make_validation_result([
            make_result("output_count", False, "15 lines", f"{len(lines)} lines",
                       f"Expected 15 output lines, got {len(lines)}")
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

    # Test 7: true == true (boolean equality, true)
    results.append(make_result(
        "boolean_equal_true",
        lines[6] == "1",
        "1",
        lines[6],
        "true == true should be true (1.0)"
    ))

    # Test 8: true == false (boolean equality, false)
    results.append(make_result(
        "boolean_equal_false",
        lines[7] == "0",
        "0",
        lines[7],
        "true == false should be false (0.0)"
    ))

    # Test 9: true == 1 (boolean to number, true)
    results.append(make_result(
        "boolean_to_number_true",
        lines[8] == "1",
        "1",
        lines[8],
        "true == 1 should be true (1.0) with boolean to number conversion"
    ))

    # Test 10: false == 0 (boolean to number, true)
    results.append(make_result(
        "boolean_to_number_false",
        lines[9] == "1",
        "1",
        lines[9],
        "false == 0 should be true (1.0) with boolean to number conversion"
    ))

    # Test 11: null == null (null equality, true)
    results.append(make_result(
        "null_equal_null",
        lines[10] == "1",
        "1",
        lines[10],
        "null == null should be true (1.0)"
    ))

    # Test 12: undefined == undefined (undefined equality, true)
    results.append(make_result(
        "undefined_equal_undefined",
        lines[11] == "1",
        "1",
        lines[11],
        "undefined == undefined should be true (1.0)"
    ))

    # Test 13: null == undefined (ECMA-262 special case, true)
    results.append(make_result(
        "null_equal_undefined",
        lines[12] == "1",
        "1",
        lines[12],
        "null == undefined should be true (1.0) per ECMA-262"
    ))

    # Test 14: null == 0 (null vs number, false)
    results.append(make_result(
        "null_not_equal_zero",
        lines[13] == "0",
        "0",
        lines[13],
        "null == 0 should be false (0.0)"
    ))

    # Test 15: undefined == 0 (undefined vs number, false)
    results.append(make_result(
        "undefined_not_equal_zero",
        lines[14] == "0",
        "0",
        lines[14],
        "undefined == 0 should be false (0.0)"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

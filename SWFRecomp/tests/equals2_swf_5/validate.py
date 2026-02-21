#!/usr/bin/env python3
"""
Validation script for equals2_swf_5

Tests the ActionEquals2 opcode (0x49) - Type-aware equality comparison.
Expected behavior follows ECMA-262 equality rules:
- Same type: direct comparison
- Number vs String: convert string to number
- Different types: false

Note: SWF5+ traces booleans as "true"/"false", not "1"/"0".
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

    Expected outputs (SWF5 boolean coercion -> "true"/"false"):
    1. 5 == 5 -> true
    2. 5 == 3 -> false
    3. "hello" == "hello" -> true
    4. "hello" == "world" -> false
    5. 5 == "5" -> true (type coercion)
    6. 10 == "10" -> true (type coercion)
    7. true == true -> true
    8. true == false -> false
    9. true == 1 -> true (boolean to number)
    10. false == 0 -> true (boolean to number)
    11. null == null -> true
    12. undefined == undefined -> true
    13. null == undefined -> true (ECMA-262 special case)
    14. null == 0 -> false
    15. undefined == 0 -> false
    """
    lines = parse_output(output)

    if len(lines) < 15:
        return make_validation_result([
            make_result("output_count", False, "15 lines", f"{len(lines)} lines",
                       f"Expected 15 output lines, got {len(lines)}")
        ])

    results = []

    expected = [
        ("number_equal_true", "true", "5 == 5 should be true"),
        ("number_equal_false", "false", "5 == 3 should be false"),
        ("string_equal_true", "true", '"hello" == "hello" should be true'),
        ("string_equal_false", "false", '"hello" == "world" should be false'),
        ("type_coercion_5", "true", '5 == "5" should be true with type coercion'),
        ("type_coercion_10", "true", '10 == "10" should be true with type coercion'),
        ("boolean_equal_true", "true", "true == true should be true"),
        ("boolean_equal_false", "false", "true == false should be false"),
        ("boolean_to_number_true", "true", "true == 1 should be true"),
        ("boolean_to_number_false", "true", "false == 0 should be true"),
        ("null_equal_null", "true", "null == null should be true"),
        ("undefined_equal_undefined", "true", "undefined == undefined should be true"),
        ("null_equal_undefined", "true", "null == undefined should be true per ECMA-262"),
        ("null_not_equal_zero", "false", "null == 0 should be false"),
        ("undefined_not_equal_zero", "false", "undefined == 0 should be false"),
    ]

    for i, (name, exp, msg) in enumerate(expected):
        results.append(make_result(name, lines[i] == exp, exp, lines[i], msg))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

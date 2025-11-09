#!/usr/bin/env python3
"""
Validation script for cast_op_swf_7

Tests the CAST_OP opcode (0x2B) with multiple scenarios.
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

    Expected outputs in order:
    1. primitive_cast_failed - casting primitive to constructor fails
    2. object_cast_without_proto_failed - casting object without prototype chain fails
    3. mixed_type_cast_failed - mixed type casting fails gracefully
    4. cast_op_tests_completed - all tests completed
    """
    lines = parse_output(output)

    results = []

    # Test 1: Primitive cast (should fail)
    expected_1 = "primitive_cast_failed"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "primitive_cast_test",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test 2: Object cast without prototype (should fail)
    expected_2 = "object_cast_without_proto_failed"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "object_cast_no_proto_test",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test 3: Mixed type cast (should fail gracefully)
    expected_3 = "mixed_type_cast_failed"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "mixed_type_cast_test",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Test 4: Completion message
    expected_4 = "cast_op_tests_completed"
    actual_4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "cast_op_completion",
        actual_4 == expected_4,
        expected_4,
        actual_4
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

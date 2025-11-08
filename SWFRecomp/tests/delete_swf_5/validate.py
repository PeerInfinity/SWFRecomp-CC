#!/usr/bin/env python3
"""
Validation script for delete_swf_5

Tests the DELETE opcode (0x3A).

Test Case 1: Delete existing property
  var obj = {a: 1, b: 2, c: 3};
  var result = delete obj.b;
  trace(result);  // Expected: 1 (true)
  trace(obj.b);   // Expected: undefined

Test Case 2: Delete non-existent property
  var obj2 = {x: 10};
  var result2 = delete obj2.xyz;
  trace(result2); // Expected: 1 (true)

Expected output:
  1
  undefined
  1
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

    Expected:
      Line 1: "1" (delete existing property returns true)
      Line 2: "undefined" (accessing deleted property)
      Line 3: "1" (delete non-existent property returns true)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Delete existing property should return 1
    expected_1 = "1"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "delete_existing_property",
        actual_1 == expected_1,
        expected_1,
        actual_1,
        "DELETE should return 1 (true) when deleting existing property"
    ))

    # Test 2: Accessing deleted property should return "undefined"
    expected_2 = "undefined"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "access_deleted_property",
        actual_2 == expected_2,
        expected_2,
        actual_2,
        "Accessing deleted property should return 'undefined'"
    ))

    # Test 3: Delete non-existent property should return 1 (AS2 spec)
    expected_3 = "1"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "delete_nonexistent_property",
        actual_3 == expected_3,
        expected_3,
        actual_3,
        "DELETE should return 1 (true) even for non-existent properties"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for init_array_swf_4

Tests the INIT_ARRAY opcode (0x42) which creates array objects.
Tests comprehensive array functionality including:
- Empty array creation
- Simple array with numeric elements
- Mixed-type arrays
- Array length property access
- Array element access by index
- Out of bounds access

Expected output:
0      - Empty array length
3      - Simple array length
1      - Simple array element [0]
2      - Simple array element [1]
3      - Simple array element [2]
hello  - Mixed array element [0]
42     - Mixed array element [1]
world  - Mixed array element [2]
undefined - Out of bounds access
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

    Expected output (9 lines):
    1. 0 (empty array length)
    2. 3 (simple array length)
    3. 1 (array[0])
    4. 2 (array[1])
    5. 3 (array[2])
    6. hello (mixed array[0])
    7. 42 (mixed array[1])
    8. world (mixed array[2])
    9. undefined (out of bounds)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Empty array length
    if len(lines) > 0:
        results.append(make_result(
            "empty_array_length",
            lines[0] == "0",
            "0",
            lines[0]
        ))
    else:
        results.append(make_result("empty_array_length", False, "0", ""))

    # Test 2: Simple array length
    if len(lines) > 1:
        results.append(make_result(
            "simple_array_length",
            lines[1] == "3",
            "3",
            lines[1]
        ))
    else:
        results.append(make_result("simple_array_length", False, "3", ""))

    # Test 3: Simple array element [0]
    if len(lines) > 2:
        results.append(make_result(
            "simple_array_elem_0",
            lines[2] == "1",
            "1",
            lines[2]
        ))
    else:
        results.append(make_result("simple_array_elem_0", False, "1", ""))

    # Test 4: Simple array element [1]
    if len(lines) > 3:
        results.append(make_result(
            "simple_array_elem_1",
            lines[3] == "2",
            "2",
            lines[3]
        ))
    else:
        results.append(make_result("simple_array_elem_1", False, "2", ""))

    # Test 5: Simple array element [2]
    if len(lines) > 4:
        results.append(make_result(
            "simple_array_elem_2",
            lines[4] == "3",
            "3",
            lines[4]
        ))
    else:
        results.append(make_result("simple_array_elem_2", False, "3", ""))

    # Test 6: Mixed array element [0] - "hello"
    if len(lines) > 5:
        results.append(make_result(
            "mixed_array_elem_0",
            lines[5] == "hello",
            "hello",
            lines[5]
        ))
    else:
        results.append(make_result("mixed_array_elem_0", False, "hello", ""))

    # Test 7: Mixed array element [1] - 42
    if len(lines) > 6:
        results.append(make_result(
            "mixed_array_elem_1",
            lines[6] == "42",
            "42",
            lines[6]
        ))
    else:
        results.append(make_result("mixed_array_elem_1", False, "42", ""))

    # Test 8: Mixed array element [2] - "world"
    if len(lines) > 7:
        results.append(make_result(
            "mixed_array_elem_2",
            lines[7] == "world",
            "world",
            lines[7]
        ))
    else:
        results.append(make_result("mixed_array_elem_2", False, "world", ""))

    # Test 9: Out of bounds access
    if len(lines) > 8:
        results.append(make_result(
            "out_of_bounds_access",
            lines[8] == "undefined",
            "undefined",
            lines[8]
        ))
    else:
        results.append(make_result("out_of_bounds_access", False, "undefined", ""))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

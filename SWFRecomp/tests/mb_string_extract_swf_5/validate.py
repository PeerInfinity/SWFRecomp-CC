#!/usr/bin/env python3
"""
Validation script for mb_string_extract_swf_5

Tests the MB_STRING_EXTRACT opcode with UTF-8 character awareness.
Expected output: Multiple substring extractions with correct character counting
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
    - Test 1: "Hello" (first 5 characters of "Hello World")
    - Test 2: "World" (5 characters starting at index 6)
    - Test 3: "caf" (first 3 characters of "café", é is 1 character)
    - Test 4: "llo" (from index 2 to end, even though count is 100)
    - Test 5: "" (empty - index 10 is out of bounds for "Hello")
    - Test 6: "" (empty - count is 0)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Basic extraction
    expected1 = "Hello"
    actual1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "basic_extraction",
        actual1 == expected1,
        expected1,
        actual1
    ))

    # Test 2: Middle extraction
    expected2 = "World"
    actual2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "middle_extraction",
        actual2 == expected2,
        expected2,
        actual2
    ))

    # Test 3: Multibyte character handling
    expected3 = "caf"
    actual3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "multibyte_extraction",
        actual3 == expected3,
        expected3,
        actual3
    ))

    # Test 4: Count extends beyond end
    expected4 = "llo"
    actual4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "count_beyond_end",
        actual4 == expected4,
        expected4,
        actual4
    ))

    # Test 5: Index out of bounds
    expected5 = ""
    actual5 = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "index_out_of_bounds",
        actual5 == expected5,
        expected5,
        actual5
    ))

    # Test 6: Zero count
    expected6 = ""
    actual6 = lines[5] if len(lines) > 5 else ""
    results.append(make_result(
        "zero_count",
        actual6 == expected6,
        expected6,
        actual6
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

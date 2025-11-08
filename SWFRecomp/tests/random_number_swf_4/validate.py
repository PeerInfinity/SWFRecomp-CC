#!/usr/bin/env python3
"""
Validation script for random_number_swf_4

Tests the RANDOM_NUMBER opcode (0x30).

Test cases:
1. random(0) -> should be 0
2. random(1) -> should be 0
3. random(10) -> should be in [0, 10)
4. random(100) -> should be in [0, 100)
5. random(1000) -> should be in [0, 1000)
6. random(-5) -> should be 0 (negative edge case)
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

    Expected output pattern:
    Test 1 - random(0):
    0
    Test 2 - random(1):
    0
    Test 3 - random(10):
    <integer in [0, 10)>
    Test 4 - random(100):
    <integer in [0, 100)>
    Test 5 - random(1000):
    <integer in [0, 1000)>
    Test 6 - random(-5):
    0
    """
    lines = parse_output(output)

    # Filter out test label lines (those starting with "Test")
    value_lines = [line for line in lines if not line.startswith("Test")]

    results = []

    # Validate Test 1: random(0) should be 0
    if len(value_lines) > 0:
        expected = "0"
        actual = value_lines[0]
        results.append(make_result(
            "random_0",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "random_0",
            False,
            "0",
            "missing",
            "No output for test 1"
        ))

    # Validate Test 2: random(1) should be 0
    if len(value_lines) > 1:
        expected = "0"
        actual = value_lines[1]
        results.append(make_result(
            "random_1",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "random_1",
            False,
            "0",
            "missing",
            "No output for test 2"
        ))

    # Validate Test 3: random(10) should be in [0, 10)
    if len(value_lines) > 2:
        try:
            value = int(value_lines[2])
            passed = 0 <= value < 10
            results.append(make_result(
                "random_10",
                passed,
                "[0, 10)",
                str(value),
                None if passed else f"Value {value} out of range"
            ))
        except ValueError:
            results.append(make_result(
                "random_10",
                False,
                "[0, 10)",
                value_lines[2],
                "Could not parse as integer"
            ))
    else:
        results.append(make_result(
            "random_10",
            False,
            "[0, 10)",
            "missing",
            "No output for test 3"
        ))

    # Validate Test 4: random(100) should be in [0, 100)
    if len(value_lines) > 3:
        try:
            value = int(value_lines[3])
            passed = 0 <= value < 100
            results.append(make_result(
                "random_100",
                passed,
                "[0, 100)",
                str(value),
                None if passed else f"Value {value} out of range"
            ))
        except ValueError:
            results.append(make_result(
                "random_100",
                False,
                "[0, 100)",
                value_lines[3],
                "Could not parse as integer"
            ))
    else:
        results.append(make_result(
            "random_100",
            False,
            "[0, 100)",
            "missing",
            "No output for test 4"
        ))

    # Validate Test 5: random(1000) should be in [0, 1000)
    if len(value_lines) > 4:
        try:
            value = int(value_lines[4])
            passed = 0 <= value < 1000
            results.append(make_result(
                "random_1000",
                passed,
                "[0, 1000)",
                str(value),
                None if passed else f"Value {value} out of range"
            ))
        except ValueError:
            results.append(make_result(
                "random_1000",
                False,
                "[0, 1000)",
                value_lines[4],
                "Could not parse as integer"
            ))
    else:
        results.append(make_result(
            "random_1000",
            False,
            "[0, 1000)",
            "missing",
            "No output for test 5"
        ))

    # Validate Test 6: random(-5) should be 0 (negative edge case)
    if len(value_lines) > 5:
        expected = "0"
        actual = value_lines[5]
        results.append(make_result(
            "random_negative",
            actual == expected,
            expected,
            actual,
            None if actual == expected else "Negative max should return 0"
        ))
    else:
        results.append(make_result(
            "random_negative",
            False,
            "0",
            "missing",
            "No output for test 6"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

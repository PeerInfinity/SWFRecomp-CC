#!/usr/bin/env python3
"""
Validation script for call_swf_4 comprehensive test

Tests all ActionCall (0x9E) scenarios:
- Numeric frames (executed)
- String numeric frames (executed)
- Frame labels (logged as not implemented)
- Target paths (logged as not implemented)
- Edge cases (negative, out of range)
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
    Validate comprehensive test output.

    Expected trace output sequence:
    1. Frame 0 starting
    2. Frame 1 executed (from numeric call)
    3. Frame 0 done
    4. Test 1: Call frame 1 with string
    5. Frame 1 executed (from string call)
    6. Test 2: Call with label
    7. Test 3: Call with target path
    8. Test 4: Negative frame
    9. Test 5: Out of range
    10. All tests complete
    """
    lines = parse_output(output)

    results = []

    # Expected outputs
    expected_sequence = [
        ("frame_0_start", "Frame 0 starting"),
        ("frame_1_called", "Frame 1 executed"),
        ("frame_0_done", "Frame 0 done"),
        ("test_1_label", "Test 1: Call frame 1 with string"),
        ("frame_1_called_again", "Frame 1 executed"),
        ("test_2_label", "Test 2: Call with label"),
        ("test_3_label", "Test 3: Call with target path"),
        ("test_4_label", "Test 4: Negative frame"),
        ("test_5_label", "Test 5: Out of range"),
        ("all_tests_done", "All tests complete"),
    ]

    # Validate each expected output
    for i, (test_name, expected) in enumerate(expected_sequence):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            test_name,
            actual == expected,
            expected,
            actual
        ))

    # Additional validation: check that frame 1 was called twice
    frame_1_count = sum(1 for line in lines if line == "Frame 1 executed")
    results.append(make_result(
        "frame_1_called_twice",
        frame_1_count == 2,
        "2",
        str(frame_1_count)
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

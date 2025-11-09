#!/usr/bin/env python3
"""
Validation script for clone_sprite_swf_4

Tests the CLONE_SPRITE opcode (0x24) with comprehensive edge cases.
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

    Expected output tests various clone operations including edge cases.
    """
    lines = parse_output(output)

    results = []

    # Expected test outputs
    expected_outputs = [
        ("basic_clone", "Test 1: Basic clone"),
        ("different_depth", "Test 2: Different depth"),
        ("negative_depth", "Test 3: Negative depth"),
        ("zero_depth", "Test 4: Zero depth"),
        ("empty_strings", "Test 5: Empty strings"),
        ("long_names", "Test 6: Long names"),
        ("completion", "All tests complete"),
    ]

    # Validate each expected output
    for i, (test_name, expected) in enumerate(expected_outputs):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            test_name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

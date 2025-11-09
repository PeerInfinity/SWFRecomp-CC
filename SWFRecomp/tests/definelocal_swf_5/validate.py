#!/usr/bin/env python3
"""
Validation script for definelocal_swf_5

Tests the DEFINE_LOCAL opcode (0x3C).
Expected output: 42
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

    Expected output (6 lines):
    42       - Test 1: Basic definition
    100      - Test 2: Redefinition
    Hello    - Test 3: String value
    0        - Test 4: Zero value
    -5       - Test 5: Negative value
    100      - Test 6: Variable persistence
    """
    lines = parse_output(output)

    # Define expected outputs for each test
    test_cases = [
        ("definelocal_basic", "42", "Basic variable definition"),
        ("definelocal_redefine", "100", "Variable redefinition"),
        ("definelocal_string", "Hello", "String value"),
        ("definelocal_zero", "0", "Zero value"),
        ("definelocal_negative", "-5", "Negative value"),
        ("definelocal_persistence", "100", "Variable persistence")
    ]

    results = []

    # Check we have enough output lines
    if len(lines) < len(test_cases):
        for i, (name, expected, description) in enumerate(test_cases):
            actual = lines[i] if i < len(lines) else ""
            results.append(make_result(
                name,
                i < len(lines) and actual == expected,
                expected,
                actual,
                f"{description} - missing output" if i >= len(lines) else None
            ))
        return make_validation_result(results)

    # Validate each test case
    for i, (name, expected, description) in enumerate(test_cases):
        actual = lines[i]
        results.append(make_result(
            name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

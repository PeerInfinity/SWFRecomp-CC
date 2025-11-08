#!/usr/bin/env python3
"""
Validation script for or_swf_4

Tests the ActionOr (0x11) opcode - logical OR operation.

Expected output (4 lines):
1. trace(1 || 1) = 1
2. trace(1 || 0) = 1
3. trace(0 || 1) = 1
4. trace(0 || 0) = 0
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
    Validate test output for ActionOr opcode.

    Expected outputs:
    - Line 0: 1 (test: 1 || 1)
    - Line 1: 1 (test: 1 || 0)
    - Line 2: 1 (test: 0 || 1)
    - Line 3: 0 (test: 0 || 0)
    """
    lines = parse_output(output)

    results = []

    # Validate each test case
    test_cases = [
        ("both_true", "1", "1 || 1"),
        ("first_true_second_false", "1", "1 || 0"),
        ("first_false_second_true", "1", "0 || 1"),
        ("both_false", "0", "0 || 0")
    ]

    for i, (name, expected, description) in enumerate(test_cases):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            results.append(make_result(name, passed, expected, actual))
        else:
            results.append(make_result(
                name,
                False,
                expected,
                "(missing)",
                f"Missing output for test: {description}"
            ))

    # Check if we have exactly 4 outputs (no more, no less)
    if len(lines) > len(test_cases):
        results.append(make_result(
            "extra_outputs",
            False,
            f"{len(test_cases)} outputs",
            f"{len(lines)} outputs",
            f"Got {len(lines) - len(test_cases)} extra output line(s)"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

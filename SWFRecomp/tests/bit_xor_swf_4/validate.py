#!/usr/bin/env python3
"""
Validation script for bit_xor_swf_4

Tests the BIT_XOR opcode with 5 test cases:
1. Basic XOR: 12 ^ 10 = 6
2. Identity property: 42 ^ 0 = 42
3. Self-cancellation: 15 ^ 15 = 0
4. Bit flipping: 170 ^ 85 = 255
5. Self-inverse property: (42 ^ 17) ^ 17 = 42
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
    Validate test output for BIT_XOR opcode.

    Expected outputs:
    - Line 1: 6 (12 ^ 10)
    - Line 2: 42 (42 ^ 0, identity property)
    - Line 3: 0 (15 ^ 15, self-cancellation)
    - Line 4: 255 (170 ^ 85, bit flipping)
    - Line 5: 42 ((42 ^ 17) ^ 17, self-inverse property)
    """
    lines = parse_output(output)

    results = []

    # Test case 1: Basic XOR (12 ^ 10 = 6)
    expected = "6"
    actual = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "basic_xor_12_10",
        actual == expected,
        expected,
        actual
    ))

    # Test case 2: XOR with zero - identity property (42 ^ 0 = 42)
    expected = "42"
    actual = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "identity_42_xor_0",
        actual == expected,
        expected,
        actual
    ))

    # Test case 3: XOR with itself - self-cancellation (15 ^ 15 = 0)
    expected = "0"
    actual = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "self_cancel_15_xor_15",
        actual == expected,
        expected,
        actual
    ))

    # Test case 4: Bit flipping (170 ^ 85 = 255)
    expected = "255"
    actual = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "bit_flip_170_xor_85",
        actual == expected,
        expected,
        actual
    ))

    # Test case 5: Double XOR - self-inverse property ((42 ^ 17) ^ 17 = 42)
    expected = "42"
    actual = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "self_inverse_double_xor",
        actual == expected,
        expected,
        actual
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

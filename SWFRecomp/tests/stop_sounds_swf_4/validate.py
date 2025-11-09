#!/usr/bin/env python3
"""
Validation script for stop_sounds_swf_4

Comprehensive test of the STOP_SOUNDS opcode (0x09).
Tests:
1. Basic functionality - opcode executes without error
2. Stack integrity - opcode doesn't affect the stack
3. Multiple calls - opcode can be called multiple times
4. Integration - opcode works with other operations
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

    Expected output:
    Test 1: Basic stopAllSounds
    Success
    Test 2: Stack integrity
    42
    Test 3: Multiple calls
    Success
    Test 4: Integration test
    15
    """
    lines = parse_output(output)

    results = []

    # Test 1: Basic functionality
    results.append(make_result(
        "test1_header",
        lines[0] == "Test 1: Basic stopAllSounds" if len(lines) > 0 else False,
        "Test 1: Basic stopAllSounds",
        lines[0] if len(lines) > 0 else ""
    ))

    results.append(make_result(
        "test1_success",
        lines[1] == "Success" if len(lines) > 1 else False,
        "Success",
        lines[1] if len(lines) > 1 else ""
    ))

    # Test 2: Stack integrity - value should still be on stack after stopAllSounds
    results.append(make_result(
        "test2_header",
        lines[2] == "Test 2: Stack integrity" if len(lines) > 2 else False,
        "Test 2: Stack integrity",
        lines[2] if len(lines) > 2 else ""
    ))

    results.append(make_result(
        "test2_stack_integrity",
        lines[3] == "42" if len(lines) > 3 else False,
        "42",
        lines[3] if len(lines) > 3 else ""
    ))

    # Test 3: Multiple calls
    results.append(make_result(
        "test3_header",
        lines[4] == "Test 3: Multiple calls" if len(lines) > 4 else False,
        "Test 3: Multiple calls",
        lines[4] if len(lines) > 4 else ""
    ))

    results.append(make_result(
        "test3_success",
        lines[5] == "Success" if len(lines) > 5 else False,
        "Success",
        lines[5] if len(lines) > 5 else ""
    ))

    # Test 4: Integration with arithmetic - stopAllSounds shouldn't affect stack operations
    results.append(make_result(
        "test4_header",
        lines[6] == "Test 4: Integration test" if len(lines) > 6 else False,
        "Test 4: Integration test",
        lines[6] if len(lines) > 6 else ""
    ))

    results.append(make_result(
        "test4_arithmetic",
        lines[7] == "15" if len(lines) > 7 else False,
        "15",
        lines[7] if len(lines) > 7 else ""
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

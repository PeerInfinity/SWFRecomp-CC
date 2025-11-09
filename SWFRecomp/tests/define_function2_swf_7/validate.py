#!/usr/bin/env python3
"""
Validation script for define_function2_swf_7

Tests the DEFINE_FUNCTION2 opcode (0x8E) with comprehensive tests including:
1. Function with register parameters and ADD operation
2. Function with no parameters returning a constant
3. Function calls with different arguments
4. Return value handling

Expected outputs:
- add(10, 20) -> 30
- add(5, 7) -> 12
- getFortyTwo() -> 42
- add(100.5, 200.5) -> 301
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
    - Line 0: 30 (result of add(10, 20))
    - Line 1: 12 (result of add(5, 7))
    - Line 2: 42 (result of getFortyTwo())
    - Line 3: 301 (result of add(100.5, 200.5))
    """
    lines = parse_output(output)
    results = []

    # Test 1: add(10, 20) = 30
    if len(lines) > 0:
        results.append(make_result(
            "add_10_20",
            lines[0] == "30",
            "30",
            lines[0]
        ))
    else:
        results.append(make_result("add_10_20", False, "30", "(no output)"))

    # Test 2: add(5, 7) = 12
    if len(lines) > 1:
        results.append(make_result(
            "add_5_7",
            lines[1] == "12",
            "12",
            lines[1]
        ))
    else:
        results.append(make_result("add_5_7", False, "12", "(no output)"))

    # Test 3: getFortyTwo() = 42
    if len(lines) > 2:
        results.append(make_result(
            "getFortyTwo",
            lines[2] == "42",
            "42",
            lines[2]
        ))
    else:
        results.append(make_result("getFortyTwo", False, "42", "(no output)"))

    # Test 4: add(100.5, 200.5) = 301
    if len(lines) > 3:
        results.append(make_result(
            "add_100_5_200_5",
            lines[3] == "301",
            "301",
            lines[3]
        ))
    else:
        results.append(make_result("add_100_5_200_5", False, "301", "(no output)"))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

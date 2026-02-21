#!/usr/bin/env python3
"""
Validation script for set_target_swf_3

Tests the ActionSetTarget opcode (0x8B) with trace output.
In NO_GRAPHICS mode, SetTarget to any sprite name silently fails.

Expected output:
  Line 1: test1 (trace before SetTarget)
  Line 2: test2 (trace after SetTarget to nonexistent sprite)
  Line 3: Done (trace after SetTarget reset to main)
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

    Expected 3 lines:
    1. "test1" - trace on main timeline before any SetTarget
    2. "test2" - trace after SetTarget("nonexistent") (silently ignored)
    3. "Done" - trace after SetTarget("") resets to main
    """
    lines = parse_output(output)

    results = []

    # Test 1: trace before SetTarget
    expected_1 = "test1"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "trace_before_set_target",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test 2: trace after SetTarget to nonexistent sprite
    expected_2 = "test2"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "trace_after_invalid_set_target",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test 3: trace after SetTarget reset
    expected_3 = "Done"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "trace_after_set_target_reset",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

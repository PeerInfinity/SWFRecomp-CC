#!/usr/bin/env python3
"""
Validation script for jump_swf_4

Tests the JUMP opcode (0x99) - unconditional forward jump.

Test sequence:
1. Push 1, trace (executes)
2. Jump forward to skip next instruction
3. Push 2, trace (skipped)
4. Push 3, trace (executes)

Expected output:
  1
  3
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
    - Line 1: "1" (executed before jump)
    - Line 2: "3" (executed after jump - value 2 was skipped)
    """
    lines = parse_output(output)

    results = []

    # Check first output (before jump)
    expected_1 = "1"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "before_jump",
        actual_1 == expected_1,
        expected_1,
        actual_1,
        None if actual_1 == expected_1 else "First trace should output 1"
    ))

    # Check second output (after jump - skipped value 2)
    expected_3 = "3"
    actual_3 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "after_jump",
        actual_3 == expected_3,
        expected_3,
        actual_3,
        None if actual_3 == expected_3 else "Jump should skip value 2, output 3"
    ))

    # Verify no extra output
    if len(lines) > 2:
        results.append(make_result(
            "no_extra_output",
            False,
            "2 lines",
            f"{len(lines)} lines",
            "Should only have 2 outputs (jump should skip the middle trace)"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

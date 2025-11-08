#!/usr/bin/env python3
"""
Validation script for return_swf_4

Tests the RETURN opcode (0x3E).

Expected behavior:
- "Script started" appears
- Script exits via RETURN opcode
- "After RETURN" message does NOT appear (proving early exit works)
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
    - Line 1: "Script started"
    - No additional output (script exits early via RETURN)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Check that "Script started" appears
    if len(lines) > 0:
        expected = "Script started"
        actual = lines[0]
        results.append(make_result(
            "script_started",
            actual == expected,
            expected,
            actual
        ))
    else:
        results.append(make_result(
            "script_started",
            False,
            "Script started",
            "(no output)",
            "No output received from test"
        ))

    # Test 2: Verify that no additional output appears after RETURN
    # (The "After RETURN" message should NOT appear)
    if len(lines) == 1:
        results.append(make_result(
            "early_exit",
            True,
            "1 line (early exit)",
            f"{len(lines)} line(s)"
        ))
    else:
        results.append(make_result(
            "early_exit",
            False,
            "1 line (early exit)",
            f"{len(lines)} line(s)",
            f"RETURN should exit early - unexpected output: {lines[1:] if len(lines) > 1 else []}"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

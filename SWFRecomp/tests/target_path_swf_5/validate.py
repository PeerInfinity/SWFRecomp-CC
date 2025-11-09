#!/usr/bin/env python3
"""
Validation script for target_path_swf_5

Tests the TARGET_PATH opcode (0x45) comprehensively.
Expected output:
- "undefined" for targetPath(number)
- "undefined" for targetPath(string)
- "undefined" for targetPath(0)
- "undefined" for targetPath(undefined)
- "All tests complete"
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

    Expected lines:
    1. "undefined" - targetPath(42.0)
    2. "undefined" - targetPath("test")
    3. "undefined" - targetPath(0)
    4. "undefined" - targetPath(undefined)
    5. "All tests complete"
    """
    lines = parse_output(output)

    results = []

    # Check line count
    expected_count = 5
    if len(lines) != expected_count:
        results.append(make_result(
            "output_count",
            False,
            f"{expected_count} lines",
            f"{len(lines)} lines",
            f"Expected {expected_count} lines, got {len(lines)}: {lines}"
        ))
    else:
        results.append(make_result(
            "output_count",
            True,
            f"{expected_count} lines",
            f"{expected_count} lines"
        ))

    # Test 1: targetPath(number) should return undefined
    if len(lines) > 0:
        results.append(make_result(
            "targetPath_number",
            lines[0] == "undefined",
            "undefined",
            lines[0]
        ))
    else:
        results.append(make_result(
            "targetPath_number",
            False,
            "undefined",
            "<missing>"
        ))

    # Test 2: targetPath(string) should return undefined
    if len(lines) > 1:
        results.append(make_result(
            "targetPath_string",
            lines[1] == "undefined",
            "undefined",
            lines[1]
        ))
    else:
        results.append(make_result(
            "targetPath_string",
            False,
            "undefined",
            "<missing>"
        ))

    # Test 3: targetPath(0) should return undefined
    if len(lines) > 2:
        results.append(make_result(
            "targetPath_zero",
            lines[2] == "undefined",
            "undefined",
            lines[2]
        ))
    else:
        results.append(make_result(
            "targetPath_zero",
            False,
            "undefined",
            "<missing>"
        ))

    # Test 4: targetPath(undefined) should return undefined
    if len(lines) > 3:
        results.append(make_result(
            "targetPath_undefined",
            lines[3] == "undefined",
            "undefined",
            lines[3]
        ))
    else:
        results.append(make_result(
            "targetPath_undefined",
            False,
            "undefined",
            "<missing>"
        ))

    # Test 5: Completion message
    if len(lines) > 4:
        results.append(make_result(
            "completion_message",
            lines[4] == "All tests complete",
            "All tests complete",
            lines[4]
        ))
    else:
        results.append(make_result(
            "completion_message",
            False,
            "All tests complete",
            "<missing>"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

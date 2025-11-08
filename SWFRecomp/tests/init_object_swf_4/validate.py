#!/usr/bin/env python3
"""
Validation script for init_object_swf_4

Tests the INIT_OBJECT opcode (0x43) which creates objects with properties.

Expected output:
  Line 1: "object" - typeof empty object
  Line 2: "object" - typeof object with properties
  Line 3: "InitObject tests complete" - completion message
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
    Validate test output for INIT_OBJECT opcode.

    Expected outputs:
    1. "object" - typeof empty object {}
    2. "object" - typeof object with properties {x: 10, y: 20}
    3. "InitObject tests complete" - completion message
    """
    lines = parse_output(output)

    results = []

    # Check we have enough output lines
    if len(lines) < 3:
        results.append(make_result(
            "output_count",
            False,
            "3 lines",
            f"{len(lines)} lines",
            f"Expected 3 output lines, got {len(lines)}"
        ))
        return make_validation_result(results)

    # Test 1: Empty object typeof should be "object"
    results.append(make_result(
        "empty_object_typeof",
        lines[0] == "object",
        "object",
        lines[0]
    ))

    # Test 2: Object with properties typeof should be "object"
    results.append(make_result(
        "object_with_props_typeof",
        lines[1] == "object",
        "object",
        lines[1]
    ))

    # Test 3: Completion message
    results.append(make_result(
        "completion_message",
        lines[2] == "InitObject tests complete",
        "InitObject tests complete",
        lines[2]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))

#!/usr/bin/env python3
"""
Validation script for constant_pool_swf_5

Tests the CONSTANT_POOL opcode (0x88).
Expected output: Traces three strings from the constant pool
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
    hello
    world
    test
    """
    lines = parse_output(output)

    results = []

    # Check we have exactly 3 lines
    if len(lines) != 3:
        results.append(make_result(
            "output_count",
            False,
            "3 lines",
            f"{len(lines)} lines",
            f"Expected 3 output lines, got {len(lines)}"
        ))
        # Pad with empty strings if needed
        while len(lines) < 3:
            lines.append("")
    else:
        results.append(make_result("output_count", True, "3 lines", "3 lines"))

    # Check each output line
    results.append(make_result(
        "constant_pool_index_0",
        lines[0] == "hello",
        "hello",
        lines[0] if lines else ""
    ))

    results.append(make_result(
        "constant_pool_index_1",
        lines[1] == "world",
        "world",
        lines[1] if len(lines) > 1 else ""
    ))

    results.append(make_result(
        "constant_pool_index_2",
        lines[2] == "test",
        "test",
        lines[2] if len(lines) > 2 else ""
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
